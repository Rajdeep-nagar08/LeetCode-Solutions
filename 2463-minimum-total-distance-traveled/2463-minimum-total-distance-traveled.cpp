
#define lln long long int

/*

for each robot we have two choices, either move left or move right

dp[i][3]= min dist. travelled by robots [i...n-1] , if current robot is either moving in left or right, or stay at current position


but how to keep track of limits of each factory ? how to memoize their limits ?

---------------------------

dp[i][j]= min distance travelled by robots [i...n-1] using factories 

[j...m-1]

ith robot has choices among factories


ans=dp[0][0]


*/



lln dp[101][10001];

class Solution {
public:
    
    lln ans=-1e18;
    
//    map<lln,int>mp;

    
    long long minimumTotalDistance(vector<int>& rob, vector<vector<int>>& fact) {
       
        sort(rob.begin(),rob.end());
        
        sort(fact.begin(),fact.end());
        
        vector<int>v;
        
        for(auto it:fact){
            for(int i=0;i<it[1];i++){
            v.push_back(it[0]);
            }
        }
        
        memset(dp,-1,sizeof(dp));
        
        return find(0,0,rob,v);
    
    }
    
    lln find(int i,int j,vector<int>&rob,vector<int>&v){
        
        if(i>=rob.size()){
            
            return 0;
        }
     
        
        if(j>=v.size())
            return 1e16;
        
         if(dp[i][j]!=-1)
             return dp[i][j];
        
        lln temp1=1e18;
        
        temp1=find(i,j+1,rob,v);
      
        lln temp2=1e18;
        
        temp2=abs(v[j]-rob[i])+find(i+1,j+1,rob,v);
        
    
        return dp[i][j]=min(temp1,temp2);
    }
};