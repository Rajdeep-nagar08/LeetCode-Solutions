class Solution {
public:
    int maxDepth(string s) {
       
        
        int n=s.size();
        
        
        int open=0;
        
        int ans=0;
        
        for(char ch:s){
            if(ch=='('){
                open++;
                ans=max(ans,open);
            }
           
            if(ch==')'){
                open--;
            }
            
            
        }
        
        return ans;
    }
};