/*

THINKING STRAIGHT-FORWARD :

minimum no of deletions in the string to bring all a's before all b's

CASE 1:

deleting all a's that are after 1st b: 


CASE 2:

deleting all b's that are before last a :


return min of both cases


LOGIC FAILED : bsc we can remove both a from back and b from front to get minimuma ans

*/


// LOGIC APPLICABLE
     
//for index  [0....i]=>a , [i+1.....n-1]=>'b'
// so delete all b's in range [0....i] and all a's in range [i+1....n-1]
// we pre store the count of a's and b's 
// prefB[i] = count of b's in range [0....i]
// suffA[i] = count of a's in range [i....n-1]   

class Solution {
public:
    int minimumDeletions(string s) {
        
        int n=s.length();
        
        vector<int>prefB(n,0);  // prefB[i] = count of b's in range [0....i]
        vector<int>suffA(n,0);  // suffA[i] = count of a's in range [i....n-1]
        
        prefB[0]=s[0]=='b'?1:0;  
        for(int i=1;i<n;i++){
            prefB[i]=s[i]=='b'?1+prefB[i-1]:prefB[i-1];
        }
        
        suffA[n-1]=s[n-1]=='a'?1:0;
        for(int i=n-2;i>=0;i--){
            suffA[i]=s[i]=='a'?1+suffA[i+1]:suffA[i+1];
        }
      
         int ans=INT_MAX;
        
        // removing all A's
        ans=min(ans,suffA[0]);
        
        // removing all B's
        ans=min(ans,prefB[n-1]);
       
        int countB,countA;
        for(int i=0;i<n-1;i++){
            countB=prefB[i];
            countA=suffA[i+1];
            ans=min(ans,countB+countA);
        }
    
        if(ans==INT_MAX)
            return 0;
        
        return ans;
    }
};