#include <cctype>
#include <fstream>
#include <cassert>
#include <cstdlib>
#include <sstream>

#include "Driver.hpp"
#include "FinalCode.h"

C0::Driver::~Driver() {
    delete (scanner);
    scanner = nullptr;
    delete (parser);
    parser = nullptr;
    delete table;
    table = nullptr;
}

void C0::Driver::parse(const string& filename) {
    this->filename = filename;
    std::ifstream in_file(filename);
    if (!in_file.good()) {
        exit(EXIT_FAILURE);
    }
    parse_helper(in_file);
    return;
}

void C0::Driver::parse_helper(std::istream &stream) {

    delete (scanner);
    try {
        scanner = new C0::Scanner(&stream);
    }    catch (std::bad_alloc &ba) {
        std::cerr << "Failed to allocate scanner: (" << ba.what() << "), exiting!!\n";
        exit(EXIT_FAILURE);
    }

    delete (parser);
    try {
        parser = new C0::Parser((*scanner) /* scanner */,
                (*this) /* driver */);
    }    catch (std::bad_alloc &ba) {
        std::cerr << "Failed to allocate parser: (" << ba.what() << "), exiting!!\n";
        exit(EXIT_FAILURE);
    }
    const int accept(0);
    if (parser->parse() != accept) {
        std::cerr << "Parse failed!!\n";
    }
    return;
}

void C0::Driver::init() {
    // TODO(39) Borrar la línea 56
    table = new Table();
    // TODO(40) Crear el apuntador a stack de tipo Stack 
    gDir = 0;
    iStack = new PilaCount();
    wStack = new PilaCount();
    // TODO(41) Crear el apuntador a dirStack similar a iStack
    numIf = 0;
    numWhile = 0;
    numTemp = 0;
    numString = 0;
    // TODO(42) Asignar un valor inicial de cero a gType
    // TODO(43) Asignar un valor inicial de cero a gBase
    int pos=  filename.find(".");
    output = filename.substr(0,pos-1)+".ens";
}

string C0::Driver::newLabel(int n) {
    stringstream l;
    l << "L" << n;
    return l.str();
}

string C0::Driver::newTemp() {
    stringstream l;
    l << "t" << numTemp;
    numTemp++;
    return l.str();
}

bool C0::Driver::isInSymbol(string id) {
    // TODO(43) Cambiar el uso de table por tstak, siempre obteniendo la tabla que se encuenta en el top de tstack
    return table->isInSymbol(id);
}

void C0::Driver::addSymbol(string id) {
    // TODO(44) Cambiar el uso de table por tstak, siempre obteniendo la tabla que se encuenta en el top de tstack
    table->addSymbol(id);
}

void C0::Driver::setDir(string id, int dir) {
    // TODO(45) Cambiar el uso de table por tstak, siempre obteniendo la tabla que se encuenta en el top de tstack
    table->setDir(id, dir);
}

void C0::Driver::setType(string id, int type) {
    // TODO(46) Cambiar el uso de table por tstak, siempre obteniendo la tabla que se encuenta en el top de tstack
    table->setType(id, type);
}

int C0::Driver::getType(string id) {
    // TODO(47) Cambiar el uso de table por tstak, siempre obteniendo la tabla que se encuenta en el top de tstack
    return table->getType(id);
}

void C0::Driver::setVar(string id, string var) {
    // TODO(48) Cambiar el uso de table por tstak, siempre obteniendo la tabla que se encuenta en el top de tstack
    table->setTypeVar(id, var);
}

string C0::Driver::getVar(string id) {
    // TODO(49) Cambiar el uso de table por tstak, siempre obteniendo la tabla que se encuenta en el top de tstack
    return table->getTypeVar(id);
}

C0::Expresion C0::Driver::add(Expresion e1, Expresion e2) {
    Expresion e;
    if (e1.getType() == e2.getType()) {
        e = Expresion(newTemp(), e1.getType());
        addQuad(Quad("+", e1.getDir(), e2.getDir(), e.getDir()));
        return e;
    }
    return e;
}

C0::Expresion C0::Driver::sub(Expresion e1, Expresion e2) {
    Expresion e3;
    if (e1.getType() == e2.getType()) {
        e3 = Expresion(newTemp(), e1.getType());
        addQuad(Quad("-", e1.getDir(), e2.getDir(), e3.getDir()));
        return e3;
    }
    return e3;
}

C0::Expresion C0::Driver::mul(Expresion e1, Expresion e2) {
    Expresion e3;
    if (e1.getType() == e2.getType()) {
        e3 = Expresion(newTemp(), e1.getType());
        addQuad(Quad("*", e1.getDir(), e2.getDir(), e3.getDir()));
        return e3;
    }
    return e3;
}

C0::Expresion C0::Driver::div(Expresion e1, Expresion e2) {
    Expresion e3;
    if (e1.getType() == e2.getType()) {
        e3 = Expresion(newTemp(), e1.getType());
        addQuad(Quad("/", e1.getDir(), e2.getDir(), e3.getDir()));
        return e3;
    }
    return e3;
}

C0::Expresion C0::Driver::number(string num) {
    Expresion e3(num, 0);
    return e3;
}

C0::Expresion C0::Driver::ident(string id) {
    // TODO(51) Buscar el id en la tabla de la cima de la pila
    // TODO(52) En caso de que el id no exista en la tabla de la cima buscar en la tabla global
    // TODO(53) Cambiar el uso de table por tstak, siempre obteniendo la tabla que se encuenta en el top de tstack
    int type = table->getType(id);
    Expresion e2(id, type);
    return e2;
}

C0::Expresion C0::Driver::_or(Expresion e1, Expresion e2) {
    Expresion e3;
    if (e1.getType() == e2.getType()) {
        e3 = Expresion(newTemp(), e1.getType());
        addQuad(Quad("or", e1.getDir(), e2.getDir(), e2.getDir()));
        return e3;
    }
    return e3;
}

C0::Expresion C0::Driver::_and(Expresion e1, Expresion e2) {
    Expresion e3;
    if (e1.getType() == e2.getType()) {
        e3 = Expresion(newTemp(), e1.getType());
        addQuad(Quad("and", e1.getDir(), e2.getDir(), e3.getDir()));
        return e3;
    }
    return e3;
}

C0::Expresion C0::Driver::gt(Expresion e1, Expresion e2) {
    Expresion e3;
    if (e1.getType() == e2.getType()) {
        e3 = Expresion(newTemp(), e1.getType());
        addQuad(Quad(">", e1.getDir(), e2.getDir(), e3.getDir()));
        return e3;
    }
    return e3;
}

C0::Expresion C0::Driver::lt(Expresion e1, Expresion e2) {
    Expresion e3;
    if (e1.getType() == e2.getType()) {
        e3 = Expresion(newTemp(), e1.getType());
        addQuad(Quad("<", e1.getDir(), e2.getDir(), e3.getDir()));
        return e3;
    }
    return e3;
}

C0::Expresion C0::Driver::equal(Expresion e1, Expresion e2) {
    Expresion e3;
    if (e1.getType() == e2.getType()) {
        e3 = Expresion(newTemp(), e1.getType());
        addQuad(Quad("==", e1.getDir(), e2.getDir(), e3.getDir()));
        return e3;
    }
    return e3;
}

C0::Expresion C0::Driver::distinct(Expresion e1, Expresion e2) {
    Expresion e3;
    if (e1.getType() == e2.getType()) {
        e3 = Expresion(newTemp(), e1.getType());
        addQuad(Quad("!=", e1.getDir(), e2.getDir(), e3.getDir()));
        return e3;
    }
    return e3;
}

void C0::Driver::asign(string id, Expresion e2) {
    C0::Expresion e3;
    // TODO(50) Cambiar el uso de table por tstak, siempre obteniendo la tabla que se encuenta en el top de tstack
    int type = table->getType(id);
    //int dir = table->getDir(id);
    if (type == e2.getType()) {
        addQuad(Quad("=", e2.getDir(), "", id));

    }

}

void C0::Driver::addQuad(Quad q) {
    ci.push_back(q);
}

void C0::Driver::_if(Expresion e, int n) {
    stringstream l;
    l << "Le" << n;
    addQuad(Quad("ifFalse", e.getDir(), "", l.str()));
}

void C0::Driver::_while(Expresion e, int n) {
    stringstream l, l2;
    l << "Lew" << n;
    addQuad(Quad("ifFalse", e.getDir(), "", l.str()));

}

void C0::Driver::_goto(string label, int n) {
    stringstream l;
    l << label << n;
    addQuad(Quad("goto", "", "", l.str()));
}

void C0::Driver::_label(string label, int n) {
    stringstream l;
    l << label << n;
    addQuad(Quad("label", "", "", l.str()));
}

void C0::Driver::printCI() {
    cout << "Codigo intermedio " << ci.size() << endl;
    for (Quad q : ci) {
        if (q.getOp() == "=")
            cout << "\t\t" << q.getRes() << " " << q.getOp() << " " << q.getArg1() << endl;
        else if (q.getOp() == "label")
            cout << q.getRes() << ": " << endl;
        else if (q.getOp() == "ifFalse")
            cout << "\t\t" << q.getOp() << " " << q.getArg1() << " goto " << q.getRes() << endl;
        else if (q.getOp() == "goto")
            cout << "\t\t" << q.getOp() << " " << q.getRes() << endl;
        else if (q.getArg2() == "")
            cout << "\t\t" << q.getRes() << " = " << q.getOp() << " " << q.getArg1() << endl;
        else
            cout << "\t\t" << q.getRes() << " = " << q.getArg1() << " " << q.getOp() << " " << q.getArg2() << endl;
    }
}

void C0::Driver::printSymTab() {
    cout << "Tabla de símbolos" << endl;
    for (Symbol s : table->getSymTab()) {
        cout << s.getId() << "\t" << s.getDir() << "\t" << s.getType() << "\t" << s.getTypeVar() << endl;
    }
}

void C0::Driver::writew(Expresion e) {
    addQuad(Quad("printi", e.getDir(), "", ""));
}

void C0::Driver::writes(string s,int c) {
    stringstream ss;
    ss << c;
    addQuad(Quad("prints", ss.str(), "", ""));
    addString(s);
}

void C0::Driver::generateStrings() {
    for (unsigned int i = 0; i < strings.size(); i++) {
        addQuad(Quad("string",strings[i],"",""));
    }

}

void C0::Driver::addString(string s){
    strings.push_back(s);
}

void C0::Driver::translate() {
    FinalCode fc(output, ci);
    fc.translate();
}

void C0::Driver::addQuad(Quad q) {
    ci.push_back(q);
}

// TODO(54) Programar la funcion miembro que envuelve a getName de la tabla de tipos
   int getName(SYMTAB *st, char *id){
    int i;
    for(i =0; i< st->num; i++){
        if(strcmp(st->syms[i].id, id) == 0)
            return st->syms[i].name;
        }
    return -1;
    }
// TODO(55) Programar la funcion miembro que envuelve a getTam de la tabla de tipos
    int getTam(TYPTAB *t, int id){
        TYP *i = t->head;
        while(i != NULL){
            if(i->id == id){
			return i->tam;
            }
            i = i->next;
        }
        return -1;
    }
// TODO(56) Programar la funcion miembro que envuelve a getTipoBase de la tabla de tipos
    TYPTAB getTipoBase(TYPTAB *t, int id){
	TYP *i = t->head;
	while(i != NULL){
		if(i->id == id){
			return i->tb;
		}
		i = i->next;
        }

    } 
// TODO(57) Programar la funcion miembro que envuelve a getNumImtes de la tabla de tipos


// TODO(58) Programar la funcion miembro que envuelve a getBase de la tabla de tipos
    int getBase(SYMTAB *st, char *id){
    int i;
    for(i =0; i< st->num; i++){
        if(strcmp(st->syms[i].id, id) == 0)
            return st->syms[i].base;
    }
    return -1;
    }

// TODO(59) Programar la funcion miembro que envuelve a setBase de la tabla de tipos   

void C0::Driver::variable(string id){
    if(isInSymbol(id))
        cout<<"La variable ya fue declarada"<<endl;
    else{
        addSymbol(id);
        setType(id, gType);
        setDir(id, gDir);
        setVar(id, "variable");
        gDir+= stack->top().getTam(gType);
    }
}


//TODO(65) Programar la función miembro que envuelva un push a tstack
//TODO(66) Programar la función miembro que retorne un Table* al hacer pop a tstack
//TODO(70) Programar la función miembro que añade el tipo struct a la tabla de tipos
// Como consejo usar la función miembro de Table setBase(Table *t)
