//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
		vector<string> AllPossibleStrings(string s){
		    // Code here
		    
		    
		    vector<string>ans;
		    
		    string temp="";
		    
		    find(s,0,temp,ans);
		    
		    
		    sort(ans.begin(),ans.end());
		    
		    return ans;
		}
		
		void find(string s, int i, string temp, vector<string>&ans){
		    
		    
		    if(i>=s.size())
		    {
		        if(temp.size()>0)
		        ans.push_back(temp);
		        
		        return;
		    }
		    
		    
		     find(s,i+1,temp,ans);
		     
		    temp.push_back(s[i]);
		    
		    find(s,i+1,temp,ans);
		    
		    temp.pop_back();
		    
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}
// } Driver Code Ends