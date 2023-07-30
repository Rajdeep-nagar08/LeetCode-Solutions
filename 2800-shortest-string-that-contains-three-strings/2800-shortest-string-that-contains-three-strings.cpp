

class Solution {
public:
    
    
     string merge(string s1, string s2) {

         
         int n=s1.size();
         
         int m=s2.size();
         
         int l = min(n,m);

         
             
  if (s1.find(s2) < n || s2.find(s1) < m) {
      
    return n > m ? s1 : s2;
      
}
         
 
         
         bool f=false;
         

    
    for (int i = l; i > 0; --i) {
        
        
        if (s1.substr(s1.size()-i) == s2.substr(0,i)) {
            
            return s1 + s2.substr(i);
        }
        
    }
         
    return s1 + s2; 
         
         
}
    
    
    string minimumString(string a, string b, string c) {
        
        
     string v[6];
        
        
        v[0] = merge(merge(b,c),a);
        
    v[1] = merge(merge(c,a),b);
        
    v[2] = merge(merge(c,b),a);
        
    v[3] = merge(merge(a, b), c);
        

        
    v[4] = merge(merge(a,c),b);
        
     v[5] = merge(merge(b,a),c);
        
               string final = v[0];



        
    for (int i=1; i<6;i++) {
        
        
        if (v[i].size() < final.size() || (v[i].size()==final.size() && v[i]<final)) {
            final = v[i];
        }
        
        
    }
        
        
    return final;
        
        
    }
};

