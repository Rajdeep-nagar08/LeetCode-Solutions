class Solution {
public:
    int totalMoney(int n) {
       
        
        int sum=0;
        
        int mn=1;
        
        int cnt=0;
        
        int start=mn;
        
        while(n--){
            
            if(cnt<7){
               sum+=start;
               start++;
               cnt++;
            }
            else{
               mn++;
               start=mn;
               sum+=start;
               cnt=1; 
               start++;
            }
            
        }
        
        return sum;
    }
};