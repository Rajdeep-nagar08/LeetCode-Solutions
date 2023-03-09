class DisjointSet
{
    public:
    vector<int>rank,parent,size;

    DisjointSet(int n)
    {
        rank.resize(n,0);
        parent.resize(n,0);
        size.resize(n,1);

        for(int i=0;i<n;i++)
        {
            parent[i]=i;
           
        }

    }

    int findParent(int node)
    {
        if(node==parent[node])
        {
            return node;
        }

        return parent[node]=findParent(parent[node]);

    }

    void UnionByRank(int u,int v)
    {
        int ulp_u=findParent(u);
        
        int ulp_v=findParent(v);

        if(ulp_u==ulp_v)
        {
            return;
        }

        if(rank[ulp_u]<rank[ulp_v])
        {
            parent[ulp_u]=ulp_v;
        }

        else if(rank[ulp_u]>rank[ulp_v])
        {
            parent[ulp_v]=ulp_u;
        }

        else
        {
            parent[ulp_v]=ulp_u;
            rank[ulp_v]++;

        }

    }

    void UnionBySize(int u,int v)
    {
        int ulp_u=findParent(u);
        
        int ulp_v=findParent(v);
        
        // cout<<ulp_u<<" "<<ulp_v<<endl;

        if(ulp_u==ulp_v)
        {
            return;
            
        }
        if(size[ulp_u]<size[ulp_v])
        {
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }

        else 
        {
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }

    }
};


  int dx[]={-1,1,0,0};
                
  int dy[]={0,0,1,-1};
    

class Solution {
public:
    
      
              
    
    bool isValid(int i,int j,int n)
    {
        if(i>=0 && i<n && j>=0 && j<n)
        {
            return true;
        }
        
        return false;
    }
    
    int largestIsland(vector<vector<int>>& grid)
    {
        
        int n=grid.size();
        
        int totalCnt=0;
        
        int totalCntofzero=0;
        
        DisjointSet ds(n*n);
        
        
//            for(int x:ds.size){
//             cout<<x<<endl;
//            }
        
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==0)
                {
                    totalCntofzero++;
                    continue;
                }
                
                totalCnt++;
                
                int dx[]={-1,1,0,0};
                int dy[]={0,0,1,-1};
                
                int row=i;
                int col=j;
                int node=row*n+col;
                
                for(int k=0;k<4;k++)
                {
                    int nrow=row+dx[k];
                    
                    int ncol=col+dy[k];
                    

                    if(isValid(nrow,ncol,n) && grid[nrow][ncol]==1)
                    {
                        int adjnode=nrow*n+ncol;
                        
                    // cout<<i<<" "<<j<<" "<<nrow<<" "<<ncol<<endl;

                        ds.UnionBySize(node,adjnode);
                        
                        
                    }
                }
            }
        }
        
        if(totalCnt==n*n)
        {
            return totalCnt;
        }
        
        if(totalCntofzero==n*n)
        {
            return 1;
        }
        
        int maxi=0;
        
        
        for(int row=0;row<n;row++)
        {
            for(int col=0;col<n;col++)
            {
                if(grid[row][col]==1)
                {
                    continue;
                }
                
              int node=row*n+col;
             
                 set<int>st;
                
                for(int i=0;i<4;i++)
                {
                    int nrow=row+dx[i];
                    
                    int ncol=col+dy[i];
                    
                    
                    
                    if(isValid(nrow,ncol,n) && grid[nrow][ncol]==1)
                    {
                        int adjnode=nrow*n+ncol;
                        
                        st.insert(ds.findParent(adjnode));
                    }
                }
                
                int maxCount=0;
                
                for(auto it:st)
                {
                    maxCount+=ds.size[it];
                }
                
                // cout<<maxCount<<endl;
                
                maxi=max(maxi,maxCount+1);
            }
        }
        
        for(int i=0;i<n*n;i++)
        {
            maxi=max(maxi,ds.size[i]);
        }
        
        return maxi;
        
    }
};