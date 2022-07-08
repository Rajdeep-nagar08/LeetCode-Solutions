/*

No of components formed after painting each remaining house = target 

Cost of painting should be minimum
    
        among all the colors for a particular uncolored house, we have a choice what color to choose or not for it, As we have choices so we can think about dp
        
        We needs to break our array into 'target' components such that color of each component should be same [and adjacent component should have differet colors]
        
 And cost to give colors to uncolored houses should be minimum
        
Now there can be two cases:

1. if current house is colored than:
     1. if its color is similar to previous house color than include this house with previous house
     2. if its color is different from previous house color than start new component from here
    

2. if current house is not colored, than try to give all colors to it:

    1. if color givento it is similar to previous house color than include this house with previous house
   
    2. If color given to it is different from previous house color than start new component from here
     
    
dp[i][target][prev] = min cost to color houses [i.....m-1] 

 , No. of components needs to form = target , color of prev component = prev

Ans = dp[0][target][0]


*/
   

int dp[101][101][21];


class Solution {
public:
    int minCost(vector<int>& h, vector<vector<int>>& cost, int m, int n, int target) {
        
        
        // no of houses =m   
        
        memset(dp,-1,sizeof(dp));
        
        int ans= find(0,target,0,h,cost,m,n);
        
        if(ans==1e8)
            return -1;
        
        return ans;
        
    }
    
    
    int find(int i,int target,int prev,vector<int>&h,vector<vector<int>>&cost,int m,int n){
        
        if(i>=m){
            
            if(target==0){
                return 0;
            }
            
            return 1e8;
        }
        
        
        if(target<0)
            return 1e8;
        
        
        if(dp[i][target][prev]!=-1)
            return dp[i][target][prev];
        
        
        
    int mn1=1e8,mn2=1e8;    
        
        // case 1 (house already colored)
            
        if(h[i]!=0){
            if(h[i]!=prev)   // new component starts from here
          mn1=min(mn1,find(i+1,target-1,h[i],h,cost,m,n));
            else             // previous component going on
          mn1=min(mn1,find(i+1,target,h[i],h,cost,m,n));
        }
        
        // case 2 (house not colored, try all colorss for it)
        
        else{
          
       for(int c=1;c<=n;c++){
           if(prev!=c)   // new component starts from here
        mn2=min(mn2,cost[i][c-1]+find(i+1,target-1,c,h,cost,m,n));
           else          // previous component going on
        mn2=min(mn2,cost[i][c-1]+find(i+1,target,c,h,cost,m,n));
      
       }
            
    }
        
        return dp[i][target][prev]=min(mn1,mn2);
          
    }
};


//T.C = O(m*m*n)*O(n) = O(m*m*n*n)