class Solution {
public:
   struct TrieNode {

    vector<string>allIdx;  
       // used to store string whose pref is comes upto here
    struct TrieNode* children[26];
        
    };

  
    
struct TrieNode* getNode(){
 
struct TrieNode* pNode = new TrieNode;
 
 for (int i = 0; i < 26; i++)
   pNode->children[i] = NULL;
 
    pNode->allIdx={};
           
    return pNode;
    
}
    
    
struct TrieNode *root = getNode();
    
    
void insert(struct TrieNode* root, string key){
    
    struct TrieNode* pCrawl=root;

    for (int i = 0; i < key.length(); i++) {

        int index = key[i] - 'a';

        if (!pCrawl->children[index])
        
        pCrawl->children[index] = getNode();
        
     
        pCrawl->children[index]->allIdx.push_back(key);
                
        
        pCrawl = pCrawl->children[index];
     
    }
    
}

    
vector<string> find(struct TrieNode* root,string key){
    
 
struct TrieNode* pCrawl=root;

    
struct TrieNode *curr=root;
    
for(int i=0;i<key.length();i++)
{
    
int index=key[i]-'a';
    
if(curr->children[index]==NULL || curr->children[index]->allIdx.size()==0)
   return {};

 curr=curr->children[index];
}


return curr->allIdx;
   
  }
    
    
vector<vector<string>> suggestedProducts(vector<string>& prod, string word) {
        
      int n=prod.size();
        
        for(int i=0;i<n;i++){
            insert(root,prod[i]);
        }
        
        vector<vector<string>>ans(word.size());
    
        string pref;
        
        for(int l=1;l<=word.size();l++){
            
            string pref=word.substr(0,l);
                        
            vector<string>v=find(root,pref);
            
            int m=v.size();
            
            if(m==0)
                continue;
            
            sort(v.begin(),v.end());
            
            vector<string>temp;
            
            for(int i=0;i<=min(2,m-1);i++){
                temp.push_back(v[i]);
            }
          
            
            ans[l-1]=temp;
                        
        }
        
        return ans;
        
    }
};