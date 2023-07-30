/*

dp[i][j]= min no of turns the printer needed to print [i....j]

if s contains only 1 character, 1 turn is needed
if s contains 2 characters, 1 turn is needed if they equal to each other, or else, 2 turns are needed


 - For each of the string 's'
        - If 's' has a length of 1
            - Then we can use 1 turn to generate the string
            
        - If 's' has a length of greater than 1
            - We can partition the string into substrings 'x' and 'y'
                - Then we can find the turns of both of the substrings
                - Then the number of turns of 's' will be 'turns(x) + turns(y)'
            - Since, we want the smallest number of turns
                - We will want to pick the index 'k' that will give us
                  the partition that will give us the smallest number of turns
                  
                  
            - A side case we have to handle is when the first character is
              equal to the last character
                - Then we have to decrement the number of turns by 1
                - Examples: "aa"
                    - We do not want 1 + 1 = 2, because the printer can
                      generate a sequence of the same characters
                    - We will want to decrement it to '2 - 1 = 1'
                    
    - We can keep track of our current left 'i' and right 'j' boundaries
      of the input string and find the minimum number of turns

DIVIDE AND CONQUER ALGO;;;;
*/

// TLEEE

int dp[101][101];
class Solution {
public:
    int strangePrinter(string s) {
        memset(dp,-1,sizeof(dp));
      
      return get(0,s.length()-1,s);
    }
  
    int get(int i,int j,string &s){
      if(i==j)
        return 1;
      if(dp[i][j]!=-1)
        return dp[i][j];
      
      int ans=INT_MAX;
      for(int k=i;k<j;k++){  //not do k<=j otherwise K+1 will be out of bound
        ans=min(ans,get(i,k,s)+get(k+1,j,s));
      }
      
      if(s[i]==s[j]) // only one turn needed, so decrease by 1 as both are same
        ans--;
      
      return dp[i][j]=ans;
    }
};