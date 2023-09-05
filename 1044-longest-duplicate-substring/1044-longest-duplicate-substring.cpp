/*
Since the length of the answer must between 0 to the length of string minus 1, In the example one "banana", the answer must between 0 to 5, we can guess 3 at the first time. We will check every possible substring with length 3 to see if we can find any duplicate.
*/

#define lln long long int
class Solution {
          lln d=26;
         lln p=19260817;
public:
    string longestDupSubstring(string s) {
        
      int l=0;
      int h=s.length();
      string ans="";
      
      vector<int>powr(s.length(),1);
      for(int i=1;i<s.length();i++)
        powr[i]=(powr[i-1]*26)%p;
        
      while(l<=h){
        int mid=(h-(h-l)/2);
        string temp=search(s,mid,powr);
        if(temp.length()==0)
           h=mid-1;
        else{
          if(ans.length()<temp.length())
            ans=temp;
          l=mid+1;
        }
          
      }
      return ans;
    }
        
  
       string search(string &text,int l,vector<int>&powr){
         if(l==0)
           return "";
    unordered_map<int, vector<int>> hash;
           // storing [hash value of]
           
         string pat=text.substr(0,l);
         lln hp=0;
         
         for(int i=0;i<l;i++){
            hp = ((hp * d) % p + (pat[i] - 'a')) % p;
         }
         
         hash[hp].push_back(0);
         for(int i=l;i<=text.length();i++){
      hp = ((hp - (lln) powr[l - 1] * (text[i -l] - 'a')) % p + p) % p;
      hp = (hp * d + (text[i] - 'a')) % p;
           
           if(hash.find(hp)==hash.end())
             hash[hp].push_back(i-l+1);
           else{
             for(auto it:hash[hp]){
         if(strcmp(text.substr(it,l).data(),text.substr(i-l+1,l).data())==0)
                 return text.substr(it,l);
             }
             hash[hp].push_back(i-l+1);
           }
         }
         return "";
       }
  
};

/*

class Solution {
public:
    string longestDupSubstring(string S) {
        ans = "";
        power = vector<int>(S.length(), 1);
        int i;
		// precompute all the pow(26, k) 0 < k < S.length() modulus prime
        for (i = 1 ; i < S.length(); i++) {
            power[i] = (power[i - 1] * 26) % prime;
        }
        int low = 0, high = S.length();
		// code for the binary search, very trivial
        while (low <= high) {
            int mid = low + (high - low) / 2;
            string tmp = validate(mid, S);
            if (tmp.length() == 0) {
                high = mid - 1;
            } else {
                if (tmp.length() > ans.length()) {
                    ans = tmp;
                }
                low = mid + 1;
            }
        }
        
        return ans;
    }
    
private:
   // large prime number
    int prime = 19260817;
    string ans;
    vector<int> power;
    string validate(int desire, string &str) {
       // if the desire length is 0, return the empty string
        if (desire == 0) return "";
        unordered_map<int, vector<int>> hash = unordered_map<int, vector<int>>();
        long long current = 0;
        int i;
		// compute the hash value of the first "length" characters
        for (i = 0 ; i < desire; i++) {
            current = ((current * 26) % prime + (str[i] - 'a')) % prime;
        }
        // store the result in a hashmap that maps from hashvalue to starting index
        hash[current] = vector<int>(1, 0);
        for (i = desire ; i < str.length(); i++) {
		    // sliding window to maintain the current substr's hash value
			// be aware of overflow
            current = ((current - (long long) power[desire - 1] * (str[i - desire] - 'a')) % prime + prime) % prime;
            current = (current * 26 + (str[i] - 'a')) % prime;
           // if that hash value is not in our set we do nothing and add the value to our map
            if (hash.find(current) == hash.end()) {
                hash[current] = vector<int>(1, i - desire + 1);
            } else {
			   // otherwise, start a string by string comparason and see if there's a match
                for (auto it : hash[current]) {
                    
                    if (strcmp((str.substr(it, desire)).data(), str.substr(i - desire + 1, desire).data()) == 0) {
                        return str.substr(it, desire);
                    }
                }
                
                hash[current].push_back(i - desire + 1);
            }
        }
        
        return "";
    }
};

*/