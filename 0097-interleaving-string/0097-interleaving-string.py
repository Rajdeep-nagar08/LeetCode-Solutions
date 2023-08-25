

# int dp[101][101];
# class Solution {
# public:
#     int n1,n2,m;
#     bool isInterleave(string s1, string s2, string s3) {
        
        
#         n1=s1.size();
        
#         n2=s2.size();
        
#         m=s3.size();
        
        
#         if(n1+n2!=m)
#             return false;
        
#         memset(dp,-1,sizeof(dp));
        
#         return find(0,0,0,s1,s2,s3);
        
        
#     }
    
#     int find(int i,int j,int k,string &s1,string &s2,string &s3){
        
#         if(k>=m){
#             if(i>=n1 && j>=n2)
#                 return true;
            
            
#             return false;
#         }
            
        
#         if(dp[i][j]!=-1)
#             return dp[i][j];
        
#         int f1=0,f2=0;
        
#         if(i<n1 && j<n2){
#             if(s1[i]==s3[k] && (s2[j]==s3[k]))
#                 f1=f1||find(i+1,j,k+1,s1,s2,s3)||find(i,j+1,k+1,s1,s2,s3);
            
#             else if(s1[i]==s3[k])
#                 f1=f1||find(i+1,j,k+1,s1,s2,s3);
            
#             else if(s2[j]==s3[k])
#                 f1=f1||find(i,j+1,k+1,s1,s2,s3);
#         }
        
#         else if(i<n1){
#              if(s1[i]==s3[k])
#                 f1=f1||find(i+1,j,k+1,s1,s2,s3);
            
#         }
        
#         else if(j<n2){
#             if(s2[j]==s3[k])
#                 f1=f1||find(i,j+1,k+1,s1,s2,s3);
#         }
        
#         return dp[i][j]=f1;
            
#     }
# };



class Solution:
    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
        n1, n2, m = len(s1), len(s2), len(s3)
        
        if n1 + n2 != m:
            return False
        
        dp = {}
        
        def find(i, j, k):
            if k >= m:
                return i >= n1 and j >= n2
            
            if (i, j) in dp:
                return dp[(i, j)]
            
            f1 = False
            
            if i < n1 and j < n2:
                if s1[i] == s3[k] and s2[j] == s3[k]:
                    f1 = find(i + 1, j, k + 1) or find(i, j + 1, k + 1)
                elif s1[i] == s3[k]:
                    f1 = find(i + 1, j, k + 1)
                elif s2[j] == s3[k]:
                    f1 = find(i, j + 1, k + 1)

            elif i < n1:
                if s1[i] == s3[k]:
                    f1 = find(i + 1, j, k + 1)
            elif j < n2:
                if s2[j] == s3[k]:
                    f1 = find(i, j + 1, k + 1)

            dp[(i, j)] = f1
            return f1
        
        return find(0, 0, 0)




        