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

    //"aa0"
    opStack[++opStackIndex] = opTemp = data[0x00000000];

    //"8"
    opStack[++opStackIndex] = opTemp = 0x00000008;

    //"->"
    lastBindDataIndex = opStack[opStackIndex];
    data[lastBindDataIndex] = opTemp = opStack[opStackIndex - 1], opStackIndex = 0;

    //null statement (non-context)

    //";"

    //"1"
    opStack[++opStackIndex] = opTemp = 0x00000001;

    //"12"
    opStack[++opStackIndex] = opTemp = 0x0000000C;

    //"->"
    lastBindDataIndex = opStack[opStackIndex];
    data[lastBindDataIndex] = opTemp = opStack[opStackIndex - 1], opStackIndex = 0;

    //null statement (non-context)

    //";"

    //ident "lc0"(as label) previous ":"
LABEL__0000000000A65780:

    //"If"

    //"ii0"
    opStack[++opStackIndex] = opTemp = data[0x00000008];

    //"bb0"
    opStack[++opStackIndex] = opTemp = data[0x00000004];

    //">"
    opTemp = opStack[opStackIndex - 1] = opStack[opStackIndex - 1] > opStack[opStackIndex]; --opStackIndex;

    //null statement (non-context)

    //after cond expresion (after "If")
    if (opTemp == 0) goto LABEL__AFTER_THEN_0000000002D8DC98;

    //"Goto" previous ident "ed2"(as label)
    goto LABEL__0000000000A60748;

    //null statement (non-context)

    //";" (after "then"-part of If-operator)
    opTemp = 1;
LABEL__AFTER_THEN_0000000002D8DC98:

    //null statement (non-context)

    //"ii0"
    opStack[++opStackIndex] = opTemp = data[0x00000008];

    //"jj0"
    opStack[++opStackIndex] = opTemp = data[0x0000000C];

    //"Mul"
    opTemp = opStack[opStackIndex - 1] *= opStack[opStackIndex]; --opStackIndex;

    //"Output"
    (void)printf("%d\r\n", opTemp = opStack[opStackIndex]), opStackIndex = 0;

    //null statement (non-context)

    //"ii0"
    opStack[++opStackIndex] = opTemp = data[0x00000008];

    //"1"
    opStack[++opStackIndex] = opTemp = 0x00000001;

    //"+"
    opTemp = opStack[opStackIndex - 1] += opStack[opStackIndex]; --opStackIndex;

    //"8"
    opStack[++opStackIndex] = opTemp = 0x00000008;

    //"->"
    lastBindDataIndex = opStack[opStackIndex];
    data[lastBindDataIndex] = opTemp = opStack[opStackIndex - 1], opStackIndex = 0;

    //null statement (non-context)

    //"Goto" previous ident "lc0"(as label)
    goto LABEL__0000000000A65780;

    //null statement (non-context)

    //ident "ed2"(as label) previous ":"
LABEL__0000000000A60748:

    //"0"
    opStack[++opStackIndex] = opTemp = 0x00000000;

    //"16"
    opStack[++opStackIndex] = opTemp = 0x00000010;

    //"->"
    lastBindDataIndex = opStack[opStackIndex];
    data[lastBindDataIndex] = opTemp = opStack[opStackIndex - 1], opStackIndex = 0;

    //null statement (non-context)

    //";"

    //"1"
    opStack[++opStackIndex] = opTemp = 0x00000001;

    //"8"
    opStack[++opStackIndex] = opTemp = 0x00000008;

    //"->"
    lastBindDataIndex = opStack[opStackIndex];
    data[lastBindDataIndex] = opTemp = opStack[opStackIndex - 1], opStackIndex = 0;

    //null statement (non-context)

    //";"

    //ident "la0"(as label) previous ":"
LABEL__0000000000A719B0:

    //"If"

    //"ii0"
    opStack[++opStackIndex] = opTemp = data[0x00000008];

    //"aa0"
    opStack[++opStackIndex] = opTemp = data[0x00000000];

    //">"
    opTemp = opStack[opStackIndex - 1] = opStack[opStackIndex - 1] > opStack[opStackIndex]; --opStackIndex;

    //null statement (non-context)

    //after cond expresion (after "If")
    if (opTemp == 0) goto LABEL__AFTER_THEN_0000000002D9B090;

    //"Goto" previous ident "ed0"(as label)
    goto LABEL__0000000000A71A30;

    //null statement (non-context)

    //";" (after "then"-part of If-operator)
    opTemp = 1;
LABEL__AFTER_THEN_0000000002D9B090:

    //"1"
    opStack[++opStackIndex] = opTemp = 0x00000001;

    //"12"
    opStack[++opStackIndex] = opTemp = 0x0000000C;

    //"->"
    lastBindDataIndex = opStack[opStackIndex];
    data[lastBindDataIndex] = opTemp = opStack[opStackIndex - 1], opStackIndex = 0;

    //null statement (non-context)

    //";"

    //ident "lb0"(as label) previous ":"
LABEL__0000000000A71AB0:

    //"If"

    //"bb0"
    opStack[++opStackIndex] = opTemp = data[0x00000004];

    //"jj0"
    opStack[++opStackIndex] = opTemp = data[0x0000000C];

    //"<"
    opTemp = opStack[opStackIndex - 1] = opStack[opStackIndex - 1] < opStack[opStackIndex]; --opStackIndex;

    //null statement (non-context)

    //after cond expresion (after "If")
    if (opTemp == 0) goto LABEL__AFTER_THEN_0000000002DA0C00;

    //"Goto" previous ident "ed1"(as label)
    goto LABEL__0000000000A83A28;

    //null statement (non-context)

    //";" (after "then"-part of If-operator)
    opTemp = 1;
LABEL__AFTER_THEN_0000000002DA0C00:

    //"xx0"
    opStack[++opStackIndex] = opTemp = data[0x00000010];

    //"1"
    opStack[++opStackIndex] = opTemp = 0x00000001;

    //"+"
    opTemp = opStack[opStackIndex - 1] += opStack[opStackIndex]; --opStackIndex;

    //"16"
    opStack[++opStackIndex] = opTemp = 0x00000010;

    //"->"
    lastBindDataIndex = opStack[opStackIndex];
    data[lastBindDataIndex] = opTemp = opStack[opStackIndex - 1], opStackIndex = 0;

    //null statement (non-context)

    //";"

    //"jj0"
    opStack[++opStackIndex] = opTemp = data[0x0000000C];

    //"1"
    opStack[++opStackIndex] = opTemp = 0x00000001;

    //"+"
    opTemp = opStack[opStackIndex - 1] += opStack[opStackIndex]; --opStackIndex;

    //"12"
    opStack[++opStackIndex] = opTemp = 0x0000000C;

    //"->"
    lastBindDataIndex = opStack[opStackIndex];
    data[lastBindDataIndex] = opTemp = opStack[opStackIndex - 1], opStackIndex = 0;

    //null statement (non-context)

    //";"

    //"Goto" previous ident "lb0"(as label)
    goto LABEL__0000000000A71AB0;

    //null statement (non-context)

    //ident "ed1"(as label) previous ":"
LABEL__0000000000A83A28:

    //"ii0"
    opStack[++opStackIndex] = opTemp = data[0x00000008];

    //"1"
    opStack[++opStackIndex] = opTemp = 0x00000001;

    //"+"
    opTemp = opStack[opStackIndex - 1] += opStack[opStackIndex]; --opStackIndex;

    //"8"
    opStack[++opStackIndex] = opTemp = 0x00000008;

    //"->"
    lastBindDataIndex = opStack[opStackIndex];
    data[lastBindDataIndex] = opTemp = opStack[opStackIndex - 1], opStackIndex = 0;

    //null statement (non-context)

    //"Goto" previous ident "la0"(as label)
    goto LABEL__0000000000A719B0;

    //null statement (non-context)

    //ident "ed0"(as label) previous ":"
LABEL__0000000000A71A30:

    //"xx0"
    opStack[++opStackIndex] = opTemp = data[0x00000010];

    //"Output"
    (void)printf("%d\r\n", opTemp = opStack[opStackIndex]), opStackIndex = 0;

    //null statement (non-context)

    //";"

    return 0;
}