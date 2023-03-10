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
    ListNode* node;
public:
    Solution(ListNode* head) {
        node=head;
    }
    
    int getRandom() {
        ListNode*curr=node;
        int n=1;
        int ans=0;
        while(curr){
            if(rand()%n==0)
                ans=curr->val;
            n++;
            curr=curr->next;
        }
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */