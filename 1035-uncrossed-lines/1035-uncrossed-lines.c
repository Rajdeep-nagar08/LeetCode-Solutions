  //  int dp[nums1Size+1][nums2Size+1];
    int dp[501][501];

int alu(int *nums1, int nums1Size, int *nums2, int nums2Size)
{
  
  if(nums1Size==0 || nums2Size==0)
    return 0;
  
  if(dp[nums1Size][nums2Size]!=-1)
    return dp[nums1Size][nums2Size];
 
     if(nums1[0]==nums2[0]) 
       return dp[nums1Size][nums2Size]= 1+alu(&nums1[1],nums1Size-1,&nums2[1],nums2Size-1);
  
      else
     return dp[nums1Size][nums2Size]= max(alu(&nums1[0],nums1Size,&nums2[1],nums2Size-1),alu(&nums1[1],nums1Size-1,&nums2[0],nums2Size));

}

int max(int a,int b) 
    
{
   if(a>b)
     return a;
  return b;
}          


int maxUncrossedLines(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int c;
  

  for(int i=0;i<=nums1Size;i++){
    for(int j=0;j<=nums2Size;j++){
      dp[i][j]=-1;
    }
  }
  
c=alu(&nums1[0],nums1Size,&nums2[0],nums2Size);
    
    return(c);
}