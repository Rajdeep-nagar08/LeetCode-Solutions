class Solution {
public:
    int mod=1e9+7;
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        if(n==0)
            return 0;
        vector<long long int>v;
        
       for(int i=0;i<n;i++){
           long long int sum=0;
           for(int j=i;j<n;j++){
               sum+=nums[j];
               v.push_back(sum);
           }}
        sort(v.begin(),v.end());
        long long int ans=0;
        for(int i=left-1;i<=right-1;i++)
            ans=(int)(ans+v[i] )%mod;
        return ans;
    }
};