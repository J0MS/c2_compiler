%skeleton "lalr1.cc"
%require  "3.0"
%debug 
%defines 
%define api.namespace {C0}
%define parser_class_name {Parser}

%code requires{

// TODO(60) Incluir a Numero.h
// TODO(61) Incluir a Expresion.h
namespace C0 {
    class Driver;
    class Scanner;      
}

// The following definitions is missing when %locations isn't used
# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif
}

%parse-param { Scanner  &scanner  }
%parse-param { Driver  &driver  }

%code{
#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;

#include "Driver.hpp"
// TODO(62) Definir una variable externa numType: int

#undef yylex
#define yylex scanner.yylex
}

%define api.value.type variant
%define parse.assert

%token <std::string>    ID
%token <std::string>    NUMERO
%token <std::string>    STRING
%token                  IF WHILE PRINT BREAK FUNC
%token                  INT VOID RETURN STRUCT
%token                  LKEY RKEY PYC COMA

%left                   ASIG /*=*/
%left                   OR /*||*/
%left                   AND /*&&*/
%left                   EQUAL DISTINCT /*== !=*/
%left                   LT GT  LTE GTE /* < >*/
%left                   MAS MENOS /* + -*/
%left                   MUL DIV MOD/* * / */
%left                   LCOR RCOR
%left                   NOT 
%left                   DOT
%nonassoc               LPAR RPAR /* ( ) */
%nonassoc               IFX
%nonassoc               ELSE

%locations
%start program
%type<int> type base arreglo
//TODO (79) definir el no terminal list_args y args como vector<int>* --- Definido




//TODO (89) definir el no terminal list_param y params como vector<int>* ----Definido
//TODO(95) definir el no terminarl param como int
%%
program 
    :
    {
        driver.init();
    }
    declarations    
    functions      
    ;

declarations
    : 
    declarations declaration
    | 
    %empty
    ;

declaration
    : 
    decl_var
    | 
    decl_struct        
    ;
    
decl_var
    : 
    type  
    {
        driver.type = $1;
    }  
    list_var PYC
    ;

list_var
    : 
    list_var COMA var
    | 
    var
    ;

var
    :
    ID 
    {
        driver.variable($1);
    }
    ;

tipo
    : 
    base  comp_arr
    |
    struct id
    ;

comp_arr:
    LCOR NUMERO RCOR comp_arr
    |
    %empty
    ;
    
base
    :
    VOID
    |
    CHAR
    |
    INT
    |
    FLOAT
    |
    DOUBLE
    ;
    
decl_struct
    :
    STRUCT LKEY body_struct RKEY list_var PYC
    ;
    
decl_struct
    :
    STRUCT ID LKEY body_struct RKEY list_var PYC
    ;
    

body_struct:
    body_struct decl_local
    |
    decl_local
    ;
    
decl_fun:
    ID LCOR list_params RCOR LKEY decl_locales bloqueSentencias RKEY
    ;
    
list_params:
    params
    |
    %empty
    ;

params:
    param COMA param
    |
    param
    ;

param:
    type_param ID
    ;
    
type_param:
    base parte_array
    |
    base
    |
    struct id
    ;
    
parte_array:
    parte_array LCOR numero RCOR
    |
    LCOR RCOR
    ;
    
decl_locales:
    decl_locales decl_local
    |
    %empty
    ;
    
decl_local:
    decl_var
    |
    decl_struct
    ;
    
decl_var:
    tipo list_var;

bloqueSentencias:
    sentencias
    |
    %empty
    ;
    
sentencias:
    sentencias sentencia
    |
    sentencia
    ;
    

    
arreglo
    : LCOR NUMERO RCOR  arreglo
    {
                $$ = $4;
					if($2.tipo == 0){
						if($2.numeroCaracter != ""){
							
							TYP *tipo4 = init_type();
							tipo4->id = posicionTablaTipo + 1;
							strcpy(tipo4->nombre, "array");
							tipo4->tam =  valorArreglo * atoi($2.numeroCaracter);
							tipo4->tb.is_est = 0;
							tipo4->tb.tipo.tipo = posicionTablaTipo;
							valorArreglo = tipo4->tam;
							posicionTablaTipo = tipo4->id;

							append_type(generalTipos, tipo4);

							pop_tst(stackTipos);
							
							push_tst(stackTipos, generalTipos);


						}else{
							yyerror("El numero del arreglo no es compatible");
						}
						

					}else{
						yyerror("El numero del arreglo no es compatible");
					}
					
    } 
    | 
    %empty
    {
        // TODO(65) Agregar las acciones semánticas para convertir gBase en el tipo de arreglo
    }

    ;

decl_struct
    : 
    STRUCT LKEY{
        // TODO(66) Agregar las acciones semánticas para push en tstack
    } body_struct RKEY
    {
        // TODO(67) Agregar las acciones semánticas para recuperar la tabla de la cima
        // TODO(68) Agregar un tipo nuevo a la tabla de tipos de tipo struct
        // TODO(71) Hacer gType igual a lo que regres la tabla de tipos al insertar el struct
    } list_var PYC
    ;

body_struct
    : 
    body_struct def_mem
    | 
    def_mem
    ;

def_mem
    : 
    base ID PYC{
        // TODO(72) Comprobar que el id no se ha declarado
        // TODO(73) En caso de que no exista agregarlo a la tabla de símbolos
    }
    ;

functions
    :
    functions function
    | 
    function
    ;

function
    : 
    FUNC base ID LPAR
    {
        // TODO(74) Hacer un push a tstack    
    }
    list_args RPAR LKEY local_decls bloqueSentencias RKEY
    {
        // TODO(75) Hacer pop a tskack
        // TODO(76) Validar que el id no está en la tabla de símbolos
        // TODO](77) En caso de no estar agregarlo
        // TODO(78) Agregar que es tipo func, su tipo de retorno, y su lista de paramétros
        // Almacenada en list_args
        if(!getID(&generalSimbolos, $3)){
					SYM s;
		            strcpy(s.id, $3);
			        s.tipo = tipoGBL;
			        s.dir = dirGBL;
			        strcpy(s.var, "def");
			        s.numArgumentos = $5.num;
			        dirGBL = dirGBL + s.dir;
			        insertar(&generalSimbolos, s);
        }else{
					yyerror("El id de la funcion ya existe");
        }
    }
    ;

list_args
    : args
    {
        // TOTOD(80) Hacer que list_args.lista =  args.lista
        strcpy($$.lista, $1.lista);
        $$.num = $1.num + 1;
    }
    | 
    %empty
    {
        // TODO(81) Hacer list_args.lista = nullptr
        char nuevo[1000];
        strcpy($$.lista, nuevo);
        $$.num = $1;
    }
    ;

args
    : 
    args COMA arg
    {
        // TODO(82) Agregar arg.type a args1.lista
        // TODO(83) Hacer args.lista = args1.lista
    $$ = $1;
    if(!getID(&generalSimbolos, $2)){
			SYM s;
            strcpy(s.id, $2);
	        s.tipo = $1;
	        s.dir = dirGBL;
	        strcpy(s.id, "arg");
	        s.numArgumentos = 0;
	        dirGBL = dirGBL + s.dir;
	        insertar(&generalSimbolos, s);
    }else{
			yyerror("El id ya existe");
		}
    | 
    arg
    {
        // TODO(84) Agregar arg.type a args.lista
    }
    }
    ;

arg
    : 
    base ID {
                {
                    $$ = $1;
                        if(!getID(&generalSimbolos, $2)){
                            SYM s;
                            strcpy(s.id, $2);
                            s.tipo = $1;
                            s.dir = dirGBL;
                            strcpy(s.id, "arg");
                            s.numArgumentos = 0;
                            dirGBL = dirGBL + s.dir;
                            insertar(&generalSimbolos, s);
			
                        }else{
                            yyerror("El id ya fue declarado en la tabla de simbolos");
                        }
            };
        }
    ;

local_decls
    : 
    local_decls local_decl
    | 
    %empty
    ;

local_decl
    : 
    base local_list PYC    
    ;

local_list
    : 
    local_list  COMA local
    { 
        //TODO(87) Similar a list_var
    }
    | 
    local
    ;

local
    : 
    ID
    {
        //TODO(88) Similar a var
    }
    ;

bloqueSentencias
    : 
    sentencias
    | 
    %empty
    ;

sentencias
    :
    sentencias sentencia     
    | 
    sentencia
    ;

sentencia
    : 
    sentIf
    | 
    sentWhile
    | 
    sentAsig
    | 
    sentPutw
    | 
    sentPuts
    | 
    sentBreak
    | 
    sentProc
    | 
    sentReturn
    ;

sentReturn
    : RETURN expresion PYC
    ;

sentProc
    : 
    ID LPAR list_params RPAR PYC
    ;
    
list_args
    :
    args
    |
    %empty
    ;

args:
    args COMA arg
    |
    arg
    |
    expresion
    ;
    

list_params
    : 
    params{
            strcpy($$.lista, "");
            sprintf($$.lista, "%d", $3.tipo);
            $$.num = $1.num + 1;
    }
    | 
    %empty{
            strcpy($$.lista, "");
            sprintf($$.lista, "%d", $1.tipo);
            $$.num = 1;
    }
    ;

params
    : 
    params COMA param
    {
        // TODO(92) Similar a args-> args, arg
        strcpy($$.lista,$1.lista);
        $$.num = $1.num;
    }
    | 
    param
    {
        // TODO(93) Similar a args-> arg
        strcpy($$.lista, "NULO");
        $$.num = 0;
    }
    ;

param
    : expresion
    {
        // TODO(94) param.type = expresion.type
    }
    ;

expresion
    : 
    expresion MAS expresion 
    | 
    expresion MENOS expresion
    | 
    expresion MUL expresion
    | 
    expresion DIV expresion
    | 
    expresion MOD expresion
    | 
    LPAR expresion RPAR
    | 
    NUMERO
    |
    CARACTER
    |  
    ID complemento
    ;

complemento
    : 
    comp_struct
    |
    array
    |
    LPAR list_params RPAR PYC
    |
    %empty
    ;

array
    : 
    array LCOR expresion RCOR 
    | 
    LCOR expresion RCOR 
    ;
/* S-> S...S | ... | S...S| otro */
condicion     
    : 
    condicion OR condicion
    | 
    condicion AND condicion
    | 
    expresion EQUAL expresion
    | 
    expresion DISTINCT expresion
    | 
    expresion GT expresion
    | 
    expresion LT expresion
    | 
    expresion GTE expresion
    | 
    expresion LTE expresion
    | 
    NOT condicion
    | 
    LPAR condicion RPAR
    ;

sentIf
    : IF LPAR
    condicion    
    RPAR bloqueOSentencia
    sentElse    
    ;

sentElse
    : 
    ELSE bloqueOSentencia
    | 
    %empty %prec IFX
    ;

bloqueOSentencia
    : 
    LKEY bloqueSentencias RKEY
    | 
    sentencia
    ;

sentWhile
    : 
    WHILE LPAR
    condicion
    RPAR 
    bloqueOSentencia    
    ;

sentSwitch
    :
    SWITCH LPAR expresion RPAR LCOR body_switch RCOR
    ;

body_switch:
    caso body_switch
    |
    predeterminado
    |
    %empty
    ;
    
caso:
    case expresion : sentencias
    ;
    
predeterminado:
    default :sentencias
    ;
    
sentFor:
    FOR LPAR sentAsig PYC CONDICION PYC sentAsig RPAR bloqueOSentencia
    ;
    
 
sentAsig
    : 
    left_part ASIG expresion PYC
    ;

left_part
    : 
    ID
    | 
    ID array
    | 
    ID DOT ID
    ;

comp_struct
    :
    comp_struct . ID
    |
    %empty
    ;
    
    
sentPutw
    :
    PRINT LPAR expresion
    RPAR PYC
    ;

sentPuts
    : 
    PRINT LPAR STRING
    RPAR PYC
    ;

sentBreak
    : BREAK    
    PYC
    ;

bloqueOSentencia:
    LCOR bloqueSentencias RCOR
    |
    sentencia
    ;
    
lista_arg : lista_arg COMA arg 
			{
			strcpy($$.lista, $1.lista);
			$$.num = $1.num + 1;
			}
			| arg
			{
				char nuevo[1000];
				strcpy($$.lista, nuevo);
				$$.num = $1;
			};

arg : tipo_arg ID
	{
		$$ = $1;
		if(!getID(&generalSimbolos, $2)){
			SYM s;
            strcpy(s.id, $2);
	        s.tipo = $1;
	        s.dir = dirGBL;
	        strcpy(s.id, "arg");
	        s.numArgumentos = 0;
	        dirGBL = dirGBL + s.dir;
	        insertar(&generalSimbolos, s);

			
		}else{
			yyerror("El id ya fue declarado");
		}
	};

tipo_arg : base param_arr
		{	
			$$ = $2;
			baseGBL = $1;

		};    
		

arreglo: LCOR expresion RCOR 
		{
			strcpy($$.dir,$2.numeroCaracter);
			$$.tipo = $2.tipo;
		}
		| arreglo LCOR expresion RCOR
		{
			strcpy($$.dir,$3.numeroCaracter);
			$$.tipo = tipoGBL;
		};

parametros : lista_param 
			{
				strcpy($$.lista,$1.lista);
				$$.num = $1.num;
			}
			| 
			{
				strcpy($$.lista, "NULO");
				$$.num = 0;
			};


lista_param : lista_param COMA expresion
			{
				strcpy($$.lista, "");
				sprintf($$.lista, "%d", $3.tipo);
				$$.num = $1.num + 1;
			} 
			| expresion
			{
				strcpy($$.lista, "");
				sprintf($$.lista, "%d", $1.tipo);
				$$.num = 1;
			};
    
    
%%

void C0::Parser::error( const location_type &l, const std::string &err_message )
{
    cerr << "Error: " << err_message << " at " << l << endl;
}
