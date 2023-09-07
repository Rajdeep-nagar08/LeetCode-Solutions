int n;

int dp[1000][1000];

class Solution {
public:
    int longestDecomposition(string t1) {
        
        n=t1.size();
        
        memset(dp,-1,sizeof(dp));
        
        string t2=t1;
        
        reverse(t2.begin(),t2.end());
        
        /*
        
        if t1[i....j] == reverse(t2[i....j])
        {
          then two choices, 
          i=j+1, ans++
          
          OR

          j++
        
        }
        
        else{
        
           j++
        }
        
        */
        
        
        return find(0,0,t1,t2)-1;
        
    }
    
    int find(int i,int j,string &t1, string &t2){
        
        if(j>=t1.size()){
            
            string x=t1.substr(i);
            
            string y=t2.substr(i);
            
            reverse(y.begin(),y.end());
    
            if(x==y)
                return 1;
            
            return -2000;
            
        }
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int ans1=-1, ans2=-1;
        
        
           string x=t1.substr(i,j-i+1);
            
            string y=t2.substr(i,j-i+1);
            
            reverse(y.begin(),y.end());
    
        
        if(x==y){
            
            ans1=1+find(j+1,j+1,t1,t2);
    
            
        }
        
        
        ans2=find(i, j+1, t1, t2);
        
        
        return dp[i][j]= max(ans1, ans2);
        
        
    }
    
    
    
};