/*
 break string into all posiible parts,and check for both non-swaped and swaped type:-
 // if not swaped
        bool case1= isScramble(x.substr(0,k),y.substr(0,k));
           bool case2= isScramble(x.substr(k,n-k),y.substr(k,n-k));
bool type1= case1 && case2;
        // if swaped
           bool case3= isScramble(x.substr(0,k),y.substr(n-k,k));
           bool case4= isScramble(x.substr(k,n-k),y.substr(0,n-k));
bool type2= case3 && case4;
*/

class Solution {
    
  map<string,bool>mp;
    
    
public:
    bool isScramble(string x, string y) {
        
      string key=x+' '+y;
      
      if(x.length()!=y.length())
        return mp[key]=false;
      
    if(x.compare(y)==0)
      return mp[key]=true;
      
      string s1 = x, s2 = y;
 
    sort(s1.begin(), s1.end());
        
        
    sort(s2.begin(), s2.end());
 
    if (s1 != s2) {
       return mp[key]=false;
    }
    
      int n=x.length();

      if(n==0)
        return mp[key]=false;
      
      if(mp.find(key)!=mp.end())
        return mp[key];
      
      bool flag=false;
        
        
        
      for(int k=1;k<n;k++){
        // if not swaped
        bool case1= isScramble(x.substr(0,k),y.substr(0,k));
          
           bool case2= isScramble(x.substr(k,n-k),y.substr(k,n-k));
          
bool type1= case1 && case2;
      /*  if(type1==true){
          flag=true;
          return true;
        }
        //  return mp[key]=true;*/
        // if swaped
           bool case3= isScramble(x.substr(0,k),y.substr(n-k,k));

           bool case4= isScramble(x.substr(k,n-k),y.substr(0,n-k));
          
           bool type2= case3 && case4;
           
     /*   if(type2==true){
          flag=true;
          return true;
        }*/
     //    return mp[key]=true;
        
        if(type1 || type2){
          flag=true;
          break;
        }
          
          
          
      }
        
        
        
        
          return mp[key]=flag;
        
        
      // return false;
        
        
        
      // return mp[key]=flag;
    }
};