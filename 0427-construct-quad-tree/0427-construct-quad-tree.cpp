class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();
        return buildQuadTree(grid, 0, 0, n, n);
    }
    
    Node* buildQuadTree(vector<vector<int>>& grid, int x1, int y1, int x2, int y2) {
        if (x1 >= x2 || y1 >= y2) {
            return nullptr;
        }
        int val = grid[x1][y1];
        bool isLeaf = true;
        for (int i = x1; i < x2; i++) {
            for (int j = y1; j < y2; j++) {
                if (grid[i][j] != val) {
                    isLeaf = false;
                    break;
                }
            }
            if (!isLeaf) {
                break;
            }
        }
        if (isLeaf) {
            return new Node(val, true);
        }
        int midx = (x1 + x2) / 2, midy = (y1 + y2) / 2;
        
        Node* topLeft = buildQuadTree(grid, x1, y1, midx, midy);
        
        Node* topRight = buildQuadTree(grid, x1, midy, midx, y2);
        
        Node* bottomLeft = buildQuadTree(grid, midx, y1, x2, midy);
        
        
        Node* bottomRight = buildQuadTree(grid, midx, midy, x2, y2);
        return new Node(false, false, topLeft, topRight, bottomLeft, bottomRight);
    }
};