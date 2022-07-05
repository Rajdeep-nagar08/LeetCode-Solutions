class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       
        
        int n=nums.size();
        
        unordered_set<int>st;
        
        for(int x:nums){
            st.insert(x);
        }
        
        
        int ans=0;
        
        for(int x:nums){
            if(st.count(x)!=1)
                continue;
            
            st.erase(x);
            
            int next=x+1;
            int prev=x-1;
            
            while(st.count(next)==1){
                st.erase(next);
                next++;
            }
            
            while(st.count(prev)==1){
                st.erase(prev);
                prev--;
            }
            
            ans=max(ans,next-prev-1);
        }
        
        return ans;
    }
};