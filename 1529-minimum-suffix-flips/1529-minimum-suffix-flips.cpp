class Solution {
public:
    int minFlips(string tar) {
        
        
        int n=tar.size();
        
        int i=0;
        
        int f=0;
        
        while(i<n){
            if(tar[i]=='0'){
                if(f%2==1){
                    f++;
                }
            }
            
            if(tar[i]=='1'){
                if(f%2==0){
                    f++;
                }
            }
            
            i++;
        }
        
        
        return f;
        
    }
};