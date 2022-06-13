class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& p) {
     
        
        int n=p.size();
        
        
        /*
        
        rearrange the persons such that
        
        [h,k]   k peoples in front (toward left of it) of it has height >=h
        
        
        for any pair [h,k]
        
        there must be k pairs that have height >=h 
        
        
        real position(index) of shortest person = k
        
        Than position of second shortest person = its k
        
        */
        
        sort(p.begin(),p.end(),[](vector<int>&p1,vector<int>&p2){
            if(p1[0]>p2[0])
                return true;
            else if(p1[0]==p2[0])
                return p1[1]<p2[1];
            else
                return false;
        });
        
        /*
        
        for(int i=0;i<n;i++){
            cout<<p[i][0]<<" "<<p[i][1]<<endl;
        }
        */
        
             
             for(int i=1;i<n;i++){
                
                 int idx=p[i][1];
                 
                 if(i==idx)
                     continue;
                 
                 int h=p[idx][0],k=p[idx][1];
                 int h1,k1;
                 for(int j=idx+1;j<=i;j++){
                     h1=p[j][0];
                     k1=p[j][1];
                     p[j][0]=h;
                     p[j][1]=k;
                     h=h1,k=k1;
                 }
                 
                 p[idx][0]=h,p[idx][1]=k;
                 
             }
             
             
             return p;
            
        
      }
};