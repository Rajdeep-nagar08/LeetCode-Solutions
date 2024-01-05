/*

egg either break or not break on floor f

Here we have k eggs and n floor
if we drop from i  (i=1 to n):

         i) egg break , now we remain k-1 eggs and i-1 floor beacase after i floor all the eggs will also break
        ii) egg not break , now we remain k eggs and n-i floor because before i (included) all eggs will be remain
        
Note: We have to find minimum attempts to find the threshold floor in worst case

        
if dp[K][N]= min no of moves needs to find threshold floor out of N floors , using K eggs 
dp[K][N] = 1 + max(dp[K - 1][i - 1], dp[K][N - i]) for i =[1...N]
O(k*N*N)

TLEEEE here


int dp[101][10001];
class Solution {
public:
    int superEggDrop(int e, int f) {
       
        memset(dp,-1,sizeof(dp));
        
        return check(e,f);
    }
    
    int check(int e,int f){
        if(f==1 || f==0)
            return f;
        if(e==1)
            return f;
        
        if(dp[e][f]!=-1)
            return dp[e][f];
        
        int mn=INT_MAX;
        
        for(int k=1;k<=f;k++){
            
            int temp=1+max(check(e-1,k-1),check(e,f-k));
            
            mn=min(mn,temp);
        }
        return dp[e][f]=mn;
    }
};


*/

// its sure that if egg is break down at kth floor than it will always break down on upper floors so we decrease k to find threshold floor and if egg is no break down at kth floor than it will never bvreak down on lowet floor so increase k to find threshold floor 

// [not break down foor...........threshold floor(break down)..............break down]

// so can apply binary search on k instead of linear search


int dp[101][10001];
class Solution {
public:
    int superEggDrop(int e, int f) {
       
        memset(dp,-1,sizeof(dp));
        
        return check(e,f);
    }
    
    int check(int e,int f){
        if(f==1 || f==0)
            return f;
        if(e==1)
            return f;
        
        if(dp[e][f]!=-1)
            return dp[e][f];
        
        int mn=INT_MAX;
        
        int l=0;
        int h=f;
        
        while(l<=h){
            
         int k=(l+h)/2;
         
         int eggBreak=check(e-1,k-1);  
            // no of moves needs to find threshold floor if egg break down at kth floor
            
         int eggNotBreak=check(e,f-k);
            // no of moves needs to find threshold floor if egg not break down at kth floor
         int temp = 1+max(eggBreak,eggNotBreak);
            
         if(eggBreak > eggNotBreak) // move to downward
             h=k-1;
          else
             l=k+1;    // move upward
              
         mn=min(mn,temp);
        }
       
        return dp[e][f]=mn;
    }
};

