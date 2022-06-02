 /*
        
        No of possible ways to break s into parts such that 
        value of each part belonges to the range [1,k]
        NOTE : value shouldn't be 0 as 0 not belongs to [1,k]
        
        
        We have choices to break the string
        so we can think abount the dp
        
        
        dp[i]= no of ways to break the string [i...n-1]
        so that each part belongs to [1,k]
        
        MCM pattern -:
        
*/

#define lln long long int

int mod=1e9+7;

int dp[100001];

class Solution {
public:
    int numberOfArrays(string s, int k) {
        
        int n=s.size();
    
        memset(dp,-1,sizeof(dp));
        
        return find(0,s,k);
        
    }
    
      int find(int i,string &s,int k){
          if(i>=s.size())
              return 1;
          
          if(dp[i]!=-1)
              return dp[i];
          
          lln count=0;
          
          string str="";
          
          for(int j=i;j<s.size();j++){   
              // O(10) at most , so overall T.C = O(1e5*10) = O(1e6)
              str.push_back(s[j]);
              
              if(str.size()>10)
                  break;
              
              lln no=stol(str);
              
                  if(j<s.size()-1 && s[j+1]=='0')
                      continue;
              
              if(no>=1 && no<=k){
                  count+=find(j+1,s,k);
              }
              
          }
         
          return dp[i]=count%mod;
          
    }
};