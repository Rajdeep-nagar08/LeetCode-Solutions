
class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& ord) {
        
      map<int,unordered_map<string,int>>mp;  // table no => food,count
         
        unordered_map<string,int>mp1;
      
      int n=ord.size();
        
        for(int i=0;i<n;i++){
            int no=stoi(ord[i][1]);
              mp[no][ord[i][2]]++;
              mp1[ord[i][2]]++;
        }
        
        vector<string>v;
        
        v.push_back("Table");
        
       for(auto it:mp1){
           v.push_back(it.first);
       }  
        
        sort(v.begin()+1,v.end());
        
        vector<vector<string>>ans;
        
        ans.push_back(v);
        
        int n1=v.size();
        
      for(auto it:mp){
          
          vector<string>v1;
          
          string s1=to_string(it.first);
          v1.push_back(s1);
         
          unordered_map<string,int>mp2=it.second;
          
          for(int i=1;i<n1;i++){
                  int no=mp2[v[i]];
                string s=to_string(no);
                  v1.push_back(s);    
          }
          
          ans.push_back(v1);

      }
        
      return ans;
        
    }
};