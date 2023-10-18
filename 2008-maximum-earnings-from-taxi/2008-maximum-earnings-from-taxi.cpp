/*

we cannot choose any person greedly directly becouse chossing any person is not contributing independently here , it also affects the incoming tasks

so we can think of dp to keep store the max. price for particular step

dp[i]=max price get from [i.....n-1]


At each step , we have two choices 
Either select a person Or not (we take max price among both)

if not selecting person i , dp[i]=dp[i+1]
if selecting person i ,
dp[i]= distace cover by i+ price of person i + dp[next valid starting point j] , j= starting point just >= end point of person i (we can find j easily using binary search)



*/

class Solution {
public:
      long long dp[(int)1e5];
    
    
    long long solve(vector<vector<int>>& rides, int idx){
       if(idx >= rides.size()) return 0;
       
       if(dp[idx] != -1) return dp[idx];
         // option 1 is to not consider this passenger
        
          long long op1 = solve(rides, idx + 1);
        
        // option 2 is to consider this passenger
        
       // int nextPos = nextPosition(rides, rides[idx][1], idx);
        
    vector<int>v={rides[idx][1],INT_MIN,INT_MIN};
        int nextPos=lower_bound(rides.begin()+idx+1,rides.end(),v)-rides.begin();
        
      long long op2 = rides[idx][1] - rides[idx][0] + rides[idx][2] + solve(rides,nextPos);
        
        return dp[idx] = max(op1,op2);
    }
    
    
    
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
            sort(rides.begin(),rides.end());
            memset(dp,-1,sizeof(dp));
             return solve(rides,0);
    }
};