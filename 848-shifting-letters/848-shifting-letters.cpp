#define lln long long int
class Solution {
public:
    string shiftingLetters(string s, vector<int>& sh) {
        
        
        int n=s.size();
        
        vector<lln>v(n,0);
        
        v[n-1]=sh[n-1];
        
        
        for(int i=n-2;i>=0;i--)
          v[i]=sh[i]+v[i+1];
        
        for(int i=0;i<n;i++){
            
            
            lln need=v[i];
            
            /*
            
            a=>0
            b=>1 
            
            [0,25] => 26=>0 , 27=>1
            
            */
                        
            char ch=s[i];  // b=> 14
            
            int no=ch-'a'+1;  // b=2
            
            need=(need+no);
            
            lln f=need/26;
            
            need=need-1ll*f*26;
            
            if(need==0)
                s[i]='z';
            
            else
            
            s[i]='a'+need-1;
        }
        
        return s;
    }
};