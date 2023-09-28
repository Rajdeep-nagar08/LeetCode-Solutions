/*
Brute force => trying all possible ways of placing k mailboxes out of d points
(d= max dist) than calculation distance of each house from that = O(nCk)*O(n)

for each mailbox, we have two choice , either we place it at current position or not place it at current position

If k =1, the minimum distance is obtained by placing the mailbox in the median of the array houses

dp[i][j] represent the min dist for [i....n-1] houses if need to place j mailboxes (j<=k)

Ans= dp[0][k] = solve (0,k)

dp[i][j] = Min( min dist for [i....k1] houses if using 1 mailbox + min dist for [k1+1.....n-1] houses                                                                        using j-1 mailboxes

dp[i][j]= Min( DistFor1(i,k1) + solve(k1+1,j-1) )

DistFor1(0,k1)= min dist for placing 1 mailbox in the range [0...k1]= dist for placing 1 

mailbox in the middle of the range [0...k1]

MCM..... PATTERN

*/

int dp[101][101];
class Solution {
public:
    int minDistance(vector<int>& h, int k) {
        
      memset(dp,-1,sizeof(dp));
        
     sort(h.begin(),h.end());  
        
     return solve(h,0,k);
        
    }
    
    
    int solve(vector<int>&h,int i,int j){
        
        if(i>=h.size() || j==0)
            return 0;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int ans=INT_MAX;
        
        for(int k1=i;k1<h.size();k1++){
            if(j==1 && k1<h.size()-1)
                continue;
            ans=min(ans,DistFor1(h,i,k1)+solve(h,k1+1,j-1));
          }
        return dp[i][j]=ans;
      }
    
      int DistFor1(vector<int>&h,int l,int r){
          int d=0;
       //   [.......[l.....mid.....r].....]
          while(l<r){
              d+= h[r]-h[l];
              r--,l++;
          }
          return d;
      }
};


