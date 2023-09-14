int dp[2001][2001][2];

    
        /*
         
         dp[i][j][first/second]= max increasing subarray using arr1[i.....n-1] if previous no was from given array from jth index
        
        */

class Solution {
public:
    int n1,n2;
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        
         memset(dp,-1,sizeof(dp));
    
        n1=arr1.size();
        
        n2=arr2.size();
        
        sort(arr2.begin(),arr2.end());
        
        int ans= min(find(1,0,0,arr1,arr2),1+find(1,0,1,arr1,arr2));
        
        if(ans==3000)
            return -1;
        return ans;
    }
    
    int find(int i,int j,int ch,vector<int>&arr1,vector<int>&arr2){
        if(i>=n1){
            return 0;
        }
        
        if(dp[i][j][ch]!=-1)
            return dp[i][j][ch];
        
        int x=3000;
        
        int y=3000;
        
        if(ch==0){  // previous no. from arr1
            if(arr1[i]>arr1[j]){
                x=find(i+1,i,0,arr1,arr2);
            }
            
            
                int j1=upper_bound(arr2.begin(),arr2.end(),arr1[j])-arr2.begin();
                if(j1<n2){
                   y=1+find(i+1,j1,1,arr1,arr2);
                }
            
        }
        
        else{  // previous no. from arr2
            
            if(arr1[i]>arr2[j]){          
                x=find(i+1,i,0,arr1,arr2);
            }
        
                int j1=upper_bound(arr2.begin()+j,arr2.end(),arr2[j])-arr2.begin();
                if(j1<n2){
                   y= 1+find(i+1,j1,1,arr1,arr2);
                }
                
            
        }
        
        
        return dp[i][j][ch]=min(x,y);
    }
};