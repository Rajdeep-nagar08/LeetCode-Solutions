class Solution {
    
public:
    
    struct TrieNode{
        struct TrieNode* child[2];
        int val=0;
    };
    
    int findMaximumXOR(vector<int>& nums) {
        int ans=INT_MIN;
        TrieNode* root=new TrieNode();
         for(int no:nums)
             insert(root,no);
        
        for(int no:nums)
            ans=max(ans,no^findAns(root,no));
        
        return ans;
        
    }
    
       void insert(TrieNode* root,int x){
           TrieNode* curr=root;
           for(int i=31;i>=0;i--){
               int bit=(x>>i)&1;
               if(curr->child[bit]==NULL)
                   curr->child[bit]=new TrieNode();
               curr=curr->child[bit];
           }
           curr->val=x;
       }
    
       int findAns(TrieNode* root,int x){
           TrieNode* curr=root;
           for(int i=31;i>=0;i--){
               int bit=(x>>i)&1;
               if(curr->child[!bit]!=NULL)  
                   
                   //first,search for opposite bit to make xor maximum
                   curr=curr->child[!bit];
               
               else if(curr->child[bit]!=NULL)
                   curr=curr->child[bit];
           }
           return curr->val;
       }
};



