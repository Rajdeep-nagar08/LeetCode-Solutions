// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++



class Solution {
  public:

    int numOfSubsets(int arr[], int n, int k) {
       vector<int>arr1;
       
       for(int i=0;i<n/2;i++){
           arr1.push_back(arr[i]);
       }
       
       vector<int>v1;
       find(arr1,v1,k);
       
       
        vector<int>arr2;
       
       for(int i=n/2;i<n;i++){
           arr2.push_back(arr[i]);
       }
       
       vector<int>v2;
       find(arr2,v2,k);
       
       
       int count=v1.size()+v2.size();
       
       int n1=v1.size();
       int n2=v2.size();
       
       
       sort(v1.begin(),v1.end());
       
       sort(v2.begin(),v2.end());
       
       for(int i=0;i<n1;i++){
           
          int val=v1[i];
    
          int idx=upper_bound(v2.begin(),v2.end(),k/val)-v2.begin();
          
          idx--;
          
          if(idx>=0){
              count+=(idx+1);
          }
       }
       
       return count;
    }
    
    void find(vector<int>&arr1,vector<int>&v1,int k){
        
        int sz=arr1.size();
        
        for(int mask=0;mask<(1<<sz);mask++){
            long long int p=0;
            for(int i=0;i<sz;i++){
                if(mask & (1<<i)){
                    if(p==0)
                    p=arr1[i];
                    else
                    p=1ll*p*arr1[i];
                }
            }
            if(p<=k && p!=0)
            v1.push_back(p);
        }
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,K;
        cin>>N;
        
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];
        cin>>K;

        Solution ob;
        cout << ob.numOfSubsets(arr,N,K) << endl;
    }
    return 0;
}  // } Driver Code Ends