class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) {
        
        
         int y1=(points[0][1]-points[1][1]);
        
        int x1=(points[0][0]-points[1][0]);
        
        
         int y2=(points[1][1]-points[2][1]);
        
        int x2=(points[1][0]-points[2][0]);
        
         int y3=(points[0][1]-points[2][1]);
        
        int x3=(points[0][0]-points[2][0]);
        
        if(y1*x2==x1*y2 && (y2*x3==x2*y3))
            return false;
       
        for(int i=0;i<3;i++){
            
            for(int j=i+1;j<3;j++){
                
                if(points[i]==points[j])
                    return false;
            }
        }
        
        return true;
        
    }
};