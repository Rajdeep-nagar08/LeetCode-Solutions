class Solution {
public:
    vector<int> constructRectangle(int area) {
       
        /*
        
        l*w=area
        
        l>=w
        
        l-w = min
        
        */
        
        int a=sqrt(area);
        
        vector<int>ans(2);
        
        int b;
        
        while(a>=1){
           if(area%a==0){
               b=area/a;
               ans[0]=b;
               ans[1]=a;
               return ans;
           } 
            
            a--;
        }
        
        return {};
    }
};