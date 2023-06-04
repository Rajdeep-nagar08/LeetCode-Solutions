
int mod=1e9+7;

int dp1[23][2][401];


int dp2[24][2][405];


#define lln long long int


class Solution {
public:
    int count(string num1, string num2, int minSum, int maxSum) {
        
        
           memset(dp1,-1,sizeof(dp1));
        
           memset(dp2,-1,sizeof(dp2));


        
        lln ans=0;
        
         int s1=0;
            
            for(char ch:num1){
                s1+=(ch-'0');
            }
        
        
        for(int i=minSum;i<=maxSum;i++){
            
            lln x1=sumX2(num2,i);
            
            lln x2=sumX1(num1,i);
            
            ans+=(x1-x2);
            
            if(s1==i)
                ans++;
        }
        
        
        return ans%mod;
        
    }
    
    
 int sumX1(string num,int X){
     
     
   int i=0,tight=1,sum=X;
     
   return find3(i,tight,sum,num);
     
 }
    
    
     
 int sumX2(string num,int X){
     
     
   int i=0,tight=1,sum=X;
     
   return find4(i,tight,sum,num);
     
 }
    

 int find3(int i,int tight,int sum,string num){
     
  if(sum<0)
  return 0;

  if(i==num.size()){


   if(sum==0)
   return 1;

   return 0;
  }
 
 if(dp1[i][tight][sum]!=-1)
  	return dp1[i][tight][sum];


  int ub;  // upper bound digit

  if(tight==1)
  ub=num[i]-'0';
  else
  ub=9;

  int ans=0;

  for(int d=0;d<=ub;d++){

  ans=ans+find3(i+1,tight && (d==ub),sum-d,num);

  }

  return dp1[i][tight][sum]=ans;
 }
    
    
    
 int find4(int i,int tight,int sum,string num){
     
  if(sum<0)
  return 0;

  if(i==num.size()){


   if(sum==0)
   return 1;

   return 0;
  }
 
 if(dp2[i][tight][sum]!=-1)
  	return dp2[i][tight][sum];


  int ub;  // upper bound digit

  if(tight==1)
  ub=num[i]-'0';
  else
  ub=9;

  int ans=0;

  for(int d=0;d<=ub;d++){

  ans=ans+find4(i+1,tight && (d==ub),sum-d,num);

  }

  return dp2[i][tight][sum]=ans;
 }
    
    
};