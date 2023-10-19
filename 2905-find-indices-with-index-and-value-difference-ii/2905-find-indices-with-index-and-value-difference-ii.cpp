class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int id, int vd) {
        
        int n=nums.size();
        
        /*
        
        abs(i-j) > = id
        
        i-j >=id if(i>=j) so, j<=i-id
        
        j-i >=id if(j>=i) so j>=i+id
        
        
        
        nums[i]-nums[j] >= vd if(nums[i]>=nums[j]) so nums[j]<=nums[i]-vd
        
        nums[j]-nums[i] >=vd if(nums[j]>=nums[i]) so nums[j]>=nums[i]+vd
        
        
        
        
        so for
        
        [i......j]
        
        if
        
        j >= i+id
        
        and
        
        if(nums[i]>=nums[j]) and nums[j]<= nums[i]-vd )== true 
        
    
        or 
        
        if(nums[j]>=nums[i]) and nums[j]>=nums[i]+vd) == true
        
        return {i,j}
        
        
        
        SIMILAR TO
        
        
        [i......j]
        
        if 
        
        j>= i+id
        
        and
        
        (nums[i] <= nums[j]-vd || nums[i]>=nums[j]+vd)
        
        return {i,j}
        
        
        
        */

        
        vector<pair<int,int>>v1(n); // max(nums[j]-vd)
        
        vector<pair<int,int>>v2(n);  // min(nums[j]+vd)
        
        v1[n-1]={nums[n-1]-vd,n-1};
        
        v2[n-1]={nums[n-1]+vd,n-1};
        
        for(int i=n-2;i>=0;i--){
            
            if(nums[i]-vd>v1[i+1].first){
                v1[i]={nums[i]-vd,i};
            }
            else
                v1[i]=v1[i+1];
            
            if(nums[i]+vd<v2[i+1].first){
                v2[i]={nums[i]+vd,i};
            }
            
            else
                v2[i]=v2[i+1];
            
        }
        
        
        for(int i=0;i<n;i++){
            int j=i+id;
            if(j>=n)
                break;
            
            if(nums[i]<=v1[j].first)
                return {i,v1[j].second};
            
            if(nums[i]>=v2[j].first)
                return {i,v2[j].second};
        }
        
        
        return {-1,-1};
        
    }
    
};
