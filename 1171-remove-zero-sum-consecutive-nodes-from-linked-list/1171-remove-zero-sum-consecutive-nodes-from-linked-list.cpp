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
    ListNode* removeZeroSumSublists(ListNode* head) {
        
    
        ListNode* temp=head;
        
        ListNode* prev=nullptr;
        
        ListNode* ans=nullptr;
        
        while(temp and temp->val==0)
            temp=temp->next;
        
        while(temp){
            ListNode* start=temp;
            
            ListNode* end=find(start);
            
            
            if(end){   // prev[start.....end] => sum==0
                           
                if(ans==nullptr){
                    
                   ans=end->next; 
                    
                   prev=end->next;
                    
                   if(prev)
                   temp=prev->next;
                    else
                   return ans;
                    
                }
                else{
                    prev->next=end->next;
                    if(prev)
                    temp=prev->next;
                    else
                    return ans;
                }
                
            }
            
            else{
                if(ans==nullptr)
                    ans=temp;
                prev=temp;
                temp=temp->next;
            }
            

        }
        
        return ans;
        
    }
    
    ListNode* find(ListNode* start){
        
        int sum=0;
        
        ListNode* last=nullptr;
        
        while(start){
            sum=sum+start->val;
            if(sum==0){
                last=start;
            }
            
            start=start->next;
        }
        
        return last;
    }
};