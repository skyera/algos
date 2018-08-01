// 7/31/2018
// Merge 2 sorted list
//
#include <stdio.h>
struct Node {
    int val;
    Node *next;

    Node(int n): val(n), next(NULL){}
};

Node* merge_sorted_lists(Node *head1, Node *head2) {
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;

    Node *head = head1;
    if (head2->val < head1->val)
        head = head2;
    
    Node *prev1 = NULL;
    Node *prev2 = NULL;
    while (head1 != NULL && head2 != NULL) {
        if (head1->val < head2->val) {
            do {
                prev1 = head1;
                head1 = head1->next;
            } while (head1 != NULL && head1->val < head2->val);
            prev1->next = head2;
        } else {
            do {
                prev2 = head2;
                head2 = head2->next;
            } while (head2 != NULL && head2->val < head1->val);
            prev2->next = head1;
        }
    }

    return head;
}


void print_list(Node *head) {
    for (Node *n = head; n != NULL; n = n->next) {
        printf("%d ", n->val);
    }
    printf("\n");
}

void test(Node *head1, Node *head2) {
    printf("--------\n");
    print_list(head1);
    print_list(head2);
    Node *r = merge_sorted_lists(head1, head2);    
    print_list(r);
}


int main() {
    {
        Node head1(1);
        Node n1(2);
        Node n2(3);
        head1.next = &n1;
        n1.next = &n2;
        
        Node head2(4);
        Node n3(5);
        head2.next = &n3;

        test(&head1, &head2);
    }

    {
        Node head1(1);
        Node n4(4);
        Node n8(8);
        
        head1.next = &n4;
        n4.next = &n8;
        
        Node head2(2);
        Node n6(6);
        head2.next = &n6;

        test(&head1, &head2);
    }

    {
        Node head1(1);
        Node n4(4);
        Node n8(8);
        head1.next = &n4;
        n4.next = &n8;

        Node head2(2);
        Node n3(3);
        head2.next = &n3;

        test(&head1, &head2);
    }

    {
        Node head1(1);
        Node head2(2);

        test(&head1, &head2);
    }

    {
        Node head1(2);
        Node head2(1);

        test(&head1, &head2);
    }

    return 0;
}
