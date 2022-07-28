class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        
        sort(arr.begin(),arr.end(),[](int &x,int &y){
           
            int no1=x,no2=y;
            
            int c1=0,c2=0;
            
            while(no1){
                if(no1&1)
                    c1++;
                no1>>=1;
            }
            
             
            while(no2){
                if(no2&1)
                    c2++;
                no2>>=1;
            }
            
            if(c1<c2)
                return true;
            else if(c1==c2)
                return x<y;
            
            return false;
        });
        
        
        return arr;
    }
};