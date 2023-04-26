class Solution {
public:
    int heightChecker(vector<int>& ht) {
        
        vector<int>v(ht);
        
        sort(v.begin(),v.end());
        
        int ans=0;
        
        for(int i=0;i<v.size();i++){
            if(ht[i]!=v[i])
                ans++;
        }
        
        return ans;
        
    }
};