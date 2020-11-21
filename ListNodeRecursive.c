#include "ListNodeIterative.h"


// -----------------------------------------------------------------------------------------
// Constructors

struct ListNode* from_array (var* arr, int dim) {
    struct ListNode* head = NULL;
    while (dim--) {
        head = push_front (head, arr[dim]);
    }
    return head;
}

struct ListNode* create_helper (struct ListNode* head, va_list nodes, int nodes_left) {
    if (nodes_left) {
        head = push_front (head, va_arg (nodes, var));
        head->next = create_helper (head->next, nodes, nodes_left - 1);
    }
    return head;
}
struct ListNode* create (int dim, ...) {
    va_list nodes;
    va_start (nodes, dim);
    struct ListNode* head = NULL;
    return create_helper (head, nodes, dim);
}

struct ListNode* random_list (int dim, var range_start, var range_end) {
    if (dim == 0) {
        return NULL;
    }
    struct ListNode* new_node = (struct ListNode*)malloc (sizeof (struct ListNode));
    new_node->val = rand() % (range_end - range_start) + range_start;
    new_node->next = random_list (dim - 1, range_start, range_end);
    return new_node;
}

struct ListNode* clone (struct ListNode* head) {
    if (!head) {
        return NULL;
    }
    struct ListNode* res = (struct ListNode*)malloc (sizeof (struct ListNode));
    res->val = head->val;
    res->next = clone (head->next);
    return res;
}

struct ListNode* copy (struct ListNode* head, int start, int quantity) {
    if (start < 0 || quantity <= 0 || !head) {
        return NULL;
    }
    if (start) {
        return copy (head->next, start - 1, quantity);
    }
    struct ListNode* res = (struct ListNode*)malloc (sizeof (struct ListNode));
    res->val = head->val;
    res->next = copy (head->next, start, quantity - 1);
    return res;
}

// -----------------------------------------------------------------------------------------
// Add

struct ListNode* push_front (struct ListNode* head, var val) {
    struct ListNode* new_node = (struct ListNode*)malloc (sizeof (struct ListNode));
    new_node->val = val;
    new_node->next = head;
    return new_node;
}

struct ListNode* push_back (struct ListNode* head, var val) {
    if (!head) {
        return push_front (head, val);
    }
    head->next = push_back (head->next, val);
    return head;
}

struct ListNode* push (struct ListNode* head, var val, int ind) {
    if (ind == 0) {
        return push_front (head, val);
    }
    if (!head) {
        return NULL;
    }
    head->next = push (head->next, val, ind - 1);
    return head;
}

// -----------------------------------------------------------------------------------------
// Remove

struct ListNode* pop_front (struct ListNode* head) {
    if (!head) {
        return NULL;
    }

    struct ListNode* foo = head;
    head = head->next;
    free (foo);
    return head;
}

struct ListNode* pop_back (struct ListNode* head) {
    if (!head) {
        return NULL;
    }
    if (!head->next) {
        return pop_front (head);
    }
    head->next = pop_back (head->next);
    return head;
}

struct ListNode* pop (struct ListNode* head, int ind) {
    if (!head) {
        return NULL;
    }
    if (ind == 0) {
        return pop_front (head);
    }
    head->next = pop (head->next, ind - 1);
    return head;
}

void delete (struct ListNode* head) {
    if (head) {
        delete (head->next);
        free (head);
    }
}

// -----------------------------------------------------------------------------------------
// Utils

void print (struct ListNode* head) {
    if (head) {
        printf ("%d ", head->val);
        print (head->next);
    } else {
        printf ("\n");
    }
}

struct ListNode* find (struct ListNode* head, var target) {
    if (!head) {
        return NULL;
    }
    if (head->val == target) {
        return head;
    }
    return find (head->next, target);
}

int size (struct ListNode* head) {
    if (head) {
        return 1 + size (head->next);
    } else {
        return 0;
    }
}

void to_array_helper (var* arr, struct ListNode* head) {
    if (head) {
        *arr = head->val;
        to_array_helper (arr + 1, head->next);
    }
}
var* to_array (struct ListNode* head, int* dim) {
    var* res = NULL;
    *dim = size (head);
    res = malloc (*dim * sizeof (var));
    to_array_helper (res, head);
    return res;
}

struct ListNode* reverse (struct ListNode* head) {
    if (!head) {
        return NULL;
    }
    if (!head->next) {
        return head;
    }

    struct ListNode* others = reverse (head->next);
    head->next->next = head;
    head->next = NULL;

    return others;
}

struct ListNode* merge (struct ListNode* a, struct ListNode* b) {
    if (!a) {
        return b;
    }
    if (!b) {
        return a;
    }

    if (a->val < b->val) {
        a->next = merge (a->next, b);
        return a;
    } else {
        b->next = merge (a, b->next);
        return b;
    }
}
struct ListNode* sort (struct ListNode* head) {
    if (!head) {
        return NULL;
    }
    if (!head->next) {
        return head;
    }
    struct ListNode* slow = head, * fast = head;
    while (1) {
        fast = fast->next->next;
        if (!fast || !fast->next) {
            break;
        }
        slow = slow->next;
    }
    struct ListNode* cp = slow->next;
    slow->next = NULL;
    return merge (sort (head), sort (cp));
}