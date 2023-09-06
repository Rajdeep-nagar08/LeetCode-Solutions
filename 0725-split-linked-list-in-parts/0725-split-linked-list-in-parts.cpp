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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*>ans(k);
      if(!head)
        return ans;
      
      int count=1;
      ListNode* temp=head;
      while(temp->next!=nullptr){
        temp=temp->next;
        count++;
      }
      
         if(count<k){
           temp=head;
           int i=0;
           while(temp!=nullptr){
             ListNode* x=temp;
             temp=temp->next;
             x->next=nullptr;
             ans[i]=x;
             i++;
           }
             return ans;
         }
        
        int mod=count%k;
        int no=(count/k);
      
         ListNode* temp1=head;
         ListNode* temp2=head;

         for(int i=1;i<=k;i++){
           int total=no+(mod>0 ? 1:0);
           mod--;
          
           while(total!=1){
             temp2=temp2->next;
             total--;
           }
          
           ListNode* x=temp1;
           ans[i-1]=x;
           temp1=temp2->next;
           temp2->next=nullptr;
           temp2=temp1;
         }
      
       return ans;
    }
};

