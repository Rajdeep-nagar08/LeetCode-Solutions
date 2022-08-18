class Solution {
public:
   bool checkRecord(string s) {
       
        int len=s.length();
        int acount=0;
        for(int i=0;i<len;i++){
            if(s[i]=='A'){
                acount++;
            }
        }
        if(acount>1){
            return false;
        }
        //char ch='L';
        int temp=0;
        int count=0;
        for(int i=0;i<len;i++){
            if(s[i]=='L'){
                count++;
            }else{
                temp=max(temp,count);
                count=0;
            }
        }
       
       
        if(temp>=3 || count>=3)
        {
            return false;
            
        }else{
            return true;
        }
    }
    
};