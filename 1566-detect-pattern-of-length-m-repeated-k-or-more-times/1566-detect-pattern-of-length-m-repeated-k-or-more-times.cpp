class Solution {
public:
    bool containsPattern(vector<int>& arr, int m, int k) {
       
        int n=arr.size();
        
        int i=0;
        
        while(i<n){
            
            int j=0;
            
            vector<int>v;
            
             while(i+j<n && j<m){
               
                 v.push_back(arr[i+j]);
                 
                 j++;
                
            }
         
            /*
            cout<<endl;
        cout<<v[0]<<" ";
        
        */
            
            if(v.size()!=m)
                return false;
            
             
            bool flag=true;
            
            
            for(int c=1;c<k;c++){
             
                vector<int>v1;
                
                int cnt=0;
                
                while(i+j<n && cnt<m){
                   
                    v1.push_back(arr[i+j]);
                    
                    j++;
                    
                    cnt++;
                }
                
                
                if(v1!=v){
                    flag=false;
                    break;
                }
                
            }
                
           
            if(flag)
                return true;
            
            i++;
            
          }
        
        
        return false;
        
    }
};