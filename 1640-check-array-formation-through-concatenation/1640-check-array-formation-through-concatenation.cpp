class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pcs) {
        
        unordered_map<int,int>mp;
        
        for(int i=0;i<pcs.size();i++){
            mp[pcs[i][0]]=i;
        }
        
        int i=0;
        
        while(i<arr.size()){
            if(mp.count(arr[i])==0)
                return false;
            
            int j=mp[arr[i]];
            
            for(int k=0;k<pcs[j].size();k++){
                if(arr[i]!=pcs[j][k])
                    return false;
                i++;
            }
            
        }
        
        return true;
    }
};