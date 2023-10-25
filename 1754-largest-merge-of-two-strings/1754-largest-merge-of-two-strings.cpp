class Solution {
public:
    
    int n, m;
    
    string largestMerge(string word1, string word2) {
        
        /*
        
        Form a new string in which at index i, 
        
        either put word1[i1] or word2[i2]
        
        new string should be lexiographically largest
        
        */
        
        n=word1.size();
        
        m=word2.size();
        
        string ans="";
        
        int i1=0,i2=0;
        
        while(i1<n and i2<m){
            if(word1[i1]>word2[i2]){
                ans.push_back(word1[i1]);
                i1++;
            }
            else if(word1[i1]<word2[i2]){
                ans.push_back(word2[i2]);
                i2++;
            }
            else{  // word1[i1]==word2[i2]
                bool flag=find(i1,i2,word1,word2);
                
                if(flag)
                {
                    ans.push_back(word1[i1]);
                    i1++;
                }
                else{
                    ans.push_back(word2[i2]);
                    i2++;
                }
                
            }
        }
        
        while(i1<n){
             ans.push_back(word1[i1]);
                i1++;
        }
        
        while(i2<m){
             ans.push_back(word2[i2]);
                i2++;
        }
        
        
        return ans;
        
    }
    
    bool find(int i1, int i2, string &word1, string &word2){
        while(i1<word1.size() and i2<word2.size()){
            if(word1[i1]>word2[i2])
                return true;
            if(word1[i1]<word2[i2])
                return false;
            
            i1++, i2++;
        }
        
        if(i2>=word2.size())
            return true;
        
        return false;
    }
};