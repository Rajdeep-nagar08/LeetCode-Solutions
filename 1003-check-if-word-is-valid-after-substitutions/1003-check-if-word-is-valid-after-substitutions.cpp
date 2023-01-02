class Solution {
public:
    bool isValid(string s) {
     
        
        int n=s.size();
        
        stack<char>st;
                
        for(int i=0;i<n;i++){
            
            st.push(s[i]);
            
            if(st.size()>=3){
                if(st.top()=='c'){
                    st.pop();
                    if(st.top()=='b'){
                        st.pop();
                        if(st.top()=='a'){
                            st.pop();
                        }
                        else{
                            st.push('b');
                            st.push('c');
                        }
                    }
                    else{
                        st.push('c');
                    }
                }
            }
            
        }
        return st.size()==0;
    }
};