#define lln long long int

class Solution {
public:
    bool splitString(string s) {
       
            
        /*
        
        break string into parts of decreasing order, such that difference between two adjacent numerical values is 1
        
        Is it possible to break it into such parts ?
        
        
        Here we have choices for first numerical values
        
        if we know the first numerical value then we can easily break string into further parts
        
        so we take all possible prefixes as strating value and check for 
        accordingly
        
        */
        
        int i=0;
        
        while(i<s.size() && s[i]=='0')
            i++;
        
        if(i==s.size())
            return false;
        
        s=s.substr(i);
        
        int n=s.size();
        
        bool ans;
        
        for(int l=1;l<=(n/2)+1;l++){
            
            string pref=s.substr(0,l);
            
            lln no1=stol(pref);
            
            cout<<"no1="<<no1<<endl;
            
            int nextIndex=l;
            
            if(nextIndex<n)
             ans=find(no1,nextIndex,s);
            
            if(ans)
                return true;
            
        }
        
       return false;
        
        
    }
    
    bool find(lln no1,int i,string s){
        
        if(i>=s.size())
            return true;
        
        int k=i;
        /*
         while(k<s.size() && s[k]=='0')
                k++;
                */
        for(int j=k;j<s.size();j++){
            
            int l=j-i+1;
            
            string str=s.substr(i,l);
        
            lln no2=stol(str);
            
            cout<<no2<<endl;
            
            if(no2>no1)
                break;

            if(no1-no2==1){
                if(find(no2,j+1,s))
                    return true;
            }
        }
        
        
        return false;
        
    }
};