/*
Перевірка РБНФ №2 за допомогою коду
(помістити у файл "EBNF_N2.h")
*/


#define NONTERMINALS labeled_point, \
goto_label, \
program_name, \
value_type, \
array_specify, \
declaration_element, \
array_specify__optional, \
other_declaration_ident, \
declaration, \
other_declaration_ident__iteration, \
index_action, \
unary_operator, \
unary_operation, \
binary_operator, \
binary_action, \
left_expression, \
group_expression, \
index_action__optional, \
expression, \
binary_action__iteration, \
expression_or_cond_block__with_optional_assign, \
assign_to_right, \
assign_to_right__optional, \
if_expression, \
body_for_true, \
false_cond_block_without_else, \
body_for_false, \
cond_block, \
false_cond_block_without_else__iteration, \
body_for_false__optional, \
statement,\
block_statements, \
input_rule, \
argument_for_input, \
output_rule, \
statement__iteration, \
expression__optional, \
program_rule, \
declaration__optional, \
non_zero_digit, \
digit__iteration, \
digit, \
unsigned_value, \
value, \
sign__optional, \
sign, \
ident, \
letter_in_upper_case, \
letter_in_lower_case, \
sign_plus, \
sign_minus



#define TOKENS \
tokenCOLON, \
tokenGOTO, \
tokenINTEGER16, \
tokenCOMMA, \
tokenNOT, \
tokenAND, \
tokenOR, \
tokenEQUAL, \
tokenNOTEQUAL, \
tokenLESS, \
tokenGREATER, \
tokenPLUS, \
tokenMINUS, \
tokenMUL, \
tokenDIV, \
tokenMOD, \
tokenGROUPEXPRESSIONBEGIN, \
tokenGROUPEXPRESSIONEND, \
tokenLRASSIGN, \
tokenELSE, \
tokenIF, \
tokenEXIT, \
tokenGET, \
tokenPUT, \
tokenNAME, \
tokenBODY, \
tokenDATA, \
tokenBEGIN, \
tokenEND, \
tokenBEGINBLOCK, \
tokenENDBLOCK, \
tokenLEFTSQUAREBRACKETS, \
tokenRIGHTSQUAREBRACKETS, \
tokenSEMICOLON, \
digit_0, \
digit_1, \
digit_2, \
digit_3, \
digit_4, \
digit_5, \
digit_6, \
digit_7, \
digit_8, \
digit_9, \
tokenUNDERSCORE, \
A, \
B, \
C, \
D, \
E, \
F, \
G, \
H, \
I, \
J, \
K, \
L, \
M, \
N, \
O, \
P, \
Q, \
R, \
S, \
T, \
U, \
V, \
W, \
X, \
Y, \
Z, \
a, \
b, \
c, \
d, \
e, \
f, \
g, \
h, \
i, \
j, \
k, \
l, \
m, \
n, \
o, \
p, \
q, \
r, \
s, \
t, \
u, \
v, \
w, \
x, \
y, \
z

#define COMMENT_BEGIN_STR "#*"
#define COMMENT_END_STR   "*#"


/* --- Визначення токенів (оновлено під синтаксис файлу №3) --- */

tokenGROUPEXPRESSIONBEGIN = "(" >> BOUNDARIES;
tokenGROUPEXPRESSIONEND = ")" >> BOUNDARIES;
tokenLEFTSQUAREBRACKETS = "[" >> BOUNDARIES;
tokenRIGHTSQUAREBRACKETS = "]" >> BOUNDARIES;
tokenBEGINBLOCK = "{" >> BOUNDARIES;
tokenENDBLOCK = "}" >> BOUNDARIES;
tokenSEMICOLON = ";" >> BOUNDARIES;
tokenCOLON = ":" >> BOUNDARIES;

tokenGOTO = "Goto" >> STRICT_BOUNDARIES;
tokenINTEGER16 = "Int16_t" >> STRICT_BOUNDARIES;
tokenCOMMA = "," >> BOUNDARIES;

tokenNOT = "!!" >> STRICT_BOUNDARIES;
tokenAND = "&&" >> STRICT_BOUNDARIES;
tokenOR = "||" >> STRICT_BOUNDARIES;

tokenEQUAL = "Eg" >> BOUNDARIES;
tokenNOTEQUAL = "Ne" >> BOUNDARIES;
tokenLESS = "<" >> BOUNDARIES;
tokenGREATER = ">" >> BOUNDARIES;
tokenPLUS = "+" >> BOUNDARIES;
tokenMINUS = "-" >> BOUNDARIES;
tokenMUL = "Mul" >> BOUNDARIES;
tokenDIV = "Div" >> STRICT_BOUNDARIES;
tokenMOD = "Mod" >> STRICT_BOUNDARIES;

tokenLRASSIGN = "->" >> BOUNDARIES;

tokenELSE = "Else" >> STRICT_BOUNDARIES;
tokenIF = "If" >> STRICT_BOUNDARIES;

tokenGET = "Input" >> STRICT_BOUNDARIES;
tokenPUT = "Output" >> STRICT_BOUNDARIES;
tokenNAME = "Mainprogram" >> STRICT_BOUNDARIES;

tokenBODY = "Start" >> STRICT_BOUNDARIES;
tokenDATA = "Data" >> STRICT_BOUNDARIES;

tokenEND = "End" >> STRICT_BOUNDARIES;


/* --- Правила граматики (Логіка як у EBNF №1, адаптована під імена змінних №2) --- */

labeled_point = ident >> tokenCOLON;
goto_label = tokenGOTO >> ident;
program_name = SAME_RULE(ident);
value_type = SAME_RULE(tokenINTEGER16);

/* Declaration */
array_specify = tokenLEFTSQUAREBRACKETS >> unsigned_value >> tokenRIGHTSQUAREBRACKETS;
array_specify__optional = -array_specify; /* Використовуємо - (optional) як у N1 */

declaration_element = ident >> array_specify__optional;

other_declaration_ident = tokenCOMMA >> declaration_element;
other_declaration_ident__iteration = *other_declaration_ident; /* Використовуємо * (Kleene star) як у N1 */

declaration = value_type >> declaration_element >> other_declaration_ident__iteration;
declaration__optional = -declaration;

/* Actions */
index_action = tokenLEFTSQUAREBRACKETS >> expression >> tokenRIGHTSQUAREBRACKETS;
index_action__optional = -index_action;

unary_operator = SAME_RULE(tokenNOT);
unary_operation = unary_operator >> expression;

binary_operator = tokenAND | tokenOR | tokenEQUAL | tokenNOTEQUAL | tokenLESS | tokenGREATER | tokenPLUS | tokenMINUS | tokenMUL | tokenDIV | tokenMOD;
binary_action = binary_operator >> expression;
binary_action__iteration = *binary_action;

/* Expressions */
/* Важливо: cond_block включено сюди, як і в N1 */
left_expression = group_expression | unary_operation | cond_block | value | ident >> index_action__optional;

expression = left_expression >> binary_action__iteration;
expression__optional = -expression;

group_expression = tokenGROUPEXPRESSIONBEGIN >> expression >> tokenGROUPEXPRESSIONEND;

/* Assignment (Right Bind) */
assign_to_right = tokenLRASSIGN >> ident >> index_action__optional;
assign_to_right__optional = -assign_to_right;

expression_or_cond_block__with_optional_assign = expression >> assign_to_right__optional;

/* IF / ELSE logic */
if_expression = SAME_RULE(expression);
body_for_true = SAME_RULE(block_statements);

false_cond_block_without_else = tokenELSE >> tokenIF >> if_expression >> body_for_true;
false_cond_block_without_else__iteration = *false_cond_block_without_else;

body_for_false = tokenELSE >> block_statements;
body_for_false__optional = -body_for_false;

cond_block = tokenIF >> if_expression >> body_for_true >> false_cond_block_without_else__iteration >> body_for_false__optional;

/* I/O Rules */
argument_for_input = ident >> index_action__optional | tokenGROUPEXPRESSIONBEGIN >> ident >> index_action__optional >> tokenGROUPEXPRESSIONEND;
input_rule = tokenGET >> argument_for_input;
output_rule = tokenPUT >> expression;

/* Statements */
/* УВАГА: labeled_point має бути ПЕРШИМ, щоб уникнути конфлікту з ident у expression */
statement = labeled_point | goto_label | input_rule | output_rule | expression_or_cond_block__with_optional_assign | tokenSEMICOLON;

statement__iteration = *statement;

block_statements = tokenBEGINBLOCK >> statement__iteration >> expression__optional >> tokenENDBLOCK;

/* Main Program */
program_rule = BOUNDARIES >> tokenNAME >> tokenDATA >> declaration__optional >> tokenSEMICOLON >> tokenBODY >> statement__iteration >> tokenEND;

/* Values & Digits */
sign = sign_plus | sign_minus;
sign_plus = SAME_RULE(tokenPLUS);
sign_minus = SAME_RULE(tokenMINUS);
sign__optional = -sign;

digit_0 = '0';
digit_1 = '1';
digit_2 = '2';
digit_3 = '3';
digit_4 = '4';
digit_5 = '5';
digit_6 = '6';
digit_7 = '7';
digit_8 = '8';
digit_9 = '9';

digit = digit_0 | digit_1 | digit_2 | digit_3 | digit_4 | digit_5 | digit_6 | digit_7 | digit_8 | digit_9;
non_zero_digit = digit_1 | digit_2 | digit_3 | digit_4 | digit_5 | digit_6 | digit_7 | digit_8 | digit_9;

digit__iteration = *digit;
unsigned_value = ((non_zero_digit >> digit__iteration) | digit_0) >> BOUNDARIES;

value = sign__optional >> unsigned_value >> BOUNDARIES;

tokenUNDERSCORE = "_";


ident = letter_in_lower_case >> letter_in_lower_case >> digit >> STRICT_BOUNDARIES;

a = "a"; b = "b"; c = "c"; d = "d"; e = "e"; f = "f"; g = "g"; h = "h"; i = "i";
j = "j"; k = "k"; l = "l"; m = "m"; n = "n"; o = "o"; p = "p"; q = "q"; r = "r";
s = "s"; t = "t"; u = "u"; v = "v"; w = "w"; x = "x"; y = "y"; z = "z";

letter_in_lower_case = a | b | c | d | e | f | g | h | i | j | k | l | m | n | o | p | q | r | s | t | u | v | w | x | y | z;


STRICT_BOUNDARIES = (BOUNDARY >> *(BOUNDARY)) | (!(qi::alpha | qi::char_("_")));
BOUNDARIES = (BOUNDARY >> *(BOUNDARY) | NO_BOUNDARY);
BOUNDARY = BOUNDARY__SPACE | BOUNDARY__TAB | BOUNDARY__VERTICAL_TAB | BOUNDARY__FORM_FEED | BOUNDARY__CARRIAGE_RETURN | BOUNDARY__LINE_FEED | BOUNDARY__NULL;

BOUNDARY__SPACE = " ";
BOUNDARY__TAB = "\t";
BOUNDARY__VERTICAL_TAB = "\v";
BOUNDARY__FORM_FEED = "\f";
BOUNDARY__CARRIAGE_RETURN = "\r";
BOUNDARY__LINE_FEED = "\n";
BOUNDARY__NULL = "\0";
NO_BOUNDARY = "";

#define WHITESPACES \
STRICT_BOUNDARIES, \
BOUNDARIES, \
BOUNDARY, \
BOUNDARY__SPACE, \
BOUNDARY__TAB, \
BOUNDARY__VERTICAL_TAB, \
BOUNDARY__FORM_FEED, \
BOUNDARY__CARRIAGE_RETURN, \
BOUNDARY__LINE_FEED, \
BOUNDARY__NULL, \
NO_BOUNDARY