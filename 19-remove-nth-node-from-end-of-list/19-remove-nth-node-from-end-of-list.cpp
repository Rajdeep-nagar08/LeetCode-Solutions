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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
      int total=1;
      ListNode* temp=head;
      while(temp->next!=nullptr){
        total++;
        temp=temp->next;
      }
        
      int k=total-n;
      
      if(k==0)
        return head->next;
      
      temp=head;
      while(k!=1){
        temp=temp->next;
        k--;
        }
        
      if(temp->next->next == nullptr)
         temp->next=nullptr;
      
      else
        temp->next=temp->next->next;
      
      
      return head;
    }
};


