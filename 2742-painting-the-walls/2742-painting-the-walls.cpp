  
      /*
      
      for each wall there are two choices, either painted by paid painter or by free painter under given condition
      
      
      free painter can paint any wall in 1 unit of time it means free painter can paint 60 walls in 60 unit of time
      
      given 1<= time[i] < = 500 and there are atmost n <=500 walls
      
      if total walls are n, then 
      
      
      it means we need to use paid painter to paint those walls whose sum of time >= no of left walls that not painted yet, and minimize the cost
     
      
      dp[i][walls painted] = minimum cost that can be collected from [i....n-1] and till now "walls painted" has been painted
      
      
      if wainting ith wall using paid painter, then no. of walls painted = 1+time[i], becouse ith wall + time[i] walls will be painted by unpaid painter
      
      */


 int dp[500][501];

class Solution {
public:

int n;

    int paintWalls(vector<int>& cost, vector<int>& time) {
        
        n=cost.size();
        
        memset(dp,-1,sizeof(dp));            
        
        return find(0,0,cost,time);
        
    
    }
    
    int find(int i, int sum,vector<int>&cost, vector<int>&time){
        
        if(sum >= n)
            return 0;
        
        
        if(i>=n){
            
     if(sum >= n)
            return 0;
           
            
            return 1e9;
        
        }
       
        
        if(dp[i][sum]!=-1)
        return dp[i][sum];
        
        
        return dp[i][sum] = min(find(i+1,sum,cost,time),
                                       cost[i]+find(i+1,sum+time[i]+1,cost,time));
       
    }
    
    
};