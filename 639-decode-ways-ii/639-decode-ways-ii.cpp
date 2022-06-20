/*

for each digit we have two choices , either take it alone or take it with next digit considering only numbers [1,26] only as valid formation

In case of start , take it as [1,9] all one by one

dp[i] = number of ways to decode string [i...n-1]

*/

#define lln long long int

int mod=1e9+7;

lln dp[100001];

class Solution {
public:
    int numDecodings(string s) {
        
        memset(dp,-1,sizeof(dp));
        
        
        return find(0,s)%mod;
        
    }
    
    lln find(int i,string &s){
        
        if(i>=s.size())
            return 1;
        
        if(dp[i]!=-1)
            return dp[i];
        
        lln c1=0,c2=0;
        
//////////////////////////////////////////////////////////////////
        
        if(s[i]!='*'){
           
            int n1=s[i]-'0';
            
            if(n1!=0)
            c1=(c1+find(i+1,s))%mod;
            
            if(i+1<s.size()){
                
                if(s[i+1]=='*'){
                    
                  if(n1==1)
                    c2=(c2+9*find(i+2,s))%mod;
                 else if(n1==2)
                     c2=(c2+6*find(i+2,s))%mod;
                 
                    
                }
                
                else{
                    
                int n2=s[i+1]-'0';
                
                if(n1==1)
                    c2=(c2+find(i+2,s))%mod;
              else if(n1==2 && n2<=6)
                   c2=(c2+find(i+2,s))%mod;
                
              }
            }
          }
        
   ///////////////////////////////////////////////////////     
        
        else{
            
            for(int k=1;k<=9;k++){
                
                c1=(c1+find(i+1,s))%mod;
                
                if(i+1<s.size()){
                    
                if(s[i+1]=='*'){
                    
                    if(k==1)
                    c2=(c2+9*find(i+2,s))%mod;
                    
                    else if(k==2)
                      c2=(c2+6*find(i+2,s))%mod;
                    
                    }
            
                else{
                    
                int n2=s[i+1]-'0';
                
               if(k==1)
                    c2=(c2+find(i+2,s))%mod;
              else if(k==2 && n2<=6)
                   c2=(c2+find(i+2,s))%mod;
                }      
            }      
          }  
        }

///////////////////////////////////////////////////////////////////////
        
        return dp[i]=(c1+c2)%mod;
        
    }
};