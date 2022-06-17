// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
public:

void help(stack<int>&st){
    
    if(st.size()==0)
       return ;
       
       int a=st.top();
       st.pop();
       help(st);
       st.push(a);
        
    return;
    
}


    vector<int> Reverse(stack<int>& st){
        
    //  help(st);
  
     vector<int>v;
    
        while(!st.empty())
        {
            v.push_back(st.top());
            st.pop();
        }
        
        return v;
        
    }
};

// { Driver Code Starts.


int main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        stack<int> St;
        for(int i=0;i<N;i++){
            int x;
            cin>>x;
            St.push(x);
        }
        Solution ob;
        vector<int> ans=ob.Reverse(St);
        for(int i=0;i<N;i++){
            cout<<ans[i];
            if(i!=N-1) cout<<" ";
        }
        cout<<endl;
    }
}  // } Driver Code Ends