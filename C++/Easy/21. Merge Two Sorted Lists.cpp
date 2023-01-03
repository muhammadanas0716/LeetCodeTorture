/*
You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.

 

Example 1:


Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]
Example 2:

Input: list1 = [], list2 = []
Output: []
Example 3:

Input: list1 = [], list2 = [0]
Output: [0]
 

Constraints:

The number of nodes in both lists is in the range [0, 50].
-100 <= Node.val <= 100
Both list1 and list2 are sorted in non-decreasing order.
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
    void insertEnd(ListNode* head, int n){
        ListNode* newNode = new ListNode(n);
        if(head == NULL){
            head = newNode;
        }
        else{
            ListNode* l = head;
            while(l->next != NULL){
                l = l->next;
            }
            l->next = newNode;
        }
        return;
    }
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL){
            return l2;
        }
        if(l2 == NULL){
            return l1;
        }
        ListNode* newlist = new ListNode();
        while(l1 != NULL && l2 != NULL){
            if(l1 != NULL || l2 != NULL){
            if(l1->val <= l2->val){
                insertEnd(newlist, l1->val);
                l1 = l1->next;
            }
            else{
                insertEnd(newlist, l2->val);
                l2 = l2->next;
            }
            }
            else if(l1 == NULL){
                newlist->next = l2;
            }
            else{
                newlist->next = l1;
            }
        }
        if(l1 == NULL){
            while(l2!= NULL){
                insertEnd(newlist, l2->val);
                l2 = l2->next;
            }
        }
            
        else{
            while(l1!= NULL){
                insertEnd(newlist, l1->val);
                l1 = l1->next;
            }
        }
        return newlist->next;
    }
};
