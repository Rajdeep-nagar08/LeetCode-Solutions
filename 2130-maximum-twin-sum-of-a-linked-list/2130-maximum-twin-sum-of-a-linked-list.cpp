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
    int pairSum(ListNode* head) {
        
        ListNode* slow=head,*fast=head->next;
      
      while(fast->next!=nullptr){
        slow=slow->next;
        fast=fast->next->next;
      }
      
      
      ListNode* t2=slow->next;  // left half part of linked list
      
      slow->next=nullptr;
      
      ListNode* t1=reverse(head); // left half reverse part of linked list
      
      int mx=0;
      
      while(t1){
        mx=max(mx,t1->val+t2->val);
        t1=t1->next;
        t2=t2->next;
      }
      
      return mx;
    }
  /*
    ListNode* reverse(ListNode** head){
      if((*head)->next==nullptr)
        return *head;
      
      if((*head)->next->next){
        ListNode* t=(*head)->next;
        t->next=(*head);
        (*head)->next=nullptr;
        return t;
      }
      
      ListNode* t1=(*head);
      ListNode* t2=(*head)->next;
      ListNode* t3=(*head)->next->next;
      
      t1->next=nullptr;
      
      while(t2){
        t2->next=t1;
        t1=t2;
        t2=t3;
        if(t3)
        t3=t3->next;
      }
        
      return t1;
    }
    */
  
   ListNode* reverse(ListNode* head) {
        
    if(!head || head->next==nullptr)
       return head;
      
      ListNode* temp1=head;
      ListNode* temp2=temp1->next;
      if(temp2->next==nullptr){
        temp2->next=temp1;
        temp1->next=nullptr;
        return temp2;
      }
       
      ListNode* temp3=temp2->next;
      
      temp1->next=nullptr;
      while(temp3){
        temp2->next=temp1;
        temp1=temp2;
        temp2=temp3;
        if(!temp3->next){
          temp3->next=temp1;
           break;
        }
         else
           temp3=temp3->next;
      }
       return temp3;
    }
};