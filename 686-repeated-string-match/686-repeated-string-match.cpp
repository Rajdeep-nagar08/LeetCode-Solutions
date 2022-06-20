class Solution {
public:

    int repeatedStringMatch(string a, string b) {
    
        int n1=a.size();
        
        int n2=b.size();
        
        int i=0,j=0;
        
        int count=1;
        
        string a1=a;
        
        while(i<n1){
            int idx=i+n2;
            
            if(i+n2-1<a1.size()){
                string s=a1.substr(i,n2);
                if(s==b)
                    return count;
                
                i++;
            }
            else{
                a1=a1+a;
                count++;
            }
        }
    
        return -1;
  }
};

