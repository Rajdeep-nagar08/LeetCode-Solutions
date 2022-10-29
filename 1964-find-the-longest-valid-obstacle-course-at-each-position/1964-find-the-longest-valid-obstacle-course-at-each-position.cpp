class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obst) {
        
        
        int n=obst.size();
        
        vector<int>ans(n);
        
        vector<int>store;
        
        for(int i=0;i<n;i++){
            
            if(store.size()==0 || store.back()<obst[i]){
                store.push_back(obst[i]);
              ans[i]=(int)store.size();   
            }
            
            else{
                
     int idx=upper_bound(store.begin(),store.end(),obst[i])-store.begin();
                
//                 if(idx==store.size())
//                     store.push_back(obst[i]);
//                 else{
                    
//                     if(store[idx]!=obst[i]){
//                     store[idx]=obst[i];
//                          ans[i]=idx+1;
//                     }
                    
//                     else{
                        
//   int idx1=upper_bound(store.begin(),store.end(),obst[i])-store.begin();
//                   ans[i]=idx1+1;
                                      
                        
//                     }

                    
//                 }
                  
                if(idx<store.size())
                store[idx]=obst[i];
                else
                    store.push_back(obst[i]);
                
                
                ans[i]=idx+1;
            }
            
        
        }
        
        return ans;
    }
};