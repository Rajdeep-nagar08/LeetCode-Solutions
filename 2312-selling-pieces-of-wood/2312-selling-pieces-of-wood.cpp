/*

We need to maximize the earning


Reversing the logic ::::

Instead of cutting pieces from wood, we are goiung to cut wood into all possible parts and we take required parts from all possible parts

Who to cut wood to maximize the earning

NOTE: we cannot move greedly becouse it may happens that price of some piece is max but its dimensions are too large and it cannot be cut down

There are several ways to make a cuts in wood

Not cut a wood at all or cut it horizonattly in two parts as n1*m, n2*m where n1+n2=n  or cut it veretically as n*m1, n*m2 where m1+m2=m

As we have choices to cut a wood, so we use dp to manage it

We cut wood in all possible ways using dp, 

Let during cutting a wood, we get a wood part of dimensions

x*y , and there is cost=p1 for this dimension than, we have two choices, either add its price to ans or cut this piece further

Our main goal will be maximize the price

dp[i][j]= max price we can get after cutting i*j into parts

          
Ans=dp[n][m]

NOTE: if length=n=4 (we can break this length it into parts as (1,3),(2,2))

make cost array, such that cost[i][j] = price of piece of dimension i*j

*/


#define lln long long int

lln dp[201][201];

class Solution {
public:
    long long sellingWood(int n, int m, vector<vector<int>>& prices) {
        
        vector<vector<int>>cost(n+1,vector<int>(m+1,0));
        
        for(auto it:prices){
            cost[it[0]][it[1]]=it[2];
        }
        
        memset(dp,-1,sizeof(dp));
        
        return find(n,m,cost);
    }
    
    
    lln find(int r,int c,vector<vector<int>>&cost){
        
        if(r==1 && c==1){
            return cost[r][c];
        }
        
        if(dp[r][c]!=-1)
            return dp[r][c];
        
        lln ans=cost[r][c];
        
        for(int r1=1;r1<=r/2;r1++){
            ans=max(ans,find(r1,c,cost)+find(r-r1,c,cost));
        }
        
        for(int c1=1;c1<=c/2;c1++){
            ans=max(ans,find(r,c1,cost)+find(r,c-c1,cost));
        }
        
        return dp[r][c]=ans;
    }
};