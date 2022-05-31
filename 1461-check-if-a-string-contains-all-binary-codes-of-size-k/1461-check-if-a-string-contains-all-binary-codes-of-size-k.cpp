 /*

Max no formed by k length binary string = 2^(k-1)
        
        
Using sliding window, check whether all no's from 0 to 2^(k-1) formed or not
        
*/


class Solution {
public:
    bool hasAllCodes(string str, int k) {
    
       int mx=pow(2,k)-1;
                
       vector<int>v(mx+1,-1);
        
       int no=0;

       int n=str.size();

       int i=0,j=k-1;

       while(i<=k-1){
           
         if(i>=n)
       return false;

        if(str[i]=='1')
            no=no|(1<<j);

        i++,j--;

       }
        

       if(no<=mx)
         v[no]=1;  

        
       while(i<n){
          
        no=no&(~(1<<(k-1)));
        no=no<<1;
          
        if(str[i]=='1')
            no=no|1;

        i++;
      
         if(no<=mx)
           v[no]=1;  
    }

       
      for(int x:v)
        if(x==-1)
      return false;
                   
               
        return true;
        
        
    }
};