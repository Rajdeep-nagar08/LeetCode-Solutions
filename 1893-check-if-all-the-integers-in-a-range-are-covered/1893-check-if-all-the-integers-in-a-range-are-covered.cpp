class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int l, int r) {
        
        vector<int>v(52,0);
        
        
        for(auto it:ranges){
            
            int l1=it[0];
            
            int r1=it[1];
            
            v[l1]+=1;
        
            v[r1+1]-=1;
            
        }
        
        for(int i=1;i<=r;i++){
            v[i]+=v[i-1];
            if(v[i]==0 && i>=l && i<=r)
                return false;
        }
        
        
        return true;
        
    }
};