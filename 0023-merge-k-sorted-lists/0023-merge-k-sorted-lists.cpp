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
        
        
        int countofList= lists.size();
        
        // base case 
        
        if(countofList==0)
            return nullptr;
        
        ListNode* start= lists[0];
        
        for(int i=1;i<lists.size();i++){
            
            start=mergeToPreviousList(start,lists[i]);
        }
        
        return start;
        
    }
    
    
    // merege list l1 with l2
    // both are in sorted order
    ListNode* mergeToPreviousList(ListNode* list1, ListNode* list2){
        
        // base case 
        
        if(!list1){
            return list2;
        }
        
        if(!list2){
            return list1;
        }
        
        if(list1->val<list2->val){
            list1->next=mergeToPreviousList(list1->next,list2);
            
            return list1;
        }
        
        list2->next=mergeToPreviousList(list1,list2->next);
        
        return list2;
    }
    
    
};



