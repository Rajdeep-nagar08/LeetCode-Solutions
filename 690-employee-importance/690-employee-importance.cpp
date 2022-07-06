/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> emp, int id) {
        
        int n=emp.size();
        
        unordered_map<int,vector<int>>g;
        
        unordered_map<int,int>mp;
        
        for(auto it:emp){
            g[it->id]=it->subordinates;
            mp[it->id]=it->importance;
        }
        
        int ans=0;
        
        queue<int>q;
        q.push(id);
        
        while(!q.empty()){
            int sz=q.size();
            
            while(sz--){
                
                int x=q.front();
                
                q.pop();
                
                ans+=mp[x];
                
                for(int y:g[x]){
                    q.push(y);
                }
                
            }
        }
        
        return ans;
    }
};