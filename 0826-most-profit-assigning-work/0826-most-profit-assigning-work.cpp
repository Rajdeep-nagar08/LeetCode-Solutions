class Solution {
public:
    int maxProfitAssignment(vector<int>& diff, vector<int>& prof, vector<int>& w) {
        
        vector<pair<int,int>>v;
        
        for(int i=0;i<diff.size();i++){
            v.push_back({diff[i],prof[i]});
        }
        
        sort(v.begin(),v.end());
        
        for(int i=1;i<diff.size();i++){
            v[i].second=max(v[i].second,v[i-1].second);
        }
        
        int sum=0;
        
        for(int i=0;i<w.size();i++){
            
            pair<int,int>p={w[i],INT_MAX};
            
        int j=upper_bound(v.begin(),v.end(),p)-v.begin();
            
            j--;
            
           if(j>=0){
               
               sum+=v[j].second;
               
           } 
            
        }
        
        return sum;
        
    }
};