int dx[9]={1,-1,0,0,-1,-1,1,1,0};
int dy[9]={0,0,1,-1,-1,1,-1,1,0};
class Solution {
public:
    vector<int> gridIllumination(int n, vector<vector<int>>& lmp, vector<vector<int>>& q) {
        
        /*
        
        no of queries = 2*10^4
        
        n=1e9
        
        so it is not possible to make the complete grid
        
        */
        
        unordered_map<int,unordered_map<int,int>>r,c,dg1,dg2;
        // r => columns
        // c => rows
        // r-c => columns
        
        
        // diagonal = r-c
        
        int sz=lmp.size();
        
        for(int i=0;i<sz;i++){
            r[lmp[i][0]][lmp[i][1]]++;
            c[lmp[i][1]][lmp[i][0]]++;
            dg1[lmp[i][0]-lmp[i][1]][lmp[i][1]]++;
            dg2[lmp[i][0]+lmp[i][1]][lmp[i][1]]++;
        }
        
        int sz1=q.size();
        vector<int>ans(sz1,0);
        
        int r1,c1,d1,d2;
        
        for(int i=0;i<sz1;i++){
            r1=q[i][0];
            c1=q[i][1];
            d1=r1-c1;
            d2=r1+c1;
 if(r[r1].size()>0 || c[c1].size()>0 || dg1[d1].size()>0 || dg2[d2].size()>0 )
                ans[i]=1;
           
            
            for(int j=0;j<9;j++){
                int x=r1+dx[j];
                int y=c1+dy[j];
                if(x>=0 && y>=0 && x<n && y<n){
                  // erase [r,c]
                  // erase [c,r]
                  // erase [r-c,c]
                    r[x].erase(y);
                    c[y].erase(x);
                    dg1[x-y].erase(y);
                    dg2[x+y].erase(y);
                }
              }
                
            }
        
       // cout<<d[0]<<endl;
        
        return ans;
    }
};