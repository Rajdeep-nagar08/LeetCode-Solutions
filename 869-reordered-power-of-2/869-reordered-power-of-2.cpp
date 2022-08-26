#define lln long long int
class Solution {
public:
    bool reorderedPowerOf2(int n) {
        
        string str=to_string(n);
        
        sort(str.begin(),str.end());
        
        do{
         
            if(str[0]=='0')
                continue;
            
            lln no=stoll(str);
            
            
            int x=log2(no);
            
            if(pow(2,x)==no)
                return true;
            
        }while(next_permutation(str.begin(),str.end()));
        
        return false;
    }
};