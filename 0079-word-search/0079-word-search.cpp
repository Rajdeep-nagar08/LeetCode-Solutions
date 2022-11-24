int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

class Solution {
public:
    bool ans=false;
    
    bool exist(vector<vector<char>>& board, string word) {
     
        
        int n=board.size();
        
        int m=board[0].size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                string str="";
                find(i,j,board,word,str);
                if(ans)
                    return true;
            }
        }
        return false;
    }
    
    
    void find(int i,int j,vector<vector<char>>&board,string &word,string &str){
        
        int sz=str.size();
        
        if(board[i][j]!=word[sz])
            return;

        str+=board[i][j];
        
     
        if(str==word){
            ans=true;
            return;
        }
                
        board[i][j]='.';
        
        for(int x=0;x<4;x++){
            int i1=i+dx[x];
            int j1=j+dy[x];
            if(i1<board.size() && j1<board[0].size() && i1>=0 && j1>=0 && board[i1][j1]!='.')
                find(i1,j1,board,word,str);
        }
        
        
        board[i][j]=str.back();
        str.pop_back();
    }
};