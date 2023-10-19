class Solution {
public:
    bool backspaceCompare(string s, string t) {
        
        
        int n=s.size();
        
        int m=t.size();
        
        
        int i=n-1, j=m-1;

        int c1=0, c2=0;
        
        while(i>=0){
            if(s[i]=='#'){
                c1++;
                // cout<<c1<<endl;
            }
            else if(c1>0){
                c1--;
            }
            else{
                
                char ch1=s[i];
                
                // cout<<ch1<<endl;
                
                char ch2=' ';
                                
                while(j>=0){
                    if(t[j]=='#'){
                        c2++;
                    }
                    else if(c2>0){
                        c2--;
                    }
                    else{
                        if(t[j]==ch1){
                            ch2=t[j];
                            j--;
                            break;
                        }
                        else
                            return false;
                    }
                    j--;
                }
                
                
                if(ch1!=ch2)
                    return false;
                
            }
            
            i--;
            
           
        }
        
        
        
        while(j>=0){
            if(t[j]=='#')
                c2++;
            else if(c2>0)
                c2--;
            else
                return false;
            
            j--;
        }
        
        
        // cout<<i<<" "<<j<<endl;
        
        if(i>=0 || j>=0)
            return false;
        
        return true;
        
        
    }
};