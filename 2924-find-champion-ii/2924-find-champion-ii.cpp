class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        
        
        
        vector<int>deg(n,0);
        
        for(auto it:edges){
            deg[it[1]]++;
        }
        
        int cnt=0;
        
        for(int i=0;i<n;i++){
            if(deg[i]==0)
                cnt++;
        }
        if(cnt>1)
            return -1;
        
        for(int i=0;i<n;i++){
            if(deg[i]==0)
                return i;
        }
        
        return -1;
    }
};