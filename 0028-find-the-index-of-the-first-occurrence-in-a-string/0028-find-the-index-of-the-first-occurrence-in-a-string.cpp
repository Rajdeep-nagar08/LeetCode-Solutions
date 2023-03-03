// either use robin karp or use kmp

#define d 26

#define lln long long int

class Solution {
public:
    int strStr(string text, string pat) {
        
        
        vector<int>lps(pat.length(),0);
     makelps(pat,lps);

    int i=0,j=0;

    while(i<text.length()){

      if(text[i]==pat[j]){
      i++;
      j++;
      }

      else{
        if(j!=0)
        j=lps[j-1];
        else
        i++;
      }

      if(j==pat.length()){
          return (i-j);
      cout<<"Pattern found at index ="<<(i-j)<<endl;
      j=lps[j-1];
       }

    }
        
        
        return -1;
        
    }
    
    
    
    

void makelps(string pat,vector<int>&lps) {
      int i=1,j=0;
      lps[0]=0;
      while(i<pat.length()){
        if(pat[i]==pat[j]){
          lps[i]=j+1;
          j++;
          i++;
        }
        else{
          if(j!=0)
            j=lps[j-1];
          else{
            lps[i]=0;
            i++;
          }
        }
      }
      return;
    }



    
};