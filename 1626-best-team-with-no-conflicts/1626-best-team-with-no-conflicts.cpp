
int dp[1001][1001][2];
class Solution {
public:
    int bestTeamScore(vector<int>& sc, vector<int>& ag) {
        
        int n=sc.size();
        
        vector<vector<int>>v(n,vector<int>(2));
        
        for(int i=0;i<n;i++){
        v[i]={ag[i],sc[i]};
        }
        
        sort(v.begin(),v.end());
        
        
        /*
        
        here we have choices, whether to choose a player or not to choose it
        
        think about dp solution
        
        dp[i][j]= max score we can get from [i...n-1] if j= previous index choosed
        
        */
        
        memset(dp,-1,sizeof(dp));
        
        return find(0,0,false,v);
          
    }
    
      int find(int i,int j,bool anyPrev,vector<vector<int>>&v){
          
          if(i>=v.size())
              return 0;
          
          if(dp[i][j][anyPrev]!=-1)
              return dp[i][j][anyPrev];
          
          int mx=INT_MIN;
          
          // ag[i] >= ag[j]
          
         if(!anyPrev){
              // choose
              mx=max(mx,v[i][1]+find(i+1,i,true,v));
              
              // not choose
              mx=max(mx,find(i+1,j,false,v));
          }
          
          else{
          
          if(v[i][1]>=v[j][1]){
              // choose  
              mx=max(mx,v[i][1]+find(i+1,i,true,v));

                 
             // not choose
              mx=max(mx,find(i+1,j,true,v));

              
          }
          else{
             
               mx=max(mx,find(i+1,j,true,v));

          }
        }
          
          
          return dp[i][j][anyPrev]=mx;
      }
};