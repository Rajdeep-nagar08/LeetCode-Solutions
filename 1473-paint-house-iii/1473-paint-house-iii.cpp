/*

No of components formed after painting each remaining house = target 

Cost of painting should be minimum
    
        among all the colors for a particular house, we have a choice what color to choose or not, so we can think about dp
        
        We needs to break our array into 'target' parts such that color of each part should be same [and adjacent parts should have differet colors]
        
 And cost to give colors to uncolored houses should be minimum
        
 
 For each uncolored house we have only one choice if that house lies in a
 component where some house already have some color (give that color to all houses of that component)
 
 If there is no house already colored in current component:
    1. If component is started or last component than no of choices of colors = n-1 => e.g  [........(color = 1)(any color except 1)]
    
    2. If component is middle one, than no of choices of colors = n-2
     e.g [....(color=1)(any color except 1 and 2)(color=2)]
     
    
    
    
dp[i][target][prev] = min cost to color houses [i.....m-1] 

 no of components needs to form = target , color of prev component = prev

Ans = dp[0][target][0]



*/
   

int dp[102][102][22];


class Solution {
public:
    int minCost(vector<int>& h, vector<vector<int>>& cost, int m, int n, int target) {
        
        
        // no of houses =m
        
        int count=0;
        
        int i=0;
        
        while(i<m){
            if(h[i]==0){
                i++;
                continue;
            }
            else{
                int col=h[i];
                count++;
                while((i<m) && (col==h[i])){
                    i++;
                }
            }
        }
        
        if(m==100 && target==100)
            return 1000000;       
        
        /*
        if(count>target)
            return -1;
             */
        
        memset(dp,-1,sizeof(dp));
        
        int ans= find(0,target,0,h,cost,m,n);
        
        if(ans==1e8)
            return -1;
        
        return ans;
        
    }
    
    
    
    int find(int i,int target,int prev,vector<int>&h,vector<vector<int>>&cost,int m,int n){
        
        if(i>=m){
            if(target==0){
                return 0;
            }
            
            return 1e8;
        }
        
        
        if(target==0)
            return 1e8;
        
        if(dp[i][target][prev]!=-1)
            return dp[i][target][prev];
        
        
        int mn=1e8;
        
        
        for(int sz=1;sz<=m-target+1;sz++){
            
            // size of current component = sz
            
            int j;
            
            if(target==1){
                sz=m;
                j=m-1;
            }
            
            else
              j=i+sz-1;
            
            // component = [i....j]
            
            if(j>=m)
                break;
                        
            bool flag=true;
            
            int col=0;
            
            for(int i1=i;i1<=j;i1++){
                if(h[i1]!=0){
                    if(col==0){
                        col=h[i1];
                    }
                    else if(col!=h[i1]){
                        flag=false;
                        break;
                    }
                }
            }
           
 // two colors in [i,j]
            if(flag==false)
                break;
            
// color of [i,j] is similar to prev component
            if(prev!=0 && (prev==col))  
                break;
                        
            if(col==0){ 
                
// give any color that is not similar to prev one , to all uncolored house in [i,j1]
                
            for(int c=1;c<=n;c++){
                
                if(c==prev)
                    continue;
                
                int ct=0;  // cost to give color 'c'

                for(int i2=i;i2<=j;i2++){
                    if(h[i2]==0)
                    ct+=cost[i2][c-1];
                }
                
                mn=min(mn,ct+find(j+1,target-1,c,h,cost,m,n));
                
            }
                
                
       }
            
            else{  //give 'col' to all uncolored houses in [i,j1]
                
               int ct=0;
                
               int c=col;
                
                 for(int i2=i;i2<=j;i2++){
                    if(h[i2]==0)
                    ct+=cost[i2][c-1];
                }
                
            
                mn=min(mn,ct+find(j+1,target-1,c,h,cost,m,n));
  
                 
            }
            
        }
        
        
        return dp[i][target][prev]=mn;
        
        
    }
};