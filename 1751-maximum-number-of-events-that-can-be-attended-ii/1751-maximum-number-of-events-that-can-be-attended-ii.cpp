/*


need to maximize the cost

select atmost k events

[a,b] [c,d]  => c > b




*/


int n;

class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
    
        n=events.size();
      
        
          vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
        
        sort(events.begin(),events.end());
        
//         for(int i=0;i<n;i++){
//             cout<<events[i][0]<<" "<<events[i][1]<<" "<<events[i][2]<<endl;
//         }
        
        
        return find(0,events,k,dp);
        
    }
    
    
    int find(int i,vector<vector<int>>&events,int k,vector<vector<int>>&dp){
        
          if(i>=n || k<=0)
              return 0;
        
        if(dp[i][k]!=-1)
            return dp[i][k];
        
        int x=0,y=0;
        
        x=find(i+1,events,k,dp);
    
            vector<int>v1={events[i][1],INT_MAX,INT_MAX};
            
            int idx=upper_bound(events.begin()+i,events.end(),v1)-events.begin();
            
            y=events[i][2]+find(idx,events,k-1,dp);
            
    
        
        return dp[i][k]=max(x,y);
        
    }
};