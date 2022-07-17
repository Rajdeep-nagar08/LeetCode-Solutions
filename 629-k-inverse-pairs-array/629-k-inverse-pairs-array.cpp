 /*
        
        array consists no's from 1 to n
        
        No of inverse pairs = k
        
        inverse pair = nums[i] > nums[j]
        
        [3,2,1] => [3,2] [3,1] [2,1] 3 invese pairs
        
        Ans = No of arrays possible that have exactly k inverse pairs
        
        
        Note:
        
if we place smallest no at i=0, than no of inverse pairs formed due to it = 0
if we place smallest no at i=1, than no of inverse piars formed due to it= 1
        .
        .
if we place smallest no at last , no of inverse pairs formed due to it = n-1
        
        So we have n choices to place the smallest no
        
        
After placing the smallest no, we are left with n-1 no's to be placed in similar way
        
        
        As we have choices
        We can think abount dp
        
Recursive in top down manner:

        
    dp[i1][k1]= no of arrays formed using [i1...n-1] such that each array have k1 inverse pairs
                (already covered [0...i1-1] no's with k-k1 inverse pairs)
                Now we needs to place i1 on n-i1 places
        
    dp[i1][k1] = dp[i+1][k1]  (0 inverse pair formed if place i1 at starting, so needs to cover k1 invers pairs using [i+1...n])
                      +
                dp[i+1][k1-1] (1 inverse pair formed if placing i1 at second position)
                      +
                 dp[i+1][k1-2]
                      +
                      .
                      .
                      .
                   
    So dp[i1][k1]= sum(dp[i1+1][k1-(n-i1)]) for all x=0 to k1
    
    
Ans= dp[1][k]


T.C = O(n*k)*O(k)------------> tleeeeeeee


CODE (top down)--------------->
 
    int find(int i1,int k1,int n){
      
        if(i1==n){
            
            if(k1==0)
                return 1;
            
            return 0;
            
        }
        
        if(k1<=0){
            if(k1==0)
                return 1;
            return 0;
        }
        
        if(dp[i1][k1]!=-1)
            return dp[i1][k1];
        
         lln sum=0;
        
        for(int x=0;x<=n-i1;x++){
            sum=sum+find(i1+1,k1-x,n);
            sum=sum%mod;
        }
        
        
        return dp[i1][k1]=sum;
        
        
    }
    
 
    
    

Tabulation:

NOTE : types of tabalution 

Type 1: calculated dp[i+1] , using it we fill dp[i] , moving from down to up
        Ans= dp[1]

Type 2: calculated dp[i] , using it we are filling dp[i+1]
        Ans= dp[n]

dp[i1][k1]= no of arrays we can form using  [1...i1] elements , such that each array have k1 inverse pairs

already covered [1.....i1-1] , need to place i1

To place i1 we have i1-1 positions

dp[i1][k1]= dp[i1-1][k1]  (no inverse pair formed if placing i1 at starting)
                +
            dp[i1-1][k1-1] (1 inverse pair formed if palcing i1 at second position, then we needs to form k1-1 inverse pairs from rest of the elements)
            
            +
            
            dp[i1-1][k1-2]
            +
            
            .
            .
            
            +
            
            dp[i1-1][k1-(i1-1)] and k1-(i1-1)>=0
            
  dp[i1][k1] = sum(dp[i1-1][k1-x])  
  
    

#define lln long long int

int mod=1e9+7;


class Solution {
public:
    int kInversePairs(int n, int k) {
       
        vector<vector<int>>dp(n+1,vector<int>(k+1,0));
        
        dp[0][0]=1;  // if k==o and n==0 than one valid array is empty {}
        
       
        for(int i=1;i<=n;i++){
            
           for(int k1=0;k1<=k;k1++){
                 

               for(int x=0;x<=min(k1,i-1);x++){
                   
                  
                   dp[i][k1]=(dp[i][k1]+dp[i-1][k1-x])%mod;
                
                  
               }
            }
        }
        
        return dp[n][k]%mod;
    
    }
    
}; 
    
    


Optimal tabulation :

dp[i1][k1] = dp[i1-1][k1]+dp[i1-1][k1-1]+dp[i1-1][k1-2] +....dp[i1-1][k1-(i1-1)]

OR

dp[i1][k1] = dp[i1-1][k1]+dp[i1-1][k1-1]+dp[i1-1][k1-2] +....dp[i1-1][k1-i1+1]


Also

dp[i1][k1-1]= dp[i1-1][k1-1]+dp[i1-1][k1-2]+....dp[i1-1][k1-1-(i1-2)]+

               dp[i1-1][k1-1-(i1-1)]
               
OR

dp[i1][k1-1]= dp[i1-1][k1-1]+dp[i1-1][k1-2]+..+dp[i1-1][k1-i1+1]+dp[i1-1][k1-i1]
          
          
Clearly:

dp[i1][k1] - dp[i1][k1-1] = dp[i1-1][k1]-dp[i1-1][k1-i1]

OR

dp[i1][k1]=dp[i1][k1-1]+dp[i1-1][k1]-dp[i1-1][k1-i1]

T.C= O(n*k)

Making sure k1-1 >=0 , i1-1>=0 , k1-i1 >=0



*/


// Recursive + tabulation (in bottum up manner)


#define lln long long int

int mod=1e9+7;

lln dp[1002][1002];

class Solution {
public:
    int kInversePairs(int n, int k) {
       
      memset(dp,-1,sizeof(dp));
        
        return find(n,k)%mod;
    
    }
    
     lln find(int i1,int k1){
      
        if(i1<=0 || k1<=0){
        
             if(k1==0)
                 return 1;
            
            
            return 0;
            
        }
        
        
        if(dp[i1][k1]!=-1)
            return dp[i1][k1];
        
      
         lln sum=(find(i1,k1-1)+find(i1-1,k1)-find(i1-1,k1-i1)+mod)%mod;
        
        return dp[i1][k1]=sum%mod;
         
    }

};
  
