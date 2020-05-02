typedef struct Node {
    uint32_t val;
    struct Node *next;
} NodeType;

uint8_t insertNode(NodeType **head, uint32_t val)
{
    NodeType **iter = head;
    NodeType  *node;

    if (NULL == iter) {
        return -1;
    }

    node = (NodeType *) malloc(sizeof(NodeType));

    if (NULL == node) {
        return -1;
    }

    node->val = val;
    node->next = NULL;

    while (NULL != *iter) {
        if (*iter->val >= val) {
            node->next = *iter;
            *iter = node;
            return 0;
        }

        iter = &((*iter)->next);
    }

    *iter = node;
    return 0;
}

NodeType *insertNode(NodeType *head, int val, int8_t *status)
{
    NodeType *prev = NULL;
    NodeType *iter = head;
    NodeType *new_node = (NodeType *) malloc(sizeof(NodeType));

    if (new_node != NULL) {
        *status = 0;
        new_node->val  = val;
        new_node->next = NULL;

        if (NULL == iter) {
            return node;
        }

        while (NULL != iter) {
            if (iter->val < val) {
                prev = iter
            } else {
                new_node->next = iter;

                if (NULL == prev) {
                    return new_node;
                } else {
                    prev->next = new_node;
                    return head;
                }
            }

            iter = iter->next;
        }

        prev->next = new_node;
    } else {
        *status = -1;
    }

    return head;
}