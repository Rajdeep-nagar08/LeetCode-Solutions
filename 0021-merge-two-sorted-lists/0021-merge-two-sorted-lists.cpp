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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        
        ListNode*t1,*t2;
        
        t1=list1,t2=list2;
        
        ListNode* dummy=new ListNode();
        
        ListNode* t=dummy;
        
        while(t1 && t2){
            if(t1->val<=t2->val){
                ListNode* x=new ListNode(t1->val);
                t->next=x;
                t=x;
                t1=t1->next;
            }
            else{
                ListNode* x=new ListNode(t2->val);
                t->next=x;
                t=x;
                t2=t2->next;
            }
        }
        
        
        while(t1){
             ListNode* x=new ListNode(t1->val);
                t->next=x;
                t=x;
                t1=t1->next;
        }
        
        while(t2){
             ListNode* x=new ListNode(t2->val);
                t->next=x;
                t=x;
                t2=t2->next;
        }
        
        return dummy->next;
    }
};