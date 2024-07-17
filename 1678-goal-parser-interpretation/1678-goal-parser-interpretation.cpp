class Solution {
public:
    string interpret(string cmd) {
        
        
        int n=cmd.size();
        
        
        // () => o
        // (al) => al
        
        string ans="";
        
        int i=0;
        
        while(i<n){
            if(cmd[i]=='G')
                ans+="G", i++;
            else if(cmd[i]=='(' && cmd[i+1]=='a')
                ans+="al", i+=4;
            else if(cmd[i]=='(' && cmd[i+1]==')')
                ans+="o",i+=2;
        }
        
        return ans;
    }
};