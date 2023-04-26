class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
     
        int n=nums.size();
        
        int m=l.size();
        
        vector<bool>ans(m);
        
        for(int i=0;i<m;i++){
            vector<int>v;
            for(int j=l[i];j<=r[i];j++){
                v.push_back(nums[j]);
            }
            
            sort(v.begin(),v.end());
            
            if(v.size()<=2){
                ans[i]=true;
                continue;
            }
            
            int d=v[1]-v[0];
            
            bool f=true;
            
            for(int j=0;j<v.size()-1;j++){
                if(v[j+1]-v[j]!=d){
                    f=false;
                    ans[i]=false;
                    break;
                }
            }
            
            if(f)
                ans[i]=true;
        }
       
        return ans;
        
    }
};