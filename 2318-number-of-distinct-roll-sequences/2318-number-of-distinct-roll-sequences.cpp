

int mod=1e9+7;

#define lln long long int


lln myDP[10001][7][7];


class Solution {
public:
    int distinctSequences(int n) {
        
        memset(myDP,-1,sizeof(myDP));
        
        return solve(0,0,0,n)%mod;
             
    }
    
     
    
    lln solve(int i,int p1,int p2,int n){
        
        if(i>=n){
            return 1;
        }
        
        lln c=0;
        
        if(myDP[i][p1][p2]!=-1)
            return myDP[i][p1][p2];
        
        
        for(int k1=1;k1<=6;k1++){
            
            if(k1==p1 || k1==p2)
                continue;
            
            
            if(k1==p2)
                continue;
            
            
            if(p1==0)
                c=c+solve(i+1,k1,p1,n)%mod;
          
            else{
                
                
            int g=gcd1(k1,p1);
            
            if(g==1){
            
            c=c+solve(i+1,k1,p1,n)%mod;
                
              }
                
                
                
            }
        }
        
        
        return myDP[i][p1][p2]=c%mod;

    }
    
    
    int gcd1(int a1, int b1) {
         
         
         if (a1 == 0)
       return b1;
         
         
         
    if (b1 == 0)
       return a1;
  
    if (a1 == b1)
        return a1;
         
         
  
    if (a1 > b1)
        return gcd1(a1-b1, b1);
         
         
         
    return gcd1(a1, b1-a1);
         
         
    }

};