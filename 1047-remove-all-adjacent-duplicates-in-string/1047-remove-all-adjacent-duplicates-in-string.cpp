class Solution {
public:
    string removeDuplicates(string s) {
        
        int n=s.length();
        
        int k=2;
        
        stack<pair<char,int>>st;
        
        st.push({s[0],1});
        
        int i=1;
        
        char c1,c2;
        
        while(i<n){
            
            if(st.size()==0){
              st.push({s[i],1});
              i++;
                continue;
            }
            
            c1=st.top().first;
            
            c2=s[i];
            
            if(c1==c2){
                    int k1=st.top().second;
                    if(k1==k-1)
                        st.pop();
                    else
                    {
                        st.pop();
                        st.push({c1,k1+1});
                    }
                }
            else
                st.push({c2,1});
            
              i++;
        }
        
        string ans="";
        
        while(st.size()>0){
            char ch=st.top().first;
            int k1=st.top().second;
            while(k1--){
                ans.push_back(ch);
            }
            st.pop();
        }
        
        reverse(ans.begin(),ans.end());
        
        return ans;
       }
    
};