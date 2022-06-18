class WordFilter {
public:
    
    struct TrieNodeF {

    vector<int>allIdx;
        
    struct TrieNodeF* children[26];
        
    };

  
    
struct TrieNodeF* getNodeF()
{

    
struct TrieNodeF* pNode = new TrieNodeF;
 
   
 for (int i = 0; i < 26; i++)
   pNode->children[i] = NULL;
 
    pNode->allIdx={};
           
    return pNode;
}
    
    

  struct TrieNodeF *rootF = getNodeF();
    
    
struct TrieNodeB {

    vector<int>allIdx;
        
    struct TrieNodeB* children[26];
        
    };

  
    
struct TrieNodeB* getNodeB()
{

    
struct TrieNodeB* pNode = new TrieNodeB;
 
   
 for (int i = 0; i < 26; i++)
   pNode->children[i] = NULL;
 
    pNode->allIdx={};
           
    return pNode;
}
    
    

  struct TrieNodeB *rootB = getNodeB();



    WordFilter(vector<string>& words) {
        
        
        for (int i = 0; i < words.size(); i++){
           
           
           insertF(rootF, words[i],i);   // forward
            
            
           reverse(words[i].begin(),words[i].end());

    
           insertB(rootB, words[i],i);   // backward
 
            
        }
        
    }
    
    
    
    int f(string pref, string suff) {
        
        vector<int>v1=findF(rootF,pref);
        
        reverse(suff.begin(),suff.end());
        
        vector<int>v2=findB(rootB,suff);
        
        if(v1.size()==0 || v2.size()==0)
            return -1;
        
        int n1=v1.size();
        
        int n2=v2.size();
        
        for(int i=n1-1;i>=0;i--){
            int no=v1[i];
            
            int i1=lower_bound(v2.begin(),v2.end(),no)-v2.begin();
            
            if(i1<n2 && v2[i1]==no)
                return no;
        }
        
        return -1;
        
    }
    

void insertF(struct TrieNodeF* rootF, string key,int idx)
{

    struct TrieNodeF* pCrawl = rootF;
 

    for (int i = 0; i < key.length(); i++) {

        int index = key[i] - 'a';

        if (!pCrawl->children[index])
        
        pCrawl->children[index] = getNodeF();
        
     
        pCrawl->children[index]->allIdx.push_back(idx);
                
        
        pCrawl = pCrawl->children[index];
     
    }
    
}
 
void insertB(struct TrieNodeB* rootB, string key,int idx)
{

    struct TrieNodeB* pCrawl = rootB;
 

    for (int i = 0; i < key.length(); i++) {

        int index = key[i] - 'a';

        if (!pCrawl->children[index])
        
        pCrawl->children[index] = getNodeB();
        
     
        pCrawl->children[index]->allIdx.push_back(idx);
                
        
        pCrawl = pCrawl->children[index];
     
    }
    
}
 

    
    
vector<int> findF(struct TrieNodeF* rootF,string key){
    
struct TrieNodeF *curr=rootF;
    
for(int i=0;i<key.length();i++)
{
    
int index=key[i]-'a';
    
if(curr->children[index]==NULL || curr->children[index]->allIdx.size()==0)
   return {};

 curr=curr->children[index];
}


return curr->allIdx;
   
  }
    
    
vector<int> findB(struct TrieNodeB* rootB,string key){
    
struct TrieNodeB *curr=rootB;
    
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

