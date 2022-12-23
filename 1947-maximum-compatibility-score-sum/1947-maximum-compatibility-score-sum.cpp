class Solution {
public:
    int maxCompatibilitySum(vector<vector<int>>& stud, vector<vector<int>>& ment) {
      int score=0;
      int mx=INT_MIN;
      int n=stud.size();
      int m=stud[0].size();
      vector<bool>vis(n,false);
      find(0,mx,score,stud,ment,vis);
      
      return mx;
    }
      
void find(int start,int& mx,int& score,vector<vector<int>>&stud,vector<vector<int>>&ment,vector<bool>&vis){
        if(start==ment.size()){
          mx=max(mx,score);
          return;
        }
      
      for(int i=0;i<ment.size();i++){
        if(vis[i]==true)
            continue;
        
        vis[i]=true;
          int sc=0;
        for(int j=0;j<ment[0].size();j++){
          if(stud[start][j]==ment[i][j])
            sc++;
        }
      
        score=score+sc;
        find(start+1,mx,score,stud,ment,vis);
         score=score-sc;
        vis[i]=false;
      }  

    }
};