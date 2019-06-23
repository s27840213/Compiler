/*	Definition section */
%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
extern int yylineno;
extern int yylex();
extern char* yytext;   // Get current token from lex
extern char buf[256];  // Get current code line from lex


FILE *file; // To generate .j file for Jasmin

/* Symbol table function - you can add new function if needed. */
void set_type(int);
void set_parameter();
int lookup_symbol(char*);
void create_symbol();
void insert_symbol(char*,int,int);
void dump_symbol();
int get_stack_num(char*);
int get_symbol_index(char*);
int get_symbol_type(char*);
float get_symbol_value(char*);
int getParam();
int getParamNum();
int check_global(char*);
void set_value(char*,float);
char* type2str(int);
/* code generation functions, just an example! */
void gencode_function();
void gencode_load();
void gencode_ADD(float left[7],float right[7]);
void gencode_SUB(float left[7],float right[7]);
void gencode_MUL(float left[7],float right[7]);
void gencode_DIV(float left[7],float right[7]);
void gencode_MOD(float left[7],float right[7]);
void gencode_INC(float var[7]);
void gencode_DEC(float var[7]);
void gencode_function_call(char*,int);
void gencode_print();
void gencode_assign();
void gencode_compare();
void gencode_store();





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
    float value;
    char *string_value;
    int param_n;
    int param_a[128];
    struct symbol_table* next;
    struct symbol_table* prev;
}symbol_table;

typedef struct id_list{
    char* id;
    struct id_list* next;
    struct id_list* prev;
}id_list;
int scope_num = 0;
int index_num = 0;
int decl_count = 0;
int dump_flag = -1;
int param_num = 0;
char error_buf[128];
char param_array[512];
char curr_func[128];
int curr_func_type=0;
int isMain = 0;
char string_buf[128];
int semantic_error_flag=0;
int syntax_error_flag=0;
int error_flag=0;
int cmp_label=0;
int while_count=0;
int ret_type=5;
int func_undecl_flag = 0;
int func_call_param_num = 0;
int if_end_num = 0;
int while_num = 0;
int while_end_num = 0;
int while_flag = 0;
symbol_table *head;
symbol_table *tail;
symbol_table *record;
symbol_table *curr;
id_list *id_head;
id_list *id_tail;
void yyerror(char*);
void print_error(char*,char*);
void print_test();
void clear_symbol(int);
void need_dump(int);
char* search_id();

%}

/* Use variable or self-defined structure to represent
 * nonterminal and token type
 */
%union {
    int i_val;
    double f_val;
    char* string;
    //0: value  1:type  2: stack num(global->index) 3:global or not
    float var_info[7]; 
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
%type <i_val> func_part1
%type <string> func_call
%type <i_val> func_call_param
%type <i_val> assign_op
%type <i_val> compare_op
%type <string> string_text
%type <var_info> param
%type <var_info> value
%type <var_info> value_stat
%type <var_info> p1_arithmetic_stat
%type <var_info> p3_arithmetic_stat
%type <var_info> p2_arithmetic_stat
%type <var_info> logic_stat
%type <var_info> initializer
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
    : type ID ASGN initializer SEMICOLON{
        if(lookup_symbol($2)!=0){
            insert_symbol($2,1,-1);
            decl_count++;
            set_type($1);
            set_value($2,$4[0]);

            // global scope
            if(scope_num == 0){
                gencode_function(".field public static ");
                gencode_function($2);
                gencode_function(" ");
                char tempbuf[64];
                switch($1){
                    case 1:
                        gencode_function("I = ");
                        sprintf(tempbuf, "%d", (int)$4[0]);
                        gencode_function(tempbuf);
                        gencode_function("\n");
                        break;
                    case 2:
                        gencode_function("F = ");
                        sprintf(tempbuf, "%f", (float)$4[0]);
                        gencode_function(tempbuf);
                        gencode_function("\n");
                        break;
                    case 3:
                        gencode_function("Z = ");
                        gencode_function("\n");
                        break;
                    case 4:
                        gencode_function("Ljava/lang/String; = \"");
                        gencode_function(yylval.string);
                        gencode_function("\"\n");
                        break;
                    case 5:                        
                        gencode_function("V = ");
                        sprintf(tempbuf, "%f", (float)$4[0]);
                        gencode_function(tempbuf);
                        gencode_function("\n");
                        break;
                }
            }
            else if(scope_num>0){
                char tempbuf[64];
                switch($1){
                    case 1:
                            gencode_assign($2,1,$4);

                        break;
                    case 2:
                        gencode_assign($2,1,$4);

                        break;
                    case 3:
                        gencode_assign($2,1,$4);
                        break;
                    case 4:
                        gencode_assign($2,1,$4);
                        break;
                    case 5:
                        gencode_assign($2,1,$4);
                        break;

                }
            }
        }
        else
            print_error("Redeclared variable ",$2);
    }
    | type ID SEMICOLON{
        if(lookup_symbol($2)!=0){
            insert_symbol($2,1,-1);
            decl_count++;
            set_type($1);
            set_value($2,0);
            if(scope_num == 0){
                gencode_function(".field public static ");
                gencode_function($2);
                gencode_function(" ");
                char tempbuf[64];
                switch($1){
                    case 1:
                        gencode_function("I\n");
                        break;
                    case 2:
                        gencode_function("F\n");
                        break;
                    case 3:
                        gencode_function("Z\n");
                        break;
                    case 4:
                        gencode_function("Ljava/lang/String;\n");
                        break;
                    case 5:
                        gencode_function("V\n");
                        break;
                }
            }
            if(scope_num > 0){

                char tempbuf[64];
                switch($1){
                    case 1:
                        
                        gencode_function("\tldc 0\n");
                        gencode_function("\tistore ");
                        sprintf(tempbuf,"%d\n",get_stack_num($2));
                        gencode_function(tempbuf);
                        break;
                    case 2:
                        gencode_function("\tldc 0\n");
                        gencode_function("i2f\n");
                        gencode_function("\tfstore ");
                        sprintf(tempbuf,"%d\n",get_stack_num($2));
                        gencode_function(tempbuf);
                        break;
                    case 3:
                        gencode_function("\tldc 0\n");
                        gencode_function("\tistore ");
                        sprintf(tempbuf, "%d\n", get_stack_num($2));
                        gencode_function("\n");
                        break;
                    case 4:
                        gencode_function("\tldc ""\n");
                        gencode_function("\tastore ");
                        sprintf(tempbuf, "%d\n", get_stack_num($2));
                        gencode_function(tempbuf);
                        break;
                    case 5:
                        gencode_function("\tldc 0\n");
                        gencode_function("\tistore ");
                        sprintf(tempbuf, "%d\n", get_stack_num($2));
                        break;
                }
            }
        }
        else
            print_error("Redeclared variable ",$2);
    }
;

initializer
    : p3_arithmetic_stat{
        $$[0] = $1[0];  $$[1] = $1[1];
        $$[2] = $1[2];  $$[3] = $1[3];
    }
;

p3_arithmetic_stat
    : p3_arithmetic_stat ADD p2_arithmetic_stat{
        $$[0] = $1[0] + $3[0]; $$[1] = ($1[1]==2 || $3[1]==2)? 2:1; 
        $$[2] = -1; $$[3] = -1;
        gencode_ADD($1,$3);
        gencode_store($1,$3);
    }
    | p3_arithmetic_stat SUB p2_arithmetic_stat{


        $$[0] = $1[0] - $3[0]; $$[1] = ($1[1]==2 || $3[1]==2)? 2:1; 
        $$[2] = -1; $$[3] = -1;
        gencode_SUB($1,$3);
        gencode_store($1,$3);
    }
    | p2_arithmetic_stat {
        
        $$[0] = $1[0];
        $$[1] = $1[1];
        $$[2] = $1[2];
        $$[3] = $1[3];
    }
    | LB p3_arithmetic_stat RB{
        $$[0] = $2[0];
        $$[1] = $2[1];
        $$[2] = $2[2];
        $$[3] = $2[3];
    }

;

p2_arithmetic_stat
    : p2_arithmetic_stat MUL p1_arithmetic_stat{
        gencode_MUL($1,$3);
        gencode_store($1,$3);
        $$[0] = $1[0] * $3[0]; $$[1] = ($1[1]==2 || $3[1]==2)? 2:1; 
        $$[2] = -1; $$[3] = -1;
    }
    | p2_arithmetic_stat DIV p1_arithmetic_stat{
        if($3[0] == 0) {
            yyerror("Divided by Zero");
            $$[0] = 0;
        }
        else{
            $$[0] = $1[0] / $3[0]; 
        }
        $$[1] = ($1[1]==2 || $3[1]==2)? 2:1;
        $$[2] = -1; $$[3] = -1;
        gencode_DIV($1,$3);


    }
    | p2_arithmetic_stat MOD p1_arithmetic_stat{
        gencode_MOD($1,$3);

        $$[0] = $1[0];
        $$[1] = $1[1];
        $$[2] = $1[2];
        $$[3] = $1[3];
    }
    | p1_arithmetic_stat {
        $$[0] = $1[0];
        $$[1] = $1[1];
        $$[2] = $1[2];
        $$[3] = $1[3];
    }
    | LB p2_arithmetic_stat RB{
        $$[0] = $2[0];
        $$[1] = $2[1];
        $$[2] = $2[2];
        $$[3] = $2[3];
    }
;

p1_arithmetic_stat
    : INC p1_arithmetic_stat{
        $$[0] = $2[0] + 1;  $$[1] = $2[1];
        $$[2] = $2[2];      $$[3] = $2[3];
        gencode_INC($2);
    }
    | DEC p1_arithmetic_stat{
        $$[0] = $2[0] - 1;  $$[1] = $2[1];
        $$[2] = $2[2];      $$[3] = $2[3];
        gencode_DEC($2);
    }
    | p1_arithmetic_stat INC{
        $$[0] = $1[0] + 1;  $$[1] = $1[1];
        $$[2] = $1[2];      $$[3] = $1[3];
        gencode_INC($1);
    }
    | p1_arithmetic_stat DEC{
        $$[0] = $1[0] - 1;  $$[1] = $1[1];
        $$[2] = $1[2];      $$[3] = $1[3];
        gencode_DEC($1);
    }
    | value_stat{
        $$[0] = $1[0];
        $$[1] = $1[1];
        $$[2] = $1[2];
        $$[3] = $1[3];
    }
    | LB p3_arithmetic_stat RB{
        $$[0] = $2[0] - 1;  $$[1] = $2[1];
        $$[2] = $2[2];      $$[3] = $2[3];
    }
;


value_stat
    : ADD value_stat {
        $$[0] = $2[0];
        $$[1] = $2[1];
        $$[2] = $2[2];
        $$[3] = $2[3];
    }
    | SUB value_stat {
        $$[0] = $2[0];
        $$[1] = $2[1];
        $$[2] = $2[2];
        $$[3] = $2[3];
    }   
    | string_text {
        $$[0] = -1;
        $$[1] = 4;

    }
    | value {
        $$[0] = $1[0];
        $$[1] = $1[1];
        $$[2] = $1[2];
        $$[3] = $1[3];
    }
    | LB value_stat RB  {
        $$[0] = $2[0];
        $$[1] = $2[1];
        $$[2] = $2[2];
        $$[3] = $2[3];
    }
;
value
    :I_CONST{
        /* 
            1 : value = $1
            2 : type = int
        */ 
        $$[0] = $1; $$[1] = 1;
        $$[2] = -1; $$[3] = 0;
        char tempbuf[64];
        if(scope_num>0){
            sprintf(tempbuf, "\tldc %d\n", yylval.i_val);
            gencode_function(tempbuf);
        }

    }
    |F_CONST{
        /* 
            1 : value = $1
            2 : type = float
        */ 
        $$[0] = $1; $$[1] = 2;
        $$[2] = -1; $$[3] = 0;
        char tempbuf[64];
        if(scope_num>0){
            sprintf(tempbuf, "\tldc %f\n", yylval.f_val);
            gencode_function(tempbuf);
        }
    }
    |TRUE{
        /* 
            1 : value = 1
            2 : type = bool
        */ 
        $$[0] = 1;  $$[1] = 3;
        $$[2] = -1; $$[3] = 0;
        char tempbuf[64];
        if(scope_num>0){
            sprintf(tempbuf, "\tldc %d\n", yylval.i_val);
            gencode_function(tempbuf);
        }
    }
    |FALSE{
        /* 
            1 : value = 0
            2 : type = bool
        */ 
        $$[0] = 0;  $$[1] = 3; 
        $$[2] = -1; $$[3] = 0;
        char tempbuf[64];
        if(scope_num>0){
            sprintf(tempbuf, "\tldc %d\n", yylval.i_val);
            gencode_function(tempbuf);
        }
    }
    |ID {
        if(lookup_symbol($1)==-1){
            print_error("Undeclared Variable ",$1);
        }
        else{
                $$[0] = get_symbol_value($1);
                $$[1] = get_symbol_type($1);
                $$[2] = get_stack_num($1);
                $$[3] = check_global($1);
                gencode_load($$,$1);
        }
    }
    |func_call {
        $$[1] = get_symbol_type($1);
    }
;

string_text
    : STRING_TEXT {
        if(scope_num>0){
            char tempbuf[64];
            sprintf(tempbuf, "\tldc \"%s\"\n", yylval.string);
            gencode_function(tempbuf);
        }

    }
    |         
        {
                
            if(scope_num>0){
                gencode_function("\tldc \"\"\n");
            }
        }
;

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
        while_end_num--;
        char tempbuf[64];
        sprintf(tempbuf,"WHILE_EXIT_%d_%d",while_end_num,scope_num+1);
        gencode_function(tempbuf);
        gencode_function(":\n");
    }
;

while_begin
    : WHILE {
        while_num++;
        char tempbuf[64];
        sprintf(tempbuf,"L_WHILE_%d_%d",while_num,scope_num);
        gencode_function(tempbuf);
        gencode_function(":\n");

    }
;

while_stat_part1
    : while_begin LB logic_stats RB {
        ++scope_num;
        char tempbuf[64];
        sprintf(tempbuf,"\tifeq WHILE_EXIT_%d_%d",while_end_num,scope_num);
        gencode_function(tempbuf);
        gencode_function("\n");
        while_end_num++;

        }
;


while_stat_part2
    : stats
    | LCB  stats_in_func RCB{
        char tempbuf[64];
        sprintf(tempbuf,"\tgoto L_WHILE_%d_%d",while_num--,(scope_num-1));
        gencode_function(tempbuf);
        gencode_function("\n");
    }
    | SEMICOLON
;


if_else_stat
    : if_stat else_if_stat else_stat{
        char tempbuf[64];
        sprintf(tempbuf,"IF_EXIT_%d",if_end_num);
        gencode_function(tempbuf);
        gencode_function(":\n");
        if_end_num++;
    }
    | if_stat else_stat{
        char tempbuf[64];
        sprintf(tempbuf,"IF_EXIT_%d",if_end_num);
        gencode_function(tempbuf);
        gencode_function(":\n");
        if_end_num++;

    }
    | if_stat{
        char tempbuf[64];
        sprintf(tempbuf,"IF_EXIT_%d",if_end_num);
        gencode_function(tempbuf);
        gencode_function(":\n");
        if_end_num++;

    }
;
if_stat
    : if_part1 if_part2 {
        need_dump(scope_num);
        scope_num--;
    }
;
if_part1
    : IF LB logic_stats RB {
        ++scope_num;
        char tempbuf[64];
        sprintf(tempbuf, "\tifeq L_FALSE_ACTION_%d\n", scope_num);
        gencode_function(tempbuf);
        }
;
if_part2
    : stat
    | LCB stats_in_func RCB{
        char tempbuf[64];
        sprintf(tempbuf, "\tgoto IF_EXIT_%d\n", if_end_num);
        gencode_function(tempbuf);
        sprintf(tempbuf,"L_FALSE_ACTION_%d",scope_num);
        gencode_function(tempbuf);
        sprintf(tempbuf,"%s",":\n");
        gencode_function(tempbuf);
    }
    | LCB RCB
    | SEMICOLON
;
else_if_stat
    : else_if_part1 else_if_part2 {
        need_dump(scope_num);
        scope_num--;

    }

else_if_part1
    : ELSE IF LB logic_stats RB {
        ++scope_num;
        char tempbuf[64];
        sprintf(tempbuf, "\tifeq L_FALSE_ACTION_%d\n", scope_num);
        gencode_function(tempbuf);
    }


else_if_part2
    : stat
    | LCB stats_in_func RCB{
        char tempbuf[64];
        sprintf(tempbuf, "\tgoto IF_EXIT_%d\n", if_end_num);
        gencode_function(tempbuf);
        sprintf(tempbuf,"L_FALSE_ACTION_%d",scope_num);
        gencode_function(tempbuf);
        sprintf(tempbuf,"%s",":\n");
        gencode_function(tempbuf);
    }
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
    | RETURN initializer SEMICOLON{
        if(ret_type == 1 && $2[1] == 1){
			gencode_function("\tireturn\n");
		}
		else if(ret_type == 1 && $2[1] == 2){

            yyerror("Return type mismatch");

		}
		else if(ret_type == 2 && $2[1] == 1){
            yyerror("Return type mismatch");
		}
		else if(ret_type == 2 && $2[1] == 2){
			gencode_function("\tfreturn\n");
		}
		else if(ret_type == 3 && $2[1] == 3){
			gencode_function("\tireturn\n");
		}
		else {
			yyerror("Return Type mismatch");
		}
	
    }
    | RETURN SEMICOLON{
        gencode_function("\treturn\n");
    }
;

assign_stat
    : ID assign_op p3_arithmetic_stat{
        if(lookup_symbol($1)==(-1)){
            print_error("Undeclared variable ",$1);
        }

        gencode_assign($1,$2,$3);
    }
    | p3_arithmetic_stat
    | assign_stat COMMA assign_stat
;

assign_op
    : ASGN {
        $$ = 1;
    }
    | ADDASGN{
        $$ = 2;
    }
    | SUBASGN{
        $$ = 3;
    }
    | MULASGN{
        $$ = 4;
    }
    | DIVASGN {
        $$ = 5;
    }
    | MODASGN{
        $$ = 6;
    }
;
func_call
    : ID LB func_call_param RB {
        if(lookup_symbol($1)==-1){
            print_error("Undeclared function ",$1);
            func_undecl_flag = 1;
        }
        gencode_function_call($1,func_call_param_num);
        func_call_param_num =0;

    }
;
func_call_param
    : func_call_param COMMA p3_arithmetic_stat{
        func_call_param_num++;
    }
    | p3_arithmetic_stat{
        func_call_param_num++;
        
    }
    | logic_stats{
        func_call_param_num++;
    }

print_func
    : PRINT LB value RB SEMICOLON{
        gencode_print($3);
    }
    | PRINT LB string_text RB SEMICOLON{
        gencode_function("\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n");
        gencode_function("\tswap\n");
        gencode_function("\tinvokevirtual java/io/PrintStream/println(Ljava/lang/String;)V\n");
    }
;

func_declaration
    :func_part1 func_part2 func_part3{
        need_dump(scope_num);

        if(param_num>0){
            set_parameter();
        }

        scope_num--;
    }
;

func_part1
    : type ID LB {
        if(lookup_symbol($2) == -1){
            insert_symbol($2, 2, $1);
            fprintf(file,".method public static %s(",$2);
            strcpy(curr_func,$2);
            curr_func_type = $1;
        }
        else print_error("Redeclared function ", $2);
        ++scope_num;
        $$ = $1;
        ret_type = $1;
    }
;

func_part2
    : RB{
        if(strcmp(curr_func,"main")==0){
            isMain=1;
            gencode_function("[Ljava/lang/String;");
            ret_type = 5;
        }
        gencode_function(")");
        isMain = 0;

        switch(curr_func_type){
            case 1:
                gencode_function("I\n");
                break;
            case 2:
                gencode_function("F\n");
                break;
            case 3:
                gencode_function("Z\n");
                break;
            case 4:
                gencode_function("Ljava/lang/String;\n");
                break;
            case 5:
                gencode_function("V\n");
                break;                
            }
        curr_func_type = 0;
        gencode_function(".limit stack 50\n");
        gencode_function(".limit locals 50\n");
    }
    | param RB {
        if(strcmp(curr_func,"main")==0){
            isMain=1;
            gencode_function("[Ljava/lang/String;");
        }
        
        for(int i = 0;i<param_num;i++){
            switch(param_array[i]){
                case 1:
                    if(isMain == 0)
                        gencode_function("I");
                    break;
                case 2:
                    if(isMain == 0)
                        gencode_function("F");
                    break;
                case 3:
                    if(isMain == 0)
                        gencode_function("Z");
                    break;
                case 4:
                    if(isMain == 0)
                        gencode_function("Ljava/lang/String;");
                    break;
                case 5:
                    if(isMain == 0)
                        gencode_function("V");
                    break;
            }
        }
        
        gencode_function(")");
        isMain = 0;

        switch(curr_func_type){
            case 1:
                gencode_function("I\n");
                break;
            case 2:
                gencode_function("F\n");
                break;
            case 3:
                gencode_function("Z\n");
                break;
            case 4:
                gencode_function("Ljava/lang/String;\n");
                break;
            case 5:
                gencode_function("V\n");
                break;                
            }
        curr_func_type = 0;
        gencode_function(".limit stack 50\n");
        gencode_function(".limit locals 50\n");
    }
;

func_part3
    : SEMICOLON
    | LCB stats_in_func RCB{
        gencode_function(".end method\n");
    }
    | LCB RCB{
            gencode_function(".end method\n");
            // yyerror("Error return type!");
    }
;

param
    : type ID{
        if(lookup_symbol($2) != 0){
            insert_symbol($2, 3, $1);
            param_array[param_num] = $1;
            ++param_num;
            decl_count++;
            set_type($1);
        }
        else    print_error("Redeclared variable ", $2);

    }
    | param COMMA type ID{
        if(lookup_symbol($4) != 0){
            insert_symbol($4, 3, $3);
            param_array[param_num] = $3;
            ++param_num;
            decl_count++;
            set_type($3);

        }
        else    print_error("Redeclared variable ", $4);
    }
;


logic_stats
    : logic_stats logic_op logic_stats{
    }
    | logic_stat
;
logic_stat
    : value_stat compare_op value_stat{
        gencode_compare($1,$3,$2);
    }
    | value_stat {
        $$[0] = $1[0];
        $$[1] = $1[1];
    }
;

compare_op
    : MT {$$=1;}
    | LT {$$=2;}
    | MTE {$$=3;}
    | LTE {$$=4;}
    | EQ {$$=5;}
    | NE {$$=6;}
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
    file = fopen("compiler_hw3.j","w");
    fprintf(file,   ".class public compiler_hw3\n"
                    ".super java/lang/Object\n");
    yyparse();
    dump_symbol(scope_num);




    printf("\nTotal lines: %d \n",yylineno);
    
    fclose(file);
    if(error_flag){
        remove("compiler_hw3.j");
    }
    return 0;
}

void yyerror(char *s)
{

    error_flag=1;
    printf("\n|-----------------------------------------------|\n");
    printf("| Error found in line %d: %s\n", yylineno+1, buf);
    printf("| %s", s);
    printf("\n|-----------------------------------------------|\n\n");

    if(strcmp("syntax error",s)==0){
        remove("compiler_hw3.j");        
        exit(0);
    }
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
    head->string_value = NULL;
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

void set_value(char* name,float input){
    symbol_table *temp = head;
    while(temp->next != NULL){
        temp = temp->next;
        if(strcmp(temp->name, name) == 0 && temp->scope == scope_num){
            temp->value = input;
            return;
        }

    }   
    temp = head;
    while(temp->next != NULL){
        temp = temp->next;
        if(strcmp(temp->name, name) == 0 && temp->scope < scope_num){
            temp->value = input; 
            return;
        }
    }   
}


void set_string_value(char* name,char* input){
    symbol_table *temp = head;
    while(temp->next != NULL){
        temp = temp->next;
        if(strcmp(temp->name, name) == 0 && temp->scope == scope_num){
            temp->string_value = input;
            return;
        }

    }   
    temp = head;
    while(temp->next != NULL){
        temp = temp->next;
        if(strcmp(temp->name, name) == 0 && temp->scope < scope_num){
            return;
        }
    }   
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
                        temp->param_a[0] = 1;
                        temp->param_n++;
                    }

                    else{
                        strcat(temp->attribute,", int");
                        temp-> param_a[temp->param_n] = 1;
                        temp->param_n++;
                    }

                        
                 break;
                case 2:


                    if(temp->attribute==NULL)
                    {
                        temp->attribute = (char*)malloc(sizeof(char)*512);
                        strcpy(temp->attribute,"float");
                        temp->param_a[0] = 2;
                        temp->param_n++;
                    }

                    else{
                        strcat(temp->attribute,", float");
                        temp->param_a[temp->param_n] = 2;
                        temp->param_n++;   
                    }
              
                    break;
                case 3:


                    if(temp->attribute==NULL)
                    {
                        temp->attribute = (char*)malloc(sizeof(char)*512);
                        strcpy(temp->attribute,"bool");
                        temp->param_a[0] = 3;
                        temp->param_n++; 
                    }

                    else
                        strcat(temp->attribute,", bool");
                        temp->param_a[temp->param_n] = 3;
                        temp->param_n++; 
                    break;
                case 4:


                    if(temp->attribute==NULL){

                        temp->attribute = (char*)malloc(sizeof(char)*512);
                        strcpy(temp->attribute,"string");
                        temp->param_a[0] = 4;
                        temp->param_n++; 
                    }

                    else
                        strcat(temp->attribute,", string");
                        temp->param_a[temp->param_n] = 4;
                        temp->param_n++; 
                    break;
                case 5:

                    if(temp->attribute==NULL){
                        temp->attribute = (char*)malloc(sizeof(char)*512);
                        strcpy(temp->attribute,"void");
                        temp->param_a[0] = 5;
                        temp->param_n++; 
                    }
                    else
                        strcat(temp->attribute,", void");
                        temp->param_a[temp->param_n] = 5;
                        temp->param_n++; 
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

void gencode_function(char* output_text){
    fprintf(file,"%s", output_text);
}

int get_symbol_index(char *name){
    symbol_table* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
        if(strcmp(temp->name, name) == 0 && temp->scope == scope_num){
            return temp->index;
        }
    }   
    temp = head;
    while(temp->next != NULL){
        temp = temp->next;
        if(strcmp(temp->name, name) == 0 && temp->scope < scope_num){
             return temp->index;
        }
    }  
}

int get_stack_num(char *name){
    symbol_table *temp = head;
    int return_num = 0;
    while(temp->next!=NULL){
        temp = temp->next;
        if(strcmp(temp->name,name)==0 && temp->scope <= scope_num && temp->scope>0){
            return return_num;
        }
        else if(temp->scope<=scope_num && temp->scope>0){
            return_num++;
        }
    }
    return -1;
}

void gencode_ADD(float left[7],float right[7]){
    if(left[1] == 1 && left[1] == 1){
        // int & int 
        gencode_function("\tiadd\n");
    }
    // int float
    else if(left[1]==1 &&right[1]==2){
        gencode_function("\tswap\n");
        gencode_function("\ti2f\n");
        gencode_function("\tswap\n");
        gencode_function("\tfadd\n");

    }
    // float float
    else if(left[1]==2 && right[1]==2){
        gencode_function("\tfadd\n");
    }
    else if(left[1]==2 &&right[1]==1){
        gencode_function("\ti2f\n");
        gencode_function("\tfadd\n");        
    }


}

void gencode_SUB(float left[7],float right[7]){
    if(left[1] == 1 && left[1] == 1){
        // int & int 
        gencode_function("\tisub\n");
    }
    // int float
    else if(left[1]==1 &&right[1]==2){
        gencode_function("\tswap\n");
        gencode_function("\ti2f\n");
        gencode_function("\tswap\n");
        gencode_function("\tfsub\n");

    }
    // float float
    else if(left[1]==2 && right[1]==2){
        gencode_function("\tfadd\n");
    }
    else if(left[1]==2 &&right[1]==1){
        gencode_function("\ti2f\n");
        gencode_function("\tfsub\n");        
    }

}

void gencode_MUL(float left[7],float right[7]){
    if(left[1] == 1 && left[1] == 1){
        // int & int 
        gencode_function("\timul\n");
    }
    // int float
    else if(left[1]==1 &&right[1]==2){
        gencode_function("\tswap\n");
        gencode_function("\ti2f\n");
        gencode_function("\tswap\n");
        gencode_function("\tfmul\n");

    }
    // float float
    else if(left[1]==2 && right[1]==2){
        gencode_function("\tfmul\n");
    }
    else if(left[1]==2 &&right[1]==1){
        gencode_function("\ti2f\n");
        gencode_function("\tfmul\n");        
    }

}

void gencode_DIV(float left[7],float right[7]){
    if(left[1] == 1 && left[1] == 1){
        // int & int 
        gencode_function("\tidiv\n");
    }
    // int float
    else if(left[1]==1 &&right[1]==2){
        gencode_function("\tswap\n");
        gencode_function("\ti2f\n");
        gencode_function("\tswap\n");
        gencode_function("\tfdiv\n");

    }
    // float float
    else if(left[1]==2 && right[1]==2){
        gencode_function("\tfdiv\n");
    }
    else if(left[1]==2 &&right[1]==1){
        gencode_function("\ti2f\n");
        gencode_function("\tfdiv\n");        
    }

}
void gencode_MOD(float left[7],float right[7]){
    if(left[1] == 1 && left[1] == 1){
        // int & int 
        gencode_function("\tirem\n");
    }
    else{
		yyerror("Only int can do mod");
	}
    }



void gencode_load(float data[7],char* id){
    char tempbuf[64];
    switch((int)data[1]){
        case 1:
            //global
            if(data[5]){
                sprintf(tempbuf, "\tgetstatic compiler_hw3/%s %s\n", id, "I");
                gencode_function(tempbuf);
            }
            else{
            	sprintf(tempbuf, "\tiload %d\n", get_stack_num(id));
                gencode_function(tempbuf);

            }
            break;
        case 2:
            if(data[5]){
                sprintf(tempbuf, "\tgetstatic compiler_hw3/%s %s\n", id, "F");
                gencode_function(tempbuf);
            }
            else{
            	sprintf(tempbuf, "\tfload %d\n", get_stack_num(id));
                gencode_function(tempbuf);

            }
            break;
        case 3:
            if(data[5]){
                sprintf(tempbuf, "\tgetstatic compiler_hw3/%s %s\n", id, "Z");
                gencode_function(tempbuf);
            }
            else{
            	sprintf(tempbuf, "\tiload %d\n", get_stack_num(id));
                gencode_function(tempbuf);

            }
            break;
        case 4:
            if(data[5]){
                sprintf(tempbuf, "\tgetstatic compiler_hw3/%s %s\n",id, "Ljava/lang/String;");
                gencode_function(tempbuf);
            }
            else{
            	sprintf(tempbuf, "\taload %d\n", get_stack_num(id));
                gencode_function(tempbuf);

            }
            break;

    }

}

void gencode_store(int type,char* name){
    char tempbuf[64];
    int isGlobal = check_global(name);
    switch(type){
        case 1:
            //global
            if(isGlobal){
                sprintf(tempbuf, "\tputstatic compiler_hw3/%s %s\n", name, "I");
                gencode_function(tempbuf);
            }
            else{
            	sprintf(tempbuf, "\tistore %d\n", get_stack_num(name));
                gencode_function(tempbuf);

            }
            break;
        case 2:
            if(isGlobal){
                sprintf(tempbuf, "\tputstatic compiler_hw3/%s %s\n", name, "F");
                gencode_function(tempbuf);
            }
            else{
                int a = get_stack_num(name);
            	sprintf(tempbuf, "\tfstore %d\n", a);
                gencode_function(tempbuf);

            }
            break;
        case 3:
            if(isGlobal){
                sprintf(tempbuf, "\tputstatic compiler_hw3/%s %s\n", name, "Z");
                gencode_function(tempbuf);
            }
            else{
            	sprintf(tempbuf, "\tistore %d\n", get_stack_num(name));
                gencode_function(tempbuf);

            }
            break;
        case 4:
            if(isGlobal){
                sprintf(tempbuf, "\tputstatic compiler_hw3/%s %s\n", name, "Ljava/lang/String");
                gencode_function(tempbuf);
            }
            else{
            	sprintf(tempbuf, "\tastore %d\n", get_stack_num(name));
                gencode_function(tempbuf);

            }
            break;
    }
}

int check_global(char* name){
    symbol_table *temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
        if(strcmp(temp->name,name)==0 && temp->scope==0){
            return 1;
        }
    }
    return 0;
}

int get_symbol_type(char* name){
    symbol_table *temp = head;

    // search for temp in curr scope
    while(temp->next!=NULL){
        temp = temp->next;
        if(strcmp(temp->name,name)==0 && temp->scope==scope_num){
            int type = 0;
            if(strcmp("int",temp->type)==0)
                type = 1;
            if(strcmp("float",temp->type)==0)            
                type = 2;
            if(strcmp("bool",temp->type)==0)            
                type = 3;
            if(strcmp("string",temp->type)==0)            
                type = 4;
            if(strcmp("void",temp->type)==0)            
                type = 5;
            return type;
        }
    }
    temp = head;

    // search for temp in lower scope
    while(temp->next!=NULL){
        temp = temp->next;
        if(strcmp(temp->name,name)==0 && temp->scope<scope_num){
            int type = 0;
            if(strcmp("int",temp->type)==0)
                type = 1;
            if(strcmp("float",temp->type)==0)            
                type = 2;
            if(strcmp("bool",temp->type)==0)            
                type = 3;
            if(strcmp("string",temp->type)==0)            
                type = 4;
            if(strcmp("void",temp->type)==0)            
                type = 5;
            return type;
        }
    }
}

char* type2str(int type){
    switch(type){
        case 1:
            return "I";
        case 2:
            return "F";
        case 3:
            return "Z";
        case 4:
            return "Ljava/lang/String;";
        case 5:
            return "V";
    }
}

float get_symbol_value(char* name){
    symbol_table *temp = head;
    while(temp->next != NULL){
        temp = temp->next;
        if(strcmp(temp->name, name) == 0 && temp->scope == scope_num){
            return temp->value;
        }
    }   
    temp = head;
    while(temp->next != NULL){
        temp = temp->next;
        if(strcmp(temp->name, name) == 0 && temp->scope < scope_num){
             return temp->value;
        }
    } 
}



void gencode_print(float* var){
    gencode_function("\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n");
    gencode_function("\tswap\n");
    gencode_function("\tinvokevirtual java/io/PrintStream/println(");
    if(var[1] == 1)
        gencode_function("I)V\n");
    else if(var[1] == 2)
        gencode_function("F)V\n");
    else if(var[1] == 3)
        gencode_function("I)V\n");
    else if(var[1] == 4)
        gencode_function("Ljava/lang/String;)V\n");
    else if(var[1] == 5)
        gencode_function("I)V\n");
}

void gencode_DEC(float var[7]){
    switch((int)var[1]){
        case 1:
            gencode_function("\tldc 1\n");
			gencode_function("\tisub\n");
        break;

        case 2:
            gencode_function("\tldc 1.0\n");
		    gencode_function("\tfsub\n");
        break;
        default:
		yyerror("Only int and float can do post expression");
        break;

    }
}
void gencode_INC(float var[7]){
    char tempbuf[64];
    sprintf(tempbuf,"%d\n",(int)var[4]);
    switch((int)var[1]){
        case 1:
            gencode_function("\tldc 1\n");
			gencode_function("\tiadd\n");
            gencode_function("\tistore ");
            gencode_function(tempbuf);
        break;

        case 2:
            gencode_function("\tldc 1.0\n");
		    gencode_function("\tfadd\n");
            gencode_function("\tfsotre ");
            gencode_function(tempbuf);

        break;
        default:
		yyerror("Only int and float can do post expression");
        break;

    }




}

void gencode_function_call(char* name,int p_num){
    gencode_function("\tinvokestatic compiler_hw3/");
    gencode_function(name);
    gencode_function("(");
    int num = getParamNum(name);
    if(num !=p_num){
        yyerror("Wrong number of parameter");
    }
    int par[64];
    for(int i =0;i<num;i++){
        par[i] = getParam(name,i);
        gencode_function(type2str(par[i]));
    }
    gencode_function(")");
    gencode_function(type2str(get_symbol_type(name)));
    gencode_function("\n");

}
void gencode_assign(char*name,int assign_type,float right[7]){
    int type = get_symbol_type(name);
    float info[7];
    info[0] = get_symbol_value(name);
    info[1] = get_symbol_type(name);
    info[5] = check_global(name);
    switch(assign_type){
        case 1:
		if(right[1] == 1 && type ==1){
			gencode_store(type,name);
		}
		else if(right[1] == 1 && type == 2){
			gencode_function("\ti2f\n");
			gencode_store(type,name);

		}
		else if(right[1] == 2 && type == 2){
			gencode_store(type,name);

		}
		else if(right[1] == 2 && type == 1){
			gencode_function("\tf2i\n");
			gencode_store(type,name);
		}
		else if(right[1] == 3 && type == 3){
			gencode_store(type,name);

		}
		else if(right[1] == 4 && type == 4){
			gencode_store(type,name);

		}
		else{
            if(func_undecl_flag=0){
			    yyerror("Wrong type at assign!");
                func_undecl_flag = 0;
            }
		}
		break;
        case 2:
            gencode_load(info,name);
		    gencode_function("\tswap\n");
	    	gencode_ADD(info, right);
		    gencode_store(type,name);
            
            break;
        case 3:
            gencode_load(info,name);
		    gencode_function("\tswap\n");
	    	gencode_SUB(info, right);
		    gencode_store(type,name);
            break;
        case 4:
            gencode_load(info,name);
		    gencode_function("\tswap\n");
	    	gencode_MUL(info, right);
		    gencode_store(type,name);
            break;
        case 5:
            gencode_load(info,name);
		    gencode_function("\tswap\n");
	    	gencode_DIV(info, right);
		    gencode_store(type,name);
            break;
        case 6:
            gencode_load(info,name);
		    gencode_function("\tswap\n");
	    	gencode_MOD(info, right);
		    gencode_store(type,name);
            break;
    }
}
void gencode_compare(float left[7],float right[7],int op){
    char tempbuf[64];
	if(left[1] == 1 && right[1] == 1){
		// change right to float
		gencode_function("\ti2f\n");
		// save right to register
		gencode_function("\tswap\n");
		gencode_function("\ti2f\n");
		gencode_function("\tswap\n");
	}
	else if(left[1] == 1 && right[1] == 2){
		gencode_function("\tswap\n");
		gencode_function("\ti2f\n");
		gencode_function("\tswap\n");
	}
	else if(left[1] == 2 && right[1] == 2){
	}
	else if(left[1] == 2 && right[1] == 1){
		gencode_function("\ti2f\n");
	}
	else{
		yyerror("Unsupported data type!");
	}

	gencode_function("\tfcmpl\n");

	char label_name[10];
	char op_code[10];

	switch(op){
        	
	case 1:
		sprintf(op_code, "ifgt");
		sprintf(label_name, "MT");
		break;

	case 2:
		sprintf(op_code, "iflt");
		sprintf(label_name, "LT");
		break;

	case 3:
		sprintf(op_code, "ifge");
		sprintf(label_name, "MTE");
		break;
	case 4:
		sprintf(op_code, "ifle");
		sprintf(label_name, "LTE");
		break;
	case 5:
		sprintf(op_code, "ifeq");
		sprintf(label_name, "EQ");
		break;

	case 6:
		sprintf(op_code, "ifne");
		sprintf(label_name, "NE");
		break;
	}

	sprintf(tempbuf, "\t%s L_%s_TRUE_%d\n", op_code, label_name, cmp_label);
	gencode_function(tempbuf);
	gencode_function("\ticonst_0\n");
	sprintf(tempbuf, "\tgoto L_%s_FALSE_%d\n", label_name, cmp_label);
	gencode_function(tempbuf);
	sprintf(tempbuf, "L_%s_TRUE_%d:\n", label_name, cmp_label);
	gencode_function(tempbuf);
	gencode_function("\ticonst_1\n");
	sprintf(tempbuf,"L_%s_FALSE_%d:\n", label_name, cmp_label);
	gencode_function(tempbuf);

	cmp_label++;
}

int getParam(char* name,int i){
    symbol_table* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
        if(strcmp(temp->name, name) == 0 && temp->scope == scope_num){
            return temp->param_a[i];
        }
    }   
    temp = head;
    while(temp->next != NULL){
        temp = temp->next;
        if(strcmp(temp->name, name) == 0 && temp->scope < scope_num){
             return temp->param_a[i];
        }
    }      
}

int getParamNum(char* name,int i){
    symbol_table* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
        if(strcmp(temp->name, name) == 0 && temp->scope == scope_num){
            return temp->param_n;
        }
    }   
    temp = head;
    while(temp->next != NULL){
        temp = temp->next;
        if(strcmp(temp->name, name) == 0 && temp->scope < scope_num){
             return temp->param_n;
        }
    }      
}
