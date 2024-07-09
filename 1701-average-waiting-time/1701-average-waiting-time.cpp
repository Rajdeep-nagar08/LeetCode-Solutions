class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& cust) {
        
        
        int n=cust.size();
        
        int end=0;
        
        double wait=0.0;
        
        for(int i=0;i<n;i++){
        
                if(cust[i][0]<end){
                    
                    end+=cust[i][1];
                    
                    wait+=end-cust[i][0];
                    
                }
                else{
                    
                    end=cust[i][0]+cust[i][1];
                    
                    wait+=cust[i][1];
                    
                }
            
        }
        
        
        
        return (double)wait/(double)n;
        
    }
};