class Solution {
public:
    int minimumCost(vector<int>& cost) {
        
        int n=cost.size();
        
        sort(cost.rbegin(),cost.rend());
        
        if(n==1)
            return cost[0];
        
        if(n==2)
            return cost[0]+cost[1];
        
        int i=0;
        
        int sum=0;
        
        while(i<n){
            sum+=cost[i];
            i++;
            if(i<n)
            sum+=cost[i];
            i++;
            i++;
        }
        
        return sum;
    }
};