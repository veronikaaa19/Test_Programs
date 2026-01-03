/*
LL(2) ГРАМАТИКА, АДАПТОВАНА ПІД ЛЕКСИКУ РБНФ (Mainprogram/Start/Input/->/Eg/!!)
ВИПРАВЛЕНО: Додано T_ASSIGN_0, T_ELSE_0, нові правила Else If, прибрано body_for_false__optional
*/

#define COMMENT_BEGIN_STR "#*"
#define COMMENT_END_STR "*#"
#define TOKENS_RE "!!|\\|\\||&&|;|->|\\+|-|Mul|,|Eg|Ne|:|\\[|\\]|\\(|\\)|\\{|\\}|<|>|[_0-9A-Za-z]+|[^ \t\r\f\v\n]"
#define KEYWORDS_RE "Mainprogram|Data|Start|End|Input|Output|If|Else|Goto|Div|Mod|Int16_t|;|->|\\+|-|Mul|,|Eg|Ne|:|\\[|\\]|\\(|\\)|\\{|\\}|<|>|!!|&&|\\|\\|"
#define IDENTIFIERS_RE "[a-z][a-z][0-9]"
#define UNSIGNEDVALUES_RE "0|[1-9][0-9]*"

#define T_BEGIN_GROUPEXPRESSION_0 "("
#define T_BEGIN_GROUPEXPRESSION_1 ""
#define T_BEGIN_GROUPEXPRESSION_2 ""
#define T_BEGIN_GROUPEXPRESSION_3 ""
#define T_END_GROUPEXPRESSION_0 ")"
#define T_END_GROUPEXPRESSION_1 ""
#define T_END_GROUPEXPRESSION_2 ""
#define T_END_GROUPEXPRESSION_3 ""
#define T_LEFT_SQUAREBRACKETS_0 "["
#define T_LEFT_SQUAREBRACKETS_1 ""
#define T_LEFT_SQUAREBRACKETS_2 ""
#define T_LEFT_SQUAREBRACKETS_3 ""
#define T_RIGHT_SQUAREBRACKETS_0 "]"
#define T_RIGHT_SQUAREBRACKETS_1 ""
#define T_RIGHT_SQUAREBRACKETS_2 ""
#define T_RIGHT_SQUAREBRACKETS_3 ""
#define T_BEGIN_BLOCK_0 "{"
#define T_BEGIN_BLOCK_1 ""
#define T_BEGIN_BLOCK_2 ""
#define T_BEGIN_BLOCK_3 ""
#define T_END_BLOCK_0 "}"
#define T_END_BLOCK_1 ""
#define T_END_BLOCK_2 ""
#define T_END_BLOCK_3 ""
#define T_SEMICOLON_0 ";"
#define T_SEMICOLON_1 ""
#define T_SEMICOLON_2 ""
#define T_SEMICOLON_3 ""
#define T_COLON_0 ":"
#define T_COLON_1 ""
#define T_COLON_2 ""
#define T_COLON_3 ""

#define T_GOTO_0 "Goto"
#define T_GOTO_1 ""
#define T_GOTO_2 ""
#define T_GOTO_3 ""

#define T_DATA_TYPE_0 "Int16_t"
#define T_DATA_TYPE_1 ""
#define T_DATA_TYPE_2 ""
#define T_DATA_TYPE_3 ""

#define T_COMA_0 ","
#define T_COMA_1 ""
#define T_COMA_2 ""
#define T_COMA_3 ""

/* Логічні операції */
#define T_BITWISE_NOT_0 "!!"
#define T_BITWISE_NOT_1 ""
#define T_BITWISE_NOT_2 ""
#define T_BITWISE_NOT_3 ""
#define T_NOT_0 "!!"
#define T_NOT_1 ""
#define T_NOT_2 ""
#define T_NOT_3 ""
#define T_BITWISE_AND_0 "&&"
#define T_BITWISE_AND_1 ""
#define T_BITWISE_AND_2 ""
#define T_BITWISE_AND_3 ""
#define T_AND_0 "&&"
#define T_AND_1 ""
#define T_AND_2 ""
#define T_AND_3 ""
#define T_BITWISE_OR_0 "||"
#define T_BITWISE_OR_1 ""
#define T_BITWISE_OR_2 ""
#define T_BITWISE_OR_3 ""
#define T_OR_0 "||"
#define T_OR_1 ""
#define T_OR_2 ""
#define T_OR_3 ""

/* Порівняння */
#define T_EQUAL_0 "Eg"
#define T_EQUAL_1 ""
#define T_EQUAL_2 ""
#define T_EQUAL_3 ""
#define T_NOT_EQUAL_0 "Ne"
#define T_NOT_EQUAL_1 ""
#define T_NOT_EQUAL_2 ""
#define T_NOT_EQUAL_3 ""
#define T_LESS_0 "<"
#define T_LESS_1 ""
#define T_LESS_2 ""
#define T_LESS_3 ""
#define T_GREATER_0 ">"
#define T_GREATER_1 ""
#define T_GREATER_2 ""
#define T_GREATER_3 ""

/* Арифметика */
#define T_ADD_0 "+"
#define T_ADD_1 ""
#define T_ADD_2 ""
#define T_ADD_3 ""
#define T_SUB_0 "-"
#define T_SUB_1 ""
#define T_SUB_2 ""
#define T_SUB_3 ""
#define T_MUL_0 "Mul"
#define T_MUL_1 ""
#define T_MUL_2 ""
#define T_MUL_3 ""
#define T_DIV_0 "Div"
#define T_DIV_1 ""
#define T_DIV_2 ""
#define T_DIV_3 ""
#define T_MOD_0 "Mod"
#define T_MOD_1 ""
#define T_MOD_2 ""
#define T_MOD_3 ""

/* Присвоєння */
#define T_ASSIGN_0 "->"
#define T_ASSIGN_1 ""
#define T_ASSIGN_2 ""
#define T_ASSIGN_3 ""
#define T_LRASSIGN_0 "->"
#define T_LRASSIGN_1 ""
#define T_LRASSIGN_2 ""
#define T_LRASSIGN_3 ""

/* Умови */
#define T_THEN_BLOCK_0 "{"
#define T_THEN_BLOCK_1 ""
#define T_THEN_BLOCK_2 ""
#define T_THEN_BLOCK_3 ""
#define T_ELSE_0 "Else"
#define T_ELSE_1 ""
#define T_ELSE_2 ""
#define T_ELSE_3 ""
#define T_ELSE_BLOCK_0 "Else"
#define T_ELSE_BLOCK_1 T_BEGIN_BLOCK_0
#define T_ELSE_BLOCK_2 ""
#define T_ELSE_BLOCK_3 ""
#define T_IF_0 "If"
#define T_IF_1 ""
#define T_IF_2 ""
#define T_IF_3 ""
#define T_ELSE_IF_0 "Else"
#define T_ELSE_IF_1 T_IF_0
#define T_ELSE_IF_2 ""
#define T_ELSE_IF_3 ""

/* Завершення */
#define T_EXIT_0 "End"
#define T_EXIT_1 "" 
#define T_EXIT_2 "" 
#define T_EXIT_3 ""

/* Ввід/Вивід */
#define T_INPUT_0 "Input"
#define T_INPUT_1 ""
#define T_INPUT_2 ""
#define T_INPUT_3 ""
#define T_OUTPUT_0 "Output"
#define T_OUTPUT_1 ""
#define T_OUTPUT_2 ""
#define T_OUTPUT_3 ""

/* Структура програми */
#define T_NAME_0 "Mainprogram"
#define T_NAME_1 ""
#define T_NAME_2 ""
#define T_NAME_3 ""

#define T_BODY_0 "Start"
#define T_BODY_1 ""
#define T_BODY_2 ""
#define T_BODY_3 ""

#define T_DATA_0 "Data"
#define T_DATA_1 ""
#define T_DATA_2 ""
#define T_DATA_3 ""

#define T_BEGIN_0 "Start"
#define T_BEGIN_1 ""
#define T_BEGIN_2 ""
#define T_BEGIN_3 ""

#define T_END_0 "End"
#define T_END_1 ""
#define T_END_2 ""
#define T_END_3 ""

#define T_NULL_STATEMENT_0 "NULL"
#define T_NULL_STATEMENT_1 "STATEMENT"
#define T_NULL_STATEMENT_2 ""
#define T_NULL_STATEMENT_3 ""


#define GRAMMAR_LL2__2025 {\
/* 1. labeled_point: ident : */\
{ LA_IS, {"ident_terminal"}, { "labeled_point",{\
    { LA_IS, {T_COLON_0}, 2, {"ident", T_COLON_0}}\
}}},\
\
/* 2. goto_label: Goto ident */\
{ LA_IS, {T_GOTO_0}, { "goto_label",{\
    { LA_IS, {""}, 2, {T_GOTO_0, "ident"}}\
}}},\
\
/* 3. program_name: ident */\
{ LA_IS, {"ident_terminal"}, { "program_name",{\
    { LA_IS, {""}, 1, {"ident"}}\
}}},\
\
/* 4. value_type: Int16_t */\
{ LA_IS, {T_DATA_TYPE_0}, { "value_type",{\
    { LA_IS, {""}, 1, {T_DATA_TYPE_0}}\
}}},\
\
/* 5. array_specify: [ unsigned_value ] */\
{ LA_IS, {T_LEFT_SQUAREBRACKETS_0}, { "array_specify",{\
    { LA_IS, {""}, 3, {T_LEFT_SQUAREBRACKETS_0, "unsigned_value", T_RIGHT_SQUAREBRACKETS_0}}\
}}},\
\
/* 6. declaration_element: ident array_specify__optional */\
{ LA_IS, {"ident_terminal"}, { "declaration_element",{\
    { LA_IS, {""}, 2, {"ident", "array_specify__optional"}}\
}}},\
\
/* 7. array_specify__optional: array_specify | epsilon */\
{ LA_IS, {T_LEFT_SQUAREBRACKETS_0}, { "array_specify__optional",{\
    { LA_IS, {""}, 1, {"array_specify"}}\
}}},\
{ LA_NOT, {T_LEFT_SQUAREBRACKETS_0}, { "array_specify__optional",{\
    { LA_IS, {""}, 0, {""}}\
}}},\
\
/* 8. other_declaration_ident: , declaration_element */\
{ LA_IS, {T_COMA_0}, { "other_declaration_ident",{\
    { LA_IS, {""}, 2, {T_COMA_0, "declaration_element"}}\
}}},\
\
/* 9. declaration: value_type declaration_element other_declaration_ident__iteration */\
{ LA_IS, {T_DATA_TYPE_0}, { "declaration",{\
    { LA_IS, {""}, 3, {"value_type", "declaration_element", "other_declaration_ident__iteration"}}\
}}},\
\
/* 10. other_declaration_ident__iteration: other_declaration_ident other_declaration_ident__iteration | epsilon */\
{ LA_IS, { T_COMA_0 }, { "other_declaration_ident__iteration",{\
    { LA_IS, {""}, 2, { "other_declaration_ident", "other_declaration_ident__iteration" }}\
}}},\
{ LA_NOT, { T_COMA_0 }, { "other_declaration_ident__iteration",{\
    { LA_IS, {""}, 0, { "" }}\
}}},\
\
/* 11. index_action: [ expression ] */\
{ LA_IS, { T_LEFT_SQUAREBRACKETS_0 }, { "index_action",{\
    { LA_IS, {""}, 3, { T_LEFT_SQUAREBRACKETS_0, "expression", T_RIGHT_SQUAREBRACKETS_0 }}\
}}},\
\
/* 12. unary_operator: !! */\
{ LA_IS, { T_NOT_0 }, { "unary_operator",{\
    { LA_IS, {""}, 1, { T_NOT_0 }}\
}}},\
\
/* 13. unary_operation: unary_operator expression */\
{ LA_IS, { T_NOT_0 }, { "unary_operation",{\
    { LA_IS, {""}, 2, { "unary_operator", "expression" }}\
}}},\
\
/* 14. binary_operator: && | || | Eg | Ne | < | > | + | - | Mul | Div | Mod */\
{ LA_IS, { T_AND_0 }, { "binary_operator",{\
    { LA_IS, {""}, 1, { T_AND_0 }}\
}}},\
{ LA_IS, { T_OR_0 }, { "binary_operator",{\
    { LA_IS, {""}, 1, { T_OR_0 }}\
}}},\
{ LA_IS, { T_EQUAL_0 }, { "binary_operator",{\
    { LA_IS, {""}, 1, { T_EQUAL_0 }}\
}}},\
{ LA_IS, { T_NOT_EQUAL_0 }, { "binary_operator",{\
    { LA_IS, {""}, 1, { T_NOT_EQUAL_0 }}\
}}},\
{ LA_IS, { T_LESS_0 }, { "binary_operator",{\
    { LA_IS, {""}, 1, { T_LESS_0 }}\
}}},\
{ LA_IS, { T_GREATER_0 }, { "binary_operator",{\
    { LA_IS, {""}, 1, { T_GREATER_0 }}\
}}},\
{ LA_IS, { T_ADD_0 }, { "binary_operator",{\
    { LA_IS, {""}, 1, { T_ADD_0 }}\
}}},\
{ LA_IS, { T_SUB_0 }, { "binary_operator",{\
    { LA_IS, {""}, 1, { T_SUB_0 }}\
}}},\
{ LA_IS, { T_MUL_0 }, { "binary_operator",{\
    { LA_IS, {""}, 1, { T_MUL_0 }}\
}}},\
{ LA_IS, { T_DIV_0 }, { "binary_operator",{\
    { LA_IS, {""}, 1, { T_DIV_0 }}\
}}},\
{ LA_IS, { T_MOD_0 }, { "binary_operator",{\
    { LA_IS, {""}, 1, { T_MOD_0 }}\
}}},\
\
/* 15. binary_action: binary_operator expression */\
{ LA_IS, { T_AND_0, T_OR_0, T_EQUAL_0, T_NOT_EQUAL_0, T_LESS_0, T_GREATER_0, T_ADD_0, T_SUB_0, T_MUL_0, T_DIV_0, T_MOD_0 }, { "binary_action",{\
    { LA_IS, {""}, 2, { "binary_operator", "expression" }}\
}}},\
\
/* 16. left_expression: (expression) | unary_operation | value | ident index_action__optional */\
{LA_IS, { T_BEGIN_GROUPEXPRESSION_0 }, { "left_expression",{\
    {LA_IS, { "" }, 1, { "group_expression" }}\
}}},\
{LA_IS, { T_NOT_0 }, { "left_expression",{\
    {LA_IS, { "" }, 1, { "unary_operation" }}\
}}},\
{LA_IS, { "unsigned_value_terminal" }, { "left_expression",{\
    {LA_IS, {""}, 1, { "value" }}\
}}},\
{LA_IS, { T_ADD_0, T_SUB_0 }, { "left_expression",{\
    {LA_IS, { "unsigned_value_terminal"}, 1, { "value" }}\
}}},\
{LA_IS, { "ident_terminal" }, { "left_expression",{\
    {LA_IS, {""}, 2, { "ident", "index_action__optional" }}\
}}},\
\
/* 17. index_action__optional: index_action | epsilon */\
{LA_IS, { T_LEFT_SQUAREBRACKETS_0 }, { "index_action__optional",{\
    {LA_IS, {""}, 1, { "index_action" }}\
}}},\
{LA_NOT, { T_LEFT_SQUAREBRACKETS_0 }, { "index_action__optional",{\
    {LA_IS, {""}, 0, { "" }}\
}}},\
\
/* 18. expression: left_expression binary_action__iteration */\
{LA_IS, { T_BEGIN_GROUPEXPRESSION_0, T_NOT_0, T_ADD_0, T_SUB_0, "ident_terminal", "unsigned_value_terminal" }, { "expression",{\
    {LA_IS, {""}, 2, { "left_expression", "binary_action__iteration" }}\
}}},\
\
/* 19. binary_action__iteration: binary_action binary_action__iteration | epsilon */\
{LA_IS, { T_AND_0, T_OR_0, T_EQUAL_0, T_NOT_EQUAL_0, T_LESS_0, T_GREATER_0, T_ADD_0, T_SUB_0, T_MUL_0, T_DIV_0, T_MOD_0 }, { "binary_action__iteration",{\
    {LA_IS, {""}, 2, { "binary_action", "binary_action__iteration" }}\
}}},\
{LA_NOT, { T_AND_0, T_OR_0, T_EQUAL_0, T_NOT_EQUAL_0, T_LESS_0, T_GREATER_0, T_ADD_0, T_SUB_0, T_MUL_0, T_DIV_0, T_MOD_0 }, { "binary_action__iteration",{\
    {LA_IS, {""}, 0, { "" }}\
}}},\
\
/* 20. group_expression: ( expression ) */\
{LA_IS, { T_BEGIN_GROUPEXPRESSION_0 }, { "group_expression",{\
    {LA_IS, {""}, 3, { T_BEGIN_GROUPEXPRESSION_0, "expression", T_END_GROUPEXPRESSION_0 }}\
}}},\
\
/* 21. expression_or_cond_block__with_optional_assign: expression assign_to_right__optional */\
{LA_IS, { T_BEGIN_GROUPEXPRESSION_0, T_NOT_0, T_ADD_0, T_SUB_0, "ident_terminal", "unsigned_value_terminal" }, { "expression_or_cond_block__with_optional_assign",{\
    {LA_IS, {""}, 2, { "expression", "assign_to_right__optional" }}\
}}},\
\
/* 22. assign_to_right: -> ident index_action__optional */\
{LA_IS, { T_ASSIGN_0 }, { "assign_to_right",{\
    {LA_IS, {""}, 3, { T_ASSIGN_0, "ident", "index_action__optional" }}\
}}},\
\
/* 23. assign_to_right__optional: assign_to_right | epsilon */\
{LA_IS, { T_ASSIGN_0 }, { "assign_to_right__optional",{\
    { LA_IS, {""}, 1, { "assign_to_right" }}\
}}},\
{LA_NOT, { T_ASSIGN_0 }, { "assign_to_right__optional",{\
    {LA_IS, {""}, 0, { "" }}\
}}},\
\
/* 24. if_expression: expression */\
{LA_IS, { T_BEGIN_GROUPEXPRESSION_0, T_NOT_0, T_ADD_0, T_SUB_0, "ident_terminal", "unsigned_value_terminal" }, { "if_expression",{\
    {LA_IS, {""}, 1, { "expression" }}\
}}},\
\
/* 25. body_for_true: block_statements */\
{LA_IS, { T_BEGIN_BLOCK_0 }, { "body_for_true",{\
    {LA_IS, {""}, 1, { "block_statements" }}\
}}},\
\
/* 26. else_if_chain: Else If if_expression body_for_true else_part__optional */\
{ LA_IS, { T_ELSE_0 }, { "else_if_chain",{\
    /* другий lookahead: наступний токен має бути If */\
    { LA_IS, { T_IF_0 }, 5, { T_ELSE_0, T_IF_0, "if_expression", "body_for_true", "else_part__optional" }}\
}}},\
\
/* 27. body_for_false: Else block_statements */\
{ LA_IS, { T_ELSE_0 }, { "body_for_false",{\
    /* другий lookahead: наступний токен НЕ повинен бути If */\
    { LA_NOT, { T_IF_0 }, 2, { T_ELSE_0, "block_statements" }}\
}}},\
\
/* 28. cond_block: If if_expression body_for_true else_part__optional */\
{ LA_IS, { T_IF_0 }, { "cond_block",{\
    { LA_IS, {""}, 4, { T_IF_0, "if_expression", "body_for_true", "else_part__optional" }}\
}}},\
\
/* 29. else_part__optional: else_if_chain | body_for_false | epsilon */\
{ LA_IS, { T_ELSE_0 }, { "else_part__optional",{\
    /* If після Else ? це else_if_chain */\
    { LA_IS,  { T_IF_0 }, 1, { "else_if_chain" }},\
    /* НЕ If після Else ? звичайний Else { ... } */\
    { LA_NOT, { T_IF_0 }, 1, { "body_for_false" }}\
}}},\
{ LA_NOT, { T_ELSE_0 }, { "else_part__optional",{\
    /* немає Else ? порожня гілка */\
    { LA_IS, {""}, 0, { "" }}\
}}},\
\
/* 31. input_rule: Input argument_for_input */\
{LA_IS, { T_INPUT_0 }, { "input_rule",{\
    {LA_IS, {""}, 2, { T_INPUT_0, "argument_for_input" }}\
}}},\
\
/* 32. argument_for_input: ident index_action__optional | ( ident index_action__optional ) */\
{LA_IS, { "ident_terminal" }, { "argument_for_input",{\
    {LA_IS, {""}, 2, { "ident", "index_action__optional" }}\
}}},\
{LA_IS, { T_BEGIN_GROUPEXPRESSION_0 }, { "argument_for_input",{\
    {LA_IS, {""}, 4, { T_BEGIN_GROUPEXPRESSION_0, "ident", "index_action__optional", T_END_GROUPEXPRESSION_0 }}\
}}},\
\
/* 33. output_rule: Output expression */\
{LA_IS, { T_OUTPUT_0 }, { "output_rule", {\
    {LA_IS, { T_BEGIN_GROUPEXPRESSION_0, T_NOT_0, T_ADD_0, T_SUB_0, "ident_terminal", "unsigned_value_terminal" }, 2, {T_OUTPUT_0, "expression"} }\
}}},\
\
/* 34. statement: labeled_point | expression_or_cond_block__with_optional_assign | goto_label | input_rule | output_rule | cond_block | ; */\
{LA_IS, { "ident_terminal" }, { "statement", {\
    { LA_IS, { T_COLON_0 }, 1, {"labeled_point"}},\
    { LA_NOT, { T_COLON_0 }, 1, {"expression_or_cond_block__with_optional_assign"}}\
}}},\
{LA_IS, { T_BEGIN_GROUPEXPRESSION_0, T_NOT_0, "unsigned_value_terminal", T_ADD_0, T_SUB_0 }, { "statement", {\
    { LA_IS, {""}, 1, {"expression_or_cond_block__with_optional_assign"}}\
}}},\
{LA_IS, { T_GOTO_0 }, { "statement",{\
    {LA_IS, {""}, 1, {"goto_label"}}\
}}},\
{LA_IS, { T_INPUT_0 }, { "statement",{\
    {LA_IS, {""}, 1, {"input_rule"}}\
}}},\
{LA_IS, { T_OUTPUT_0 }, { "statement",{\
    {LA_IS, {""}, 1, {"output_rule"}}\
}}},\
{LA_IS, { T_IF_0 }, { "statement",{\
    {LA_IS, {""}, 1, {"cond_block"}}\
}}},\
{LA_IS, { T_SEMICOLON_0 }, { "statement",{\
    {LA_IS, {""}, 1, {T_SEMICOLON_0}}\
}}},\
\
/* 35. statement__iteration: statement statement__iteration | epsilon */\
{ LA_IS, { "ident_terminal", T_BEGIN_GROUPEXPRESSION_0, T_NOT_0, "unsigned_value_terminal", T_ADD_0, T_SUB_0, T_IF_0, T_GOTO_0, T_INPUT_0, T_OUTPUT_0, T_SEMICOLON_0 }, { "statement__iteration",{\
    { LA_IS, {""}, 2, { "statement", "statement__iteration" }}\
}}},\
{ LA_NOT, { "ident_terminal", T_BEGIN_GROUPEXPRESSION_0, T_NOT_0, "unsigned_value_terminal", T_ADD_0, T_SUB_0, T_IF_0, T_GOTO_0, T_INPUT_0, T_OUTPUT_0, T_SEMICOLON_0 }, { "statement__iteration",{\
    { LA_IS, {""}, 0, { "" }}\
}}},\
\
/* 36. block_statements: { statement__iteration } */\
{ LA_IS, { T_BEGIN_BLOCK_0 }, { "block_statements",{\
    { LA_IS, {""}, 3, { T_BEGIN_BLOCK_0, "statement__iteration", T_END_BLOCK_0 }}\
}}},\
\
/* 37. expression__optional: expression | epsilon */\
{LA_IS, { T_BEGIN_GROUPEXPRESSION_0, T_NOT_0, T_ADD_0, T_SUB_0, "ident_terminal", "unsigned_value_terminal" }, { "expression__optional",{\
    {LA_IS, {""}, 1, { "expression" }}\
}}},\
{LA_NOT, { T_BEGIN_GROUPEXPRESSION_0, T_NOT_0, T_ADD_0, T_SUB_0, "ident_terminal", "unsigned_value_terminal" }, { "expression__optional",{\
    {LA_IS, {""}, 0, { "" }}\
}}},\
\
/* 38. program_rule: Mainprogram Data declaration__optional ; Start statement__iteration End */\
{ LA_IS, { T_NAME_0 }, { "program_rule",{\
    { LA_IS, {""}, 7, { T_NAME_0, T_DATA_0, "declaration__optional", T_SEMICOLON_0, T_BODY_0, "statement__iteration", T_END_0 }}\
}}},\
\
/* 39. declaration__optional: declaration | epsilon */\
{ LA_IS, { T_DATA_TYPE_0 }, { "declaration__optional",{\
    { LA_IS, {""}, 1, { "declaration" }}\
}}},\
{ LA_NOT, { T_DATA_TYPE_0 }, { "declaration__optional",{\
    { LA_IS, {""}, 0, { "" }}\
}}},\
\
/* 40. value: sign__optional unsigned_value */\
{LA_IS, { "unsigned_value_terminal", T_ADD_0, T_SUB_0 }, { "value", {\
    {LA_IS, { "" }, 2, { "sign__optional", "unsigned_value" }}\
}}},\
\
/* 41. sign__optional: sign | epsilon */\
{LA_IS, { T_ADD_0, T_SUB_0 }, { "sign__optional", {\
    {LA_IS, { "" }, 1, { "sign" }}\
}}},\
{LA_NOT, { T_ADD_0, T_SUB_0 }, { "sign__optional",{\
    {LA_IS, { "" }, 0, { "" }}\
}}},\
\
/* 42. sign: sign_plus | sign_minus */\
{LA_IS, { T_ADD_0 }, { "sign", {\
    {LA_IS, {""}, 1, { "sign_plus" }}\
}}},\
{LA_IS, { T_SUB_0 }, { "sign", {\
    {LA_IS, {""}, 1, { "sign_minus" }}\
}}},\
\
/* 43. sign_plus: + */\
{LA_IS, { T_ADD_0 }, { "sign_plus", {\
    {LA_IS, {""}, 1, {T_ADD_0}}\
}}},\
\
/* 44. sign_minus: - */\
{LA_IS, { T_SUB_0 }, { "sign_minus", {\
    {LA_IS, {""}, 1, {T_SUB_0} }\
}}},\
\
/* 45. unsigned_value: unsigned_value_terminal */\
{LA_IS, { "unsigned_value_terminal" }, { "unsigned_value", {\
    {LA_IS, { "" }, 1, { "unsigned_value_terminal" }}\
}}},\
\
/* 46. ident: ident_terminal */\
{LA_IS, { "ident_terminal" }, { "ident", {\
    {LA_IS, {""}, 1, {"ident_terminal"} }\
}}},\
\
/* 47. program____part1: Mainprogram Data declaration_optional ; Start */\
{ LA_IS, { T_NAME_0 }, { "program____part1",{\
    { LA_IS, {""}, 5, { T_NAME_0, T_DATA_0, "declaration__optional", T_SEMICOLON_0, T_BODY_0}}\
}}},\
\
},\
"program_rule"
