/*

No. of subarray's whose sum = k

sum[i]=sum[0....i]

let there is an index j<i, in an array such that sum[j]=sum[i]-k ,
then , sum[i]-sum[j]= sum[(i.....j)]=k ,sum of subarray(i,,,j)=k 

then no of subarrays till i whose sum is k= no of subarrays till i whose sum=sum[i]-k

To store the sum[i] and their count, we can use unordered_map




class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        mp[0]=1;  //there is one subarray whose sum=0 =>{empty subarray}
      
      int sum=0;
      int count=0;
      for(int i=0;i<nums.size();i++){
        sum+=nums[i];
        int need=sum-k;
        count+=mp[need];
        mp[sum]++;
        
      }
      return count;
    }
};


*/

/*

LOGIC : make prefix sum for each row means: mat[i][j]+=mat[i][j-1]

now, for each pair of columns (c1,c2)

c1       c2
|         |
|         |
|         |




sum=0
(k=0;k<n;k++)
unordered_map<int,int>mp;
mp[sum]= how many rows are there like (row0, row0+row2, row0+...rowk) whose sum=> sum (row range is between ca and c2)
sum+=(sum of kth row between c1 and c2)

Now let
mp[sum-target]= 1
it means there is exactly one set among (row0, row0+row1, row0......rowk) whose sum => sum-target, let its row0+row1+row2

then (row3+row4+row5+...rowk = target)
 so ans++;

*/



class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& mat, int tar) {
        
        int n=mat.size();
        
        int m=mat[0].size();
        
        for(int i=0;i<n;i++){
            for(int j=1;j<m;j++){
                mat[i][j]+=mat[i][j-1];
            }
        }
        
        int ans=0;
        
        for(int c1=0;c1<m;c1++){
            
            for(int c2=c1;c2<m;c2++){
                
                unordered_map<int,int>mp;
                                
                mp[0]=1;  //there is one subarray whose sum=0 =>{empty subarray}
                
                int sum=0;
                
                for(int k=0;k<n;k++){
                    
                    sum+=(mat[k][c2]-(c1==0?0:mat[k][c1-1]));
                    
                    if(mp.count(sum-tar)){
                        ans+=mp[sum-tar];
                    }
                    
                    mp[sum]++;
                }

            }
        }
        
        return ans;
        
    }
};