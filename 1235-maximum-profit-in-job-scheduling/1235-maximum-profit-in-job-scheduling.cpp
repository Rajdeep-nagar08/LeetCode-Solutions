 /*
     
     maximum profit ?
    
     for a paticular event, we have two choices either choose it or not choose it
     
     as we have choices we can think about dp
     
     if we are choosing int event [x,y]
     
     then next events starting time should be >=y
     
     
     dp[i]= max profit we can make by choosing events from [i....n-1] events
     
     
     ans=dp[0]
    
      
     */


int dp[50001];

class Solution {
public:
    int jobScheduling(vector<int>& st, vector<int>& et, vector<int>& prof) {
        
        memset(dp,-1,sizeof(dp));
        
        vector<vector<int>>v(prof.size());
        
        for(int i=0;i<prof.size();i++){
            v[i]={st[i],et[i],prof[i]};
        }
        
        sort(v.begin(),v.end());
        
        return find(0,v);
        
     
    }
    
    int find(int i,vector<vector<int>>&v){
        if(i>=v.size())
            return 0;
        
        if(dp[i]!=-1)
            return dp[i];
        
        int ans1=0;
        
        int ans2=0;
        
        // not choosing this event
        
        ans1+=find(i+1,v);
        
        
        // choosing this event
        
        int s=v[i][0];
        
        int e=v[i][1];
        
        vector<int>v1={e,INT_MIN,INT_MIN};
        
        int i1=lower_bound(v.begin(),v.end(),v1)-v.begin();
        
        ans2+=v[i][2]+find(i1,v);
        
        
        return dp[i]=max(ans1,ans2);
        
    }
};