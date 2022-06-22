class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& pt, vector<vector<int>>& q) {
        
        int n1=pt.size();
        
        int n2=q.size();
        
        vector<int>ans(n2,0);
        
        for(int i=0;i<n2;i++){
            int x1=q[i][0],y1=q[i][1],r=q[i][2];
            
            for(int j=0;j<n1;j++){
                int x2=pt[j][0],y2=pt[j][1];
                
                int d1=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
                int d2=r*r;
                
                if(d1<=d2)
                    ans[i]++;
            }
        }
        
        return ans;
        
    }
};