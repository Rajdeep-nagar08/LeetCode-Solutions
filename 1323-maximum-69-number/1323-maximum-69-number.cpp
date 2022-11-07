class Solution {
public:
    int maximum69Number (int num) {
       string str=to_string(num);
      int n=str.length();
      int i=0;
      while(i<n){
        if(str[i]=='6')
          break;
        i++;
      }
      
      if(i==n)
        return num;
      
      str.replace(i,1,"9");
      
      int no=stoi(str);
      return no;
      
    }
};