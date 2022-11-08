class Solution {
public:
    string makeGood(string s) {
        
        
        // 65-90 [A-Z]
        
        // 97-  [a-z]
        
      stack<char>st;
    
     int n=s.size();
        
        int i=0;
        
        while(i<n){
            char ch=s[i];
            
            if(st.size()==0)
               st.push(ch);
               
               else if(st.size()>0 && abs(st.top()-ch)==32){
                   st.pop();
               }
            
            else 
                st.push(ch);
            
            i++;
                
        }
        
        string ans="";
        
        while(st.size()>0){
            ans+=st.top();
            st.pop();
        }
        
        if(ans=="")
            return ans;
        
        reverse(ans.begin(),ans.end());
        
        return ans;
        
        
      
    }
};