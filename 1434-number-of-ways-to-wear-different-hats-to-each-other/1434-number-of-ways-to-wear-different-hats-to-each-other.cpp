  
        /*
        
        either give hats to peoples (optimal here as peoples < no of hats hats)
        (mask used to store the info of peoples having hats , as no of peoples =10 , so max size of mask = (1<<10)-1 
        
        or give peoples to hat
        (mask used to store the info of hats whether it is weared by any people or not , as no of hats = 40, so max size of mask = (1<<40)-1
        
        So optimal way is to give hats to peoples 
         
         dp[i][mask]=no of ways to give hat from [i....40] to peoples , here mask represent the person already having hats
       
       if(mask>>i)&1 !=0)  or (mask&(1<<i) !=0) it means person i having hat
       
       for a particular hat , we have two choices 
       1) not give it to any-one
       2) give it to someone who can wear it and not have any hat till now
         (so first store the information of all persons who wear particular type of hat)
       
         
         Ans=dp[1][0];   // hats start from [1.....40]
         
        */

        
int mod=1e9+7;

int dp[41][1024];   // 1<<10 == 1024

class Solution {
public:
    int numberWays(vector<vector<int>>& hats) {
       
        int n=hats.size();
        
        memset(dp,-1,sizeof(dp));
        
        vector<vector<int>>v(41);
        
        // v[h]= peoples who weared hat h
        
        for(int i=0;i<n;i++){
         for(int j=0;j<hats[i].size();j++){
                int h=hats[i][j];  
                v[h].push_back(i);
            }
        }
        
        return find(1,0,(1<<n)-1,v);
    }
    
    int find(int h,int mask,int total,vector<vector<int>>&v){
        
// given different hats to each people (one way completed)
        if(mask==total)
            return 1;
        
        if(h>40)  // no more hat left to give, (this way not completed , return 0)
            return 0;
        
        if(dp[h][mask]!=-1)
            return dp[h][mask];
        
        int ans=find(h+1,mask,total,v);  
        // not give this hat to any person
        
        for(int j=0;j<v[h].size();j++){  
            // give this hat to valid person p (who can wear it but not have any hat till now)
               int p=v[h][j];    
            
            if(((mask>>p)&1)==1)
            continue;
            
            ans+=find(h+1,mask|(1<<p),total,v);
            ans=ans%mod; 
        }
    
        return dp[h][mask]=ans;
    }
};