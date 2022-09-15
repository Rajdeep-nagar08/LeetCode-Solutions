class Solution {
public:
    vector<int> findOriginalArray(vector<int>& change) {
        
        
        int n=change.size();
        
        sort(change.begin(),change.end());
        
        unordered_map<int,int>mp;
        
        for(int x:change){
            mp[x]++;
        }
        
        vector<int>ans;
        
        for(int i=n-1;i>=0;i--){
            int no=change[i];
            
            if(mp[no]==0)
                continue;
            
            mp[no]--;

            
            if(no%2==0){
                
              if(mp[no/2]>0){
                  mp[no/2]--;
                  ans.push_back(no/2);
              }  
               else
                   return {};
     
            }
            else{
                
                return {};
            }
            
        }
        
        return ans;
    }
};