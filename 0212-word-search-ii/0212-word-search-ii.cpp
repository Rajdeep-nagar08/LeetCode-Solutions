int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

class Solution {
public:
    int n,m;
    
    
    unordered_map<string,int>mp;
    
    vector<string>ans;

    
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

void insert(struct TrieNode* root, string key)
{

    struct TrieNode* pCrawl = root;
 

    for (int i = 0; i < key.length(); i++) {

        int index = key[i] - 'a';

        if (!pCrawl->children[index])
        
       pCrawl->children[index] = getNode();
 

        pCrawl = pCrawl->children[index];
     
    }
         
    pCrawl->wc +=1; //not write pCrawl->wc+=1

}
 


    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        
        n=board.size();
        
        m=board[0].size();
        
        
        for(string str:words){
            insert(root,str);
        }
    
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                vector<vector<bool>>vis(n,vector<bool>(m,false));
                 string str="";
                str+=board[i][j];
                if(root->children[board[i][j]-'a']!=NULL)
                vis[i][j]=true;
                dfs(i,j,str,root->children[board[i][j]-'a'],vis,board);
                }
            }
        
        return ans;
    
    }
    
    
    void dfs(int i,int j, string str,TrieNode* root,vector<vector<bool>>&vis,vector<vector<char>>&board){
        
        if(!root)
            return ;
        
        if(root->wc){
            ans.push_back(str);
            root->wc=0;
        }
        
        for(int k=0;k<4;k++){
           int x1=i+dx[k];
            
            int y1=j+dy[k];
            
    if(x1>=0 && y1>=0 && x1<n && y1<m && (vis[x1][y1]==false) && (root->children[board[x1][y1]-'a']!=NULL)){
                vis[x1][y1]=true;
  dfs(x1,y1,str+board[x1][y1],root->children[board[x1][y1]-'a'],vis,board);
                vis[x1][y1]=false;
            }
        }
    }
};