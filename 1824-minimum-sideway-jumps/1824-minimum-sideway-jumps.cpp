/*
frog has three choices at each point
either he move ahead on same path
either he make side jumps to both other parts 

dp[i][j] = min no of side jumps frong needs to do from line i (1,2,3) and frog to cover [j....n-1] 

Note: let there is stone on next step of 2, if we jump to 1 or 3 than its sure that there will not be any stone on next to 1 and 3 , becouse There will be at most one obstacle in the 3 lanes at each point.

*/

#define lln long long int

lln dp[4][500002];

class Solution {
public:
    int n;
    int minSideJumps(vector<int>& obst) {
        
        n=obst.size();
                
        memset(dp,-1,sizeof(dp));
    
        return find(2,0,obst);        
        
    }
    
    lln find(int i,int j,vector<int>&obst){
        
        if(j==n-2)
            return dp[i][j]= 0;
     
        if(dp[i][j]!=-1)
            return dp[i][j];
        
       
        if(obst[j+1]!=i)
        return dp[i][j]=find(i,j+1,obst);
          
        else{
            
        int a,b;
        
        if(i==1)
            a=2,b=3;
        else if(i==2)
            a=1,b=3;
        else if(i==3)
            a=1,b=2;
        
        if(obst[j]==a)
        return dp[i][j]=1+find(b,j+1,obst);
        
        else if(obst[j]==b)
        return dp[i][j]=1+find(a,j+1,obst);
        
        else
        return dp[i][j]=1+min(find(a,j+1,obst),find(b,j+1,obst));

        }
        
        return dp[i][j]=0;
        
    }
};