/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
      if(head==nullptr || head->next==nullptr)
        return nullptr;
      
      ListNode* temp=head;
      int count=0;
      
      while(count<10000){
        temp=temp->next;
        count++;
        if(temp==nullptr)
          return nullptr;
      }
      
        ListNode* slow=head;
        ListNode* fast =head->next;
      
      while(slow!=fast){
        slow=slow->next;
        fast=fast->next->next;
      }
      
      ListNode* t1= head;
      ListNode* t2=slow->next;
      
      while(t1!=t2){
          while(t2->next!=slow){
            t2=t2->next;
            if(t2==t1)
              return t1;
          }
         t1=t1->next;
         t2=slow->next;
      }
    
       return t1;
    }
};