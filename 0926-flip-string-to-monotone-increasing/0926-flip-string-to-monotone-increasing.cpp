
class Solution {
public:
    int minFlipsMonoIncr(string s) {
//WITHOUT DP, when one comes,no option
// One zero comes=> two options , either make present zero to 1,or make all previous 1's to 0
        
        int prevOnes=0;
        
        int flip=0;
        
        for(char c:s){
            if(c=='1')
                prevOnes++;
            else if(c=='0')
                flip=min(flip+1,prevOnes);
        }
            return flip;
    }
};

/* USING DP
        
        int n=s.length();
        
        vector<vector<int>>dp(n,vector<int>(2));
        if(s[0]=='0'){
            dp[0][0]=0;
            dp[0][1]=1;
        }
        else{
            dp[0][0]=1;
            dp[0][1]=0;
        }
        
        for(int i=1;i<n;i++){
            
            if(s[i]=='0'){
            
dp[i][1]=min(dp[i-1][0],dp[i-1][1])+1;
    
 dp[i][0]=dp[i-1][0];
                }
    else{
dp[i][1]=min(dp[i-1][0],dp[i-1][1]);
dp[i][0]=dp[i-1][0]+1;
        
        
    }
        }
        
return min(dp[n-1][1],dp[n-1][0]);
        
        
    }
};


dp[i][bool]= min no of flips to make string [0..i]
monotonic increasing if last char is 1(bool=true)//0(bool =false)

dp[0][1]=s[i]=='1'?0:1
dp[0][0]=s[i]=='0'?0:1

Ans=min(dp[n-1][1],dp[n-1][0])

dp[i][1]= min(dp[i-1][0],dp[i-1][1]) + s[i]=='0'?1:0
dp[i][0]= dp]i-1][0]+ s[i]=='0'?0:1

*/



