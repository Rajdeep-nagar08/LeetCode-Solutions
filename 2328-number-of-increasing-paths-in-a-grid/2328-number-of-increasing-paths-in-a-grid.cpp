

#define lln long long int

int myMod=1e9+7;


lln myDp[1001][1001];


int dx[]={1,-1,0,0};



int dy[]={0,0,1,-1};


class Solution {
public:
    
    int n,m;

    int countPaths(vector<vector<int>>& grid) {
        
        n=grid.size();
        
        m=grid[0].size();
        
        
        
    
        memset(myDp,-1,sizeof(myDp));
        
        
        
        lln myAns=0;
        
        
        myAns=0;
        
        
        
        for(int i=0;i<n;i++){
          
            for(int j=0;j<m;j++){
                
                myAns+=find(i,j,grid)%myMod;
            }
            
        }
        
        
        
        
        return myAns%myMod;
        
        
        
        
    }
    
    
    
    
     lln find(int x,int y,vector<vector<int>>&mt){
         
           if(myDp[x][y]!=-1)
            return myDp[x][y];
                  
            lln myAns=1;

         
         
         
        for(int i=0;i<4;i++){
            

            int y2=y+dy[i];


            int x2=x+dx[i];
            
            
    if(x2 < 0 || y2  <0 || y2 >= m ||  x2 >= n ||    mt[x2][y2]<=mt[x][y])
                continue;
           
            myAns+=find(x2,y2,mt)%myMod;
            
        }
         
         
         
         
         return myDp[x][y]=myAns%myMod;
         
    }

    
    
};