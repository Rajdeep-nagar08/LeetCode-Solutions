/*

four sides of the rectangle and n circles are the n+4 nodes of the graph

now making edges in the graph : edges between nodes

there is an edge between two circles if they intersect : distance between their centres <= sum of radiuses

there is an edge between four sides and circle if circle touches or intrsect the side

====


if there is any edge connecting left-right or left bottum or right bottom or right-top

than ans= false


=====



*/

// Giving TLE, optimized using DSU


// #define lln long long int


// class Solution {
// public:
//     bool canReachCorner(int X, int Y, vector<vector<int>>& circles) {
//         unordered_map<int, unordered_map<int, int>> g;
//         int n = circles.size();

//         // Make edges between the circles
        
//         // total n+4 nodes
        
//          // [0...n-1] from n circles
        
//          // 4 nodes from 4 sides of the rectangle
        
//         for (int i = 0; i < n; ++i) {
//             for (int j = i + 1; j < n; ++j) {
//                 int x1 = circles[i][0], y1 = circles[i][1], r1 = circles[i][2];
//                 int x2 = circles[j][0], y2 = circles[j][1], r2 = circles[j][2];
//                 lln dr = 1ll*(x1 - x2) * (x1 - x2) + 1ll*(y1 - y2) * (y1 - y2);
//                 lln sumr = 1ll*(r1 + r2) * (r1 + r2);
//                 if (dr <= sumr) {
//                     // cout<<i<<"c"<<j<<endl;
//                     g[i][j]++;
//                     g[j][i]++;
//                 }
//             }
//         }

//         // Make edges between circles and the sides
//         for (int i = 0; i < n; ++i) {
//             int h = circles[i][0], k = circles[i][1], r = circles[i][2];
//             // L
//             if (touch(1, 0, 0, h, k, r)) {
//                 g[i][n]++;
//                 g[n][i]++;
//             }
//             // T
//             if (touch(0, 1, -Y, h, k, r)) {
//                 g[i][n+1]++;
//                 g[n+1][i]++;
//             }
//             // B
//             if (touch(0, 1, 0, h, k, r)) {
//                 g[i][n+2]++;
//                 g[n+2][i]++;
//             }
//             // R
//             if (touch(1, 0, -X, h, k, r)) {
//                 g[i][n+3]++;
//                 g[n+3][i]++;
//             }
//         }

//         // Check if there's any path connecting the critical sides (Left-Right, Left-Bottum, Right-Top, Top-Bottum)
        
//         if (isConnected(g, n, n + 3) || isConnected(g, n, n + 2) || isConnected(g, n + 3, n + 1) || isConnected(g, n + 1, n + 2)) {
//             return false;
//         }

//         return true;
//     }

// private:
//     bool touch(int a, int b, int c, int h, int k, int radius) {
        
//         // h, k= centre of circle
        
//         // ax+by+c=0 line
        
//         // leftTop line equation x=0 (a=1, b=0, c=0), y-y1=0 (a=0, b=1, c=-Y)
        
//         // bottum right equation (y=0) (a=0, b=1, c=0), x-X1=0 (a=1, b=0, c=-X)
        
//         // int dist = (abs(a * h + b * k + c)) / sqrt(a * a + b * b);
        
//         lln distSquared = 1ll*(a * h + b * k + c) * (a * h + b * k + c);
        
//         lln radiusSquared = 1ll*radius * radius * (a * a + b * b);
        
//         return distSquared <= radiusSquared;
//     }

//     bool isConnected(unordered_map<int, unordered_map<int, int>>& g, int src, int dest) {
//         queue<int> q;
//         unordered_map<int, bool> visited;
//         q.push(src);
//         visited[src] = true;

//         while (!q.empty()) {
//             int node = q.front();
//             q.pop();

//             if (node == dest) {
//                 // cout<<src<<"E"<<dest<<endl;
//                 return true;
//             }

//             for (auto& neighbor : g[node]) {
//                 if (!visited[neighbor.first]) {
//                     visited[neighbor.first] = true;
//                     q.push(neighbor.first);
//                 }
//             }
//         }

//         return false;
//     }
// };



class DSU {
public:
    DSU(int n) : parent(n), rank(n, 1) {
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (x != parent[x]) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(int x, int y) {
        int xr = find(x), yr = find(y);
        if (xr == yr) return;

        if (rank[xr] < rank[yr]) {
            parent[xr] = yr;
        } else if (rank[xr] > rank[yr]) {
            parent[yr] = xr;
        } else {
            parent[yr] = xr;
            rank[xr]++;
        }
    }

private:
    vector<int> parent;
    vector<int> rank;
};

class Solution {
public:
    bool canReachCorner(int X, int Y, vector<vector<int>>& circles) {
        int n = circles.size();
        DSU dsu(n + 4);

        // Making edges between circles
        // Make edges between the circles
        
         // total n+4 nodes
        
          // [0...n-1] from n circles
        
        // 4 nodes from 4 sides of the rectangle
        
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int x1 = circles[i][0], y1 = circles[i][1], r1 = circles[i][2];
                int x2 = circles[j][0], y2 = circles[j][1], r2 = circles[j][2];
                long long dr = 1LL * (x1 - x2) * (x1 - x2) + 1LL * (y1 - y2) * (y1 - y2);
                long long sumr = 1LL * (r1 + r2) * (r1 + r2);
                if (dr <= sumr) {
                    dsu.unite(i, j);
                }
            }
        }

        // Making edges between circles and the sides
        for (int i = 0; i < n; ++i) {
            int h = circles[i][0], k = circles[i][1], r = circles[i][2];
            if (touch(1, 0, 0, h, k, r)) {
                dsu.unite(i, n); // Left side
            }
            if (touch(0, 1, -Y, h, k, r)) {
                dsu.unite(i, n + 1); // Top side
            }
            if (touch(0, 1, 0, h, k, r)) {
                dsu.unite(i, n + 2); // Bottom side
            }
            if (touch(1, 0, -X, h, k, r)) {
                dsu.unite(i, n + 3); // Right side
            }
        }

        // Check critical connections
        return !(
            dsu.find(n) == dsu.find(n + 3) || // Left-Right
            dsu.find(n) == dsu.find(n + 2) || // Left-Bottom
            dsu.find(n + 3) == dsu.find(n + 1) || // Right-Top
            dsu.find(n + 1) == dsu.find(n + 2) // Top-Bottom
        );
    }

private:
    bool touch(int a, int b, int c, int h, int k, int radius) {
        // h, k= centre of circle
        
         // ax+by+c=0 line
        
         // leftTop line equation x=0 (a=1, b=0, c=0), y-y1=0 (a=0, b=1, c=-Y)
        
         // bottum right equation (y=0) (a=0, b=1, c=0), x-X1=0 (a=1, b=0, c=-X)
        
        // int dist = (abs(a * h + b * k + c)) / sqrt(a * a + b * b);
        long long distSquared = 1LL * (a * h + b * k + c) * (a * h + b * k + c);
        long long radiusSquared = 1LL * radius * radius * (a * a + b * b);
        return distSquared <= radiusSquared;
    }
};

