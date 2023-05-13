class Solution {
public:
    int kIncreasing(vector<int>& arr, int k) {
       
        int n=arr.size();
        
        /*
        
        arr[i-k] <= arr[i]  where k<=i<=i
        
       In one operation we can change any integer to any other integer 
        
       Min. no of operations to make array increasing = ?
       
        */
        
        int ans=0;
        vector<int>vis(n,0);
        
        for(int i=0;i<k;i++){
            
            int j=i;
            
            vector<int>v;
            
            while(j<n){
                v.push_back(arr[j]);
                j=j+k;
            }
            
            int sz=v.size();
            
// find length of longest increrasing subsequence(LIS) in this array
// lis should also count duplicates
            
            //min no of changes needs to do = sz-lis
            
            
            int lis=lengthOfLIS(v);
                        
            ans+=sz-lis;
           
        }
        return ans;
       
    }
    
    
    int lengthOfLIS(vector<int>& arr) {
       int n=arr.size();
       vector<int>lis;
        
        for(int i=0;i<n;i++){
          auto it=upper_bound(lis.begin(),lis.end(),arr[i]);
          if(it==lis.end())
              lis.push_back(arr[i]);
          else
            *it=arr[i];
        }
        return lis.size();
      }
            
};