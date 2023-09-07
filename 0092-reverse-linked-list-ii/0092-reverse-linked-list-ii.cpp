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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head || head->next==nullptr || left==right)
          return head;
      
            /*
      head--------(prev)->[start-------end]->last------
      
      Now reverse the linked list [start------end] then coonect to prev and last
      */

      ListNode *start=head;
      int count=2;
      
      while(count<left){
        start=start->next;
        count++;
      }
      
     ListNode* prev=start;
      if(left>1)
      start=start->next;
      
      ListNode* end=start;
      count=left;
      while(count!=right){
        end=end->next;
        count++;
      }
       
      ListNode* last=nullptr;
      if(end->next){
        last=end->next;
         end->next=nullptr;
      }
      
      ListNode* head2= reverse(start);
      end=head2;
      while(end->next!=nullptr)
        end=end->next;
      
      if(last)
        end->next=last;
      
      if(left>1){
      prev->next=head2;
      return head;
      }
        else
        return head2;
    }
  
  
  ListNode* reverse(ListNode* head){
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


