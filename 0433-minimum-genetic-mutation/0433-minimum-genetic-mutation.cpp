class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        vector<char>store={'A','G','C','T'};
        queue<string>q;
        q.push(start);
        
        unordered_set<string>st;
        for(auto str:bank)
            st.insert(str);
        
        if(st.find(end)==st.end())
            return -1;
        
        int count=0;
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
          string s1=q.front();
                q.pop();
                if(s1==end)
                    return count;
                st.erase(s1);
                
   for(int i=0;i<s1.size();i++){
       char ch=s1[i];
      for(int j=0;j<4;j++){
          s1[i]=store[j];
          if(st.find(s1)!=st.end())
              q.push(s1);
          }
       s1[i]=ch;
       }
                }
                count++;
            }
         return -1;       
           
    }
};