/*

at most k transactions

so for each stock, we have two choices either buy it or not

dp[i][k][have]= max profit we can make by doing transaction in the price range [i....n-1] by doing atmost k transactions, if currently we have any stoke or not

Ans= dp[0][k][0]

*/

int dp[1001][101][2];

class Solution {
public:
    
    int n;
    
    int maxProfit(int k, vector<int>& price) {
        
        n=price.size();
        
        
        memset(dp,-1,sizeof(dp));
        
        return find(0,k,0,price);
        
    }
    
    
    int find(int i,int k,int has,vector<int>&price){
        
        if(i>=n || k==0){
            
            if(has)
                return -2*1e6;
            
            return 0;
            
        }
        
        if(dp[i][k][has]!=-1)
            return dp[i][k][has];
        
        int ch1=0,ch2=0;
        
        ch1=find(i+1,k,has,price);  // not do anything, move ahead
        
        if(has){  // already has a stock, sell (1 transaction completed) 
            
            
            ch2=price[i]+find(i+1,k-1,0,price);
            
        }
        
        else{  // not have any stock, buy
            
            ch2=-price[i]+find(i+1,k,1,price);
            
        }
        
        return dp[i][k][has]=max(ch1,ch2);
        
    }
};