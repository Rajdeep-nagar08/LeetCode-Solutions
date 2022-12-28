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
        
         vector<int>ans(w.size(),0);
                
        for(int i=0;i<w.size();i++)
        {
            int l=0;
            int high=v.size()-1;
            int mid=l+(high-l)/2;
            
            while(l<=high)
            {
                if(w[i]>=v[mid].first)
                {
                    
                    ans[i]=v[mid].second;
                    l=mid+1;
                }
                else
                {
                    high=mid-1;
                }
                
                mid=l + (high-l)/2;
            }
        }
        
        int final=0;
        
        for(int i=0;i<ans.size();i++)
        {
            final+=ans[i];
        }
        
        return final;
    }
};