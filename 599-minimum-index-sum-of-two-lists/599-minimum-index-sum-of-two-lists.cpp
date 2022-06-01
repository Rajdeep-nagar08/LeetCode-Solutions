class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
      
       unordered_map<string ,int>mp;
        
        int n=list1.size();
        
        for(int i=0;i<n;i++)
            mp[list1[i]]=i;
        
        int sum=INT_MAX;
                
        int m=list2.size();
    
        
        for(int i=0;i<m;i++){
            if(mp.count(list2[i])==1)
                if(sum>mp[list2[i]]+i)
                    sum=mp[list2[i]]+i;
        }
         
        vector<string>ans;
        
        for(int i=0;i<m;i++){
            if(mp.count(list2[i])==1 && (mp[list2[i]]+i==sum))
                ans.push_back(list2[i]);
        }
         
        return ans;
     }
};