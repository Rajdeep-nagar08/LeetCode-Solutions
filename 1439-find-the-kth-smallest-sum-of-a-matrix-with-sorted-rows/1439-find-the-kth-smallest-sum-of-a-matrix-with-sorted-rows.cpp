/*
lets try a problem of finding no of arrays (form by choosing 1 element from each row) whose sum=target,it can be done by dfs (start from 1st row , and for each row check each column till last row


int count=0;
dfs(r=0,sum=0,target,arr){
if(sum>target)
  return 0;
if(r==n-1 ){
if(sum==target)
  return 1;
 return 0;
 }
 
 for(int c=0;c<m;c++){
  int c= dfs(r+1,sum+arr[r][c],target,arr);
  count+=c;
  }
  return count;
 }
 
 
Binary search on Ans::::


 Now in this problem 
 min sum=l=n=no of rows
 max sum=h= n*5000
 
 mid=(l+h)/2
 
 Now we can binary search for each mid , we need to find the kth smallest sum or mid

so for each mid, if no of arrays whose sum<=mid are >=k, then mid can be our Ans Or Not so we store it as our ans and reduce the range to get just kth ans (or smaller mid) , if count of such ans's < k we need to increase our mid/ans so that ans will be kth smallest instead of (k-x)th smallest
   
   
*/




class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        
        int n=mat.size();
        int m=mat[0].size();
        
        int l=n,h=n*5000;
        int ans;
        
        while(l<=h){
            int mid=(l+h)/2;
            
         int count=dfs(0,0,mid,mat,k);
            if(count>=k){
                ans=mid;
                h=mid-1;
            }
            else
             l=mid+1;
        }
        return ans;
    }
    

    int dfs(int r,int sum,int target, vector<vector<int>>&arr,int k){
        if(sum>target)
            return 0;
        if(r==arr.size())
            return 1;
        int ans=0;
        for(int c=0;c<arr[0].size();c++){
             int cnt=dfs(r+1,sum+arr[r][c],target,arr,k-ans);
            if(cnt==0)
                break;
           ans+=cnt;
            if(ans>k)
                break;
        }
        return ans;
            
    }
};