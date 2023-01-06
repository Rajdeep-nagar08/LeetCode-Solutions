class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& trip, vector<int>& tar) {
        
      int n=trip.size();
        
        bool a=false,b=false,c=false;
        
        for(int i=0;i<n;i++){
            
            if(!a && trip[i][0]==tar[0] && trip[i][1]<=tar[1] && trip[i][2]<=tar[2])
                a=true;
            
            
              
            if(!b && trip[i][1]==tar[1] && trip[i][0]<=tar[0] && trip[i][2]<=tar[2])
                b=true;
            
            
              
            if(!c && trip[i][2]==tar[2] && trip[i][1]<=tar[1] && trip[i][0]<=tar[0])
                c=true;
            
            
          
        }
        
        return a&&b&&c;
        
    }
};