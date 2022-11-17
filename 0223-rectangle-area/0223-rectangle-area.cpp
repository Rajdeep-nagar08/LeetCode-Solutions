 /*
      No overlapping :
      ax1>=bx2 || ax2<=bx1 || ay1>=by2 || ay2<=by1
      return a1+a2
      
      When overlapping:
  sort all x cordinates : x1 x2 x3 x4 ( sure that x2 and x3 contribute in sharing as they are middle ones)
  sort all y cordinates : y1 y2 y3 y3 ( sure that y2 and y3 contribute in sharing)
  
  so sharing area= (x3-x2)*(y3-y2)
  */

class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        
      int a1=abs(ax2-ax1)*abs(ay2-ay1);
      int a2=abs(bx2-bx1)*abs(by2-by1);
    
          if(ax1>=bx2 || ax2<=bx1 || ay1>=by2 || ay2<=by1)
            return a1+a2;
      
      vector<int>x={ax1,ax2,bx1,bx2};
      sort(x.begin(),x.end());
      vector<int>y={ay1,ay2,by1,by2};
      sort(y.begin(),y.end());
      
      int cA=(x[2]-x[1])*(y[2]-y[1]);
      return a1+a2-cA;
    }
};
