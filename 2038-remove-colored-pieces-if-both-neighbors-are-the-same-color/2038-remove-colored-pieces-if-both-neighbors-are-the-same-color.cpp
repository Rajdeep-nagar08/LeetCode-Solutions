class Solution {
public:
    bool winnerOfGame(string s) {
        
      int n=s.length();
      
        int a=0,b=0;
        int i=0;
      while(i<n){
        int count=0;
        while(s[i]=='A' && i<n){
          count++;
          i++;
        }
          if(count>2)
            a=a+count-2;
        count=0;
        while(s[i]=='B' && i<n){
          count++;
          i++;
        }
           if(count>2)
             b=b+count-2;
      }
        if(a>b)
          return true;
      
      return false;
      
      }
};