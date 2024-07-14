
vector<string>ans;

struct TrieNode{
    
    TrieNode* children[26];
    
    bool end;
    
};

TrieNode *root;

void insert(string str){
    
    TrieNode* node= root;
    
    for(char ch: str){
        int idx= ch-'a';
        if(node->children[idx]==NULL){
            node->children[idx]=new TrieNode();
        }
        node=node->children[idx];
    }
    node->end=true;
}


bool check(string &str){
        
    TrieNode* node=root;
    
    for(char ch: str){
        int idx=ch-'a';
        if(node->children[idx]==NULL)
            return false;
        node=node->children[idx];
    }
    
    if(node->end==true)
        return true;
    
    return false;
    
}


class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        
        ans.clear();
        
        root=new TrieNode();
        
        for(string str: wordDict){
           insert(str);
        }
        
        string temp="";
        
        string str="";
        
        solve(0, s,str, temp);

        return ans;
    }
    
    void solve(int i, string &s, string &str, string &temp){
        
        
        if(i>=s.size()){
                        
            if(str.size()==0){
                ans.push_back(temp);
            }
            return;
        }
        
        str.push_back(s[i]);
        
        solve(i+1,s,str,temp);
        
        if(check(str)){
                        
            string temp1=temp;
            
            string str1=str;
            
            if(temp.size()==0){
                temp=str;
            }
            else{
                temp+=" ";
                temp+=str;
            }
            
            str="";
            
            solve(i+1,s,str,temp);
            
            temp=temp1;
            
            str=str1;
            
        }
        
        str.pop_back();

        
    }
};