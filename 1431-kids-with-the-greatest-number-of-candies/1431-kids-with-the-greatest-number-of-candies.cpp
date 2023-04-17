class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& cand, int extraCand) {
        
        int mx=*max_element(cand.begin(),cand.end());
        
        int n=cand.size();
        
        vector<bool>ans(n);
        
        
        for(int i=0;i<n;i++){
            if(cand[i]+extraCand>=mx){
                ans[i]=true;
            }
            else
                ans[i]=false;
        }
        return ans;
    }
};