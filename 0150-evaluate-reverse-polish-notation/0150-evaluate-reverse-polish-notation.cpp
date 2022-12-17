#define lln long long int
class Solution {
public:
    int evalRPN(vector<string>& tk) {
    
        int n=tk.size();
        
        stack<lln>st;
        
        for(string str:tk){
            
            if(str.size()==1){
                
                if(str[0]>='0' && str[0]<='9'){
                    
                    
                    st.push(str[0]-'0');
                    
                }
                
                else{
                    
                  int val1=st.top();
                    st.pop();
                    
                  int val2=st.top();
                    st.pop();
                    
                    if(str[0]=='+')
                        st.push(val1+val2);
                    else if(str[0]=='-')
                       st.push(val2-val1);
                    else if(str[0]=='*')
                        st.push(1ll*val1*val2);
                    else
                        st.push(val2/val1); 
                    
                }
                

            }
            
            else{
                
                int val=0;
                int neg=1;
                int i=0;
                if(str[0]=='-'){
                    i++; 
                    neg=-1;
                }
                
                for(;i<str.size();i++){
                    val=val*10+(str[i]-'0');
                }
                
                val=val*neg;
                
                st.push(val);
            }     
            
           // cout<<st.top()<<endl;

        }
        
        return st.top();
        
    }
};