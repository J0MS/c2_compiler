#include "Table.h"
#include <iostream>
#include <cstring>
using namespace std;

C0::Table::Table(){
    addType("int");
}

C0::Table::~Table(){

}

void C0::Table::addSymbol(string id){
    symTab.push_back(Symbol(id));
}

void C0::Table::addType(string  name){
    typeTab.push_back(Type(name, 4));
}

bool C0::Table::isInSymbol(string id){
    //cout<<"buscando ...."<<id<<endl;
    for(Symbol s: symTab){
        //cout<<"comparando con"<<s.getId()<<endl;
        if(strcmp(s.getId().c_str(), id.c_str())==0){
            //cout<<"se encontro la variable "<<id<<endl;
            return true;
        }
    }
    return false;
}

void C0::Table::setDir(string id, int dir){    
    for(unsigned int i= 0; i < symTab.size();i++){
        if(symTab[i].getId() == id){
            symTab[i].setDir(dir);            
            return;
        }
    }
}

void C0::Table::setType(string id, int type){
    for(unsigned int i= 0; i < symTab.size();i++){
        if(symTab[i].getId() == id){
            symTab[i].setType(type);
            //cout<<s.getDir()<<endl;
            return;
        }
    }
}

void C0::Table::setTypeVar(string id, string type){
    for(unsigned int i= 0; i < symTab.size();i++){
        if(symTab[i].getId() == id){
            symTab[i].setTypeVar(type);
            //cout<<s.getDir()<<endl;
            return;
        }
    }
}

void C0::Table::setArgs(string id, vector<int> args){
    for(unsigned int i= 0; i < symTab.size();i++){
        if(symTab[i].getId() == id){
            symTab[i].setArgs(args);
            //cout<<s.getDir()<<endl;
            return;
        }
    }
}

int C0::Table::getDir(string id){
    for(Symbol s: symTab){
        if(s.getId() == id){            
            return s.getDir();
        }
    }
    return -1;
}

int C0::Table::getType(string id){
    for(Symbol s: symTab){
        if(s.getId() == id){            
            return s.getType();
        }
    }
    return -1;
}
    
string C0::Table::getTypeVar(string id){
    for(Symbol s: symTab){
        if(s.getId() == id){            
            return s.getTypeVar();
        }
    }
    return "";
}

vector<int> C0::Table::getArgs(string id){
    for(Symbol s: symTab){
        if(s.getId() == id){            
            return s.getArgs();
        }
    }
    vector<int> a;
    return a;
}

vector<C0::Symbol> C0::Table::getSymTab(){
    return symTab;
}

// TODO(16) Programar addType para que reciba un nombre: string, tam:int

// TODO(17) Programar addType para que reciba un nombre: string, numeroItems:int, tipoBase:int
// TODO(18) Programar getName para tabla de tipos, recibe id:int
   int getName(TYPTAB *t, int id){
        TYP *i = t->head;
        while(i != NULL){
            if(i->id == id){
			return i->name;
            }
            i = i->next;
        }
        return -1;
    }
// TODO(19) Programar getNumItems, recibe id:int
// TODO(20) Programar getTam, recibe id:int
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
// TODO(21) Programar getTipoBase, recibe id:int
    TYPTAB getTipoBase(TYPTAB *t, int id){
	TYP *i = t->head;
	while(i != NULL){
		if(i->id == id){
			return i->tb;
		}
		i = i->next;
        }

    } 
// TODO(22) Programar getBase, recibe id:int
    int getBase(SYMTAB *st, char *id){
    int i;
    for(i =0; i< st->num; i++){
        if(strcmp(st->syms[i].id, id) == 0)
            return st->syms[i].base;
    }
    return -1;
    }

// TODO(23) Programar setBase, recibe id:int y t:*Tabl
    void setBase( char *id, SYMTAB *st){
    int i;
    for(i =0; i< st->num; i++){
        if(strcmp(st->syms[i].id, id) == 0)
            st->syms[i].base = id;
    }
    return -1;
    }

// TODO(24) Programar getTypes, retorna un apuntador a la tabla de tipos
    TYPTAB getTypes(){
	return TYPTAB *t;

    }

// TODO(25) Programar getSyms, retorna un pauntador a la tabla de súmb  
    SYMTAB getSyms(){
	return SYMTAB *t;

    }

