
/*

dp[i][tight][nonZero][mask]= count of all numbers till n, such that all

numbers in position range [i...n-1] should not belongs to mask,

and till now we have included no. of nonzero digits = nonzero

where mask stores all the numbers that have taken in range [0....i-1]


Using mask to make sure that all digits should be included ones


Note we are taking count of nonZero numbers becouse-:

For 5 digit no:

-----

Possible no. = 00012 , 00013  

[they are number 12,13 but while forming them we taken 0's multiple times, so we needs to take care that we can take multiple zeroes before any non zero digit

]

*/


int dp[10][2][11][1025];

class Solution {
public:
    int countSpecialNumbers(int n) {
    
        string num=to_string(n);
        
         memset(dp,-1,sizeof(dp));
        
   int i=0,tight=1;
        
   set<int>st;
    
   return find(i,tight,0,num,st,0)-1;
   
        // doing '-1' to ignore no =0
        
        
        
    }
    
    
 int find(int i,int tight,int nonZero,string &num,set<int>&st,int mask){

  if(i==num.size()){
   return 1;
  }


  int ub;  // upper bound digit

  if(tight==1)
  ub=num[i]-'0';
  else
  ub=9;

       
  if(dp[i][tight][nonZero][mask]!=-1)
  return dp[i][tight][nonZero][mask];
  
  int ans=0;

  for(int d=0;d<=ub;d++){
 
       if(nonZero==0 || ((mask & (1<<d))==0)){
           
           if(d!=0)
               nonZero++;
           
           mask=mask|(1<<d);
      
  ans=ans+find(i+1,tight && (d==ub),nonZero,num,st,mask);
                   
           if(d!=0)
               nonZero--;
           
           mask=mask^(1<<d);
      
    
       }

 }
                  
 return dp[i][tight][nonZero][mask]=ans;

 }

    
};
