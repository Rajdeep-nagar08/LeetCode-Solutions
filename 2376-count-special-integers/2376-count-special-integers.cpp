
/*

dp[i][tight][nonZero][mask]= count of all numbers till n, such that all

numbers in position range [i...n-1] should not belongs to mask,

and till now we have included no. of nonzero digits = nonzero

where mask stores all the numbers that have taken in range [0....i-1]


*/


int dp[10][2][11][1025];

class Solution {
public:
    int countSpecialNumbers(int n) {
    
        string num=to_string(n);
        
         memset(dp,-1,sizeof(dp));
        
   int i=0,tight=1;
        
   set<int>st;
    
   return find(i,tight,0,num,st,0);
        
        
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
   
  if(i==num.size()-1 && (nonZero==0) && (d==0))
      continue;
     

// if(nonZero==0 || (st.count(d)!=1)){
      
       if(nonZero==0 || ((mask & (1<<d))==0)){

     
    //  st.insert(d);
   
           if(d!=0)
               nonZero++;
           
           mask=mask|(1<<d);
      
  ans=ans+find(i+1,tight && (d==ub),nonZero,num,st,mask);
        
   //  st.erase(d);
           
           if(d!=0)
               nonZero--;
           
           mask=mask^(1<<d);
      
    
       }

 }

     
  //  return ans;
                  
 return dp[i][tight][nonZero][mask]=ans;

 }

    
};


// (mask|(1<<d))