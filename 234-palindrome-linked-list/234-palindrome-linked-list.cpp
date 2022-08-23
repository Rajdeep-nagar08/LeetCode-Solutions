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
    bool isPalindrome(ListNode* head) {
        
        
        if(head->next==nullptr)
            return true;
        
        ListNode* slow=head,*fast=head;
                
        while(true){
            slow=slow->next;
            
            fast=fast->next;
            
            if(fast==nullptr)
                break;
            
        
            fast=fast->next;
            
            if(fast==nullptr)
                break;
          
        }
       
        ListNode* temp1=slow;
        ListNode* temp2=slow->next;
        temp1->next=nullptr;

        ListNode* temp3;
        
        while(true){
            
            if(!temp2)
                break;
            
            temp3=temp2->next;
            
            temp2->next=temp1;
            
            temp1=temp2;
            
            temp2=temp3;
 
        }
        
        while(true){
            if(!temp1)
                break;
            
            if(head->val!=temp1->val)
                return false;
            
            head=head->next;
            
            temp1=temp1->next;
            
        }
        
       
        return true;
    }
};