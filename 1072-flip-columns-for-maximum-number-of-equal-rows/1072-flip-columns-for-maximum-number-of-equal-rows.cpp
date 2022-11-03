/*
for each row, store all the colmns having zeros and all the columns having ones

for particular row, basically either we flip all zeores or all ones


mp[all cols having zeros]++

mp[all colms having ones]++


ans= max(mp[])



*/

class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& mat) {
        
        
        int n=mat.size();
        
        int m=mat[0].size();
        
        map<vector<int>,int>mp;
        
        
        for(int i=0;i<n;i++){
            vector<int>z,o;
            
            for(int j=0;j<m;j++){
                if(mat[i][j])
                    o.push_back(j);
                else
                    z.push_back(j);
            }
            
            sort(o.begin(),o.end());
            
            sort(z.begin(),z.end());
            
            mp[o]++;
            
            mp[z]++;
        }
        
        int ans=0;
        
        for(auto it:mp){
            ans=max(ans,it.second);
        }
        return ans;
    }
};