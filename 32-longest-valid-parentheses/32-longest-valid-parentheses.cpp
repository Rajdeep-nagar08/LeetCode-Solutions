class Solution {
public:
    int longestValidParentheses(string s) {
        
        int n=s.size();
        
        stack<int>st;
        
        int i=0;
        
        vector<int>v;
        
        while(i<n){
          
            if(s[i]=='('){
                st.push(i);
            }
            else{
                if(st.size()==0 || s[st.top()]==')')
                    st.push(i);
                else {
                    v.push_back(st.top());
                    v.push_back(i);
                    st.pop();
                }
            }
            
            i++;
        }
        
        if(v.size()==0)
            return 0;
        
      sort(v.begin(),v.end());
        
       int sz=v.size();
      
        i=0;
        
        int l=0;
        
        
        while(i<sz){
          int a=v[i];
            i++;
            int count=1;
          while(i<sz && ((v[i]-a)==1)){
              a=v[i];
              count++;
              i++;
          }
            l=max(l,count);
        }
        
        return l;
    }
};