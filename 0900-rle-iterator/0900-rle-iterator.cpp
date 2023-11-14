class RLEIterator {
public:
    vector<int>v;
    
    int i=0;

    
    RLEIterator(vector<int>& encoding) {
        
        v=encoding;
        
        
    }
    
    int next(int n) {
        while(i<v.size() and n>0){
            if(v[i]<n){
                n=n-v[i];
                v[i]=0;
                i+=2;
            }
            else{
                v[i]=v[i]-n;
                return v[i+1];
            }
        }
        
        return -1;
    }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(encoding);
 * int param_1 = obj->next(n);
 */