class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
            int n=strs.size();
           vector<vector<string>>ans;
      
            vector<pair<string,int>>copy;
           
          int empt=0;
      for(int i=0;i<n;i++){
        if(strs[i]=="")
           empt++;
        else{
          string st=strs[i];
          sort(st.begin(),st.end());
          copy.push_back({st,i});
        }
      }
        
        vector<string>temp;
        for(int i=0;i<empt;i++)
          temp.push_back("");
       
      if(empt>0)
         ans.push_back(temp);
      
      if(empt==n)
        return ans;
      
      sort(copy.begin(),copy.end());
      
      int i=0;
      while(i<copy.size()){
        temp.clear();
        string str=copy[i].first;
        

        while(str==copy[i].first){
          temp.push_back(strs[copy[i].second]);
          i++;
          if(i==copy.size())
            break;
        }
        
          ans.push_back(temp);
      }
        return ans;
      
    }
};
        