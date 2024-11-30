/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include <stdio.h>
#include <stdlib.h>


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {

    struct ListNode* l3_head = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* l3_tail = l3_head;

    l3_tail->val = 0;

    while (true) {
        int val = (l1 ? l1->val: 0) + (l2 ? l2->val: 0) + l3_tail->val;
            l3_tail->val = val % 10;

        l1 = l1 ? l1->next : NULL;
        l2 = l2 ? l2->next : NULL;

        if (l1 || l2 || val/10) {
                l3_tail->next = (struct ListNode*)malloc(sizeof(struct ListNode));
                l3_tail->next->val = val/10;
                l3_tail = l3_tail->next;
                
        } else {
                l3_tail->next = NULL;
                return l3_head;
        }
    }
}