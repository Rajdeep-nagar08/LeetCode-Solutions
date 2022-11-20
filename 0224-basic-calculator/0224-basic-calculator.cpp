#define lln long long int
class Solution {
public:
    int calculate(string s) {
        
        stack<int>st;
        stack<int>sig;
        
        lln temp=0;
        lln ans=0;
        int sign=1;
        
     for(int i=0;i<s.size();i++){
            if(isdigit(s[i]))
                temp=temp*10+(s[i]-'0');
        
            else{
                ans=ans+sign*temp;
                temp=0;
                
                if(s[i]=='+')
                    sign=1;
                else if(s[i]=='-')
                    sign=-1;
                else if(s[i]=='('){
                    st.push(ans);
                    sig.push(sign);
                    ans=0;
                    sign=1;
                }
                else if(s[i]==')'){
                    ans=ans*sig.top()+st.top();
                    sig.pop();
                    st.pop();
                }
            }
     }
        
        ans+=temp*sign;
        return ans;
    }
};
