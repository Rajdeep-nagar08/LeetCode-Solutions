class Solution {
public:
    string reverseParentheses(string s) {
        
        
        int n=s.size();
        
        stack<string>st;
        
        
        for(int i=0;i<n;i++){
            
           if(s[i]==')'){
               string s1;
               
               while(st.top()!="("){
                   string x=st.top();
                   reverse(x.begin(),x.end());
                   s1+=x;
                   st.pop();
               }
               st.pop();
               st.push(s1);
           }
            
            else{
                string s2;
                s2+=s[i];
                st.push(s2);
            }
            
        }
        
        string ans;
        
        stack<string>st1;
        
        
        
        while(st.size()>0){
            st1.push(st.top());
            st.pop();
        }
        
        while(st1.size()>0){
            ans+=st1.top();
            st1.pop();
        }
        
        return ans;
        
    }
};