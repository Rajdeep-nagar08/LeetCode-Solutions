class Solution {
public:
    bool digitCount(string str) {
        
        
        int n=str.size();
        
        for(int i=0;i<n;i++){
            char ch=char(i+'0');
            int no=str[i]-'0';
            
            int count=0;
            
            for(int j=0;j<n;j++){
                if(str[j]==ch)
                    count++;
            }
            if(count!=no)
                return false;
        }
        return true;
    }
};