class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        
          int n=s.size();
        
          vector<string>ans;
        
          int i=0;
        
           string str;
          while(i<n){
              str="";
              int k1=k;
              
              while(i<n && k1>0){
                  str+=s[i];
                  i++;
                  k1--;
              }
              if(str.size()==k)
                  ans.push_back(str);
          }
        
          if(str.size()!=k){
              while(str.size()<k){
                  str+=fill;
              }
                      ans.push_back(str);

          }
        
        
        return ans;
    }
};