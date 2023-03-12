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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head=nullptr;
         for(ListNode* node:lists){
            head= merge_sort(head,node);
         }
        return head;
    }
    
     ListNode* merge_sort(ListNode* l1,ListNode* l2){
        if(l1==nullptr)
            return l2;
        if(l2==nullptr)
            return l1;
        ListNode* head=nullptr;
         
         ListNode* t1=l1,*t2=l2;
         ListNode* t=head;
         while(t1 && t2){
             if(t1->val < t2->val){
                if(t==nullptr){
                    t=t1;
                    head=t;
                    t1=t1->next;
                }
                 else{
                     t->next=t1;
                     t=t->next;
                     t1=t1->next;
                 }
             }
             else{
                 if(t==nullptr){
                     t=t2;
                     head=t;
                     t2=t2->next;
                 }
                 else{
                     t->next=t2;
                     t=t->next;
                     t2=t2->next;
                 }
             }
         }
         
         while(t1){
             t->next=t1;
             t=t->next;
             t1=t1->next;
         }
         
         while(t2){
             t->next=t2;
             t=t->next;
             t2=t2->next;
         }
         
         
         return head;
                     
    }
};