/*	Definition section */
%{
#include <stdio.h>
#include <string.h>
extern int yylineno;
extern int yylex();
extern char* yytext;   // Get current token from lex
extern char buf[256];  // Get current code line from lex

/* Symbol table function - you can add new function if needed. */
void set_type(int);
void set_parameter();
int lookup_symbol(char*);
void create_symbol();
void insert_symbol(char*,int,int);
void dump_symbol();


// for kind
#define VAR 1
#define FUNC 2
#define PARAM 3 

// for type
#define T_INT 1
#define T_FLOAT 2
#define T_BOOL 3
#define T_STRING 4
#define T_VOID 5



typedef struct symbol_table{
    //from 0~
    int index;
    char* name;
    // 1:variable 2:function 3:parameter
    char *kind;
    // 1:int 2:float 3:bool 4:string 5:void
    char *type;
    // from 0~
    int scope;
    // 1:int 2:float 3:bool 4:string 5:void
    char *attribute;
    struct symbol_table* next;
    struct symbol_table* prev;
}symbol_table;

int scope_num = 0;
int index_num = 0;
int decl_count = 0;
int dump_flag = -1;
int param_num = 0;
char error_buf[128];
char param_array[512];
symbol_table *head;
symbol_table *tail;
symbol_table *record;
void yyerror(char*);
void print_error(char*,char*);
void print_test();
void clear_symbol(int);
void need_dump(int);

%}

/* Use variable or self-defined structure to represent
 * nonterminal and token type
 */
%union {
    int i_val;
    double f_val;
    char* string;
}

/* Token without return */
// %token PRINT 
// %token IF ELSE FOR
// %token ID SEMICOLON

    /* Arithmetic */
%token ADD SUB MUL DIV MOD INC DEC
    /* Relational */
%token MT LT MTE LTE EQ NE
    /* Assignment */
%token ASGN ADDASGN SUBASGN MULASGN DIVASGN MODASGN
    /* Logical */
%token AND OR NOT
    /* Delimiters */    
%token LB RB LCB RCB LSB RSB COMMA SEMICOLON
    /* Print Keywords */
%token PRINT 
    /* Condition and Loop Keywords */
%token IF ELSE FOR WHILE
    /* Declaration Keywords */
%token VOID INT FLOAT STRING BOOL
    /* boolean Keywords */
%token TRUE FALSE
    /* other Keywords */
%token RETURN
%token ENDFILE

/* Token with return, which need to sepcify type */
// %token <i_val> I_CONST
// %token <f_val> F_CONST
// %token <string> STRING
%token <i_val> I_CONST
%token <f_val> F_CONST
%token <string> STRING_TEXT
%token <string> ID
/* Nonterminal with return, which need to sepcify type */
%type <i_val> type
// %type <f_val> stat

/* Yacc will start at this nonterminal */
%start program

/* Grammar section */
%%

program
    : program stats
    | stats
;

stats
    : stat
    | func_declaration

;

stats_in_func
    : stats_in_func stat
    | stat
;
stat
    : declaration_stat
    | compound_stat
    | expression_stat
    | print_func
;

declaration_stat
    : type declaration { set_type($1);}
;
declaration
    : ID ASGN initializer SEMICOLON{
        if(lookup_symbol($1)!=0){
            insert_symbol($1,1,-1);
            decl_count++;
        }
        else
            print_error("Redeclared variable ",$1);
    }
    | ID SEMICOLON{
        if(lookup_symbol($1)!=0){
            insert_symbol($1,1,-1);
            decl_count++;
        }
        else
            print_error("Redeclared variable ",$1);
    }
    | ID ASGN initializer COMMA declaration{
        if(lookup_symbol($1)!=0){
            insert_symbol($1,1,-1);
            decl_count++;
        }
        else
            print_error("Redeclared variable ",$1);
    }


type
	: INT       {$$ = 1;}
    | FLOAT     {$$ = 2;}
    | BOOL      {$$ = 3;}
    | STRING    {$$ = 4;}
    | VOID      {$$ = 5;} 
;
compound_stat
    :if_else_stat
    | while_stat
;
while_stat
    : while_stat_part1 while_stat_part2 {
        need_dump(scope_num);
        scope_num--;
    }
;
while_stat_part1
    : WHILE LB logic_stats RB {++scope_num;}
;
while_stat_part2
    : stats
    | LCB  stats_in_func RCB
    | SEMICOLON

if_else_stat
    : if_stat else_if_stat else_stat
    | if_stat else_stat
    | if_stat
;
if_stat
    : if_part1 if_part2 {
        need_dump(scope_num);
        scope_num--;
    }
;
if_part1
    : IF LB logic_stats RB {++scope_num;}
;
if_part2
    : stat
    | LCB stats_in_func RCB
    | LCB RCB
    | SEMICOLON
;
else_if_stat
    : else_if_part1 else_if_part2 {
        need_dump(scope_num);
        scope_num--;
    }

else_if_part1
    : ELSE IF LB logic_stats RB {++scope_num;}


else_if_part2
    : stat
    | LCB stats_in_func RCB
    | LCB RCB
    | SEMICOLON
else_stat
    : else_part1 else_part2{
        need_dump(scope_num);        
        scope_num--;
    }
;

else_part1
    : ELSE{++scope_num;}
;
else_part2
    : stat
    | LCB stats_in_func RCB
    | SEMICOLON
;
expression_stat
    : assign_stat SEMICOLON
    | func_call SEMICOLON;
    | RETURN p3_arithmetic_stat SEMICOLON
    | RETURN SEMICOLON
;

assign_stat
    : ID ASGN p3_arithmetic_stat{
        if(lookup_symbol($1)==(-1)){
            print_error("Undeclared variable ",$1);
        }
    }
    | ID ADDASGN p3_arithmetic_stat{
        if(lookup_symbol($1)==(-1)){
            print_error("Undeclared variable ",$1);
        }
    }
    | ID SUBASGN p3_arithmetic_stat{
        if(lookup_symbol($1)==(-1)){
            print_error("Undeclared variable ",$1);
        }
    }
    | ID MULASGN p3_arithmetic_stat{
        if(lookup_symbol($1)==(-1)){
            print_error("Undeclared variable ",$1);
        }
    }
    | ID DIVASGN p3_arithmetic_stat{
        if(lookup_symbol($1)==(-1)){
            print_error("Undeclared variable ",$1);
        }
    }
    | ID MODASGN p3_arithmetic_stat{
        if(lookup_symbol($1)==(-1)){
            print_error("Undeclared variable ",$1);
        }
    }
    | p3_arithmetic_stat
    | assign_stat COMMA assign_stat
;
func_call
    : ID LB func_call_param RB {
        if(lookup_symbol($1)==-1){
            print_error("Undeclared function ",$1);
        }
    }
;
func_call_param
    : func_call_param COMMA p3_arithmetic_stat
    | p3_arithmetic_stat
    | logic_stats

print_func
    : PRINT LB print_content RB SEMICOLON
;
initializer
    : p3_arithmetic_stat
;

p3_arithmetic_stat
    : p2_arithmetic_stat ADD p3_arithmetic_stat
    | p2_arithmetic_stat SUB p3_arithmetic_stat
    | p2_arithmetic_stat
    | LB p3_arithmetic_stat RB
;

p2_arithmetic_stat
    : p1_arithmetic_stat MUL p2_arithmetic_stat
    | p1_arithmetic_stat DIV p2_arithmetic_stat
    | p1_arithmetic_stat MOD p2_arithmetic_stat
    | p1_arithmetic_stat
    | LB p2_arithmetic_stat RB
;

p1_arithmetic_stat
    : INC p1_arithmetic_stat
    | DEC p1_arithmetic_stat
    | p1_arithmetic_stat INC
    | p1_arithmetic_stat DEC
    | value_stat
    | LB p1_arithmetic_stat RB
;


value_stat
    : ADD value_stat
    | SUB value_stat
    | STRING_TEXT
    | value
    | LB value_stat RB
value
    :I_CONST
    |F_CONST
    |TRUE
    |FALSE
    |ID {
        if(lookup_symbol($1)==-1){
            print_error("Undeclared Variable ",$1);
        }
    }
;

func_declaration
    :fucn_part1 func_part2{
        need_dump(scope_num);
        if(param_num>0){
            set_parameter();
        }
        scope_num--;
    }
;

fucn_part1
    : type ID LB {
        if(lookup_symbol($2) == -1){
            insert_symbol($2, 2, $1);
        }
        else print_error("Redeclared function ", $2);
        ++scope_num;
    }
;
func_part2
    : RB SEMICOLON
    | RB LCB stats_in_func RCB
    | RB LCB RCB
    | param RB SEMICOLON
    | param RB LCB stats_in_func RCB
    | param RB LCB RCB
    

param
    : type ID{
        if(lookup_symbol($2) != 0){
            insert_symbol($2, 3, $1);
            param_array[param_num] = $1;
            ++param_num;
        }
        else    print_error("Redeclared variable ", $2);

    }
    | param COMMA type ID{
        if(lookup_symbol($4) != 0){
            insert_symbol($4, 3, $3);
            param_array[param_num] = $3;

            ++param_num;
        }
        else    print_error("Redeclared variable ", $4);
    }
;

print_content
    : ID{
        if(lookup_symbol($1)==(-1)){
            print_error("Undeclared variable ",$1);
        }
    }
    | STRING_TEXT
;

logic_stats
    : logic_stats logic_op logic_stats
    | logic_stat
;
logic_stat
    : value_stat MT value_stat
    | value_stat LT value_stat
    | value_stat MTE value_stat
    | value_stat LTE value_stat
    | value_stat EQ value_stat
    | value_stat NE value_stat
    | value_stat
;

logic_op
    : AND
    | OR
;

%%

/* C code section */
int main(int argc, char** argv)
{
    yylineno = 0;
    create_symbol();

    yyparse();
    dump_symbol(scope_num);
	printf("\nTotal lines: %d \n",yylineno);

    return 0;
}

void yyerror(char *s)
{
    // if(had_print_flag == 0){
    //     if(buf[0] == '\n')
    //         printf("%d:%s", yylineno, buf);
    //     else
    //         printf("%d: %s\n", yylineno+1, buf);
    //     had_print_flag = 1;
    // }
    // if(strstr(s, "syntax") != NULL) syntax_error_flag = 1;
    printf("\n|-----------------------------------------------|\n");
    printf("| Error found in line %d: %s\n", yylineno+1, buf);
    printf("| %s", s);
    printf("\n|-----------------------------------------------|\n\n");
}

void create_symbol() {
    head = (symbol_table*)malloc(sizeof(symbol_table));
    head->index = -1;
    head->name = NULL;
    head->kind = NULL;
    head->type = NULL;
    head->scope = -1;
    head->attribute = NULL;
    head->next = NULL;
    head->prev = head;
    tail = head;
}
void insert_symbol(char *name,int kind,int type) {
    symbol_table *temp = tail;
    if(temp == head){
        temp->next = (symbol_table*)malloc(sizeof(symbol_table));
        temp->next->prev = temp;
        temp = temp->next;
        temp->next = NULL;
        head-> next = temp;
        tail = temp;
    }
    else{
        temp->next = (symbol_table*)malloc(sizeof(symbol_table));
        temp->next->prev = temp;
        temp = temp->next;
        temp->next = NULL;
        tail = temp;
    }

    
    temp->index = index_num;
    temp->name = (char*)malloc(sizeof(char)*strlen(name)+1);
    strncpy(temp->name, name, strlen(name));

    temp->scope = scope_num;
    switch(kind){
        case 1:
            temp->kind = (char*)malloc(sizeof(char)*strlen("variable"));
            strcpy(temp->kind,"variable");
            break;
        case 2:
            temp->kind = (char*)malloc(sizeof(char)*strlen("function"));
            strcpy(temp->kind,"function");
            break;
        case 3:
            temp->kind = (char*)malloc(sizeof(char)*strlen("parameter"));
            strcpy(temp->kind,"parameter");
            break;
        case -1:
            temp->type = (char*)malloc(sizeof(char)*strlen("default"));
            strcpy(temp->type,"default");
            break;
    }

    switch(type){
        case 1:
            temp->type = (char*)malloc(sizeof(char)*strlen("int"));
            strcpy(temp->type,"int");
            break;
        case 2:
            temp->type = (char*)malloc(sizeof(char)*strlen("float"));
            strcpy(temp->type,"float");
            break;
        case 3:
            temp->type = (char*)malloc(sizeof(char)*strlen("bool"));
            strcpy(temp->type,"bool");
            break;
        case 4:
            temp->type = (char*)malloc(sizeof(char)*strlen("string"));
            strcpy(temp->type,"string");
            break;
        case 5:
            temp->type = (char*)malloc(sizeof(char)*strlen("void"));
            strcpy(temp->type,"void");
            break;
        case -1:
            temp->type = (char*)malloc(sizeof(char)*strlen("default"));
            strcpy(temp->type,"default");
            break;
    }
    index_num ++;
}
int lookup_symbol(char *name) {
    symbol_table *temp = head;
    while(temp->next!=NULL){
        temp = temp-> next;
        if(strcmp(temp->name,name)==0 && temp->scope == scope_num) 
            return 0;
        if(strcmp(temp->name, name) == 0 && temp->scope < scope_num)
            return 1;

    }
    return -1;
}
void dump_symbol(int dump_scope_num) {

    int table_has_element_flag = 0;
    symbol_table* element = head;
    while(element->next != NULL){
        element = element->next;
        if(element->scope == dump_scope_num)
            table_has_element_flag = 1;
    }
    if(table_has_element_flag == 0) return;

    //printf("dump_symbol: %d\n", dump_scope_num);
    int index_count = 0;

    symbol_table* temp = head;
    printf("\n%-10s%-10s%-12s%-10s%-10s%-10s\n\n",
    "Index", "Name", "Kind", "Type", "Scope", "Attribute ");
    while(temp->next != NULL)
    {

        temp = temp->next;
        if(temp->scope == dump_scope_num){

		        printf("%-10d%-10s%-12s%-10s%-10d",
			    index_count, temp->name, temp->kind, temp->type, temp->scope);
                if(temp->attribute!=NULL){
                    printf("%-10s",temp-> attribute);
                }     
                    index_count++;
                    printf("\n");

        }

    }
        printf("\n");

    clear_symbol(dump_scope_num);
}
void print_test() {
	symbol_table* test = head->next;
    printf("\n%-10s%-10s%-12s%-10s%-10s%-10s\n\n",
       "Index", "Name", "Kind", "Type", "Scope", "Attribute");
	while(test != NULL) {
		printf("%-10d%-10s%-12s%-10s%-10d\n",
			test->index, test->name, test->kind, test->type, test->scope);
        if(test->attribute!=NULL){
            printf("%-10s",test-> attribute);
        }    
		test = test->next;
	}
}

void set_type(int type){
    symbol_table *temp = tail;


    for(int i = 0; i < decl_count;i++){
    switch(type){
        case 1:
            temp->type = (char*)malloc(sizeof(char)*strlen("int"));
            strcpy(temp->type,"int");
            break;
        case 2:
            temp->type = (char*)malloc(sizeof(char)*strlen("float"));
            strcpy(temp->type,"float");
            break;
        case 3:
            temp->type = (char*)malloc(sizeof(char)*strlen("bool"));
            strcpy(temp->type,"bool");
            break;
        case 4:
            temp->type = (char*)malloc(sizeof(char)*strlen("string"));
            strcpy(temp->type,"string");
            break;
        case 5:
            temp->type = (char*)malloc(sizeof(char)*strlen("void"));
            strcpy(temp->type,"void");
            break;
        case -1:
            temp->type = (char*)malloc(sizeof(char)*strlen("default"));
            strcpy(temp->type,"default");
            break;
    }
        temp = temp->prev;
    }
    decl_count = 0;
}

void clear_symbol(int scope_num){
    if(scope_num != 0){
        symbol_table* temp = head;

        while(temp->next != NULL){
            temp = temp -> next;
            if(temp->scope == scope_num){
                if(temp->next != NULL){
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;
                }
                else temp->prev->next = NULL;
                symbol_table* deletenode = temp;
                temp = temp -> prev;
                tail = temp;
                free(deletenode);
            }
        }

    }
}

void need_dump(int scope_num){
    dump_flag = scope_num;
}

void set_parameter(){
    symbol_table *temp = tail;
    while(strcmp(temp->kind,"function")!=0){
        temp = temp->prev;
    }

        for(int i = 0;i<param_num;i++){
            switch(param_array[i]){
                case 1:
                    if(temp->attribute==NULL)
                    {
                        temp->attribute = (char*)malloc(sizeof(char)*512);
                        strcpy(temp->attribute,"int");
                    }

                    else
                        strcat(temp->attribute,", int");
                 break;
                case 2:
                    if(temp->attribute==NULL)
                    {
                        temp->attribute = (char*)malloc(sizeof(char)*512);
                        strcpy(temp->attribute,"float");
                    }

                    else
                        strcat(temp->attribute,", int");                        
                    break;
                case 3:
                    if(temp->attribute==NULL)
                    {
                        temp->attribute = (char*)malloc(sizeof(char)*512);
                        strcpy(temp->attribute,"bool");
                    }

                    else
                        strcat(temp->attribute,", int");
                    break;
                case 4:
                    if(temp->attribute==NULL){

                        temp->attribute = (char*)malloc(sizeof(char)*512);
                        strcpy(temp->attribute,"string");
                    }

                    else
                        strcat(temp->attribute,", int");
                    break;
                case 5:
                    if(temp->attribute==NULL){
                        temp->attribute = (char*)malloc(sizeof(char)*512);
                        strcpy(temp->attribute,"void");
                    }
                    else
                        strcat(temp->attribute,", int");
                    break;
                case -1:
                    break;
            }
    }

    param_num = 0;
    param_array[0]='\0';

}
void print_error(char* msg, char* Name){
    sprintf(error_buf, "%s%s", msg, Name);
    yyerror(error_buf);
}