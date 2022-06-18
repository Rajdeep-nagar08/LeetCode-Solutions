// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    int longestUniqueSubsttr(string s){
        int n=(int)s.size();
        int maxi=0;
        int i=0,j=0;
        vector<int>v(26,0);
        char x;
        while(j<n){
            x=s[j];
            if(v[x-'a']>0){
                while(s[i]!=x){
                    v[s[i]-'a']--;
                    i++;
                }
                v[s[i]-'a']--;
                i++;
            }
            v[x-'a']++;
            maxi=max(maxi,j-i+1);
            j++;
        }
    return maxi;
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string str;
		cin>>str;
		Solution ob;
		cout<<ob.longestUniqueSubsttr(str)<<endl;
	}
	return 0;
}  // } Driver Code Ends