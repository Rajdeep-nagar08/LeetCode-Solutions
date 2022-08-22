class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
     
        stack<int>s;
        
        int ans[nums2.size()];
        
        ans[nums2.size()-1] = -1;
        
        s.push(nums2[nums2.size()-1]);
        
        for(int i=nums2.size()-2; i>=0; i--){
            
            while(!s.empty() && nums2[i] > s.top()){
                s.pop();
            }
            
            if(!s.empty())
                
            ans[i] = s.top();
            
            else 
                
                ans[i]=-1;
            
            s.push(nums2[i]);
            
        }
        
        cout<<"Fuck"<<endl;
        
        vector<int> output;
        
        for(int i=0; i<nums1.size(); i++){
            
            for(int j=0; j<nums2.size(); j++){
                
                if(nums1[i]== nums2[j]){
                    
                    output.push_back(ans[j]);
                    
                }
            }
        }
        
        return output;
    
        
    }
};