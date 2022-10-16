/*

needs to to atleat one job every day , needs to finish all jobs
needs to complete jobs in a sequence
diificulty of a day= max diff. among all jobs doneo on the day

Ans= minimum diff of job schedule


It means we needs to distribute given array into d continous parts 
such that sum of max. of each part becomes as minimum as possible

for each no we to decide whether to include it in the
current part or not include

we can think of dp as:-

dp[i][d1]= min. difficulty till now if we are on ith element and left with d1 parts

dp[i][d1]= min(max(arr[i]...arr[j]) + dp[j+1][d1-1])  , 
j=i+1,i+2,i+3...j1 , till (such that atleast one job left for each remaining days)
n-j1-1>=d1-1

we are including [i.....j] in part no d1

Ans[0][d]


*/

int dp[301][11];

class Solution {
public:
    int minDifficulty(vector<int>& arr, int d) {
        int n= arr.size();
       
        if(n<d)
            return -1;
        
        if(n==d){
            int sum=accumulate(arr.begin(),arr.end(),0);
            return sum;
        }
        
        for(int i=0;i<=300;i++){
            for(int j=0;j<=10;j++){
                dp[i][j]=1e6;
            }
        }
    
        int ans= solve(0,d,arr);
        
        if(ans >=1e6)
            return -1;
        
        return ans;
    }
    
    int solve(int i,int d1,vector<int>&arr){
       
        if(arr.size()-i<d1)  // not possible to fill all d1 parts
            return 1e6;
         
         if(d1==1){  // if there is only 1 part left , give all the remaining no's to this
             if(i>=arr.size()) // if no number left
                 return 1e6;
            return maxVal(i,arr.size()-1,arr);
        }
        
       
        if(dp[i][d1]<1e6)
            return dp[i][d1];
        
     //   int j1=d1-arr.size();
        
        for(int j=i;j<arr.size()-1;j++){
            
            dp[i][d1]= min(dp[i][d1],maxVal(i,j,arr)+solve(j+1,d1-1,arr));
        }
        
        return dp[i][d1];
        
    }
    
    
    int maxVal(int i,int j,vector<int>&arr){
        int mx=INT_MIN;
        for(int k=i;k<=j;k++){
            mx=max(mx,arr[k]);
        }
        return mx;
    }
};