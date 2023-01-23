
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>outdeg(n,0);
        vector<int>indeg(n,0);
        for(int i=0;i<trust.size();i++){
               ++outdeg[trust[i][0]-1];
               ++indeg[trust[i][1]-1];
            }
        for(int i=0;i<n;i++){
            if(outdeg[i]==0 && indeg[i]==n-1)
                return i+1;
        }
        return -1;
    }
};