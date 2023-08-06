 class Solution {
public:
    int mod = 1e9+7;
    int dp[101][101];
    long long helper(int taken,vector<int>& vis,int& goal,int& k){
        if(taken==goal){   
            // Checking all songs have been played atleast once
            for(int i=0;i<vis.size();i++){
                if(vis[i]==-1) return 0;
            }
            return 1;
        }
        // This is done to know how many unqiue songs have be
        // chosen till now
        int chosen = 0;
        for(int i=0;i<vis.size();i++){
            if(vis[i]!=-1) chosen++;
        }
        if(dp[taken][chosen]!=-1) return dp[taken][chosen];
        int res = 0;
        for(int i=0;i<vis.size();i++){
            int t = vis[i];
            // Checking for the song can be played or not
            if(vis[i]==-1 or taken>vis[i]){
                // setting the index for which song can be played
                // again
                vis[i] = taken+k;
                res+=helper(taken+1,vis,goal,k);
                res%=mod;
            }
            vis[i]=t;
        }
        return dp[taken][chosen] = res%mod;
    }
    int numMusicPlaylists(int n, int goal, int k) {
        vector <int> vis(n,-1);
        memset(dp,-1,sizeof(dp));
        return helper(0,vis,goal,k)%mod;
    }
};