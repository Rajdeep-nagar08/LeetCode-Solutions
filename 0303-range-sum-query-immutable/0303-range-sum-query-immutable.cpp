class NumArray {
public:
    
    int n;
    
    vector<int>v;
    
    NumArray(vector<int>& nums) {
        
        
       n=nums.size(); 
        
        v.resize(n,0);
        
        v[0]=nums[0];
        
        for(int i=1;i<n;i++){
            v[i]=v[i-1]+nums[i];
        }
        
    }
    
    int sumRange(int l, int r) {
        
        if(l==0){
            return v[r];
        }
        
        return v[r]-v[l-1];
        
    }
};
