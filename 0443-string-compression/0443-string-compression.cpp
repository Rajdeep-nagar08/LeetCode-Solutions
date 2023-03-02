class Solution {
public:
    int compress(vector<char>& chars) {
        
        int n=chars.size();
        string s="";
        int i=0;
        
        int len=0;
        while(i<n){
            char c=chars[i];
            int count=0;
            while(i<n && c==chars[i]){
                i++;
                count++;
            }
                s.push_back(c);
            if(count>1)
                s+=to_string(count);
        }
        
        int k=s.length();
        
        for(int i=0;i<k;i++)
            chars[i]=s[i];
        
        return k;
    }
};