/*
Given the head of a linked list, return the list after sorting it in ascending order.

 

Example 1:


Input: head = [4,2,1,3]
Output: [1,2,3,4]
Example 2:


Input: head = [-1,5,3,4,0]
Output: [-1,0,3,4,5]
Example 3:

Input: head = []
Output: []
 

Constraints:

The number of nodes in the list is in the range [0, 5 * 104].
-105 <= Node.val <= 105
 
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* midpoint(ListNode* head){
        if(head == NULL or head->next == NULL){
            return head;
        }
        
        ListNode *slow = head, *fast = head->next;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
    }
    
    ListNode* mergeSortedLists(ListNode* a, ListNode* b){
        if(a == NULL) return b;
        if(b == NULL) return a;
        
        ListNode* temp;
        if(a->val <= b->val){
            temp = a;
            temp->next = mergeSortedLists(a->next, b);
        }
        else{
            temp = b;
            temp->next = mergeSortedLists(a, b->next);
        }
        
        return temp;
    }
    
    ListNode* sortList(ListNode* head) {
        if(head == NULL or head->next == NULL){
            return head;
        }
        
        ListNode* mid = midpoint(head);
        ListNode* a = head;
        ListNode* b = mid->next;
        
        mid->next = NULL;
        
        a = sortList(a);
        b = sortList(b);
        
        ListNode* temp = mergeSortedLists(a, b);
        return temp;
    }
};
