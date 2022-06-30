// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:

	void rearrange(int arr[], int n) {
	    
	     vector<int> v;
	    vector<int> l;
	    for(int i=0;i<n;i++){
	        if(arr[i]>=0){
	            v.push_back(arr[i]);
	        }else{
	            l.push_back(arr[i]);
	        }
	    }
	    int i=0;
	    int j=0;
	    vector<int> s;
	    while(i<v.size()&&j<l.size()){
	         s.push_back(v[i]);
	         i++;
	         s.push_back(l[j]);
	         j++;
	    }
	    while(i<v.size()){
	        s.push_back(v[i]);
	        i++;
	    }
	    while(j<l.size()){
	        s.push_back(l[j]);
	        j++;
	    }
	    for(int i=0;i<s.size();i++){
	        arr[i]=s[i];
	    }
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.rearrange(arr, n);
        for (i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
  // } Driver Code Ends