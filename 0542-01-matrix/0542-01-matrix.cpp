int dx[4]={1,-1,0,0};

int dy[4]={0,0,1,-1};

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
          
        int n=mat.size();
        
        int m=mat[0].size();
        
        vector<vector<int>>ans(n,vector<int>(m,-1));
      
        queue<pair<int,int>>q;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!mat[i][j]){
                    q.push({i,j});
                    ans[i][j]=0;
                }
            }
        }
        
        int sz=1;
        
        while(!q.empty()){
            
            
            int l=q.size();
            
            while(l--){
                
            auto it=q.front();
            
            q.pop();
            
            int x=it.first;
            
            int y=it.second;
            
            for(int i=0;i<4;i++){
                
                int x1=x+dx[i];
                
                int y1=y+dy[i];
                
                if(x1>=0 && y1>=0 && x1<n && y1<m && ans[x1][y1]==-1){
                    ans[x1][y1]=sz;
                    q.push({x1,y1});
                }
            }
                
            }
            
            sz++;
            
        }
        
        return ans;
        
    }
};