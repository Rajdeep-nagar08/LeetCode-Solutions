// https://leetcode.com/problems/find-array-given-subset-sums/discuss/1431457/Easy-Explanation-for-Noobs-%2B-Python-code-with-comments


class Solution {
public:
   
    
    unordered_map<int,int>mp;
    
    vector<int>ans;
    
    vector<int> recoverArray(int n, vector<int>& sums) {
        
      sort(sums.begin(),sums.end());
        
      find(sums);
        
      return ans;
        
    }
    
    void find(vector<int>&sums){
        
        if(sums.size()==2){
            ans.push_back(sums[0]+sums[1]);
            return;
        }
        
        vector<int>include,exclude;
        
        int no=sums[1]-sums[0];
        
        for(int i=0;i<sums.size();i++){
            if(mp[sums[i]]==0){
               exclude.push_back(sums[i]);
               mp[sums[i]+no]++;
            }
            else{
               include.push_back(sums[i]);
               mp[sums[i]]--;
            }
        }
        
        
        bool flag=false;
        
        for(int x:exclude){
            if(x==0){
                flag=true;
                break;
            }
        }
        
        if(flag==true){
            ans.push_back(no);
            find(exclude);
        }
       else{
           ans.push_back(-1*no);
           find(include);
       }
    }
    
   
};