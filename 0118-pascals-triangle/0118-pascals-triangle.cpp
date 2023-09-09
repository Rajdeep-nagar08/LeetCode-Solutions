class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        ans.push_back({1});
        if(numRows==1)
            return ans;
        ans.push_back({1,1});
        
        for(int i=2;i<numRows;i++){
            vector<int>temp(i+1);
            temp[0]=1;
            temp[i]=1;
            for(int j=1;j<i;j++){
                temp[j]=ans[i-1][j-1]+ans[i-1][j];
            }
            ans.push_back(temp);
        }
        return ans;
    }
};