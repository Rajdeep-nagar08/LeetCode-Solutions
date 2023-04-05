class Solution {
public:
    bool queryString(string s, int n) {
        
        vector<bool>v(n+1,false);
        
        int sz=log2(n)+1;
        
        int m=s.size();        
        
        for(int l=1;l<=sz;l++){
            
            for(int i=0;i<m;i++){
                
                if(i+l-1<m){
                                        
                string str=s.substr(i,l);
                
                  int num = stoi(str, 0, 2);
                    
                    if(num<=n && (v[num]==false)){
                        v[num]=true;
                    }

                }
            }
            
        }
        
        
        for(int i=1;i<=n;i++){
            if(v[i]==false)
                return false;
        }
        
        return true;
        
    }
};