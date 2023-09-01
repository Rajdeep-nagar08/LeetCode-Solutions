class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>ans(n+1);
        ans[0]=0;
        if(n==0)
            return ans;
        for(int i=1;i<=n;i++){
            if(i%2==0)
                ans[i]=ans[i/2];    //no of set-bits in 4=no of set-bits in 2
            else
                ans[i]=ans[i-1]+1;  // no of set-bits in 5=no of set bits in 4+ 1;
        }
        return ans;
    }
};