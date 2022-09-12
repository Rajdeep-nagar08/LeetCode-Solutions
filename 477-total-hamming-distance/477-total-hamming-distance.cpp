class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
     
        
        int n=nums.size();
        
      vector<pair<int,int>>v(32,{0,0});   
        
        // count of 1's and 0's at each pos
        
        for(int i=0;i<=31;i++){
          if(nums[0] & (1<<i))   // 1
              v[i].first++;
            else                 // 0
                v[i].second++;
        }
        
        
        int count=0;
        
        for(int i=1;i<n;i++){
            
            for(int j=0;j<=31;j++){
                
                if(nums[i] & (1<<j)){    // 1
                    count+=v[j].second;  
                    v[j].first++;
                }
                else{                   // 0
                    
                    count+=v[j].first;
                    v[j].second++;
                }
            }
        }
        
        return count;
    }
};