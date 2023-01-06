#define lln long long int
class Solution {
public:
    int maxIceCream(vector<int>& v, int cost) {
        
        
        int n=v.size();
        
        sort(v.begin(),v.end());

        vector<lln>coins(n);

        coins[0]=v[0];
        
        for(int i=1;i<n;i++){
            coins[i]=v[i]+coins[i-1];
        }
        
        int idx=upper_bound(coins.begin(),coins.end(),cost)-coins.begin();
        
        return idx;
    }
};