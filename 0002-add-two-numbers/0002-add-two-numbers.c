 
#include <stdlib.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    // Create a dummy node to act as the ground/start for our result list
    struct ListNode dummy;
    dummy.val = 0;
    dummy.next = NULL;
    
    struct ListNode* current = &dummy;
    int carry = 0;
    
    // Loop through both lists until both are completely exhausted AND no carry remains
    while (l1 != NULL || l2 != NULL || carry != 0) {
        int sum = carry;
        
        if (l1 != NULL) {
            sum += l1->val;
            l1 = l1->next;
        }
        
        if (l2 != NULL) {
            sum += l2->val;
            l2 = l2->next;
        }
        
        // Calculate new carry and the isolated digit value
        carry = sum / 10;
        
        // Allocate memory for the new node
        struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        newNode->val = sum % 10;
        newNode->next = NULL;
        
        // Link the new node and move the tracking pointer forward
        current->next = newNode;
        current = current->next;
    }
    
    // The actual head of our summed list begins after the dummy node
    return dummy.next;
}
