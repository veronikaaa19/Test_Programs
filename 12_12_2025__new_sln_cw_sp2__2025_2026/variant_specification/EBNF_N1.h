/*
Перевірка РБНФ №1 за допомогою коду
(помістити у файл "EBNF_N1.h")
ВИПРАВЛЕНО для file2.s21 та file3.s21
*/

#define NONTERMINALS labeled_point, \
goto_label, \
program_name, \
value_type, \
array_specify, \
declaration_element, \
\
other_declaration_ident, \
declaration, \
\
index_action, \
unary_operator, \
unary_operation, \
binary_operator, \
binary_action, \
left_expression, \
group_expression, \
\
expression, \
\
expression_or_cond_block__with_optional_assign, \
assign_to_right, \
\
if_expression, \
body_for_true, \
false_cond_block_without_else, \
body_for_false, \
cond_block, \
\
bind_left_to_right, \
cond_block__with_optionally_return_value, \
cond_block__with_optionally_return_value_and_optionally_bind, \
body_for_true__with_optionally_return_value, \
false_cond_block_without_else__with_optionally_return_value, \
body_for_false__with_optionally_return_value, \
block_statements__with_optionally_return_value, \
\
statement,\
block_statements, \
input_rule, \
argument_for_input, \
output_rule, \
\
\
program_rule, \
\
non_zero_digit, \
digit__iteration, \
digit, \
unsigned_value, \
value, \
\
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

/* Визначення токенів згідно з новим шаблоном */
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

/* У шаблоні це tokenLRBIND "->", мапимо на існуючий tokenLRASSIGN */
tokenLRASSIGN = "->" >> BOUNDARIES;

tokenELSE = "Else" >> STRICT_BOUNDARIES;
tokenIF = "If" >> STRICT_BOUNDARIES;


tokenGET = "Input" >> STRICT_BOUNDARIES;
tokenPUT = "Output" >> STRICT_BOUNDARIES;
tokenNAME = "Mainprogram" >> STRICT_BOUNDARIES;

/* У шаблоні tokenSTART "Start", мапимо на існуючий tokenBODY */
tokenBODY = "Start" >> STRICT_BOUNDARIES;

tokenDATA = "Data" >> STRICT_BOUNDARIES;

tokenEND = "End" >> STRICT_BOUNDARIES;


/* Правила граматики згідно з новим шаблоном */

labeled_point = ident >> tokenCOLON;
goto_label = tokenGOTO >> ident;
program_name = SAME_RULE(ident); /* Використовується в program_rule (Mainprogram program_name) */
value_type = SAME_RULE(tokenINTEGER16);

declaration_element = ident >> -(tokenLEFTSQUAREBRACKETS >> unsigned_value >> tokenRIGHTSQUAREBRACKETS);
other_declaration_ident = tokenCOMMA >> declaration_element;
declaration = value_type >> declaration_element >> *other_declaration_ident;

index_action = tokenLEFTSQUAREBRACKETS >> expression >> tokenRIGHTSQUAREBRACKETS;

unary_operator = SAME_RULE(tokenNOT);
unary_operation = unary_operator >> expression;

binary_operator = tokenAND | tokenOR | tokenEQUAL | tokenNOTEQUAL | tokenLESS | tokenGREATER | tokenPLUS | tokenMINUS | tokenMUL | tokenDIV | tokenMOD;
binary_action = binary_operator >> expression;

/* left_expression оновлено */
left_expression = group_expression | unary_operation | ident >> -index_action | value | cond_block__with_optionally_return_value;

expression = left_expression >> *binary_action;

group_expression = tokenGROUPEXPRESSIONBEGIN >> expression >> tokenGROUPEXPRESSIONEND;

/* Нове правило bind_left_to_right, використовує tokenLRASSIGN замість tokenLRBIND */
bind_left_to_right = expression >> tokenLRASSIGN >> ident >> -index_action;

if_expression = SAME_RULE(expression);

/* ВИПРАВЛЕНО: Логіка блоків IF/ELSE з явними tokenBEGINBLOCK/tokenENDBLOCK */
body_for_true__with_optionally_return_value = tokenBEGINBLOCK >> *statement >> -expression >> tokenENDBLOCK;

false_cond_block_without_else__with_optionally_return_value = tokenELSE >> tokenIF >> if_expression >> body_for_true__with_optionally_return_value;

body_for_false__with_optionally_return_value = tokenELSE >> tokenBEGINBLOCK >> *statement >> -expression >> tokenENDBLOCK;

cond_block__with_optionally_return_value = tokenIF >> if_expression >> body_for_true__with_optionally_return_value >> *false_cond_block_without_else__with_optionally_return_value >> -body_for_false__with_optionally_return_value;

cond_block__with_optionally_return_value_and_optionally_bind = cond_block__with_optionally_return_value >> -(tokenLRASSIGN >> ident >> -index_action);

/* Вхід/Вихід */
input_rule = tokenGET >> (ident >> -index_action | tokenGROUPEXPRESSIONBEGIN >> ident >> -index_action >> tokenGROUPEXPRESSIONEND);
output_rule = tokenPUT >> expression;

/* ВИПРАВЛЕНО: Statement з опціональними крапками з комою */
statement = bind_left_to_right >> -tokenSEMICOLON
| cond_block__with_optionally_return_value_and_optionally_bind
| labeled_point
| goto_label >> -tokenSEMICOLON
| input_rule >> -tokenSEMICOLON
| output_rule >> -tokenSEMICOLON
| tokenSEMICOLON;

block_statements = tokenBEGINBLOCK >> *statement >> tokenENDBLOCK;
block_statements__with_optionally_return_value = tokenBEGINBLOCK >> *statement >> -expression >> tokenENDBLOCK;

/* Main Program Rule - крапка з комою після declaration тепер опціональна */
program_rule = BOUNDARIES >> tokenNAME >> tokenDATA >> (-declaration) >> -tokenSEMICOLON >> tokenBODY >> *statement >> tokenEND;

/* Значення та цифри */
value = -sign >> unsigned_value >> BOUNDARIES;

sign = sign_plus | sign_minus;
sign_plus = SAME_RULE(tokenPLUS);
sign_minus = SAME_RULE(tokenMINUS);

unsigned_value = ((non_zero_digit >> *digit) | digit_0) >> BOUNDARIES;

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

tokenUNDERSCORE = "_";

/* Оновлений ident згідно шаблону (letter_in_lower_case >> letter_in_lower_case >> digit) */
ident = letter_in_lower_case >> letter_in_lower_case >> digit >> STRICT_BOUNDARIES;

a = "a";
b = "b";
c = "c";
d = "d";
e = "e";
f = "f";
g = "g";
h = "h";
i = "i";
j = "j";
k = "k";
l = "l";
m = "m";
n = "n";
o = "o";
p = "p";
q = "q";
r = "r";
s = "s";
t = "t";
u = "u";
v = "v";
w = "w";
x = "x";
y = "y";
z = "z";

letter_in_lower_case = a | b | c | d | e | f | g | h | i | j | k | l | m | n | o | p | q | r | s | t | u | v | w | x | y | z;


STRICT_BOUNDARIES = (BOUNDARY >> *(BOUNDARY)) | (!(qi::alpha | qi::char_("_")));
BOUNDARIES = (BOUNDARY >> *(BOUNDARY) | NO_BOUNDARY);
BOUNDARY = BOUNDARY__SPACE | BOUNDARY__TAB | BOUNDARY__VERTICAL_TAB | BOUNDARY__FORM_FEED | BOUNDARY__CARRIAGE_RETURN | BOUNDARY__LINE_FEED | BOUNDARY__NULL;

/* Mapping template boundary names to original structure names if needed, or defining new ones */
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