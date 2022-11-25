int mod=1e9+7;

class Solution {
public:
    int sumSubarrayMins(vector<int>& h) {
      
         
        int n=h.size();
        
        /*
        
        finding no. of subarrays in which current no. is minimum
        
        
        [NGL(i1)......x.......(i2)NGR]
        
        so x is minimum in range [i1+1....(i).....i2-1]
        
        n1= i-(i1+1)
        
        n2= i2-1-i
        
        no of subarrays in which x is min = n1+n2+n1*n2
        
        so contribution of x in ans= x* (n1+n2+n1*n2)
        
        
        */
        
        
       vector<int>NGR(n);
      NGR[n-1]=n;
      stack<int>st;
      st.push(n-1);
      
      for(int i=n-2;i>=0;i--){
        if(st.size()==0){
          NGR[i]=n;
          st.push(i);
        }
        
        else if(h[st.top()]<h[i]){
          NGR[i]=st.top();
          st.push(i);
        }
        else{
          while(st.size()>0 && h[st.top()]>=h[i])
            st.pop();
          
          if(st.size()==0){
            NGR[i]=n;
            st.push(i);
          }
          else{
            NGR[i]=st.top();
            st.push(i);
          }
        }
      }
      
      
      vector<int>NGL(n);
      stack<int>st1;
      NGL[0]=-1;
      st1.push(0);
      for(int i=1;i<n;i++){
        if(st1.size()==0){
          NGL[i]=-1;
          st1.push(i);
        }
        
        else if(h[st1.top()]<h[i]){
          NGL[i]=st1.top();
          st1.push(i);
        }
        
        else{
          while(st1.size()>0 && h[st1.top()]>h[i])
            st1.pop();
          
          if(st1.size()==0){
            NGL[i]=-1;
            st1.push(i);
          }
          else{
            NGL[i]=st1.top();
            st1.push(i);
          }
        }
      }
      
        
        
    long long int ans=0;
        
        
        int i1,i2,n1,n2;
        
        for(int i=0;i<n;i++){
            
            
            i1=NGL[i];
            
            i2=NGR[i];
            
        //   cout<<i1<<" "<<i<<" "<<i2<<endl;
            
            
            n1=i-(i1+1);
            
            n2=i2-1-i;
            
            ans=ans+1ll*h[i]*(n1+n2+n1*n2+1);
            
            ans%=mod;
            
        }
        
        return ans;
      
    }
};