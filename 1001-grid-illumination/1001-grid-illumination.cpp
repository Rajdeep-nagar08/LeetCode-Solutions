
        /*
        
        no of queries = 2*10^4
        
        n=1e9
        
        so it is not possible to make the complete grid
        
        store the information of each bulb we are going to lamped using unordered maps
        
        */
        



class Solution {
public:

int dx[9]={1,-1,0,0,-1,-1,1,1,0};
int dy[9]={0,0,1,-1,-1,1,-1,1,0};
    
    vector<int> gridIllumination(int n, vector<vector<int>>& lmp, vector<vector<int>>& q) {
        
        map<int,map<int,int>>r,c,dg1,dg2;
        
        // r => columns
        // c => rows
        // r-c => columns
        
        
        // diagonal = r-c
        
        int sz=lmp.size();
        
        for(int i=0;i<sz;i++){
            r[lmp[i][0]][lmp[i][1]]++;  // [r=>columns]
            c[lmp[i][1]][lmp[i][0]]++;  // [c=> rows]
            dg1[lmp[i][0]-lmp[i][1]][lmp[i][1]]++; // [d1,y]
            dg2[lmp[i][0]+lmp[i][1]][lmp[i][1]]++; // [d2,y]
        }
        
        int sz1=q.size();
        vector<int>ans(sz1,0);
        
        int r1,c1,d1,d2;
        
        int x,y;
        
        for(int i=0;i<sz1;i++){
            
            r1=q[i][0];
            c1=q[i][1];
            d1=r1-c1;
            d2=r1+c1;
            
 if((int)r[r1].size()>0 || (int)c[c1].size()>0 || (int)dg1[d1].size()>0 || (int)dg2[d2].size()>0 )
                ans[i]=1;
           
            
            for(int j=0;j<9;j++){
                x=r1+dx[j];
                y=c1+dy[j];
                if(x>=0 && y>=0 && x<n && y<n){
                    
                    r[x].erase(y);
                    c[y].erase(x);
                    dg1[x-y].erase(y);
                    dg2[x+y].erase(y);
                    
                
                    /*
                    auto it1=r[x].find(y);
                    if(it1!=r[x].end())
                        r[x].erase(it1);
                    
                    auto it2=c[y].find(x);
                    if(it1!=c[y].end())
                        c[y].erase(it2);
                    
                    auto it3=dg1[x-y].find(y);
                    if(it3!=dg1[x-y].end())
                        dg1[x-y].erase(it3);
                    
                    auto it4=dg2[x+y].find(y);
                    if(it4!=dg2[x+y].end())
                        dg2[x+y].erase(it4);
                        
                        */
                    
                }
              }
                
            }
        
        
        return ans;
    }
};