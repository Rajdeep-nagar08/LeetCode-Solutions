

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& eq, vector<double>& val, vector<vector<string>>& q) {
      
      unordered_map<string,vector<pair<string,double>>>mp;
      
      for(int i=0;i<eq.size();i++){
        mp[eq[i][0]].push_back({eq[i][1],val[i]});
        mp[eq[i][1]].push_back({eq[i][0],double(1.00000/val[i])});

      }
    
      vector<double>ans(q.size());
      
      
      for(int i=0;i<q.size();i++){
        
        string s1=q[i][0];
        string s2=q[i][1];
        
        if(mp.count(s1)!=1 || mp.count(s2)!=1){
          ans[i]=-1.00000;
          continue;
        }
        
        double temp=1.00000;
        double a=-1.00000;
        set<string>st1;
        dfs(s1,s2,mp,temp,a,st1);
         ans[i]=a;

      }
      return ans;
        
     }
      
      void dfs(string s1,string s2, unordered_map<string,vector<pair<string,double>>>&mp,double temp ,double &a,set<string>&st){
          
      st.insert(s1);
          
     if(s1==s2){
       a=temp;
        return;
     }

          for(auto it:mp[s1]){
            if(st.count(it.first)!=1){
           dfs(it.first,s2,mp,temp*(it.second),a,st);
            }
            
       }
        
    }
};