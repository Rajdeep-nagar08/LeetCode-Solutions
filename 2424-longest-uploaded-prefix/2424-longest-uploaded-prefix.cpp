class LUPrefix {
public:
    
    int total;
        
    int last=1;
    
    vector<int>v;
    
    LUPrefix(int n) {
        
        total=n;
        
        v.resize(n+1,-1);
        
    }
    
    void upload(int video) {
            
        v[video]=1;
        
    }
    
    int longest() {
                
        for(int j=last;j<=total;j++){
            if(v[j]==-1){
                last=j;
                return last-1;
            }
        }
        
        return total;
        
    }
};

