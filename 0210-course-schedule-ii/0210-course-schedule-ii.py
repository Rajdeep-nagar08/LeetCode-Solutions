class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        n = numCourses
        m = len(prerequisites)
        indeg = [0] * n
        g = [[] for _ in range(n)]
        for i in range(m):
            g[prerequisites[i][1]].append(prerequisites[i][0])
        
        vis = [False] * n
        path = [0] * n
        iscycle = False
        for i in range(n):
            if vis[i] == False:
                if self.dfs1(i, vis, path, g):
                    iscycle = True
                    break
        if iscycle == True:
            return []
        
        vis1 = [False] * n
        ans = []

        # topological sorting
        for i in range(n):
            if vis1[i] == False:
                self.dfs(i, vis1, ans, g)
        
        ans = ans[::-1]  # reversing the list
        if len(ans) == n:
            return ans
        else:
            return []
        
        
    def dfs1(self, node, vis, path, g):
        vis[node] = True
        path[node] = 1
        for x in g[node]:
            if vis[x] == False:
                if self.dfs1(x, vis, path, g):
                    return True
            elif path[x]:
                return True
        path[node] = 0
        return False
    
    
    def dfs(self, node, vis, ans, g):
        vis[node] = True
        for x in g[node]:
            if vis[x] == False:
                self.dfs(x, vis, ans, g)
        ans.append(node)
        