class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int mn = INT_MAX;
        int n = prices.size();
        for(int i = 0;i<n;i++){
            for(int j = 0;j<i;j++){
                if(j != i){
                    mn = min(mn,prices[i]+prices[j]);
                }
            }
        }
        if(mn <= money){
            money-=mn;
        }
        return money;
    }
};