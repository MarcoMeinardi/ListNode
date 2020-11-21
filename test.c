#include "ListNodeIterative.h"
//#include "ListNodeRecursive.h"

int main () {
    srand ((unsigned)time (NULL));
    struct ListNode* head = NULL;

    printf ("from_arry\n");
    var arr[5] = {1, 2, 3, 4, 5};
    head = from_array (arr, 5);
    print (head);

    printf ("pop_front\n");
    while (head) {
        head = pop_front(head);
        print (head);
    }

    printf ("create\n");
    head = create (5, 1, 2, 3, 4, 5);
    print (head);
    printf ("pop_back\n");
    while (head) {
        head = pop_back(head);
        print (head);
    }

    printf ("push_back\n");
    for (int i = 1; i <= 5; i++) {
        head = push_back (head, (var)i);
        print (head);
    }
    printf ("pop\n");
    head = pop (head, 2);
    print (head);
    head = pop (head, 0);
    print (head);
    head = pop (head, size (head) - 1);
    print (head);
    head = pop (head, 100);
    print (head);
    printf ("delete\n");
    delete (head);
    head = NULL;
    printf ("\n");

    printf ("push_front\n");
    for (int i = 1; i <= 5; i++) {
        head = push_front (head, (var)i);
        print (head);
    }
    printf ("find\n");
    struct ListNode* sub = find (head, 3);
    print (sub);

    printf ("to_array\n");
    int dim;
    var* arr2 = to_array (sub, &dim);
    for (int i = 0; i < dim; i++) {
        printf ("%d ", arr2[i]);
    }
    printf ("\n\n");

    delete (head);

    head = create (5, 1, 2, 3, 4, 5);
    printf ("clone\n");
    print (head);
    struct ListNode* clo = clone (head);
    print (clo);
    delete (clo);
    printf ("copy\n");
    struct ListNode* cp = copy (head, 1, 3);
    print (cp);
    cp = copy (head, 3, 1);
    print (cp);
    cp = copy (head, 2, 10);
    print (cp);
    delete (cp);

    delete (head);
    head = NULL;

    printf ("\npush\n");
    head = push (head, 1, 0);
    print (head);
    head = push (head, 3, 0);
    print (head);
    head = push (head, 5, 2);
    print (head);
    head = push (head, 2, 1);
    head = push (head, 10, 100);
    print (head);
    delete (head);

    printf ("\nreverse\n");
    head = create (5, 1, 2, 3, 4, 5);
    head = reverse (head);
    print (head);
    delete (head);

    printf ("\nrandom_list\n");
    head = random_list (10, 3, 15);
    print (head);
    printf ("sort\n");
    head = sort (head);
    print (head);


    delete (head);
    return 0;
}