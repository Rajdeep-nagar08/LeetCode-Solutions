class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int>mp={{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
         
        int i = s.size() - 1;
        
        int res = 0;
        int prev = 0;
        
        while(i >= 0) {
            int val = mp[s[i]];
            // cout << val << endl;
            if(val >= prev) {
                res += val;
            } else {
                res -= val;
            }
            prev = val;
            i--;
        }
        
        return res;
    }
};