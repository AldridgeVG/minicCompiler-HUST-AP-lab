#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include "parser.tab.h"

#define MAXLENGTH   1000    //定义符号表的大小
//结点类别相当于有非终结符 和 终结符(.l文件词法分析Return的都是)
enum node_kind{_BREAK,_CONTINUE,EXT_DEF_LIST,EXT_DEF_VAR,EXT_DEF_FUNC,EXT_VARDEC_LIST,FUNC_DEC,FUNC_PARAM_LIST,FUNC_PARAM_DEC,COMP_STM,COMPSTM_LIST,COMPSTM_EXP,IF_THEN,IF_THEN_ELSE,DEF_LIST,VAR_DEF,VARDEC_LIST,FUNC_CALL,ARRAY_CALL,ARGS,FOR_CONDITION,EXP_FOR3_LIST};
 

struct node{
    enum node_kind nodeKind;    //结点类型
    union{
        int type_int;
	    float type_float;
        char type_char;
	    char type_id[32];
    };
    struct node *ptr[3];   
    struct node *parent;//父节点   
    int pos;        //记录语法单位所在的位置行号
    int size;         //记录数组的大小
    int index;      //记录数组的下标
    char scope[50]; //所属作用域
    int level;      //层号
    int place;      //结点对应的变量/运算结果符号表的位置序号
    int type;       //结点对应的值的类型
    int num;        //记录子结点个数（包括自己）
    int offset;     //偏移量

    int break_num;
};


struct node *mknode(int kind,struct node *first,struct node *second, struct node *third,int pos );
