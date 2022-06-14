class Solution {
public:
    int numDifferentIntegers(string str) {
     
        
        int i=0;
        
        unordered_set<string>st;
        
        int z=0;
        
        int n=str.size();
        
        while(i<n){
            
            if(isdigit(str[i])){
                
                if(str[i]=='0'){
                    
                while(i<n && str[i]=='0'){
                    i++;
                }
                
            
                if((i<n && isdigit(str[i]))==false)
                    st.insert("0");
                    
                }
            
                
                string val;
                
                while(i<n && isdigit(str[i])){
                    val+=str[i];
                    i++;
                }
                
                
                if(val.size()>0)
                st.insert(val);
                
            }
            else
                i++;
        }

        
        return st.size();
        
    }
};
