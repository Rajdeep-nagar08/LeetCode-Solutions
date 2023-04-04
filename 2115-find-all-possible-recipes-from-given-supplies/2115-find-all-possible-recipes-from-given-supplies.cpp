class Solution {
public:
    vector<string> findAllRecipes(vector<string>& r, vector<vector<string>>& ing, vector<string>& s) {
        
        int n=r.size();
        
        int m=s.size();
        
    
        unordered_map<string,int>mp;  
                
         queue<string>q;
        
        for(string s1:s){
            q.push(s1);
        }
        
        unordered_map<string,vector<string>>g;
        
        vector<int>v(n,0);
        
        for(int i=0;i<n;i++){
            for(string s1:ing[i]){
                g[r[i]].push_back(s1);
                mp[r[i]]++;
                g[s1].push_back(r[i]);
            }
        }
        
        
        vector<string>ans;
        
      
        while(!q.empty()){
            
            int sz=q.size();
            
            while(sz--){
                
                string s1=q.front();
                
                q.pop();
                
                for(string s2:g[s1]){
                   mp[s2]--;
                
                    if(mp[s2]==0){
                        ans.push_back(s2);
                        q.push(s2);
                    }
                }
            }
        }
     
        
        
        return ans;
        
    }
    
  
};