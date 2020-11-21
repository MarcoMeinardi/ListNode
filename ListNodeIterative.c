#include "ListNodeIterative.h"


// -----------------------------------------------------------------------------------------
// Constructors

struct ListNode* from_array (int* arr, int dim) {
    struct ListNode* head = NULL;
    while (dim--) {
        head = push_front (head, arr[dim]);
    }
    return head;
}

struct ListNode* create (int dim, ...) {
    va_list nodes;
    va_start (nodes, dim);
    struct ListNode* head = (struct ListNode*)malloc (sizeof (struct ListNode));
    head->next = NULL;
    struct ListNode* cp = head;
    
    while (dim--) {
        head->next = (struct ListNode*)malloc (sizeof (struct ListNode));
        head->next->val = va_arg (nodes, int);
        head->next->next = NULL;
        head = head->next;
    }
    va_end (nodes);

    struct ListNode* foo = cp;
    cp = cp->next;
    free (foo);
    return cp;
}

struct ListNode* random_list (int dim, int range_start, int range_end) {
    struct ListNode* head = (struct ListNode*)malloc (sizeof (struct ListNode));
    struct ListNode* res = head;
    while (dim--) {
        head->next = push_front (head->next, rand() % (range_end - range_start) + range_start);
        head = head->next;
    }
    struct ListNode* cp = res->next;
    free (res);
    return cp;
}


struct ListNode* clone (struct ListNode* head) {
    struct ListNode* res = (struct ListNode*)malloc (sizeof (struct ListNode));
    res->next = NULL;
    struct ListNode* cp = res;
    while (head) {
        res->next = (struct ListNode*)malloc (sizeof (struct ListNode));
        res->next->val = head->val;
        res->next->next = NULL;
        res = res->next;
        head = head->next;
    }
    struct ListNode* foo = cp;
    cp = cp->next;
    free (foo);
    return cp;
}

struct ListNode* copy (struct ListNode* head, int start, int quantity) {
    if (quantity < 0 || start < 0) {
        return NULL;
    }

    while (head && start--) {
        head = head->next;
    }
    struct ListNode* res = (struct ListNode*)malloc (sizeof (struct ListNode));
    res->next = NULL;
    struct ListNode* cp = res;
    while (head && quantity--) {
        res->next = (struct ListNode*)malloc (sizeof (struct ListNode));
        res->next->val = head->val;
        res->next->next = NULL;
        res = res->next;
        head = head->next;
    }
    struct ListNode* foo = cp;
    cp = cp->next;
    free (foo);
    return cp;
}

// -----------------------------------------------------------------------------------------
// Add

struct ListNode* push_front (struct ListNode* head, int val) {
    struct ListNode* new_node = (struct ListNode*)malloc (sizeof (struct ListNode));
    new_node->val = val;
    new_node->next = head;
    return new_node;
}

struct ListNode* push_back (struct ListNode* head, int val) {
    if (!head) {
        return push_front (head, val);
    }
    
    struct ListNode* cp = head;
    while (head->next) {
        head = head->next;
    }
    head->next = push_front (head->next, val);
    return cp;
}

struct ListNode* push (struct ListNode* head, int val, int ind) {
    if (!head && ind != 0) {
        return NULL;
    }

    if (ind == 0) {
        return push_front (head, val);
    }
    struct ListNode* cp = head;
    while (ind > 1 && head) {
        head = head->next;
        ind--;
    }
    if (head) {
        head->next = push_front (head->next, val);
    }
    return cp;
}

// -----------------------------------------------------------------------------------------
// Remove

struct ListNode* pop_back (struct ListNode* head) {
    if (!head || !head->next) {
        return NULL;
    }

    struct ListNode* cp = head;
    while (head->next->next) {
        head = head->next;
    }
    free (head->next);
    head->next = NULL;
    return cp;
}

struct ListNode* pop_front (struct ListNode* head) {
    if (!head) {
        return NULL;
    }

    struct ListNode* foo = head;
    head = head->next;
    free (foo);
    return head;
}

struct ListNode* pop (struct ListNode* head, int ind) {
    if (!head) {
        return NULL;
    }
    
    struct ListNode* cp = head;

    if (ind == 0) {
        return pop_front (head);
    }

    while (head->next && ind-- > 1) {
        head = head->next;
    }
    if (ind == 0) {
        head->next = pop_front (head->next);
    }
    return cp;
}

void delete (struct ListNode* head) {
    struct ListNode* foo;
    while (head) {
        foo = head;
        head = head->next;
        free (foo);
    }
}

// -----------------------------------------------------------------------------------------
// Utils

void print (struct ListNode* head) {
    while (head) {
        printf ("%d ", head->val);
        head = head->next;
    }
    printf ("\n");
}

struct ListNode* find (struct ListNode* head, int target) {
    while (head && head->val != target) {
        head = head->next;
    }
    return head;
}

int size (struct ListNode* head) {
    int n = 0;
    while (head) {
        head = head->next;
        n++;
    }
    return n;
}

int* to_array (struct ListNode* head, int* dim) {
    int* res = NULL;
    *dim = size (head);
    res = malloc (*dim * sizeof (int));
    int ind = 0;

    while (head) {
        res[ind] = head->val;
        ind++;
        head = head->next;
    }
    return res;
}

struct ListNode* reverse (struct ListNode* head) {
    if (!head) {
        return NULL;
    }
    struct ListNode* first = head;
    while (head->next) {
        struct ListNode* cp = head->next;
        head->next = head->next->next;
        cp->next = first;
        first = cp;
    }
    return first;
}

struct ListNode* merge (struct ListNode* a, struct ListNode* b, int dim) {
    struct ListNode* cp = copy (a, 0, dim);
    int n1 = 0, n2 = 0;
    while ((b && n2 < dim) || (n1 < dim && a)) {
        if ((b && n2 < dim) && (n1 >= dim || b->val < cp->val)) {
            a->val = b->val;
            b = b->next;
            n2++;
        } else {
            a->val = cp->val;
            cp = cp->next;
            n1++;
        }
        a = a->next;
    }
    return a;
}
struct ListNode* sort (struct ListNode* head) {
    if (!head) {
        return NULL;
    }

    int n = size (head);
    struct ListNode* ori = head;
    for (int dim = 1; dim < n; dim *= 2) {
        head = ori;
        for (int i = 0; i < n; i += dim * 2) {
            struct ListNode* right = head;
            int j = 0;
            while (right && j++ < dim) {
                right = right->next;
            }
            head = merge (head, right, dim);
        }
    }
    return ori;
}