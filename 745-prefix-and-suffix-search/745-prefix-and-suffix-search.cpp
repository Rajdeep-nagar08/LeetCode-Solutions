class WordFilter {
public:
    
    struct TrieNode {

    vector<int>allIdx;   // used to store indexes
        
    struct TrieNode* children[26];
        
    };

  
    
struct TrieNode* getNode()
{

    
struct TrieNode* pNode = new TrieNode;
 
   
 for (int i = 0; i < 26; i++)
   pNode->children[i] = NULL;
 
    pNode->allIdx={};
           
    return pNode;
}
    
    

  struct TrieNode *rootF = getNode();
    
    


  struct TrieNode *rootB = getNode();



    WordFilter(vector<string>& words) {
        
        
        for (int i = 0; i < words.size(); i++){
           
           
           insert(rootF, words[i],i,1);   // forward
            
            
           reverse(words[i].begin(),words[i].end());

    
           insert(rootB, words[i],i,0);   // backward
 
            
        }
        
    }
    
    
    
    int f(string pref, string suff) {
        
        vector<int>v1=find(rootF,pref,1);
        
        reverse(suff.begin(),suff.end());
        
        vector<int>v2=find(rootB,suff,0);
        
        if(v1.size()==0 || v2.size()==0)
            return -1;
        
        int n1=v1.size();
        
        int n2=v2.size();
        
        // finding greatest index present inj both the vectors
        
        for(int i=n1-1;i>=0;i--){
            
            int no=v1[i];
            
            int i1=lower_bound(v2.begin(),v2.end(),no)-v2.begin();
            
            if(i1<n2 && v2[i1]==no)
                return no;
        }
        
        return -1;
        
    }
    

void insert(struct TrieNode* rootF, string key,int idx,int f)
{
    
    struct TrieNode* pCrawl;

    if(f)
    pCrawl = rootF;
    else
    pCrawl = rootB;

 

    for (int i = 0; i < key.length(); i++) {

        int index = key[i] - 'a';

        if (!pCrawl->children[index])
        
        pCrawl->children[index] = getNode();
        
     
        pCrawl->children[index]->allIdx.push_back(idx);
                
        
        pCrawl = pCrawl->children[index];
     
    }
    
}

    
vector<int> find(struct TrieNode* rootF,string key,int f){
    
  
    struct TrieNode* pCrawl;

    if(f)
    pCrawl = rootF;
    else
    pCrawl = rootB;

    
struct TrieNode *curr=rootF;
    
for(int i=0;i<key.length();i++)
{
    
int index=key[i]-'a';
    
if(curr->children[index]==NULL || curr->children[index]->allIdx.size()==0)
   return {};

 curr=curr->children[index];
}


return curr->allIdx;
   
  }
    
    
};

