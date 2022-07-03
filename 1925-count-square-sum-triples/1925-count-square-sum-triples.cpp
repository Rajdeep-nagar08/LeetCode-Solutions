class Solution {
public:
    int countTriples(int n) {
        
        int count=0;
        
        for(int i=1;i<=n;i++){
    
            for(int j=i+1;j<=n;j++){
                
                int k=i*i+j*j;
                
                int k1=sqrt(k);
                
                if(k1>n)
                    break;
                
                if(k1*k1==k){
                    count++;
                
                if(i!=j)
                    count++;
                }
                
            }
        }
        return count;
    }
};