class Solution {
public:
    int longestValidParentheses(string s) {
        
        int n=s.size();
        
        stack<int>st;
        
        int i=0;
        
        vector<int>v(n,-1);
        
        while(i<n){
            if(s[i]=='('){
                st.push(i);
            }
            
            if(s[i]==')'){
                if(st.size()>0){
                    v[i]=0;
                    v[st.top()]=0;
                    st.pop();
                }
            }
            
            i++;
        }
        
        int mx=0;
        
        i=0;
        
        while(i<n){
            
            int cnt=0;
            
            while(i<n && v[i]==0){
                i++;
                cnt++;
            }
            
            i++;
            
            mx=max(mx,cnt);
        }
        
        return mx;
    }
};