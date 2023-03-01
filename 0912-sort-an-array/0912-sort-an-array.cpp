class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        
        merge_sort(nums,0,nums.size()-1);
        
        return nums;
    }
    
     void merge_sort(vector<int>&nums,int l,int r){
         if(l>=r)
             return ;
         
         int mid=(l+r)/2;
         
         merge_sort(nums,l,mid);
         merge_sort(nums,mid+1,r);
         merge(nums,l,mid,r);
     }
    
     void merge(vector<int>& nums,int l,int mid,int r){
    
        int n1=mid-l+1;
        int n2=r-(mid+1)+1;
         
         vector<int>left(n1),right(n2);
         
         for(int i=l;i<=mid;i++)
             left[i-l]=nums[i];
         
         for(int i=mid+1;i<=r;i++)
             right[i-mid-1]=nums[i];
         
         int i=0,j=0;
         
         int k=l;
         
         while(i<n1 && j<n2){
             if(left[i]<right[j]){
                 nums[k]=left[i];
                 i++;
                 k++;
             }
             else{
                 nums[k]=right[j];
                 j++;
                 k++;
             }
         }
         
         while(i<n1){
             nums[k]=left[i];
             i++;
             k++;
         }
         
         while(j<n2){
             nums[k]=right[j];
             j++;
             k++;
         }
     }
};