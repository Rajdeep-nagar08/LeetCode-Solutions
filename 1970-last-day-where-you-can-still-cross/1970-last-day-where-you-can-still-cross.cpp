class Solution {
public:
    vector<int> x = {0,1,-1,0};
    vector<int> y = {1,0,0,-1};
  
    
    int latestDayToCross(int row, int col, vector<vector<int>>& B) {
        
        int start = 0;
        int end = B.size()-1;
                             
        while(start<=end){
            
            int mid = start + (end-start)/2;
            
            vector<vector<int>> A(row,vector<int> (col,0));
            
            for(int i = 0;i<mid;i++){
                int u = B[i][0] - 1;
                int v = B[i][1] - 1;
                A[u][v] = 1;
            }
            
            if(check(A,mid))
                start = mid+1;
            else
                end = mid-1;
        
        }
        return end;
    }
    
    
      
    bool isvalid(vector<vector<int>> &A,int i,int j){
        return (i>=0 && j>=0 && i<A.size() && j<A[0].size() && A[i][j] == 0);
    }

    bool dfs(vector<vector<int>> &A,int i,int j){
        if(i == A.size()-1)
            return true;
        
        A[i][j] = 1;
        
        for(int k = 0;k<4;k++){
            int u = i+x[k];
            int v = j + y[k];
            
            if(isvalid(A,u,v)){
                if(dfs(A,u,v))
                    return true;
            }
        }
        return false;
    }
    
    bool check(vector<vector<int>> &A,int mid){
        if(mid < A[0].size())       //There will always be way to reach bottom in this case
            return true;            //Worst case : all boxes in 1st row gets filled one by one.
        
        for(int i = 0;i<A[0].size();i++){
            if(A[0][i] == 0 ){
                if(dfs(A,0,i))
                    return true;
            }
        }
        return false;
    }
    
    
    
};


