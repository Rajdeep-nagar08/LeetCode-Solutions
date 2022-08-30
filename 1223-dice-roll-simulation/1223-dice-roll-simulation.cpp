/*

cann't generate the no. i more than rollMax[i] consecutive times


No of rolles = n

Each roll can generate any no.


No of distinct sequences can be generated ?


dp[i][prev=6][count=15] = number of seqquences that can be obtained by filling [i...n-1], if no. at previous index is 'prev' whose continous length till previous index is = count

Ans= dp[0][0][0]

*/

int mod=1e9+7;

int dp[5001][7][16];

class Solution {
public:
    int dieSimulator(int n, vector<int>& rollMax) {
        
       memset(dp,-1,sizeof(dp));    
       
       return find(0,0,0,n,rollMax)%mod;
    }
    
    int find(int i,int prev,int count,int n,vector<int>&rollMax){
        
        if(i>=n)
            return 1;
        
        if(dp[i][prev][count]!=-1)
            return dp[i][prev][count];
        
        int ans=0;
        
        for(int j=1;j<=6;j++){
            
            if(prev==j){
              
              if(count+1<=rollMax[j-1])
                  ans+=find(i+1,prev,count+1,n,rollMax);
                ans%=mod;
                
            }
            
            else{
                
                ans+=find(i+1,j,1,n,rollMax);
                
                ans%=mod;
            }
            
        }
        
        return dp[i][prev][count]=ans%mod;
        
    }
};