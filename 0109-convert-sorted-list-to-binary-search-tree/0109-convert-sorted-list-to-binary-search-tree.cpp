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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head, ListNode* tail = NULL) {
        if (head == tail) 
            return NULL;
        
        ListNode* fast = head, *slow = head;
        while (fast != tail && fast->next != tail) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        TreeNode* root = new TreeNode(slow->val);
        root->left = sortedListToBST(head, slow);
        root->right = sortedListToBST(slow->next, tail);
        
        return root;
    }
    
};
/*
class Solution {
    vector<int>v;
public:
    TreeNode* sortedListToBST(ListNode* head) {
        int count=0;
        ListNode* temp=head;
        while(temp!=nullptr){
            v.push_back(temp->val);
            temp=temp->next;
            count++;
        }
        int l=0;
        int h=count-1;
        TreeNode* root=nullptr;
       return make(l,h,root);    
    }
      TreeNode* make(int l,int h,TreeNode* root){
          int mid=(l+h)/2;
          if(l>h)
              return nullptr;
          root=new TreeNode(v[mid]);
          root->left=make(l,mid-1,root->left);
          root->right=make(mid+1,h,root->right);
          return root;
      }
};

*/


