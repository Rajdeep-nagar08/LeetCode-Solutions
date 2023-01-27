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

    
    struct TrieNode *root = getNode();

    int n;
    
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
            
       n=words.size();
    
        int mnlen=0;
        
       for(string str:words){
           mnlen=min(mnlen,(int)str.size());
           insert(root,str);
       }
        
        vector<string>ans;
        
        for(string keys:words){
            
            if(keys.length()<2*mnlen)
                continue;
            
            int count=0;
            
            string s1;
            
            if(find(0,keys,s1,count))
                ans.push_back(keys);
             
           // cout<<endl;
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
 
        pCrawl = pCrawl->children[index];
     
    }
    
      pCrawl->wc +=1;
}
 
    
    bool find(int i,string &s,string s1,int count){
        
        
     //   cout<<"f"<<endl;
        
        if(i>=s.size()){
    
            if(search(root,s1)==true){
                
            if(count>=1)
                return true;
                
                else
                    return false;
            }
            
            return false;
            
        }
        
        s1+=s[i];
        
        bool f1=find(i+1,s,s1,count);

        bool f2=false;
        
      //  cout<<s1<<" "<<search(root,s1)<<endl;
        
        if(search(root,s1)){
            
            f2=find(i+1,s,"",count+1);
    
        }
        
        
        return f1||f2;
    }
    

bool search(struct TrieNode* root, string key)
{
    struct TrieNode* pCrawl = root;

    for (int i = 0; i < key.length(); i++) {

        int index = key[i] - 'a';

        if (!pCrawl->children[index])

            return false;
 

        pCrawl = pCrawl->children[index];

    }

    if(pCrawl->wc>=1)
        return true;
    
    return false;
}

    
};