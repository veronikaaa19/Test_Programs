#define _CRT_SECURE_NO_WARNINGS

#include "stdio.h"

int data[8192] = {0};
int contextStack[8192] = {0}, contextStackIndex = 0;
int opStack[8192] = {0}, opStackIndex = 0, opTemp = 0;
int lastBindDataIndex = 0;

int main() {
    contextStackIndex = 0;
    opStackIndex = 0;
    opTemp = 0;
    lastBindDataIndex = 0;

    //";"

    //"0"
    opStack[++opStackIndex] = opTemp = 0x00000000;

    //"Input"
    (void)scanf_s("%d", &opTemp);
    data[opStack[opStackIndex]] = opTemp, opStackIndex = 0;

    //null statement (non-context)

    //";"

    //"4"
    opStack[++opStackIndex] = opTemp = 0x00000004;

    //"Input"
    (void)scanf_s("%d", &opTemp);
    data[opStack[opStackIndex]] = opTemp, opStackIndex = 0;

    //null statement (non-context)

    //";"

    //"8"
    opStack[++opStackIndex] = opTemp = 0x00000008;

    //"Input"
    (void)scanf_s("%d", &opTemp);
    data[opStack[opStackIndex]] = opTemp, opStackIndex = 0;

    //null statement (non-context)

    //";"

    //"If"

    //"aa0"
    opStack[++opStackIndex] = opTemp = data[0x00000000];

    //"bb0"
    opStack[++opStackIndex] = opTemp = data[0x00000004];

    //">"
    opTemp = opStack[opStackIndex - 1] = opStack[opStackIndex - 1] > opStack[opStackIndex]; --opStackIndex;

    //"aa0"
    opStack[++opStackIndex] = opTemp = data[0x00000000];

    //"cc0"
    opStack[++opStackIndex] = opTemp = data[0x00000008];

    //">"
    opTemp = opStack[opStackIndex - 1] = opStack[opStackIndex - 1] > opStack[opStackIndex]; --opStackIndex;

    //"&&"
    opTemp = opStack[opStackIndex - 1] &= opStack[opStackIndex]; --opStackIndex;

    //null statement (non-context)

    //after cond expresion (after "If")
    if (opTemp == 0) goto LABEL__AFTER_THEN_0000000002D8B730;

    //"mm0"
    opStack[++opStackIndex] = opTemp = data[0x0000000C];

    //"0"
    opStack[++opStackIndex] = opTemp = 0x00000000;

    //"->"
    lastBindDataIndex = opStack[opStackIndex];
    data[lastBindDataIndex] = opTemp = opStack[opStackIndex - 1], opStackIndex = 0;

    //null statement (non-context)

    //";" (after "then"-part of If-operator)
    opTemp = 1;
LABEL__AFTER_THEN_0000000002D8B730:

    //"Else" (part of "ElseIf")
    if (opTemp != 0) goto LABEL__AFTER_ELSE_0000000002D8D448;

    //"bb0"
    opStack[++opStackIndex] = opTemp = data[0x00000004];

    //"aa0"
    opStack[++opStackIndex] = opTemp = data[0x00000000];

    //">"
    opTemp = opStack[opStackIndex - 1] = opStack[opStackIndex - 1] > opStack[opStackIndex]; --opStackIndex;

    //"bb0"
    opStack[++opStackIndex] = opTemp = data[0x00000004];

    //"cc0"
    opStack[++opStackIndex] = opTemp = data[0x00000008];

    //">"
    opTemp = opStack[opStackIndex - 1] = opStack[opStackIndex - 1] > opStack[opStackIndex]; --opStackIndex;

    //"&&"
    opTemp = opStack[opStackIndex - 1] &= opStack[opStackIndex]; --opStackIndex;

    //null statement (non-context)

    //after cond expresion (after "ElseIf")
    if (opTemp == 0) goto LABEL__AFTER_THEN_0000000002D90200;

    //"mm0"
    opStack[++opStackIndex] = opTemp = data[0x0000000C];

    //"4"
    opStack[++opStackIndex] = opTemp = 0x00000004;

    //"->"
    lastBindDataIndex = opStack[opStackIndex];
    data[lastBindDataIndex] = opTemp = opStack[opStackIndex - 1], opStackIndex = 0;

    //null statement (non-context)

    //"}" (after "then"-part of ElseIf-operator)
    opTemp = 1;
LABEL__AFTER_ELSE_0000000002D8D448:
LABEL__AFTER_THEN_0000000002D90200:

    //"Else"
    if (opTemp != 0) goto LABEL__AFTER_ELSE_0000000002D91F18;

    //"mm0"
    opStack[++opStackIndex] = opTemp = data[0x0000000C];

    //"8"
    opStack[++opStackIndex] = opTemp = 0x00000008;

    //"->"
    lastBindDataIndex = opStack[opStackIndex];
    data[lastBindDataIndex] = opTemp = opStack[opStackIndex - 1], opStackIndex = 0;

    //null statement (non-context)

    //";" (after "Else")
LABEL__AFTER_ELSE_0000000002D91F18:

    //null statement (non-context)

    //"mm0"
    opStack[++opStackIndex] = opTemp = data[0x0000000C];

    //"Output"
    (void)printf("%d\r\n", opTemp = opStack[opStackIndex]), opStackIndex = 0;

    //null statement (non-context)

    //"If"

    //"aa0"
    opStack[++opStackIndex] = opTemp = data[0x00000000];

    //"bb0"
    opStack[++opStackIndex] = opTemp = data[0x00000004];

    //"Eg"
    opTemp = opStack[opStackIndex - 1] = opStack[opStackIndex - 1] == opStack[opStackIndex]; --opStackIndex;

    //"aa0"
    opStack[++opStackIndex] = opTemp = data[0x00000000];

    //"cc0"
    opStack[++opStackIndex] = opTemp = data[0x00000008];

    //"Eg"
    opTemp = opStack[opStackIndex - 1] = opStack[opStackIndex - 1] == opStack[opStackIndex]; --opStackIndex;

    //"&&"
    opTemp = opStack[opStackIndex - 1] &= opStack[opStackIndex]; --opStackIndex;

    //"bb0"
    opStack[++opStackIndex] = opTemp = data[0x00000004];

    //"cc0"
    opStack[++opStackIndex] = opTemp = data[0x00000008];

    //"Eg"
    opTemp = opStack[opStackIndex - 1] = opStack[opStackIndex - 1] == opStack[opStackIndex]; --opStackIndex;

    //"&&"
    opTemp = opStack[opStackIndex - 1] &= opStack[opStackIndex]; --opStackIndex;

    //null statement (non-context)

    //after cond expresion (after "If")
    if (opTemp == 0) goto LABEL__AFTER_THEN_0000000002D99378;

    //"1"
    opStack[++opStackIndex] = opTemp = 0x00000001;

    //"Output"
    (void)printf("%d\r\n", opTemp = opStack[opStackIndex]), opStackIndex = 0;

    //null statement (non-context)

    //";" (after "then"-part of If-operator)
    opTemp = 1;
LABEL__AFTER_THEN_0000000002D99378:

    //"Else"
    if (opTemp != 0) goto LABEL__AFTER_ELSE_0000000002D9AC68;

    //"0"
    opStack[++opStackIndex] = opTemp = 0x00000000;

    //"Output"
    (void)printf("%d\r\n", opTemp = opStack[opStackIndex]), opStackIndex = 0;

    //null statement (non-context)

    //";" (after "Else")
LABEL__AFTER_ELSE_0000000002D9AC68:

    //"If"

    //"aa0"
    opStack[++opStackIndex] = opTemp = data[0x00000000];

    //"0"
    opStack[++opStackIndex] = opTemp = 0x00000000;

    //"<"
    opTemp = opStack[opStackIndex - 1] = opStack[opStackIndex - 1] < opStack[opStackIndex]; --opStackIndex;

    //"bb0"
    opStack[++opStackIndex] = opTemp = data[0x00000004];

    //"0"
    opStack[++opStackIndex] = opTemp = 0x00000000;

    //"<"
    opTemp = opStack[opStackIndex - 1] = opStack[opStackIndex - 1] < opStack[opStackIndex]; --opStackIndex;

    //"||"
    opTemp = opStack[opStackIndex - 1] |= opStack[opStackIndex]; --opStackIndex;

    //"cc0"
    opStack[++opStackIndex] = opTemp = data[0x00000008];

    //"0"
    opStack[++opStackIndex] = opTemp = 0x00000000;

    //"<"
    opTemp = opStack[opStackIndex - 1] = opStack[opStackIndex - 1] < opStack[opStackIndex]; --opStackIndex;

    //"||"
    opTemp = opStack[opStackIndex - 1] |= opStack[opStackIndex]; --opStackIndex;

    //null statement (non-context)

    //after cond expresion (after "If")
    if (opTemp == 0) goto LABEL__AFTER_THEN_0000000002DA03B0;

    //"-1"
    opStack[++opStackIndex] = opTemp = 0xFFFFFFFF;

    //"Output"
    (void)printf("%d\r\n", opTemp = opStack[opStackIndex]), opStackIndex = 0;

    //null statement (non-context)

    //";" (after "then"-part of If-operator)
    opTemp = 1;
LABEL__AFTER_THEN_0000000002DA03B0:

    //"Else"
    if (opTemp != 0) goto LABEL__AFTER_ELSE_0000000002DA1CA0;

    //"0"
    opStack[++opStackIndex] = opTemp = 0x00000000;

    //"Output"
    (void)printf("%d\r\n", opTemp = opStack[opStackIndex]), opStackIndex = 0;

    //null statement (non-context)

    //";" (after "Else")
LABEL__AFTER_ELSE_0000000002DA1CA0:

    //"If"

    //"aa0"
    opStack[++opStackIndex] = opTemp = data[0x00000000];

    //"bb0"
    opStack[++opStackIndex] = opTemp = data[0x00000004];

    //"cc0"
    opStack[++opStackIndex] = opTemp = data[0x00000008];

    //"+"
    opTemp = opStack[opStackIndex - 1] += opStack[opStackIndex]; --opStackIndex;

    //"<"
    opTemp = opStack[opStackIndex - 1] = opStack[opStackIndex - 1] < opStack[opStackIndex]; --opStackIndex;

    //"!!"
    opTemp = opStack[opStackIndex] = ~opStack[opStackIndex];

    //null statement (non-context)

    //after cond expresion (after "If")
    if (opTemp == 0) goto LABEL__AFTER_THEN_0000000002DA5F20;

    //"10"
    opStack[++opStackIndex] = opTemp = 0x0000000A;

    //"Output"
    (void)printf("%d\r\n", opTemp = opStack[opStackIndex]), opStackIndex = 0;

    //null statement (non-context)

    //";" (after "then"-part of If-operator)
    opTemp = 1;
LABEL__AFTER_THEN_0000000002DA5F20:

    //"Else"
    if (opTemp != 0) goto LABEL__AFTER_ELSE_0000000002DA7810;

    //"0"
    opStack[++opStackIndex] = opTemp = 0x00000000;

    //"Output"
    (void)printf("%d\r\n", opTemp = opStack[opStackIndex]), opStackIndex = 0;

    //null statement (non-context)

    //";" (after "Else")
LABEL__AFTER_ELSE_0000000002DA7810:

    return 0;
}