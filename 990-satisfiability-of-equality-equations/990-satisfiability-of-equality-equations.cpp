/*

assign same values to a group of nodes that have equality in between them , it means first make a graph for thosew nodes that have equality, than using dfs , assign same value to nodes of same component

finally return false if two nodes have same value but have inequality in between them

*/


class Solution {
   
public:
      
    bool equationsPossible(vector<string>& eq) {
        
        vector<bool>vis(26,false);

        vector<int>v(26,-1);
        
        unordered_map<char,vector<char>>g;
        
        for(auto it:eq){
            char sgn=it[1];
            
            if(sgn=='='){
                g[it[0]].push_back(it[3]);
                g[it[3]].push_back(it[0]);
            }
            else if(it[0]==it[3])
                return false;
        }

         int no=0;
        
         for(auto it:g){
             char a=it.first;
             if(vis[a-'a']==false){
                 no++;
                 dfs(a,g,no,vis,v);
             }
         }
    
        
        for(auto it:eq){
            
            char a=it[0];
            char b=it[3];
            char s=it[1];
            
            if(s=='!'){
                if(v[a-'a']==v[b-'a'] && (v[a-'a']!=-1)){
                return false;
                }
            }
        }
      
        return true;
    }

    
void dfs(char a,unordered_map<char,vector<char>>&g,int no,vector<bool>&vis,vector<int>&v){
    
    v[a-'a']=no;
    vis[a-'a']=true;
    
    for(char b:g[a]){
       if(vis[b-'a']==false){
           dfs(b,g,no,vis,v);
       } 
    }
  }
    
};