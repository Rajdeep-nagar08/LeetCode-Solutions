

class Solution {
public:

    int repeatedStringMatch(string a, string b) {
        
        int n1=a.size();
        
        int n2=b.size();
        
        int need=n2/n1;
        
        string s="";
        
        for(int i=0;i<=need+1;i++){
            s+=a;
        }
        
       int idx=search(s,b);
        
     //   cout<<s<<" "<<idx<<endl;
        
        if(idx==-1)
            return -1;
        
        int sz=s.size();
        
        int len=idx+n2;
        
        return (len/n1+(len%n1!=0));
   
        
    }
    

    int search(string &text,string &pat){

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
          return i-j;
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


