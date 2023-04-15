/*
Step 1 : Find lps array for string T = original string + "#" + reversed string (pattern to be matched)
Step 2 : Get the last element in the lps array, represents the length matched with the reverse string pattern -> say length l.
Step 3 : Remove the first l characters from the original string  , reverse the remaining characters (say string temp)
Step 4 : Add this temp to start of the original string. i.e., Answer = temp + s.
*/

/*
 s = "aacecaaa"
    x = "aaacecaa"

 T = "aacecaaa#aaacecaa" // apply kmp on this. "#" is used for separating both the s and rev(s). To avoid wrong matching.

 index =  0 1 2 3 4 5 6 7 8   9 10 11 12 13 14 15 16 
     T = {a a c e c a a}a #   a [a  a  c  e  c  a  a]
   lps =  0 1 0 0 0 1 2 2 0   1  2  2  3  4  5  6  7

"(aacecaa)a" , the part in the small bracket is common in both. So if append "a" at start of the original string s, we will get the shortest palindrome. -> (1)
*/

class Solution {
public:
  
    string shortestPalindrome(string s) {
        
      string s1=s;
      reverse(s1.begin(),s1.end());
      string newS=s+"#"+s1;
      vector<int>lps(newS.length(),0);
      find(newS,lps);
      
      int l=lps[newS.length()-1];
      string temp=s.substr(l);   // l index to last
      reverse(temp.begin(),temp.end());
      return temp+s;
      
    }
  
    void find(string &newS,vector<int>&lps){
      int m=newS.length();
      int j=0;
      int i=1;
      lps[0]=0;
      while(i<m){
        if(newS[i]==newS[j]){
          lps[i]=j+1;
          j++;
          i++;
        }
        else{
          if(j!=0)
            j=lps[j-1];
          else{
            lps[i]=0;
            i++;
          }
        }
      }
    }
};

/*
Note : In  this problem they have asked to make the string palindrome by appending minimum characters at start. We used string T = s + "#" + rev(s).
Also we have removed first first l elements from s. Reverse the remaining string and append it to start of s.

But if were being asked to find the same by appending minimum characters at start . We would have used T = rev(s) + "#" + s. 
Also we would have removed last l elements from s. Reverse the remaining elements and append it to end of s.
*/
