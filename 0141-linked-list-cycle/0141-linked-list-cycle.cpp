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
    bool hasCycle(ListNode *head) {
        if(!head || head->next==nullptr)
          return false;
      
      int count=0;
      ListNode* t=head;
      
      while(count<10000){
        t=t->next;
        count++;
        if(t==nullptr)
          return false;
      }
      
      return true;
    }
};