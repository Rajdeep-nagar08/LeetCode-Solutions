class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {

       const int n = graph.size();
        
        const int kAns = (1 << n) - 1;//for n=12 kAns = 111111111111 (all 1s means  - visited all nodes, while e.g. 111111111101 means didn't visit node 1)
        
        queue<pair<int, int>> q;//pair<node: bitmask> , // every time we visit some node Y on a path from node X we update  bitmask (state) of node X to set node's Y bit
        
        vector<vector<int>> visited(n, vector<int>(1 << n));// 1 << n = 2^n, so we create matrix [n][2^n] where row index corresponds to node in the original graph, and column index is a bitmask(state) for particular node
        
        for (int i = 0; i < n; ++i) 
            q.push({i, 1 << i});//the bitmask for each node is initialized with only its own bit set to 1 (i.e. nothing visited yet))
        
        int steps = 0;
        while (!q.empty()) {
            int s = q.size();
            while (s--) {
                pair<int, int> p = q.front(); //pair <node:bitmask>
                q.pop();
                int node = p.first;
                int state = p.second;
                if (state == kAns) return steps;   //found a full set of 1s meaning we visited all graph nodes from the current node
                if (visited[node][state]) continue;
                visited[node][state] = 1;
                //for each neighbour of current node set neighbour's bit in current node's bitmask
                for (int next : graph[node]) 
                    q.push({next, state | (1 << next)});//"state | (1 << next)" means set bit <next> in <state> bitmask
             }
             ++steps;
        }
        return -1;
    }
};