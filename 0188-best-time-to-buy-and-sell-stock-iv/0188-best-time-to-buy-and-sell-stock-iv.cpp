/*

at most k transactions

for ith day, we have choices:-
   1) if have any stock, then sell that stock 
   2) if don't have any stock, buy the stock if currently (k>0)

*/

#define lln long long int

lln dp[1001][2][101];

class Solution {
public:
    int n;

    int maxProfit(int k, vector<int>& price) {
      
        n=price.size();
        
        memset(dp,-1,sizeof(dp));
        
        return find(0,0,k,price);
        
    }
    
    
    lln find(int i, int have, int k, vector<int>&price){
        if(i>=n){
            if(have)
                return INT_MIN;
            
            return 0;
            
        }
        
        if(dp[i][have][k]!=-1)
            return dp[i][have][k];
        
        lln ch1=find(i+1,have,k,price);
        
        lln ch2=INT_MIN;
        
        if(have){
            
            // sell
            
            ch2=price[i]+find(i+1,0,k,price);
            
        }
        
        lln ch3=INT_MIN;
        
        if(!have and k>0){
            
            // buy
            
            ch3=-price[i]+find(i+1,1,k-1,price);
            
        }
        
        return dp[i][have][k]=max({ch1,ch2,ch3});
        
    }
};