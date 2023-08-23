class Solution {
public:
    string reorganizeString(string s) {
        int l=s.length();
     
        unordered_map<char,int>mp;
        for(char c:s){
            mp[c]++;
        }
        
        priority_queue<pair<int,char>>pq;
        
        for(auto it:mp){
            pq.push({it.second,it.first});
        }
        
        string temp="";
        while(pq.size()>0){
            pair<int,char>p1=pq.top();
            pq.pop();
            temp.push_back(p1.second);
            
            if(pq.size()>0){
            pair<int,char>p2=pq.top();
            pq.pop();
            temp.push_back(p2.second);
                
             if(p2.first>1)
                 pq.push({p2.first-1,p2.second});
            }
            if(p1.first>1)
                pq.push({p1.first-1,p1.second});
    
        }
        
        for(int i=1;i<l;i++){
            if(temp[i-1]==temp[i])
                return "";
        }
        
                
       return temp; 
    }
};


