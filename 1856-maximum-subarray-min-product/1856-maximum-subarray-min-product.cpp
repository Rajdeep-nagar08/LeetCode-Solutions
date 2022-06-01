/*


[i1=NSL[i]+1.......i.......i2=NSR[i]-1]

so 

nums[i] is smallest in the range [i1......i......i2]

ans=max(ans,nums[i]*sum[i1....i2])

*/

#define lln long long int

class Solution {
public:
    int maxSumMinProduct(vector<int>& h) {
        
        
          int n=h.size();
        
       vector<int>NSR(n);
      NSR[n-1]=n;
      stack<int>st;
      st.push(n-1);
      
      for(int i=n-2;i>=0;i--){
        if(st.size()==0){
          NSR[i]=n;
          st.push(i);
        }
        
        else if(h[st.top()]<h[i]){
          NSR[i]=st.top();
          st.push(i);
        }
        else{
          while(st.size()>0 && h[st.top()]>=h[i])
            st.pop();
          
          if(st.size()==0){
            NSR[i]=n;
            st.push(i);
          }
          else{
            NSR[i]=st.top();
            st.push(i);
          }
        }
      }
      
      
      vector<int>NSL(n);
      stack<int>st1;
      NSL[0]=-1;
      st1.push(0);
      for(int i=1;i<n;i++){
        if(st1.size()==0){
          NSL[i]=-1;
          st1.push(i);
        }
        
        else if(h[st1.top()]<h[i]){
          NSL[i]=st1.top();
          st1.push(i);
        }
        
        else{
          while(st1.size()>0 && h[st1.top()]>=h[i])
            st1.pop();
          
          if(st1.size()==0){
            NSL[i]=-1;
            st1.push(i);
          }
          else{
            NSL[i]=st1.top();
            st1.push(i);
          }
        }
      }
      
        
      vector<lln>pref(n,0);
        pref[0]=h[0];
        
        for(int i=1;i<n;i++){
            pref[i]=pref[i-1]+h[i];
        }
        
        
        lln ans=INT_MIN;
        
        int l,r;
        lln sum;
        
            
        for(int i=0;i<n;i++){
            if(i==0){
              r=NSR[i];
                r--;
                sum=pref[r];
              ans=max(ans,1ll*sum*h[i]);
            }
            else if(i==n-1){
                l=NSL[i];
                l++;
                
                if(l==0)
                sum=pref[n-1];
            else
                sum=pref[n-1]-pref[l-1];

                ans=max(ans,1ll*sum*h[i]);

            }
            else{
                
                r=NSR[i];
                l=NSL[i];
                r--;
                l++;
                
             if(l==0)
                sum=pref[r];
            else
                sum=pref[r]-pref[l-1];

                
                ans=max(ans,1ll*sum*h[i]);
               
            }
    
        }
        
        int md=1e9+7;
        
        return ans%md;
    }
};