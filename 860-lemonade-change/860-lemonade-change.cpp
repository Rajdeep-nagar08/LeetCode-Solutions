class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        
      int n=bills.size();
        int fcount=0,tcount=0,wcount=0;
        
            for(int i=0;i<n;i++){
               if(bills[i]==5){
                   fcount++;
               }
                else{
                   if(bills[i]==10){
                       if(fcount>0){
                       fcount--;
                       tcount++;
                       }
                       else{
                           return false;
                       }
                     }
                    
                   else{
                       
                           if(fcount>0&&tcount>0){
                               fcount--;
                               tcount--;
                               wcount++;
                           }
                       
                       else  if(fcount>=3){
                            fcount-=3;
                           wcount++;
                       }
                       else
                         return false;
                           
                       }
                   
                 }
            }
    
            return true;  
    }
};