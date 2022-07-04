class Solution {
public:
    int maxCoins(vector<int>& piles) {
        
        
        int n = piles.size();
        
        sort(piles.begin(),piles.end());
        
        int ans=0;
        
        
        int j=n-2;
        
        int count=0;
        
        while(count!=n/3){
            ans+=piles[j];
            count++;
            j-=2;
        }
       
        return ans;
    }
    
    
};