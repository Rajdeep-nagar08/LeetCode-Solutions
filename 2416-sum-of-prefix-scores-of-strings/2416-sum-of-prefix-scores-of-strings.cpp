class Solution {
public:
    
                                  

struct TrieNode {

int wc;

struct TrieNode* children[26];

 };


struct TrieNode* getNode()
{

    struct TrieNode* pNode = new TrieNode;
 
   
 for (int i = 0; i < 26; i++){
        pNode->children[i] = NULL;
        
    }

 
    pNode->wc= 0;

    return pNode;
    
}

    
    
    vector<int> sumPrefixScores(vector<string>& words) {
        
        int n=words.size();
        
        
        vector<int>ans(n);
        
        struct TrieNode* root = getNode();
        
        for(string &str:words){
            insert(root,str);
        }
        
                
        
        for(int i=0;i<n;i++){
            string str=words[i];
            
            ans[i]+=findAllPref(root,str);
        }
        
        return ans;
        
        
    }
    
    
 

void insert(struct TrieNode* root, string key)
{

    struct TrieNode* pCrawl = root;
 

    for (int i = 0; i < key.length(); i++) {

        int index = key[i] - 'a';

        if (!pCrawl->children[index])
        
       pCrawl->children[index] = getNode();
 
        pCrawl->children[index]->wc +=1; //not write pCrawl->wc+=1
        
        pCrawl = pCrawl->children[index];
     
    }
}
 

int findAllPref(struct TrieNode* root,string key){
    
struct TrieNode *curr=root;
    
    int cnt=0;
    
for(int i=0;i<key.length();i++)
{
int index=key[i]-'a';
cnt+=curr->wc;
curr=curr->children[index];
}
cnt+=curr->wc;
    
return cnt;
    
}
    
    
    
};