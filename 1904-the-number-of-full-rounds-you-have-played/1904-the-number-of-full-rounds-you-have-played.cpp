class Solution {
public:
    int numberOfRounds(string it, string ot) {
      
        if(it==ot)
            return 0;
        
        int h1=stoi(it.substr(0,2));
        
        int m1=stoi(it.substr(3,2));
        
        int t1=h1*60+m1;
         
        int h2=stoi(ot.substr(0,2));
        
        int m2=stoi(ot.substr(3,2));
        
        int t2=h2*60+m2;
        
        if(t2<t1)
            t2+=24*60;
        
           
           int x=t1/15+(t1%15==0?0:1);
            
           int y=x*15;
            
        int ans=(t2-y)/15;
            
            if(ans<0)
                return 0;
            
            return ans;
        
    }
};