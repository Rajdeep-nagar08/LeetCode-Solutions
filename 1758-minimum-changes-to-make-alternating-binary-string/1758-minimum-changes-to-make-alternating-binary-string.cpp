class Solution {
public:
    int minOperations(string s) {
        
        /*
        
        either start from 0 or 1
        
        return min changes needs among both cases
        
        */
        
        return min(find(s,0),find(s,1));
    }
    
    
    int find(string s,int c){
        
        int count=0;
        
        int n=s.size();
        
        for(int i=0;i<n;i++){
            if(i%2==0){
                
                if(c==0){  // even index par 0
                    if(s[i]!='0')
                        count++;
                }
                else{  // even index par 1
                    if(s[i]!='1')
                        count++;
                }
                
            }
            else{
                
                 if(c==0){  // odd index par 1
                    if(s[i]!='1')
                        count++;
                }
                else{  // odd index par 0
                    if(s[i]!='0')
                        count++;
                }
                
            }
        }
        
        return count;
    }
};