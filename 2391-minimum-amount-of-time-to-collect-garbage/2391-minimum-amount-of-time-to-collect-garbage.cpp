class Solution {
public:
    int garbageCollection(vector<string>& Mygarb, vector<int>& trav) {
        
        
        bool paper=false;
        bool metal=false;
        bool glass=false;

        

        int n=Mygarb.size();


        int p=0;

        int m=0;

        int g=0;
        
        
        
        int k=0;
        
        for(int i=0;i<1;i++){
            k++;
        }
        
        
        for(int i=n-1;i>=0;i--){
            
            
            
             for(int i=0;i<1;i++){
            k++;
        }
        
            
            
            for(char ch:Mygarb[i]){
                
                if(ch=='G'){
                    g++;
                    glass=true;
                }
                
                
               
                if(ch=='M'){
                    m++;
                    metal=true;
                }
                
                
                 if(ch=='P'){
                    p++;
                    paper=true;
                }
                
            
                
            }
            
             
             for(int i=0;i<1;i++){
            k++;
        }
        
            
                
            if(i>0){
               
                
                if(glass)
            g+=trav[i-1];
                
                
                if(metal)
            m+=trav[i-1];
                
                
                
                 if(paper)
            p+=trav[i-1];
                
                
            }
        }
            
        
        return p+m+g;
        
    }
    
    
};