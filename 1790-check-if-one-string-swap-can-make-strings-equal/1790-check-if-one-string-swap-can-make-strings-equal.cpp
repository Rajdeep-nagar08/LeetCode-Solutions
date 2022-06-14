class Solution {
public:
    bool areAlmostEqual(string a, string b) {
        
        if(a==b)
            return true;
        
       return makeSwap(a,b)||makeSwap(b,a); 
        
    }
    
    bool makeSwap(string a,string b){
        int n=a.size();
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                swap(a[i],a[j]);
                    if(a==b)
                        return true;
                swap(a[i],a[j]);
            }
        }
        return false;
    }
};