
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
    ListNode* sortList(ListNode* head) {
          sortL(&head);
        return head;
    }
     
    void sortL(ListNode** head ){
        
        ListNode* first; // points to first half portion of linked list
        ListNode* second;    //points it to second half portion of linked list
        ListNode* curr=*head;
        
        if(curr==nullptr ||curr->next==nullptr)
            return ;
        
       breakAtmid(curr,&first,&second);
        
         sortL(&first);
        
         sortL(&second);
        
       *head=merge_sort(first,second);
        
    }
       
    
    void breakAtmid(ListNode* curr,ListNode**first,ListNode** second){
           ListNode* slow=curr;
           ListNode* fast=curr->next;
           while(fast!=nullptr){
               fast=fast->next;
               if(fast!=nullptr){
                   fast=fast->next;
                   slow=slow->next;
               }
           }
           *first=curr;
           *second=slow->next;
           slow->next=nullptr;
       }
    
    
    ListNode* merge_sort(ListNode* l1,ListNode* l2){
        if(l1==nullptr)
            return l2;
        if(l2==nullptr)
            return l1;
        // ListNode* head;
        if(l1->val<l2->val){
            l1->next=merge_sort(l1->next,l2);
            
            return l1;
        }
        
             
            l2->next=merge_sort(l1,l2->next);
            
            return l2;

    }
};