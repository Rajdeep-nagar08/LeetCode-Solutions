/*

(top down approach)
dp[i][j] = longest string chain we can form if we are at word j and previous word was word i


(bottom up approach)
dp[i]= max(1+dp[j]) for all j>i , if j,i are valid pairs


*/

int dp[1001][1001];

class Solution {
public:
   
    int longestStrChain(vector<string>& words) {
       
        memset(dp,-1,sizeof(dp));
        
        sort(words.begin(),words.end(),[](string &s1,string &s2){
            return (s1.size()<s2.size());
                return true;
        });
        
        int n=words.size();
        
        int mx=1;
        
        string s1,s2;
        
        vector<bool>v(n,false);
        
        for(int i=1;i<n;i++){
            s1=words[i-1];
            s2=words[i];
            if(isValid(s1,s2))
                v[i-1]=true;
        }
            
        for(int i=0;i<n;i++){
        
            mx=max(mx,1+find(i,i+1,words,v));
        
    }
        
        return mx;
        
    }
    
    int find(int i,int j,vector<string>&words,vector<bool>&v){
        
        if(j>=words.size())
            return 0;
        
        
        if(dp[i][j]!=-1)
            return dp[i][j];
  
    int mx1=0,mx2=0;

 mx1=max(mx1,find(i,j+1,words,v));    // not choosing this j
        
  if(i+1==j){
      if(v[i]==true)
    mx2=max(mx2,1+find(j,j+1,words,v));

  } 
        
    else if(isValid(words[i],words[j]))              // choosing j
  mx2=max(mx2,1+find(j,j+1,words,v));
                 
                       
         return dp[i][j]=max(mx1,mx2);
        
    }
    
    
    bool isValid(string& s1,string& s2){
             
        int n1=s1.size();
        
        int n2=s2.size();
   
        if(n2-n1 !=1)
            return false;
        
        bool f1=true;
         
        bool f=true;

        int i1=0,j1=0;
       
            while(i1<n1 && j1<n2){
                if(s1[i1]==s2[j1])
                    i1++,j1++;
                else
                {
                    if(f==false){
                        f1=false;
                        break;
                    }
                    
                    f=false;
                    
                    j1++;
                }
            }
    
            
          if(f1)
              return true;
        
        return false;
    }
};

