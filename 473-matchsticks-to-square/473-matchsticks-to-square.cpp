 
        // each matchstick must be used exactly ones
        
        // sum%4 should be zero
        
        // length of each side= sum/4
        
        // now question changes to, Is it possible to make 4 sets using n elements such that the sum of each set = sum/4
        
        // try all possible ways to form 4 sets , we can try backtracking as 
        // Backtracking gives TLE

        // ecah number has 4 choices (regarding four sides)


/*

Backtracking gives TLE


#define lln long long int
class Solution {
public:
    bool makesquare(vector<int>& mt) {
        
        int n=mt.size();
       
        bool ans=false;
        
        lln sum=0;
        
        for(int x:mt){
            sum+=x;
        }
        
        if(sum%4!=0)
            return false;
        
        lln need=sum/4;
        
        vector<lln>temp(4);
                
        find(0,temp,ans,need,mt);
        
        return ans; 
        
    }
    
    
    void find(int i,vector<lln>temp,bool &ans,lln &need,vector<int>&mt){
        
        
        if(i>=mt.size()){
            bool f=true;
            for(int k=0;k<4;k++){
               if(temp[k]!=need){
                   f=false;
                   break;
               }     
            }
           
            if(f)
                ans=true;
            
            return;
        }
        
        
        if(ans)
            return;
    
        for(int j=0;j<4;j++){
            
            lln sum=temp[j];
            
            if(temp[j]==need)
                continue;
            
            else if(temp[j]+mt[i]<=need)
                temp[j]+=mt[i];
            
            else
                return;
            
            find(i+1,temp,ans,need,mt);
        
            if(sum+mt[i]<=need)
                temp[j]-=mt[i];
            
        }
        
         
    }
    
};


*/


// DP with BIT masking

// as for each number we have 4 choices, 

// we can think about dp

// dp[i][mask] = Is it is possible to make all sides from [i...4-1] to be valid sides of square , here mask stores all the numbers that have already used in some sides

// ans=dp[0][0]


int dp[5][1<<16];

#define lln long long int

class Solution {
public:
    bool makesquare(vector<int>& mt) {
        
        int n=mt.size();
               
        lln sum=0;
        
        for(int x:mt){
            sum+=x;
        }
        
        if(sum%4!=0)
            return false;
        
        lln need=sum/4;
                
        memset(dp,-1,sizeof(dp));
        
        vector<lln>temp(4);
                
        int ans= find(0,0,(1<<n)-1,temp,need,mt);
        
        if(ans==1)
            return true;
        
        return false;
                        
    }
    
    
int find(int j,int mask,int maskNeeded,vector<lln>&temp,lln &need,vector<int>&mt){


        
        if(j>=4){
                       
            if(mask!=maskNeeded)
                return 0;
            
            for(int k=0;k<4;k++){
               if(temp[k]!=need)
                   return 0;
            }
            
            return 1;
        }
    
        
        if(dp[j][mask]!=-1)
            return dp[j][mask];
    
       int ans=0;
    
        for(int i=0;i<mt.size();i++){
            
            if(temp[j]==need)
                
        ans=(ans|find(j+1,mask,maskNeeded,temp,need,mt));
            
                        
    if((mask & (1<<i))!=0 || (temp[j]+mt[i]>need))  
                continue;
           
           // if(temp[j]+mt[i]<=need){
                
                temp[j]+=mt[i];
                                
    ans=(ans|find(j,mask|(1<<i),maskNeeded,temp,need,mt));
             
                temp[j]-=mt[i];
                
           // }
        
       }
    
         return dp[j][mask]=ans;
    
    }
    
    
};
