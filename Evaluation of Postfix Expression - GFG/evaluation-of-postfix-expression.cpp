// { Driver Code Starts
// C++ program to evaluate value of a postfix expression

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to evaluate a postfix expression.
    int evaluatePostfix(string S)
    {
        
        
        stack<int>st;
        
        int n=S.size();
        
        int i=0;
        
        while(i<n){
            
            if(isdigit(S[i])){
            while(i<n && (isdigit(S[i]))){
                int no=S[i]-'0';
                st.push(no);
                i++;
            }
        }
        
        else{
            int no1=st.top();
            st.pop();
            int no2=st.top();
            st.pop();
            if(S[i]=='+')
            st.push(no2+no1);
            else if(S[i]=='-')
            st.push(no2-no1);
            else if(S[i]=='*')
            st.push(no2*no1);
            else
            st.push(no2/no1);
            i++;
          }
        }
        
        return st.top();
    }
};

// { Driver Code Starts.

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--)
    {
        string S;
        cin>>S;
        Solution obj;
    
    cout<<obj.evaluatePostfix(S)<<endl;
    }
    return 0;
}
  // } Driver Code Ends