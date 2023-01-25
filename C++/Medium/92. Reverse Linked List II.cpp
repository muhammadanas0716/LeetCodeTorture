/*
Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and return the reversed list.

 

Example 1:


Input: head = [1,2,3,4,5], left = 2, right = 4
Output: [1,4,3,2,5]
Example 2:

Input: head = [5], left = 1, right = 1
Output: [5]
 

Constraints:

The number of nodes in the list is n.
1 <= n <= 500
-500 <= Node.val <= 500
1 <= left <= right <= n
 
*/
class Solution {
public:
    ListNode* reverse(ListNode* start, ListNode* end ){
      
         ListNode *curr = start;
         ListNode *prev = NULL ;
         ListNode *forward = NULL;
              
           while(curr != end  ){
            
              forward = curr->next;
              curr -> next = prev;
         
             prev = curr;
            curr = forward;
        }
          
        return prev;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        if(head->next==NULL || head==NULL){
            return head;
        }
        
        ListNode *start=head;
        ListNode *end = head;
        ListNode *temp = start;
        ListNode* nextToEnd = NULL;
       if(left==1 && right==1){
           return head;
       }
        int cnt = 1 ;
        
        while(cnt<left){
            temp=start;
            start=start->next;
            cnt++;
        }
        cnt = 1;
           while(cnt<right){
            end=end->next;
               
            cnt++;
        }
        nextToEnd = end->next  ;
        //for left = 1
        
        if(left==1 ){
         head = reverse(start, nextToEnd);
          ListNode *tail = head;
        
        while(tail->next!=NULL){
            tail=tail->next;
         }
                    tail->next = nextToEnd ;
             return head;
        }
        
       temp->next = reverse(start, nextToEnd);
    
        ListNode *tail = head;
        
        while(tail->next!=NULL){
            tail=tail->next;
        }
        tail->next = nextToEnd ;
       return head;
    }
};
