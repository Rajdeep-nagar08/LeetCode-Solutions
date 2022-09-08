/*


dp[char1][char2] = no of distinct subsequences of type starting with char1 and ends with char2

where char1=['a','z'] and char2=['a','z'];


if(s[char1]='a'){

  we can stick this 'a' to any subsequence
  
  so dp[any char]['a'] increases to
  
  dp[any char]['a'] = sum(dp[any char][any char])
  
  
}


ans= sum(dp[any char][any char])

*/

int mod=1e9+7;

int dp[26][26];

class Solution {
public:
    int distinctSubseqII(string s) {
      
       // memset(dp,0,sizeof(dp));
        
        for(int i=0;i<=25;i++){
            for(int j=0;j<=25;j++){
                dp[i][j]=0;
            }
        }
        
        for(char ch:s){
            
             // dp[ch-'a'][ch-'a']=1;
                
                // aa,ba,ca,da,ea----increasing their value
            
                for(char ch1='a';ch1<='z';ch1++){
                                        
                    int sum=0;

                    for(char ch2='a';ch2<='z';ch2++){
                 
                      sum+=dp[ch1-'a'][ch2-'a']+(ch1==ch && ch2==ch);
                                        
                      sum%=mod;
                }
                
                    dp[ch1-'a'][ch-'a']=sum%mod;

            }
                
    }
        
        int sum=0;
        
            for(char ch1='a';ch1<='z';ch1++){
                
                for(char ch2='a';ch2<='z';ch2++){
                    
                    sum=(sum+dp[ch1-'a'][ch2-'a'])%mod;
                    
                    sum%=mod;
                    
                }
            }
        
        return sum;
        
    }
};