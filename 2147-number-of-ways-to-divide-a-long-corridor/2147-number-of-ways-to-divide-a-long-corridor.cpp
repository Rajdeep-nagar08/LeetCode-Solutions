 /*
        
        each section should have atleast two seats
        
        , at particular point we have two choices=> either put divider at this index or not put any divider here 
        
        considering a rule that there should exactly two seats between two dividers
        
         AS we have choices so think about dp
          
        We needs to count all the ways that originate from all possible choices
        
        
        dp[i][count] = no. of ways to divide the corrider [i...n-1]
        
        we are currently at index i,
        
        count=0, if there is no seat btw previous divider and index i
        
        count=1, if there is 1 seat btw previous divider and index i 
        
        count=2 , if there are 2 setas btw previous divider and inde>=2
        
        Note that if count>2, it means no of seats between previous divider and i>2 , so never put any divider otherwise no of seats between previous and that divider > 2
        
        
        */
        
        

#define lln long long int

int mod=1e9+7;

int dp[100001][4];

class Solution {
public:
    int numberOfWays(string corr) {
        
        int n=corr.size();
    
        memset(dp,-1,sizeof(dp));
        
        return find(0,0,n,corr)%mod;
      
    }
    
      lln find(int i,int count,int n,string &corr){
          
          if(i>=n){
// there should be two sets after last divider becouse its given that there is one divisor out of the array
              if(count==2)  
              return 1;
              else
                return 0;
          }
          
          if(count>2)
              return 0;
          
          if(dp[i][count]!=-1)
              return dp[i][count];
          
          lln c1=0,c2=0;
          
           if(count==2){
              
        c1+=find(i+1,corr[i]=='S',n,corr); // put divider just before i
               

        c2+=find(i+1,count+(corr[i]=='S'),n,corr);  // not put divider before i
               
           }
         
          
          else if(count<2){
              
 c2+=find(i+1,count+(corr[i]=='S'),n,corr); // not put divider before i
              
          }
          
          return dp[i][count]=(c1+c2)%mod;
      }
};