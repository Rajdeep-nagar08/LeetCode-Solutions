
struct TrieNode{
    TrieNode* children[26];
    bool end;
};

TrieNode* root;

void insert(string str){
    TrieNode* temp=root;
    for(char ch: str){
        int idx=ch-'a';
        if(temp->children[idx]==NULL){
            temp->children[idx]=new TrieNode();
        }
        temp=temp->children[idx];   
    }
    temp->end=true;
}

bool check(string str){
    TrieNode* temp=root;
    for(char ch: str){
        int idx=ch-'a';
        if(temp->children[idx]==NULL)
            return false;
        temp=temp->children[idx];
    }
    return temp->end;
}


vector<string>ans;

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
       
        root=new TrieNode();
        ans.clear();
        
        for(string str: words){
            insert(str);
        }
        
                
        int n=board.size();
        
        int m=board[0].size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                string str="";
                vector<vector<bool>>vis(n,vector<bool>(m,false));
                TrieNode* temp=root;
                find(i,j,str,board, vis,temp); 
            }
        }
        return ans;
    }
    
    int dx[4]={1,-1,0,0};
    
    int dy[4]={0,0,1,-1};
    
void find(int i, int j, string& str, vector<vector<char>>& board, vector<vector<bool>>& vis, TrieNode* temp)
{
        if(temp->children[board[i][j]-'a']==NULL)  // imp optimization
            return;
        
        temp=temp->children[board[i][j]-'a'];
    
        vis[i][j]=true;
    
        str.push_back(board[i][j]);

        if(temp->end==true){
            ans.push_back(str);
            temp->end=false;
        }

        for(int i1=0;i1<4;i1++){
            int x1=i+dx[i1];
            int y1=j+dy[i1];
            if(x1>=0 && x1<board.size() && y1>=0 && y1<board[0].size() && vis[x1][y1]==false){
                find(x1,y1,str,board,vis,temp);
            }
        }
        
        vis[i][j]=false;
        str.pop_back();
            
    }
};