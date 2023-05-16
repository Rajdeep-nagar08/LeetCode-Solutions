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
    ListNode* swapPairs(ListNode* head) {
        if(!head || head->next==nullptr)
           return head;
      ListNode* temp1=head;
         if(temp1->next->next==nullptr){
           temp1=temp1->next;
           temp1->next=head;
           head->next=nullptr;
           return temp1;
    }
      ListNode* temp2=temp1->next;
      ListNode* temp3=temp2->next;
      ListNode* prev=nullptr;
      head=temp2;
      while(temp3){
        if(temp2->next)
        temp3=temp2->next;
        else
          temp3=nullptr;
        
        temp2->next=temp1;
        temp1->next=temp3;
        if(prev)
          prev->next=temp2;
        prev=temp1;
        
        if(temp3)
        temp1=temp3;
        else
        break;
        
        if(temp3->next){
          temp2=temp3->next;
        }
         else
           break;
      }
      temp1->next=nullptr;
      return head;
    }
       
};