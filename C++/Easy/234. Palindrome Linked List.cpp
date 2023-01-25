/*
Given the head of a singly linked list, return true if it is a 
palindrome
 or false otherwise.

 

Example 1:


Input: head = [1,2,2,1]
Output: true
Example 2:


Input: head = [1,2]
Output: false
 

Constraints:

The number of nodes in the list is in the range [1, 105].
0 <= Node.val <= 9
 
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
void Print(ListNode* head) {
    ListNode* cur = head;
    while(cur!=NULL){
        cout<<cur->val<<" ";
        cur = cur->next;
    }
    cout<<endl;
}
    ListNode* reverse(ListNode* head){
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* nxt;
        while(curr != NULL){
            nxt = curr->next;
            curr->next = prev;

            prev = curr;
            curr = nxt;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if(head == NULL){
            return false;
        }
        if(head->next == NULL){
            return true;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* curr = slow;
        ListNode* prev = reverse(slow);

        Print(prev);
        Print(head);
        // check first half and last half is equal
        while(prev && head){
            if(prev->val !=head->val) return false;
            prev=prev->next;
            head=head->next;
        }
        return true;
    }
};
