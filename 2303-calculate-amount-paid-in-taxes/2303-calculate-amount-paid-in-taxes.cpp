class Solution {
public:
    double calculateTax(vector<vector<int>>& b, int inc) {
        
        if(inc==0)
            return 0.000000;
        
        
        double ans=0.00000;
        
        int n=b.size();
        
        int total=0;
        
        
        
         ans=min(b[0][0],inc)*((double)b[0][1]/(double)100);
        
        int sum=min(b[0][0],inc);
        
        for(int i=1;i<n;i++){
            int e=b[i][0]-b[i-1][0];
            double intr=b[i][1];
            
             if(sum+e<=inc){
                ans+= e*((double)b[i][1]/(double)100);
                 sum+=e;
             }
            else{
                double need=inc-sum;
                ans+= need*((double)b[i][1]/(double)100);
                return ans;
            }
        }
        
        return ans;
    }
};