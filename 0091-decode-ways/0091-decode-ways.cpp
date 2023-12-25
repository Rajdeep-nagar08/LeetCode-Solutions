/*


12=> there are diffrent ways to break it:-

1|2  OR 12

As we have choices, we can think about dp



226 => 2|26  2|2|6  22|6



dp[i] = no of ways to break [i......n-1]


ANS= dp[0]

*/

int dp[101];

class Solution {
public:
    int n;
    int numDecodings(string s) {
        
        
        n=s.size();
        
        
        memset(dp,-1,sizeof(dp));
        
        
        return find(0,s);
        
    }
    
    int find(int i,string s){
        
        if(i>n)
            return 1;
        
        if(dp[i]!=-1)
            return dp[i];
        
        if(s[i]=='0')
            return 0;
        
        int ch1=find(i+1,s);
        
        int ch2=0;
        
        if(s[i]<='1' && i+1<n){
            
              ch2=find(i+2,s);
            
        }
        
        else if(s[i]=='2' && i+1<n && s[i+1]<='6'){
            
            ch2=find(i+2,s);
            
        }
        
        
        return dp[i]=ch1+ch2;
        
    }
};