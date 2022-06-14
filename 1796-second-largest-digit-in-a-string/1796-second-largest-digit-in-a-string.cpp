class Solution {
public:
    int secondHighest(string s) {
        
        int n1=-1,n2=-1;
        
        for(char ch:s){
            if(ch>='0' && ch<='9'){
                int no=ch-'0';
                if(no>n1){
                    n2=n1;
                    n1=no;
                }
                else if(no<n1 && no>n2)
                    n2=no;
            }
        }
        
        return n2;
    }
};