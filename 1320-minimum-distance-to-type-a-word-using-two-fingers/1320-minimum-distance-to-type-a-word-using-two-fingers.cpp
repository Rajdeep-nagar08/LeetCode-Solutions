/*

for each char, we have two choices => Either use 1st finger to type this char or used second finger to type it

As we have choices, we can think about dp,

dp[i][first][second] = min distance moved by two fingers

to type letters in range [i...n-1] , currently our first finger is at 

letter = first, and second finger is at letter=second

[0<=i<300] [1<=first<=26]  [1<=second<=26]  

T.C= O(300*26*26) = O(8*1e5) 


NOTE: coordinate of char='ch' is :

x = (ch/6)-(ch%6==0?1:0)

y=  6-[(x+1)*6-ch]-1;

*/

int dp[301][27][27];

class Solution {
public:
    int n;
    int minimumDistance(string word) {
        
        n=word.size();
        
        memset(dp,-1,sizeof(dp));
        
        return find(0,0,0,word);
    
    }
    
    int find(int i,int first,int second,string& str){
        
        if(i>=n)
            return 0;
        
        if(dp[i][first][second]!=-1)
            return dp[i][first][second];
        
        int xprev=0,yprev=0;
        
        int xcurr,ycurr;
        
        int no=str[i]-'A'+1;
    // x = (ch/6)-(ch%6==0?1:0)
    
        xcurr=(no/6)-(no%6==0?1:0);
        
  // y=  6-[(x+1)*6-ch]-1;
        
        ycurr=6-((xcurr+1)*6-no)-1;
        
     //   cout<<str[i]<<" "<<xcurr<<" "<<ycurr<<endl;

        
        int c1=INT_MAX;
        
        if(first==0){
           c1=min(c1,find(i+1,no,second,str));
        }
        
        else
        {
           xprev=(first/6)-(first%6==0?1:0);
           
           yprev=6-((xprev+1)*6-first)-1;
            
        c1=min(c1,abs(xprev-xcurr)+abs(yprev-ycurr)+find(i+1,no,second,str));
 

        }
        
          int c2=INT_MAX;
        
        if(second==0){
           c2=min(c2,find(i+1,first,no,str));
        }
        else
        {
           xprev=(second/6)-(second%6==0?1:0);
           
           yprev=6-((xprev+1)*6-second)-1;
            
        c2=min(c2,abs(xprev-xcurr)+abs(yprev-ycurr)+find(i+1,first,no,str));
 

        }
        
        
        return dp[i][first][second]=min(c1,c2);
        
    }
};