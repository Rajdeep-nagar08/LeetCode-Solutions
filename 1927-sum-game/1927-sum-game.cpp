class Solution {
public:
    
    int n;
    
    bool sumGame(string num) {
        
     n=num.size();   
        
        
    // Alice starting first
        
    
        // bob to win => sum1 == sum2
        
        // alice to win => sum1 not equals to sum 2
        
        
        
        int sum1=0, c1=0;
        
        int sum2=0, c2=0;
        
        
        for(int i=0;i<n/2;i++){
            if(num[i]=='?'){
                c1++;
            }
            else{
                sum1+=num[i]-'0';
            }
        }
        
        
        for(int i=n/2;i<n;i++){
            if(num[i]=='?'){
                c2++;
            }
            else{
                sum2+=num[i]-'0';
            }
        }
        
         
        if((c1+c2)%2==1)   // ALICE always wins
            return true;
       
        if(c1==c2)  {
            if(sum1==sum2)
            // BOB always wins
            return false;
            
            else
                // Alice always wins
                return true;
        }
        
      
        if(sum1<sum2 && c1<c2)  // Alice always wins
            return true;
        
        if(sum1>sum2 && c1>c2)  // Alice always wins
            return true;
            
        
        int diff= abs(sum1-sum2);
        
        int move=abs(c1-c2)/2;
        
        // in each move, total sum increase by 9
        
        if(diff==move*9) // bob wins
            return false;
        
         return true;
            

    }
};