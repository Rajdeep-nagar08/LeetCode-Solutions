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
        
        int n=lists.size();
        
        if(n==0)
            return nullptr;
        
        ListNode* start=lists[0];
        
        for(int i=1;i<lists.size();i++){
            start=merge(start,lists[i]);
        }
        
        return start;
        
    }
    
    
    ListNode* merge(ListNode* l1, ListNode* l2){
        
        if(!l1)
            return l2;
        
        if(!l2)
            return l1;
        
        if(l1->val<l2->val){
            
            l1->next=merge(l1->next,l2);
            
            return l1;
            
        }
        
        
        l2->next=merge(l1,l2->next);
        
        return l2;
        
    }
};