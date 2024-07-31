/*

books[i] = [thicknessi, heighti]


total width = shelfWidth (sw)


sum of thicness of books <= sw

we have to adjust the books like total height is minimum

ans= minimum height

books.length <= 1000


height of ith line =max(height of all books placed at ith line)

books are placed sequence wise, means [7,8,9] [1,2,3,4] [10,11] [5,6]

dp[i]= minimum height from [i...n-1] 

note that sum of width of each subaary <= sw, and its contribution to ans= max heigt of subrray

*/


int dp[1001];

class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int sw) {
     
        int n=books.size();
        
        memset(dp,-1,sizeof(dp));
        
        return find(0,books, sw);
    
    }
    
    
    int find(int i, vector<vector<int>>& books, int &sw){
        
        if(i>=books.size())
            return 0;
        
        
        if(dp[i]!=-1)
            return dp[i];
        
        int h=0;
        int w=0;
        int ans=INT_MAX;
        for(int j=i;j<books.size();j++){
            w+=books[j][0];
            h=max(h,books[j][1]);
            if(w<=sw){
             ans=min(ans,h+find(j+1,books,sw));   
            }
            else
                break;
        }
        
        return dp[i]=ans;
    }
};