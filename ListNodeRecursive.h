#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <time.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

// constructors
struct ListNode* from_array (int* arr, int dim);
struct ListNode* create (int dim, ...);
struct ListNode* random_list (int dim, int range_start, int range_end);
struct ListNode* clone (struct ListNode* head);
struct ListNode* copy (struct ListNode* head, int start, int quantity);

// add
struct ListNode* push_front (struct ListNode* head, int val);
struct ListNode* push_back (struct ListNode* head, int val);
struct ListNode* push (struct ListNode* head, int val, int ind);
void delete (struct ListNode* head);

// remove
struct ListNode* pop_back (struct ListNode* head);
struct ListNode* pop_front (struct ListNode* head) ;
struct ListNode* pop (struct ListNode* head, int ind);

// utils
struct ListNode* find (struct ListNode* head, int target);
void print (struct ListNode* head);
int size (struct ListNode* head);
int* to_array (struct ListNode* head, int* dim);
struct ListNode* reverse (struct ListNode* head);
struct ListNode* sort (struct ListNode* head);