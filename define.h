#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include "parser.tab.h"

#define MAXLENGTH   1000    //������ű�Ĵ�С
//�������൱���з��ս�� �� �ս��(.l�ļ��ʷ�����Return�Ķ���)
enum node_kind{_BREAK,_CONTINUE,EXT_DEF_LIST,EXT_DEF_VAR,EXT_DEF_FUNC,EXT_VARDEC_LIST,FUNC_DEC,FUNC_PARAM_LIST,FUNC_PARAM_DEC,COMP_STM,COMPSTM_LIST,COMPSTM_EXP,IF_THEN,IF_THEN_ELSE,DEF_LIST,VAR_DEF,VARDEC_LIST,FUNC_CALL,ARRAY_CALL,ARGS,FOR_CONDITION,EXP_FOR3_LIST};
 

struct node{
    enum node_kind nodeKind;    //�������
    union{
        int type_int;
	    float type_float;
        char type_char;
	    char type_id[32];
    };
    struct node *ptr[3];   
    struct node *parent;//���ڵ�   
    int pos;        //��¼�﷨��λ���ڵ�λ���к�
    int size;         //��¼����Ĵ�С
    int index;      //��¼������±�
    char scope[50]; //����������
    int level;      //���
    int place;      //����Ӧ�ı���/���������ű��λ�����
    int type;       //����Ӧ��ֵ������
    int num;        //��¼�ӽ������������Լ���
    int offset;     //ƫ����

    int break_num;
};


struct node *mknode(int kind,struct node *first,struct node *second, struct node *third,int pos );
