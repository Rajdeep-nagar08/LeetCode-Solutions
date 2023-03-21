class Solution {
public:
    vector<int> decode(vector<int>& encod, int first) {
       
        
        int n=encod.size();
        
        
      vector<int>ans(n+1);
        
        
        ans[0]=first;
        
        for(int i=0;i<n;i++){

        
            ans[i+1]=ans[i]^encod[i];
            
        }
        
        
        return ans;
    }
};