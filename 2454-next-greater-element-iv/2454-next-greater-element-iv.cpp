class Solution {
public:
    vector<int> secondGreaterElement(vector<int>& nums) {
   /*
   
   
   we have to find every element's next to next greater element, we can use a stack for finding an element's next greater element.

so in the example [2,4,0,9,6] next greater element for 2 is 4.

as soon as next greater element of a number arrives, we can push that number in a multiset, and just lookout for one more greater element than that number which will be our answer.

so in the example, as soon as 4 arrives (next greater of 2) we push 2 in a multiset, when 9 arrives, we check multiset whether the elements in the multiset are smaller than 9, all the elements smaller than 9 will have answer = 9.

*/        int n=nums.size();

        
        vector<int>ans(n,-1);
        
        
        stack<int>st;
        
        st.push(0);
        
        set<pair<int,int>>mst;
        
        for(int i=1;i<n;i++){
            
            // 2nd greater founds
            
            while(mst.size()>0 && (nums[i]>(*mst.begin()).first)){
                ans[(*mst.begin()).second]=nums[i];
                mst.erase(mst.begin());
            }
            
            // storing first greater
            
            while(st.size()>0 && (nums[i]>nums[st.top()])){
                mst.insert({nums[st.top()],st.top()});
                st.pop();
            }
            
            st.push(i);
            
        }
        
          return ans;  
        
    }
};