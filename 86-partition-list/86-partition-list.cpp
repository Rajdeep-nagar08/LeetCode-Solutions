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
    ListNode* partition(ListNode* head, int x) {
        
        
        ListNode* temp=head;
        
        ListNode* h1=new ListNode(0);
        
        ListNode* t1=h1;
        
        while(temp){
            if(temp->val<x){
                ListNode* h2=new ListNode(temp->val);
                t1->next=h2;
                t1=t1->next;
            }
            temp=temp->next;
        }
        
        temp=head;
        
         while(temp){
            if(temp->val>=x){
                ListNode* h2=new ListNode(temp->val);
                t1->next=h2;
                t1=t1->next;
            }
            temp=temp->next;
        }
        
        return h1->next;
        
        
    }
};