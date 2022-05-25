class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
       
        int n=nums.size();
        
        /*
        
        kept size of left is as small as possible
        
        every element of left <= every element of right
        
        */
        
        
        vector<int>gL(n);    // gL[i] = greatest element in [0...i]

      
        vector<int>sR(n);   // gR[i] = smallest element in [i...n-1]
        
        
        gL[0]=nums[0];
        
        for(int i=1;i<n;i++){
            gL[i]=max(nums[i],gL[i-1]);
        }
        
        sR[n-1]=nums[n-1];
        
        for(int i=n-2;i>=0;i--){
            sR[i]=min(nums[i],sR[i+1]);
        }
        
        
        for(int i=0;i<n-1;i++){
                if(gL[i] <= sR[i+1]){
                    return i+1;
                }
            }
        
        return -1;
    }
};