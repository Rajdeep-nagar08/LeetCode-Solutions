  /*
      
      here we have choices
      so think about dp
      
        dp[i][j]=min no of operations needed to form n A's if currently we have i A's and no of copied A's =j
               

 */
        

int dp[1001][1001];

class Solution {
public:
    int minSteps(int n) {
      
      memset(dp,-1,sizeof(dp));
     
      return find(1,0,n);
        
    }
    
    int find(int i,int j,int n){
        
        if(i==n)
            return 0;
        
        if(i>n || j>n)
            return 1e6;
                    
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int ch1=1e6,ch2=1e6;
        
        if(i!=j)
        ch1=min(ch1,1+find(i,i,n));  //copy
        
        if(j!=0)
        ch2=min(ch2,1+find(i+j,j,n)); //past

        return dp[i][j]=min(ch1,ch2);
        
    }
};