int dp[1<<14][17];
class Solution {
 //  int ans=INT_MAX;
public:
    int minSessions(vector<int>& tasks, int time) {
  
      int n=tasks.size();
      
      /*
      dp[mask][t]= min cost , mask= task that has been completed, t= time left in current session
      */
      
      memset(dp,-1,sizeof(dp));
      
      return solve(0,16,tasks,time);
    
    }
  
    int solve(int mask,int t,vector<int>&tasks,int time){
      if(mask==(1<<tasks.size())-1)
        return 0;
      
      if(dp[mask][t]!=-1)
        return dp[mask][t];
      
       int ans=INT_MAX;
      
      for(int i=0;i<tasks.size();i++){
        if(mask&(1<<i))
          continue;
        
        if(t+tasks[i] <= time)
          ans=min(ans,solve(mask|(1<<i),t+tasks[i],tasks,time));
        else
          ans=min(ans,1+solve(mask|(1<<i),tasks[i],tasks,time));
      }
        return dp[mask][t]=ans;
      
    }
};
      
 /*     
      
      vector<int>grps;
        
    find(tasks,time,grps,0);
        return ans;
    }
    
    void find(vector<int>&tasks,int time, vector<int>& grps,int start){
        
        if(start>=tasks.size()){
            int temp=grps.size();
            ans=min(ans,temp);
            return;
        }
        
        if(grps.size()>ans)
            return;
    
        for(int i=0;i<grps.size();i++){
            if(grps[i]+tasks[start]<=time){
                grps[i]+=tasks[start];
               find(tasks,time,grps,start+1);
                grps[i]-=tasks[start];
            }
        }
        
        grps.push_back(tasks[start]);
        find(tasks,time,grps,start+1);
        grps.pop_back();
    }
    
};
*/