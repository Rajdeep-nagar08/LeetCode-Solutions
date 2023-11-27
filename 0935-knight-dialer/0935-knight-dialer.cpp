// dp[i][j][k]=count of i digits no's that can be formed if start moving from from (j,k)
//from (i,j) we have 8 choices to move as per the move of knight

#define lln long long int
lln mod=1e9+7;

int dx[8]={2,2,-2,-2,1,1,-1,-1};
int dy[8]={1,-1,1,-1,2,-2,2,-2};

lln dp[5001][4][4]; 

class Solution {
public:
    int knightDialer(int n) {
        
        memset(dp,-1,sizeof(dp));
        
        lln ans=0;
        
        for(int i=0;i<4;i++){
            for(int j=0;j<3;j++){
                if((i==3 && j==0) || (i==3 && j==2))
                    continue;
                
                ans=(ans%mod+find(i,j,1,n)%mod)%mod;
            }
        }
        
        return ans%mod;
    }
    
    lln find(int i,int j,int len,int n){
    
        if(len==n){
            return 1;
        }
        
        if(dp[len][i][j]!=-1)
            return dp[len][i][j];
        
        lln count=0;
        
        for(int x=0;x<8;x++){
            int i1=i+dx[x];
            int j1=j+dy[x];
            
         if((i1==3 && j1==0) || (i1==3 && j1==2))
             continue;
    
        if(i1>=4 || i1<0 || j1>=3 || j1<0)
            continue;
                
         count=(count%mod+find(i1,j1,len+1,n)%mod)%mod;

        }
        
        return dp[len][i][j]=count%mod;
        
    }
};