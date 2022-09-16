/*

at each step we have two choices

either select x from start of nums or from last


dp[i][j]= max score we can get from nums[i.....j] , we have already done

(i+1)+(n-j) steps

As size of mult. array <=1000 , so our max steps cannot be greater then 1000

it means i<=1000 , and j<=1000

but as we are taking j as a index so it will rise above 1000 as size of nums array can be upto 1e5



dp[i][j]= max score we can get if we are currently at ith no. from front and jth no. from back in nums array , nums[ith from front......jth from back]

So front index = i1 = i-1

back index = i2 = n+(j-1)



*/


#define lln long long int

int dp[1001][1001];

class Solution {
public:
    int n,m;
    
    int maximumScore(vector<int>& nums, vector<int>& mult) {
                
        n=nums.size();
        
        m=mult.size();
        
   //     memset(dp,-1,sizeof(dp));   not do so as ans can be -1
        
        for(int i=0;i<=m;i++){
            for(int j=0;j<=m;j++){
                dp[i][j]=INT_MIN;
            }
        }
        
        
       
        return find(1,1,nums,mult);
        
    }
    
    lln find(int i,int j,vector<int>&nums,vector<int>&mult){
        
        if(i>m || j>m)
            return 0;
        
        if(dp[i][j]!=INT_MIN)
            return dp[i][j];
        
        lln ch1,ch2;
        
        int i1=i-1;
        
        int j1=n-j;
        
        int steps=(i1+1)+(n-j1);
        
        int idx=steps-2;
        
        if(idx>=m)
            return 0;
            
        ch1=mult[idx]*nums[i1]+find(i+1,j,nums,mult);
        
        ch2=mult[idx]*nums[j1]+find(i,j+1,nums,mult);
        
    //    cout<<ch1<<" "<<ch2<<endl;
        
        return dp[i][j]=max(ch1,ch2);
        
    }
};