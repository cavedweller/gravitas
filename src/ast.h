// Definitions
typedef enum ast_node_type_e {
    AST_TYPE_NUMBER,
    AST_TYPE_VARIABLE,
    AST_TYPE_BINARY_EXPR,
    AST_TYPE_CALL,
    AST_TYPE_PROTOTYPE,
    AST_TYPE_FUNCTION,
} ast_node_type_e;

struct ast_node;

typedef struct ast_number {
    double value;
} ast_number;

typedef struct ast_variable {
    char *name;
} ast_variable;

typedef struct ast_binary_expr {
    char op;
    struct ast_node *lhs;
    struct ast_node *rhs;
} ast_binary_expr;

typedef struct ast_call {
    char *callee;
    struct ast_node **args;
    int arg_count;
} ast_call;


typedef struct ast_prototype {
    char *name;
    char **args;
    int arg_count;
} ast_prototype;


typedef struct ast_function {
    struct ast_node *prototype;
    struct ast_node *body;
} ast_function;


typedef struct ast_node {
    ast_node_type_e type;
    union {
        ast_number number;
        ast_variable variable;
        ast_binary_expr binary_expr;
        ast_call call;
        ast_prototype prototype;
        ast_function function;
    };
} ast_node;

// Functions
ast_node *ast_number_create(double value);
ast_node *ast_variable_create(char *name);
ast_node *ast_binary_expr_create(char op, ast_node *lhs, ast_node *rhs);
ast_node *ast_call_create(char *callee, ast_node **args, int arg_count);
ast_node *ast_prototype_create(char *name, char **args, int arg_count);
ast_node *ast_function_create(ast_node *prototype, ast_node *body);
void ast_node_free(ast_node *node);