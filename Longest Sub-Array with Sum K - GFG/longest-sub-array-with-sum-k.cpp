// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution{
    public:
    int lenOfLongSubarr(int A[],  int n, int k) 
    { 
        
        unordered_map<int,int>mp;
    
        int sum=0;
        
        int mx=0;
        
        for(int i=0;i<n;i++){
           sum+=A[i];
           if(sum==k)
             mx=i+1;
           if(mp.count(sum-k)==1){
               mx=max(mx,i-mp[sum-k]);
             //  mp[sum]=mp[sum-k];
           }
           if(mp.count(sum)!=1)
             mp[sum]=i;
        }
        
        return mx;
        
    } 

};

// { Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends