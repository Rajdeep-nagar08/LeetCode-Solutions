/*

all possible routes from start to end = ?

can visit any city multiple times

if we are at city i, then for next city we can move to any city except city i

as we have choices, we can think about dp

dp[i][f] = no of paths from city [i...end] if we have already travelled [start...i-1] and currently left we have "f" amount of fuel


ans=dp[start][fuel]


*/


#define lln long long int

lln dp[101][201];

int mod=1e9+7;

class Solution {
public:
    int countRoutes(vector<int>& loc, int start, int end, int fuel) {
       
        int n=loc.size();
        
       memset(dp,-1,sizeof(dp));
        
        lln ans=find(start,end,loc,fuel);
      
        return ans;
        
    }
    
    int find(int s,int e,vector<int>&loc,int fuel){
     
        lln c=0;
        
        if(s==e){
            
         c=1;
            
        }
        
        if(dp[s][fuel]!=-1)
            return dp[s][fuel];
        
        
        for(int i=0;i<loc.size();i++){
            if(i!=s && (fuel-abs(loc[s]-loc[i])>=0)){
                c+=find(i,e,loc,fuel-abs(loc[s]-loc[i]));
                c%=mod;
            }
        }
        
        return dp[s][fuel]=c;
    }
};