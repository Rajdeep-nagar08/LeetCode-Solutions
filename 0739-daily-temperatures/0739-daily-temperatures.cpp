class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& h) {
        
            
         int n=h.size();
       vector<int>NSR(n);
      NSR[n-1]=0;
      stack<int>st;
      st.push(n-1);
      
      for(int i=n-2;i>=0;i--){
        if(st.size()==0){
          NSR[i]=0;
          st.push(i);
        }
        
        else if(h[st.top()]>h[i]){
          NSR[i]=st.top();
          st.push(i);
        }
        else{
          while(st.size()>0 && h[st.top()]<=h[i])
            st.pop();
          
          if(st.size()==0){
            NSR[i]=0;
            st.push(i);
          }
          else{
            NSR[i]=st.top();
            st.push(i);
          }
        }
      }
      
      
        
        vector<int>ans;
        
        for(int i=0;i<n;i++){
            if(NSR[i]==0)
                ans.push_back(0);
            else
                ans.push_back(NSR[i]-i);
        }
        
        return ans;
    }
};