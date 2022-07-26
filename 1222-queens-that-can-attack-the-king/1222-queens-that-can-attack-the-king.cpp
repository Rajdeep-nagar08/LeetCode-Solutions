

int dx[8]={0,0,1,-1,1,1,-1,-1};
 
int dy[8]={1,-1,0,0,1,-1,1,-1};

 
class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        
        int x1=king[0];
        
        int y1=king[1];
        
        vector<vector<int>>ans;
        
        int n=queens.size();
        
        vector<vector<int>>chess(8,vector<int>(8,0));
        
        for(int i=0;i<n;i++){
            int x=queens[i][0];
            int y=queens[i][1];
            chess[x][y]=1;
        }
        
        int l=y1-1;
        
        while(l>=0){
            if(chess[x1][l]){
                ans.push_back({x1,l});
                break;
            }
            l--;
        }
      
         int r=y1+1;
        
        while(r<8){
            if(chess[x1][r]){
                ans.push_back({x1,r});
                break;
            }
            r++;
        }
      
        
        
         int u=x1-1;
        
        while(u>=0){
            if(chess[u][y1]){
                ans.push_back({u,y1});
                break;
            }
            u--;
        }
      
        
         int d=x1+1;
        
        while(d<8){
            if(chess[d][y1]){
                ans.push_back({d,y1});
                break;
            }
            d++;
        }
      
        
        int a=x1-1,b=y1-1;
        
        while(a>=0 && b>=0){
             if(chess[a][b]){
                ans.push_back({a,b});
                break;
            }
            a--,b--;
        }
        
          a=x1+1,b=y1+1;
        
        while(a<8 && b<8){
             if(chess[a][b]){
                ans.push_back({a,b});
                break;
            }
            a++,b++;
        }
        
         a=x1-1,b=y1+1;
        
        while(a>=0 && b<8){
             if(chess[a][b]){
                ans.push_back({a,b});
                break;
            }
            a--,b++;
        }
        
         a=x1+1,b=y1-1;
        
        while(a<8 && b>=0){
             if(chess[a][b]){
                ans.push_back({a,b});
                break;
            }
            a++,b--;
        }
        
        
        return ans;
    }
};