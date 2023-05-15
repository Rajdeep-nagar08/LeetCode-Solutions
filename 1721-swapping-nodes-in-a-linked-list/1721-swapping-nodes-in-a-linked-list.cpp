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
    ListNode* swapNodes(ListNode* head, int k) {
        
        if(head->next==nullptr)
            return head;
        
        ListNode* t1=head,*t2=head;
            
        int count=0;
        
        while(t1){
            t1=t1->next;
            count++;
        }
    
        int k2=count-k+1;
      //  cout<<count<<" "<<k2;
        t1=head;
        while(k!=1){
            t1=t1->next;
            k--;
        }
        
        while(k2!=1){
         t2=t2->next;
            k2--;
        }
        
        int temp=t1->val;
        t1->val=t2->val;
        t2->val=temp;
        
        return head;
    }
};