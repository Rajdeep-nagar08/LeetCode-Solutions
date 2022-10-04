class Solution {
public:
    string removeOuterParentheses(string s) {
        
        
        int n=s.size();
        
        stack<char>st;
        
        string ans;
        
        int i=0;
        
        while(i<n){
            
            string temp;
            
            st.push(s[i]);
            
            i++;
            
            while(i<n && st.size()>0){
              if(s[i]=='('){
                  st.push(s[i]);
                  temp+=s[i];
              } 
                else{
                    st.pop();
                    temp+=s[i];
                }
                i++;
            }
            
            temp.pop_back();
                        
            ans+=temp;
        }
        
        return ans;
    }
};