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
    ListNode *getIntersectionNode(ListNode *A, ListNode *B) {
        
        ListNode*t1=A;
        
        while(t1){
            t1->val=-t1->val;
            t1=t1->next;
        }
        
        ListNode*t2=B;
        
        ListNode*t3=nullptr;
        while(t2){
            if(t2->val<0){
                t3=t2;
                break;
            }
            t2=t2->next;
        }
        
        t1=A;
        
         while(t1){
            t1->val=-t1->val;
            t1=t1->next;
        }
        
        
        return t3;
        
    }
};