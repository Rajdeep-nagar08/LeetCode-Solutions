class Solution {
public:
    int minimizeSet(int div1, int div2, int cnt1, int cnt2) {
       
        
     //    cout<<find(41,59,1,7609)<<endl;
    /// cout<<find(6,9,1,50)<<endl;
        
        int l=0,h=INT_MAX;
        
        int ans;
        
        while(l<=h){
            
            int mid=(l+(h-l)/2);
           

//             while(mid%div1==0 && mid%div2==0)
//                 mid++;
            
//             if(mid>h)
//                 break;
            
         //  cout<<l<<" "<<h<<" "<<mid;

            if(isValid(mid,div1,div2,cnt1,cnt2)){
             //   cout<<" Yes"<<endl;
               ans=mid;
                h=mid-1;
            }
            else{
              //  cout<<" NO"<<endl;

               l=mid+1; 
            }
        }
        
        return ans;
        
    }
    
    bool isValid(int mid,int d1,int d2,int c1,int c2){
        
        
//           if(mid%d1==0 && mid%d2==0)
//              {
//                  cout<<mid<<endl;
              
//                  return false;
//              }
        
//         if(mid%d1==0){
//             mid--;
//             c2--;
//         }
        
//         else if(mid%d2==0){
//             mid--;
//             c1--;
//         }
        
        int f1=mid/d1;
    
        if(mid-f1<c1)
            return false;
        
        int f2=mid/d2;
    
        if(mid-f2<c2)
            return false;
        
  
        int cm=find(d1,d2,1,mid);
              
    
//         if(mid==7609)
//             cout<<cm<<endl;
        
        int totalAvl=mid-cm;
        
        if(totalAvl<c1+c2)
            return false;
        
//         if(rem<c1+c2)
//             return false;
    
//         if(rem-f1<c1)
//             return false;
        
//         if(rem-f2<c2)
//             return false;
        
        return true;
        
    }
    
    
    int find(int x, int y, int l, int r)
{
    long long int lcm = (1ll*x * y) / __gcd(x, y);
 
    // Number multiple of lcm less than L
    int countl = (l - 1) / lcm;
 
    // Number of multiples of lcm less than R+1
    int countr = r / lcm;
        
    return countr - countl;
}
 
};