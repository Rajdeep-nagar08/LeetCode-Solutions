/*

MY FIRST THOUGHT ////

Ans= sum(k*k)
so ans will be max when k=max , k=max when all similars no's are consecuctive and we remove tham at once

We can think it greadly

/////////////////////////

we need to break the array into parts , can we think abount MCM pattern ( as here solution of subproblem don't depends on the subproblem itself)

dp[i][j][k]= Max points we can get from [i...j] if we have k similar boxes similar to box[i] just to the left of i

[.....[i...j]....]=> Can be of type

[...[A,A,A,A,,,k boxes of type A][i=>A,B,C,D,(m=>A),....j]]

Now we have two choices to get points from [i....j]
1.
We collect k boxes to left of i and ith box , so we have total of (k+1) boxes whose point=(k+1)*(k+1) , and we find points for remaining 
[i+1.....j] array
So for this case , we have
dp[i][j][k]= (k+1)*(k+1) + dp[i+1][j][0] , here all (k+1) boxes are of same type

2.
We do not collect boxes of type A in a hope that we can get Some more boxes of type A in future (at index m)
So first we find points for subarray [i+1,m-1] then we handle previous k+1 boxes of type A with new box of type A at index m  in countinous to other boxes
So
dp[i][j][k]= dp[i+1][m-1][0] + dp[m][j][m+1] , here box[i]==box[m]

dp[i=[j][k]= max(case1,case2)

Ans= dp[0][n-1][0]

Base Cases:
if(i>j) No box , dp[i][j][k]=0

*/

int dp[100][100][100];
class Solution {
public:
    int removeBoxes(vector<int>& boxes) {
    
      memset(dp,-1,sizeof(dp));
      
     return getPoints(0,boxes.size()-1,0,boxes);
    }
  
    int getPoints(int i,int j,int k,vector<int>&boxes){
      if(i>j)
        return 0;
      
      if(dp[i][j][k]!=-1)
        return dp[i][j][k];
     
      // CASE 1 :
      
      int i1=i,k1=k;
      while((i+1<=j) && (boxes[i]==boxes[i+1])){
        i++,k++;
      }
       int ans=(k+1)*(k+1) + getPoints(i+1,j,0,boxes);
    
      // CASE 2 :
      
       for(int m=i+1;m<=j;m++){
         if(boxes[i]==boxes[m])
    ans=max(ans,getPoints(i+1,m-1,0,boxes)+getPoints(m,j,k+1,boxes));
       }
          
        return dp[i1][j][k1]=ans;
      }
};