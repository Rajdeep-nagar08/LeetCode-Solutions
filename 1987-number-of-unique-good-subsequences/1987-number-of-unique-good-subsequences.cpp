
/*

we starting with "0" then stop, only one subsequence

otherwise on each position we have two choices , either take it or not take it


But how to avoid duplicates ?


dp[i][j]= no of distincnt subsequences starting with i and ends with j or look likes [i...j]

ans= dp[0][0]+dp[0][1]+dp[1][0]+dp[1][1]

if s[i]=='0'

then we stick this '0' to all subsequences of type [1....0] and [1...1]

so dp[1][0] increases to dp[1][0]+dp[1][1]

also we can make one subsequence of type "0" (dp[0][0])

so we make dp[0][0]=1


(NOTE subsequence of type [0...1] is not valid)

if s[i]=='1'

then we stick this '1' to all subsequences of type [1...0] and [1....1] , also we

can get one new subsequence that is "1"

so dp[1][1] increases to dp[1][0]+dp[1][1]+1


ans= dp[0][0]+dp[0][1]+dp[1][0]+dp[1][1]


*/

int mod=1e9+7;

int dp[2][2];

class Solution {
public:
    int n;
    int numberOfUniqueGoodSubsequences(string binary) {
      
        memset(dp,0,sizeof(dp));
        
        n=binary.size();
        
        for(char ch:binary){
            
            if(ch=='0'){
                dp[0][0]=1;
                dp[1][0]=dp[1][0]+dp[1][1];
                dp[1][0]%=mod;
            }
            else{
                dp[1][1]=dp[1][0]+dp[1][1]+1;
                dp[1][1]%=mod;
            }
        }
        
        return (dp[0][0]+dp[0][1]+dp[1][0]+dp[1][1])%mod;

        
    }
};