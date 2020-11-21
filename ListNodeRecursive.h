#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <time.h>


typedef int var;
struct ListNode {
    var val;
    struct ListNode* next;
};

// constructors
struct ListNode* from_array (var* arr, int dim);
struct ListNode* create (int dim, ...);
struct ListNode* random_list (int dim, var range_start, var range_end);
struct ListNode* clone (struct ListNode* head);
struct ListNode* copy (struct ListNode* head, int start, int quantity);

// add
struct ListNode* push_front (struct ListNode* head, var val);
struct ListNode* push_back (struct ListNode* head, var val);
struct ListNode* push (struct ListNode* head, var val, int ind);
void delete (struct ListNode* head);

// remove
struct ListNode* pop_back (struct ListNode* head);
struct ListNode* pop_front (struct ListNode* head) ;
struct ListNode* pop (struct ListNode* head, int ind);

// utils
struct ListNode* find (struct ListNode* head, var target);
void print (struct ListNode* head);
int size (struct ListNode* head);
var* to_array (struct ListNode* head, int* dim);
struct ListNode* reverse (struct ListNode* head);
struct ListNode* sort (struct ListNode* head);