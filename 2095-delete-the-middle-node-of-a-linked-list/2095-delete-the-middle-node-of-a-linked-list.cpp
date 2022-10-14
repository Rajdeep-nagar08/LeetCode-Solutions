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
    ListNode* deleteMiddle(ListNode* head) {
        int i,count,k;
i=1;count=0;
struct ListNode *temp;
temp=head;
 if(head->next==0)
     return(head->next);
    
    while(temp!=0)
   {
      temp=temp->next;
        count++;
   }
    k=count/2+1;
    temp=head;
  
    
    while(i<k)
  {
     if(i==k-1)
   temp->next=temp->next->next;
      else
       temp=temp->next;
        
     i++;
  }
        
   return(head);      
    }
};