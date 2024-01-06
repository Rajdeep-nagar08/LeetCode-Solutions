class Solution {
public:
    int maximalRectangle(vector<vector<char>>& mat) {
        
        int n=mat.size();
        
        int m=mat[0].size();
        
        vector<vector<int>>mat1(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                mat1[i][j]=mat[i][j]-'0';
            }
        }
        
        for(int i=1;i<n;i++){
          for(int j=0;j<m;j++){
              if(mat1[i][j])
              mat1[i][j]+=mat1[i-1][j];
          }
        }
        
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         cout<<mat1[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        
        
        
        int ans=0;
        
        for(int i=0;i<n;i++){
            ans=max(ans,maxHist(mat1[i]));
        }
        
        return ans;
    }
    
    int maxHist(vector<int>&v){
        
        vector<int>NSL=findNSL(v);
        
        
        vector<int>NSR=findNSR(v);
        
//         cout<<"Row"<<endl;
        
//         for(int x:NSL){
//             cout<<x<<" ";
//         }
//         cout<<endl;
        
//         for(int x:NSR){
//             cout<<x<<" ";
//         }
//         cout<<endl;
        
        int m=v.size();
        
        int mx=0;
        for(int i=0;i<m;i++){
            int l=NSL[i];
            l++;
            int r=NSR[i];
            r--;
            mx=max(mx,v[i]*(r-l+1));
        }
        return mx;
    }
    
    
    vector<int>findNSL(vector<int>&v){
        
        int m=v.size();
        
        vector<int>v1(m);
        
        v1[0]=-1;
        
        stack<int>st;
        
        st.push(0);
        
        for(int i=1;i<m;i++){
                while(st.size()>0 and v[st.top()]>=v[i]){
                    st.pop();
                }
                if(st.size()==0){
                    v1[i]=-1;
                }
                else{
                    v1[i]=st.top();
                }
            st.push(i);
        }
        return v1;
        
    }
    
    
    vector<int> findNSR(vector<int>&v){
        
        int m=v.size();
        
        vector<int>v1(m);
        
        v1[m-1]=m;
        
        stack<int>st;
        
        st.push(m-1);
        
        for(int i=m-2;i>=0;i--){
                while(st.size()>0 and v[st.top()]>=v[i]){
                    st.pop();
                }
                if(st.size()==0){
                    v1[i]=m;
                }
                else{
                    v1[i]=st.top();
                }
            st.push(i);
        }
        return v1;
    }
    
    
};