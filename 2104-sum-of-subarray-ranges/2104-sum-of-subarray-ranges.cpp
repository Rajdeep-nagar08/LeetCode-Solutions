#define lln long long int
class Solution {
public:
    long long subArrayRanges(vector<int>& h) {
        
        
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
          while(st1.size()>0 && h[st1.top()]>h[i])
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
      
       
        
      vector<int>NGR(n);
      NGR[n-1]=n;
      stack<int>st2;
      st2.push(n-1);
      
      for(int i=n-2;i>=0;i--){
        if(st2.size()==0){
          NGR[i]=n;
          st2.push(i);
        }
        
        else if(h[st2.top()]>h[i]){
          NGR[i]=st2.top();
          st2.push(i);
        }
        else{
          while(st2.size()>0 && h[st2.top()]<=h[i])
            st2.pop();
          
          if(st2.size()==0){
            NGR[i]=n;
            st2.push(i);
          }
          else{
            NGR[i]=st2.top();
            st2.push(i);
          }
        }
      }
      
        
        
        
      vector<int>NGL(n);
      stack<int>st3;
      NGL[0]=-1;
      st3.push(0);
      for(int i=1;i<n;i++){
        if(st3.size()==0){
          NGL[i]=-1;
          st3.push(i);
        }
        
        else if(h[st3.top()]>h[i]){
          NGL[i]=st3.top();
          st3.push(i);
        }
        
        else{
          while(st3.size()>0 && h[st3.top()]<h[i])
            st3.pop();
          
          if(st3.size()==0){
            NGL[i]=-1;
            st3.push(i);
          }
          else{
            NGL[i]=st3.top();
            st3.push(i);
          }
        }
      }
        
        
        lln ans=0;
        
        int gl,gr,sl,sr;
        
        for(int i=0;i<n;i++){
            
            int no=h[i];
            
            gl=NGL[i];
            gr=NGR[i];
            
            
            sl=NSL[i];
            sr=NSR[i];
            
            
          //   cout<<gl<<" "<<gr<<" "<<sl<<" "<<sr<<endl;

            
            
            gl++,gr--;

            
            sl++,sr--;
            
            lln l1=(i-gl)*(gr-i+1)+(gr-i);
            
            ans+=no*l1;
            
            lln l2=(i-sl)*(sr-i+1)+(sr-i);
            
            ans-=no*l2;
            
         //   cout<<no*l1<<" -"<<no*l2<<endl;
            

            
        }
        
        
      
        
      return ans;    
        
    }
};