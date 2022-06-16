class Solution {
public:
    bool checkValid(vector<vector<int>>& mat) {
        
        int n=mat.size();
        
        
        vector<int>v(n);
        
        for(int i=0;i<n;i++){
            v[i]=i+1;
        }
        
        for(int i=0;i<n;i++){
            vector<int>v1(n);
            for(int j=0;j<n;j++){
                v1[j]=mat[i][j];
            }
            sort(v1.begin(),v1.end());
            if(v1!=v)
                return false;
        }
        
        for(int i=0;i<n;i++){
            vector<int>v1(n);
            for(int j=0;j<n;j++){
                v1[j]=mat[j][i];
            }
            sort(v1.begin(),v1.end());
            if(v1!=v)
                return false;
        }
        
        return true;
        
    }
};