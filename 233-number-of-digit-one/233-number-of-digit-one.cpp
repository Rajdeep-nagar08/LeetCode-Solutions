/*

So based on whether the position is tight bound or not we have choices for each position


  Think about dp
  ----------------

 int  n=nums.size();

  dp[i][tight][countOnes] = Count of all ones in position range [i....n-1] of all numbers 

  till "5672" based on current position i is tight bound or not, 

  And count of ones till now from positions [0...i-1] are "countOnes"

  Ans= dp[0][1][0]


  If max length of nums possible = 2000


dp[2001][2][2001];

  int countDigitOnes(string num){

   memset(dp,-1,sizeof(dp));

   int i=0,tight=1,countOnes=0;  

   // for i=0, tight=1 becouse we cannot put all digits to this position

   return find(i,tight,countOnes,nums);

  }

 int find(int i,int tight,int countOnes,nums){
  if(i==nums.size())
  return countOnes;

  if(dp[i][tight][countOnes]!=-1)
  return dp[i][tight][countOnes];

  int ub;   // upperBound digit of position i

  if(tight==1)
  ub=nums[i]-'0';
  else
  ub=9;

  int ans=0;

  for(int d=0;d<=ub;d++){

 

   ans=ans+find(i+1,tight && (d==ub),countOnes + (d==1));
  }

  return dp[i][tight][countOnes]=ans;
 }



*/

int dp[10][2][10];

class Solution {
public:
    int countDigitOne(int nums) {
        
        memset(dp,-1,sizeof(dp));

   int i=0,tight=1,countOnes=0;  

   // for i=0, tight=1 becouse we cannot put all digits to this position
        
        string str=to_string(nums);
        
   return find(i,tight,countOnes,str);

        
    }
    
int find(int i,int tight,int countOnes,string nums){
    
  if(i==nums.size())
  return countOnes;

  if(dp[i][tight][countOnes]!=-1)
  return dp[i][tight][countOnes];

  int ub;   // upperBound digit of position i

  if(tight==1)
  ub=nums[i]-'0';
  else
  ub=9;

  int ans=0;

  for(int d=0;d<=ub;d++){

   ans=ans+find(i+1,tight && (d==ub),countOnes + (d==1),nums);
      
  }

  return dp[i][tight][countOnes]=ans;
 }



};