#define lln long long int

class Solution {
public:
    int nextGreaterElement(int n) {
        
        
        string str=to_string(n);
        
        vector<int>v;
        
        for(char ch:str){
            v.push_back(ch-'0');
        }
        
        lln t=1e12;
        
        sort(v.begin(),v.end());
        
        do{
            
            lln ans=0;
            
            for(int x:v){
                ans=1ll*ans*10+x;
            }
            
            if(ans<=INT_MAX && ans>n){
                t=min(t,ans);
            }
            
        }while(next_permutation(v.begin(),v.end()));
        

        
        if(t>INT_MAX)
            return -1;
        
        return t;
        
    }
};