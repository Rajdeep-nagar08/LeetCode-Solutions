class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        
        int n=mat.size();
        int m=mat[0].size();
        
        priority_queue<pair<int,int>>pq;
        
        for(int i=0;i<n;i++){
            int c=0;
            for(int j=0;j<m;j++){
            if(mat[i][j])
                c++;
            }
            pq.push({c,i});
            if(pq.size()>k)
                pq.pop();
        }
        vector<int>ans;
        while(pq.size()>0){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        
        reverse(ans.begin(),ans.end());
        
        
        return ans;
    }
};