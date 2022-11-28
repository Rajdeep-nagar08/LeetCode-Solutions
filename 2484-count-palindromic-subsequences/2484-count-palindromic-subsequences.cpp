int mod=1e9+7;

#define lln long long int


int dp[10][10][5][10001];


class Solution {
public:
    int countPalindromes(string s) {
       
        
        int n=s.size();
                
        memset(dp,-1,sizeof(dp));
        
        return find(0,0,0,0,s)%mod;
        
    }
    
    
    int find(int f,int s,int pos,int idx,string &str){
        
        
        if(idx>=str.size())
        {
            if(pos>=5){

                return 1;
                
            }

            return 0;
        }
        
        if(pos>=5){
            return 1;
        }
        
        if(dp[f][s][pos][idx]!=-1)
            return dp[f][s][pos][idx];

        
        int ans1=0,ans2=0,ans3=0;
        
        ans1+=find(f,s,pos,idx+1,str);
        
        ans1%=mod;
       
        if(pos<=2){
            
            int no=str[idx]-'0';
            
            if(pos==0)
                ans2+=find(no,s,pos+1,idx+1,str);
            else if(pos==1)        
            ans2+=find(f,no,pos+1,idx+1,str);
            
            else
                
                ans2+=find(f,s,pos+1,idx+1,str);
 
            
            ans2%=mod;
        }
        
    
        else{
            
            
        int no=str[idx]-'0';
            
            if(pos==3 && (no==s))
                 ans3+=find(f,s,pos+1,idx+1,str);
            
            if(pos==4 && (no==f))
                ans3+=find(f,s,pos+1,idx+1,str);

            ans3%=mod;
        }
       
            
        return dp[f][s][pos][idx]=(ans1+ans2+ans3)%mod;

        
    }
};