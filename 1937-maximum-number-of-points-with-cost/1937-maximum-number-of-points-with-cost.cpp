#define lln long long int

/*

at each point [i,j] sum=point[i][j], we have 3 choices to move
   1. Move downward 
   2. Move left (If previous move was not towards right)
   3. Move right (If previous move was not towards left)
      
      
dp[i][j][move] = max sum of points we can get if we start moving from [i,j]
                 ans our previous move was in
                 direction => move [0-----> down]
                                   [1-----> left]
                                   [2-----> right]
                                   

dp[i][j][move] = points[i][j] + max(dp[i+1][j] , dp[i][j-1]-1 , dp[i][j+1]-1)


                                
Ans= max(dp[0][j][0]) for all j=0 to m-1


*/


class Solution {
public:
    
    int n,m;
    
    long long maxPoints(vector<vector<int>>& pt) {
       
        
 n=pt.size();
        
 m=pt[0].size();
        
        
vector<vector<vector<lln>>>dp(n,vector<vector<lln>>(m,vector<lln>(3,-1)));
        
        
    
     lln sum=0;
        
     for(int j=0;j<m;j++){
         sum=max(sum,pt[0][j]+find(1,j,0,pt,dp));
     }
        
        return sum;

    }
    
    
    lln find(int i,int j,int move,vector<vector<int>>&pt, vector<vector<vector<lln>>>&dp){
        
        
        if(i==n){
            return 0;
        }
        
        if(dp[i][j][move]!=-1)
            return dp[i][j][move];
        
        lln ch1=0,ch2=0,ch3=0;
        
        // moving down
        
        ch1=pt[i][j]+find(i+1,j,0,pt,dp);
        
        // moving left
        
        if(move!=2 && j-1>=0)
         ch2=find(i,j-1,1,pt,dp)-1;
        
        // moving right
        
        if(move!=1 && j+1<m)
          ch3=find(i,j+1,2,pt,dp)-1;
        
        
        return dp[i][j][move]=max({ch1,ch2,ch3});
            
    }
    
    
};