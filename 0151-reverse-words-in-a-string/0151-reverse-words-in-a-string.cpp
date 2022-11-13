/*
reverse --> [begin,end)
s.begin()+0 or s.begin() means 0th index so s.begin()+i means ith index
s.end() means nth index , where n= length of string ( points outside of string)

erase---> [begin,end) erase all characters of this range

*/

class Solution {
public:
    string reverseWords(string s) {
    
      int i=0;
      
      //removing front spaces
      while(s[i]==' ' && i<s.length())
        i++;
      
      if(i!=0)
      s.erase(s.begin(),s.begin()+i);
      
    //  removing last spaces
      i=0;
      while(s[s.length()-1-i]==' ' && i<s.length())
        i++;
      
      if(i!=0)
      s.erase(s.end()-i,s.end());
       
    //reverse whole string
      reverse(s.begin(),s.end());
      
     i=0;
      while(i<s.length()){
        
        //reverse each words
        int start=i;
        while(s[i]!=' ' && i<s.length())
          i++;
        
    
        if(start!=i)
          reverse(s.begin()+start,s.begin()+i);
        
        // remove extra spaces between two words
        start=i;
        while(s[i]==' ' && i<s.length())
          i++;
        
        if(i-start<=1)
          continue;
        else
          s.erase(s.begin()+start+1,s.begin()+i);
        
        i=start+1;
          
          
      }
 
      return s;
    }
};