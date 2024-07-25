class Solution {
public:
    vector<int>v;
    
    vector<int> sortArray(vector<int>& nums) {
     
        int n=nums.size();
        
        v.resize(n,0);
                
        merge_sort(0,n-1,nums);
        
        return nums;
    }
    
    void merge_sort(int i, int j, vector<int>&nums){
        if(i>=j)
            return;
        
        int mid=(i+j)/2;
        
        merge_sort(i, mid,nums);
        merge_sort(mid+1,j,nums);
        merge(i, mid,j,nums);
    }
    
    void merge(int i, int mid,int j,vector<int>&nums){
        
       int i1=i;
        
       int i2=mid+1;
        
       int idx=i; 
        
        while(i1<=mid && i2<=j){
           if(nums[i1]<=nums[i2]){
               v[idx]=nums[i1];
               idx++,i1++;
           }
            else{
                v[idx]=nums[i2];
                idx++,i2++;
            }
        }
        
        while(i1<=mid){
           v[idx]=nums[i1];
            idx++,i1++;
        }
        
        while(i2<=j){
            v[idx]=nums[i2];
            idx++,i2++;
        }
        
        
        for(int k=i;k<=j;k++){
            nums[k]=v[k];
        }
        
        
        return;
        
    }
};