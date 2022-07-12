/*

move first person from [0,0] to [n-1,m-1] and allowing it to collect max cherries
, make cherries collected by it to 0

than move second person from [n-1,m-1] to [0,0] and make him to collect max cherries

But this techniques failled on the test-case

11100
00101
10100
00100
00111

According to this tech. 
person 1 collect => 9 , person 2=>1, Answer = 10

But best possible answer is :
person 1 collect => 6 , person 2 =>5 ,Answer = 6+5=11

So we want collectively maximum cherries.
So, we have to do the traversal of both paths at the same time and select maximum global answer. 

If both are at the same cell we count cherry only once.

//First approach (failled)  (maximizing answer one by one)

int dp1[51][51];
int dp2[51][51];

int dx1[2]={1,0};
int dy1[2]={0,1};

int dx2[2]={-1,0};
int dy2[2]={0,-1};

#define lln long long int
class Solution {
public:
    int n,m;
    int cherryPickup(vector<vector<int>>& grid) {
        
        n=grid.size();
        m=grid[0].size();
    
        
        
        dp1[i][j]= max no of cherry taht can be get from [i,j] to [n-1,m-1]
        dp2[i][j]= max no of cherry taht can be get from [i,j] to [0,0]
 
        
        
        memset(dp1,-1,sizeof(dp1));
        memset(dp2,-1,sizeof(dp2));

        
        int ans1=find1(0,0,grid)+(grid[0][0]==1);
        
        grid[0][0]=0;
     
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
              cout<<grid[i][j]<<" ";
                }
            cout<<endl;
        }
    
        
            
      int ans2=find2(n-1,m-1,grid);
        
        if(ans1+ans2 < 0)
            return 0;
        
        return ans1+ans2;
        
    }
    
     int find1(int i,int j,vector<vector<int>>& grid){
         
         if(i==n-1 && j==m-1){
             return 0;
         }
         
         if(dp1[i][j]!=-1)
             return dp1[i][j];
         
         int mx=-1e6;
         
         for(int k=0;k<2;k++){
             int x1=i+dx1[k];
             int y1=j+dy1[k];
             
             if(x1<n && y1<m && x1>=0 && y1>=0 && grid[x1][y1]!=-1){
               bool one=false;
                 if(grid[x1][y1]==1){
                     one=true;
                     grid[x1][y1]=0;
                 }
                 int a=find1(x1,y1,grid)+one;
                 if(mx<a){
                     mx=a;
                 }
                 else{
                     if(one)
                         grid[x1][y1]=1;
                 }
                
             }
         }
         
         return dp1[i][j]=mx;
             
     }
    
    
      int find2(int i,int j,vector<vector<int>>& grid){
         
         if(i==0 && j==0){
             return 0;
         }
         
         if(dp2[i][j]!=-1)
             return dp2[i][j];
         
         int mx=-1e6;
         
         for(int k=0;k<2;k++){
             int x1=i+dx2[k];
             int y1=j+dy2[k];
            
             if(x1<n && y1<m && x1>=0 && y1>=0 && grid[x1][y1]!=-1){
      
             mx=max(mx,find2(x1,y1,grid)+(grid[x1][y1]==1));
                 
             }
         }
         
         return dp2[i][j]=mx;
             
     }
};

*/

/*
// moving both persons simultaneously to get max. global answer:

two persons move as

[LL] , [LD] , [DL] , [DD]

dp[i1][j1][i2][j2] = max (cherries collected by firest person from [i1,j1] to [n-1,m-1] + cherries collected by second person from [i2,j2] to [n-1,m-1]

*/


#define lln long long int
int dp[51][51][51][51];
class Solution {
public:
    int n,m;
    int cherryPickup(vector<vector<int>>& grid) {
        
        n=grid.size();
        m=grid[0].size();
    
        memset(dp,-1,sizeof(dp));
        
        int ans=find(0,0,0,0,grid);    
        
        if(ans<0)
            return 0;
        
        return ans;
        
    }
    
    int find(int i1,int j1,int i2,int j2,vector<vector<int>>& grid){
        
    if(i1>=n || j1>=m || i2>=n || j2>=m || i1<0 || j1<0 || i2<0 || j2<0 || grid[i1][j1]==-1 || grid[i2][j2]==-1){
            return -1e6;
        }
        
        if(i1==n-1 && j1==m-1){
            return grid[i1][j1];
        }
        
        if(i2==n && j2==m-1){
            return grid[i2][j2];
        }
        
        if(dp[i1][j1][i2][j2]!=-1)
            return dp[i1][j1][i2][j2];
        
        int mx=-1e6;
        
        int cher;
        
        if(i1==i2 && j1==j2)                   // both on the same cell, count it once
            cher=grid[i1][j1];
        else
            cher=grid[i1][j1]+grid[i2][j2];

        
        mx=max({mx,cher+find(i1,j1+1,i2,j2+1,grid),  //[LL]
                cher+find(i1,j1+1,i2+1,j2,grid),     //[LD]
                cher+find(i1+1,j1,i2,j2+1,grid),     //[D,L]
                cher+find(i1+1,j1,i2+1,j2,grid)});    //[D,D]
        
        return dp[i1][j1][i2][j2]=mx;
        
    }
               
 };
        