class Encrypter {
public:
     unordered_map<char,string>mp1; // keys[i]=>vals[i]
        
      unordered_map<string,vector<char>>mp2;
        
        unordered_map<string,int>hash;
    
    
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

        
    Encrypter(vector<char>& keys, vector<string>& vals, vector<string>& dict) {
       
     
        
        int n=keys.size();
        
        for(int i=0;i<n;i++){
            mp1[keys[i]]=vals[i];
            mp2[vals[i]].push_back(keys[i]);
        }
        
    
        for(string &str:dict){
            
            hash[str]++;
            
            insert(root,str);
        }
         
    }
    
    string encrypt(string str1) {
        
      // for char ch in str1
        
        // replace ch by vals[i] such that keys[i] == ch
        
        
        // return encrypted string
        
        string ans="";
        
        for(char &ch:str1){
            if(mp1.count(ch)==0)
                return "";
            ans+=mp1[ch];
        }
        return ans;
    }
    
    int decrypt(string str2) {
              
        // replace ch(ch+1) by keys[i] such that ch(ch+1)==vals[i]
        
        // return no. of decrypted string that can be formed and present in dict
        
        
        int n=str2.size();
        
                
        return find(0,str2,root);
        
    }
    
    
    
    int find(int i,string &str,TrieNode* root){
        
        
        if(i>=str.size()){
           return root->wc;
        }
        
        string s=str.substr(i,2);
      //  vector<char>v=mp2[s];
        
        int ans=0;
        
        for(char &ch:mp2[s]){
            if(root->children[ch-'a']){
            ans+=find(i+2,str,root->children[ch-'a']);
            }
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
            pCrawl->wc =1;

}
 


};

