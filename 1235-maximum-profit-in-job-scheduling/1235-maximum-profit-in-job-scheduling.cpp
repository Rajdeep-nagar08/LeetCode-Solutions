

int dp[50001];

class Solution {
public:
    int jobScheduling(vector<int>& start, vector<int>& end, vector<int>& profit) {
        
        
        /*
        needs to maximize the profit
        
        for eachg job, we have two choices, either do it or not do it
        
        
        => recursion => dp
    
    
    
    if any job ends at time t
    
    next job should start from time >=t
    
    
    sort jobs as per the start time
    
        
        */
        
        
        int n=start.size();
        
        vector<vector<int>>v;
        
        for(int i=0;i<n;i++){
            v.push_back({start[i],end[i],profit[i]});
        }
        
        sort(v.begin(),v.end());
        
        memset(dp,-1,sizeof(dp));
        
        
   return find(0,v);
        
        
    }
    
    int find(int i, vector<vector<int>>&v){
        
        if(i>=v.size()){
            return 0;
        }
        
        if(dp[i]!=-1)
            return dp[i];
        
        int ans1=find(i+1,v);
        
        int ans2=v[i][2];
        
        int e=v[i][1];
        
        vector<int>v1={e,INT_MIN,INT_MIN};
        
        int idx=lower_bound(v.begin(),v.end(),v1)-v.begin();
        
        ans2+=find(idx,v);
        
        return dp[i]=max(ans1,ans2);
        
    }
};