 /*
        
        if at top there is ith index of ring
        
        let we needs to metch key[k]  (we have already metched 0,1,2,...k-1 indexes)
        
        let key[k] in ring presents at => {j1,j2,j3} indexes
        
        so we can bring any j1, j2, j3 at top by either clockwise or anticlockwise rotation
        
        
        as we have choices=> think about dp
        
        
        currently at top => ith index
        
        we needs to bring j1 at top: clockwise steps :
        
        min(abs(i-j1),n-abs(i-j1)) + 1 (to press the central button)
        
        after doing this, index at top of ring => j1
        
        
        
        dp[i][k] = minimum steps to metch key[k....] if index i of ring is at the top
        
        ans= dp[0][0]
        
        */
        
int dp[101][101];

class Solution {
public:
    
    // for each key[k] finding similar chars in ring {j1,j2,j3} => using map [char=> vector]

    unordered_map<char, vector<int>>mp;

    int n, m;
    
    int findRotateSteps(string ring, string key) {
        
        
        n=ring.size();
        
        m=key.size();
        
       memset(dp,-1,sizeof(dp));
    
        for(int k=0;k<m;k++){
            for(int j=0;j<n;j++){
                if(key[k]==ring[j]){
                    mp[key[k]].push_back(j);
                }
            }
        }
        
        
        return find(0,0,key);
        
    }
    
    int find(int i, int k, string key){
        
        if(k>=key.size())
            return 0;
        
        
        if(dp[i][k]!=-1)
            return dp[i][k];
        
        
        vector<int>v=mp[key[k]];
        
        int ans=100000;
        
        for(int j=0;j<v.size();j++){
            
            ans=min(ans,min(abs(i-v[j]),n-abs(i-v[j])) + 1 + find(v[j],k+1,key));
            
        }
        
        return dp[i][k]= ans;
        
    }
    
};