  /*
        
        dp[i] = maximum alice score if both play optimally
        = max(I take ith stone then opponent can take either next 1,2 or 3 stones to make my future scores minimum, I take ith and (i+1)th stone then opponent can take either next 1,2 or 3 stones to make my future scores minimum, I take ith, (i+1)th and (i+2)th stone then opponent can take either next 1,2 or 3 stones to make my future scores minimum)
        
        dp[i] = max(stone[i]+ min(dp[i+2],dp[i+3], dp[i+4]) , 
        stone[i]+stone[i+1] + min(dp[i+3],dp[i+4], dp[i+5]),
        stone[i]+stone[i+1]+stone[i+2] + min(dp[i+4], dp[i+5], dp[i+6])
        
        
sum = total score

if dp[0] > (sum/2) Alice wins

if dp[0] == sum/2 , Match Draw

if dp[0] < (sum/2), Bob wins

        */

vector<int>dp;

int n;

class Solution {
public:
    string stoneGameIII(vector<int>& stone) {
    
        n= stone.size();
        
        dp.clear();
        
        dp.resize(n+1,INT_MIN);
        
        int sum=0;
        
        for(int x:stone){
            sum+=x;
        }
        
        int a= find(0,stone);
        
        cout<<a<<endl;
        
        if(2*a > sum)
            return "Alice";
        
        else if(2*a==sum)
            return "Tie";
        
        return "Bob";
        
    }
    
    int find(int i, vector<int>&stone){
        
        if(i>=n)
            return 0;
        
        if(dp[i]!=INT_MIN)
            return dp[i];
   
        int a=-1e7,b=-1e7,c=-1e7;
        
        a= stone[i] + min({find(i+2,stone), find(i+3,stone), find(i+4,stone)});
        
        
        if(i+1<n)
        b= stone[i] + stone[i+1]+ min({find(i+3,stone), find(i+4,stone), find(i+5,stone)});

        if(i+2<n)
c= stone[i] + stone[i+1]+ stone[i+2]+ min({find(i+4,stone), find(i+5,stone), find(i+6,stone)});

        
        return dp[i] = max({a,b,c});
        
    }
};