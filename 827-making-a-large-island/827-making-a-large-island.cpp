class Solution {
public:
    
    /*
         1 1 0 1     5 5 0 2
         1 1 0 1  => 5 5 0 2
         1 0 0 0     5 0 0 0
         0 1 1 1     0 3 3 3
    
    */
    
    /*
       [[0,0,0,0,0,0,0],
        [0,1,1,1,1,0,0],
        [0,1,0,0,1,0,0],
        [1,0,1,0,1,0,0],
        [0,1,0,0,1,0,0],
        [0,1,0,0,1,0,0],
        [0,1,1,1,1,0,0]]
    */
    
    /*
       [[1,0,1],
        [0,0,0],
        [0,1,1]]
    */
    
    bool isValid(int i, int j, int n, int m) {
        if(i >= 0 && j >= 0 && i < n && j < m) return true;
        return false;
    }
    
    vector<pair<int,int>> dir = {{1,0},{0,1},{-1,0},{0,-1}};
    
    int getCount(int i, int j, vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        if(isValid(i, j, n, m) == false || grid[i][j] == 0) return 0;
        
        int count = 1;
        grid[i][j] = 0;
        
        for(auto &it: dir) {
            int ni = it.first + i;
            int nj = it.second + j;
            
            count += getCount(ni, nj, grid);
        }
        
        return count;
    }
    
    void fillCount(int i, int j, int count, vector<vector<int>>& area, 
                   vector<vector<int>>& grid, vector<vector<int>> &mark, int marker) {
        int n = grid.size();
        int m = grid[0].size();
        
        if(isValid(i, j, n, m) == false || grid[i][j] == 0) return;
        
        grid[i][j] = 0;
        area[i][j] = count;
        mark[i][j] = marker;
        
        for(auto &it: dir) {
            int ni = it.first + i;
            int nj = it.second + j;
            
            fillCount(ni, nj, count, area, grid, mark, marker);
        }
    }
    
    int getVal(int i, int j, vector<vector<int>>& area, vector<vector<int>>& mark) {
        int n = area.size();
        int m = area[0].size();
        int val = 1;
        
        unordered_set<int> st;
        
        for(auto &it: dir) {
            int ni = i + it.first;
            int nj = j + it.second;
            
            if(isValid(ni, nj, n, m) == false) continue;
            int marker = mark[ni][nj];

            if(st.find(marker) != st.end()) continue;

            st.insert(marker);
            val += area[ni][nj];
        }
        return val;
    }
    
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> copy = grid;
        vector<vector<int>> area(n, vector<int>(m, 0));
        vector<vector<int>> mark(n, vector<int>(m, 0));
        
        int marker = 1;
        int mxCount = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 0) continue;
                
                int count = getCount(i, j, grid);
                
                mxCount = max(mxCount, count);
                
                fillCount(i, j, count, area, copy, mark, marker);
                marker++;
            }
        }
        
        // for(auto&v: area) {
        //     for(auto &it: v) cout << it << " ";
        //     cout << endl;
        // }
        
        int ans = mxCount;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(area[i][j] != 0) continue;
                
                int val = getVal(i, j, area, mark);
                if(val == 5) cout << i << " " << j << endl;
                ans = max(ans, val);
            }
        }
        
        return ans;
    }
};