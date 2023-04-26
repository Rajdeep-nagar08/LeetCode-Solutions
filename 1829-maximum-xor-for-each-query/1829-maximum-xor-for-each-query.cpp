class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maxB) {
        
        int n=nums.size();
        
        vector<int>v(n);
        
        v[0]=nums[0];
        
        for(int i=1;i<n;i++){
            v[i]=nums[i]^v[i-1];
        }
        
        reverse(v.begin(),v.end());
        
        vector<int>ans(n);
        
        for(int i=0;i<n;i++){
            int x=v[i];
            int no=0;
            // cout<<x<<endl;
            
            for(int j=1;j<=maxB;j++){
                if((x & (1<<(j-1)))==0){
                    no=no|(1<<(j-1));
                }
            }
            ans[i]=no;
        }
        return ans;
    }
};