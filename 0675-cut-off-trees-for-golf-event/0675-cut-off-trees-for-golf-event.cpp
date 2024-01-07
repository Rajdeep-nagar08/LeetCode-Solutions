  
        // 0 => block
        
        // 1 => empty
        
        // x => tree height
        
//  length of shortest increasing path in a matrix that cover all cells having  any tree

// having choices => either cut or not cut the tree

// store all trees height in a vector (in incresing order

// starts bfs from first tree to find shortest path to second tree
        

#define pp pair<int, pair<int,int>>

int dx[4]={1,-1,0,0};

int dy[4]={0,0,1,-1};

class Solution {
public:
    int cutOffTree(vector<vector<int>>& f) {
        
      
        
        int n=f.size();
        
        
        int m=f[0].size();
        
        
        priority_queue<pp,vector<pp>,greater<pp>>pq;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(f[i][j]>1)
                pq.push({f[i][j],{i,j}});
            }
        }
        
        
        int ans=0;
        
        int x1=0,y1=0;
        
        while(!pq.empty()){  // O(n*m)
        
            pp pp1=pq.top();
            
            pq.pop();
            
            int x2=pp1.second.first;
            
            int y2=pp1.second.second;
            
            // (x1,x2) => (x2,y2) and make (x2,y2) empty
            
            
            
            queue<pair<int,int>>q;
            
            vector<vector<bool>>vis(n,vector<bool>(m,false));
            
            vis[x1][y1]=true;
            
            q.push({x1,y1});
            
            bool found=false;
            
            int step=0;

            while(!q.empty()){  // O(n*m)
                
                int sz=q.size();
                                
                while(sz--){
                    
                    int a=q.front().first;
                    
                    int b=q.front().second;
                    
                    q.pop();
                    
                if(a==x2 and b==y2){
                   f[a][b]=1;
                   x1=x2;
                   y1=y2;
                   found=true;
                   break;
               } 
                    
                for(int i=0;i<4;i++){
                    
                   int a1=a+dx[i];
                    
                   int b1=b+dy[i];
                    
    if(a1<n and b1<m and a1>=0 and b1>=0 and f[a1][b1]>0 and !vis[a1][b1]){
                        
                    vis[a1][b1]=true;
                        
                    q.push({a1,b1});
                        
                    }
                    
                }
                
                    
             }
                
                 if(found)
                    break;
                
                step++;
                
            }
            
            if(found){
                ans+=step;
            }
            
            else
                return -1;
            
        }
        
        
        return ans;
    }
};