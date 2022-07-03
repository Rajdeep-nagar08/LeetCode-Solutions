/*

for each element we have choices, either select it in the sequence or not select it

So we can think about dp

dp[i][j][2]= max. length wiggle subseq. we can formeed if previous choosen index is i and element j should be smaller/greater than i , 0 for smaller , 1 for greater

*/

int dp[1001][1001][2];

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        
        int n=nums.size();
       
        memset(dp,-1,sizeof(dp));
        
        int ans=0;
        
        for(int i=0;i<n;i++){
        ans= max({ans,1+find(i,i+1,0,nums),1+find(i,i+1,1,nums)});
            
        }
        
        return ans;
        
    }
    
    int find(int i,int j,int need,vector<int>&nums){
        
        
        if(j>=nums.size())
            return 0;
        
        if(dp[i][j][need]!=-1)
            return dp[i][j][need];
        
        int c1=0,c2=0;
        
        c1+=find(i,j+1,need,nums);
        
       if(need==0) // j should be smaller
       {
         
           if(nums[j]<nums[i])
               c2+=1+find(j,j+1,1,nums);
   
       }
        
        else{
            
            if(nums[j]>nums[i])
                c2+=1+find(j,j+1,0,nums);
        }
        
       return dp[i][j][need]=max(c1,c2); 
    }
};