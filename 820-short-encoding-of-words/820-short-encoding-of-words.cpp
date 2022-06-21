class Solution {
public:
    
    
     struct TrieNode {

    int count;   // used to count no of suffixes
        
    struct TrieNode* children[26];
        
    };

  
    
struct TrieNode* getNode()
{

    
struct TrieNode* pNode = new TrieNode;
 
   
 for (int i = 0; i < 26; i++)
   pNode->children[i] = NULL;
 
    pNode->count=0;
           
    return pNode;
}
    
    
    struct TrieNode *root = getNode();
    
 
    int minimumLengthEncoding(vector<string>& words) {
       
        int c1=0;
        
        int ans=0;
        
        int n=words.size();
        
        unordered_map<string,int>mp;
        
        for(string str:words)
            mp[str]++;
        

        int len=0;
        
        for(auto it:mp){
            string s=it.first;
            len+=s.size();
            reverse(s.begin(),s.end());
            insert(root,s);
        }
        
        
        
        for(auto it:mp){
            string s=it.first;
            reverse(s.begin(),s.end());
           int c= find(root,s);
           
            /*
            if(v.size()>1)
            cout<<words[i]<<" "<<v.size()<<endl;
            */
            
            if(c==1){
                c1++;
                ans+=s.size();
            }          
        }
                
        ans+=c1;
        
        if(c1==0)                   // all words are similar
            ans+=words[0].size()+1;
        
        
/*        
        for(string str:words){
            cout<<str<<" ";
        }
        
        */
        
        return ans;
        
        
    }
    
    
void insert(struct TrieNode* root, string key){
    
    struct TrieNode* pCrawl=root;


    for (int i = 0; i < key.length(); i++) {

        int index = key[i] - 'a';

        if (!pCrawl->children[index])
        
        pCrawl->children[index] = getNode();
        
     
        pCrawl->children[index]->count+=1;
                
        
        pCrawl = pCrawl->children[index];
     
    }
    
}

    
int find(struct TrieNode* root,string key){
    
 
struct TrieNode* pCrawl=root;

    
struct TrieNode *curr=root;
    
for(int i=0;i<key.length();i++)
{
    
int index=key[i]-'a';
    
if(curr->children[index]==NULL || curr->children[index]->count==0)
   return {};

 curr=curr->children[index];
}


return curr->count;
   
  }

    
   
};