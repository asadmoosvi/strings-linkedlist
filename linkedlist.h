struct node {
    char *data;
    struct node *next;
};

typedef struct node node_t;

struct list {
    node_t *head;
    size_t size;
};

typedef struct list list_t;

node_t *init_node(const char *data);
void destroy_node(node_t *node);
void node_print(node_t *node);

list_t *init_list(void);
void list_destroy(list_t *list);
void list_push(list_t *list, const char *data);
void list_pop(list_t *list, char *buf);
void list_print(list_t *list);
int list_find(list_t *list , const char *data);
