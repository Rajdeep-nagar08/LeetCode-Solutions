class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& bar) {
        
        
        int n=bar.size();
        
         vector<int>ans(n);
               
        
        priority_queue<pair<int,int>>p1,p2;

        
        unordered_map<int,int>mp;
        
        for(int x:bar)
            mp[x]++;
        
        for(auto it:mp){
            p1.push({it.second,it.first});
        }
        
        int i=0;
        
        while(i<n){
            int f1=p1.top().first;
            int no1=p1.top().second;
            p1.pop();
            
            if(p1.size()==0){
                ans[i]=no1;
                break;
            }
            
            int f2=p1.top().first;
            int no2=p1.top().second;
            p1.pop();
            
            ans[i]=no1;
            i++;
            ans[i]=no2;
            i++;
            
            f1--;
            f2--;
            if(f1>0)
                p1.push({f1,no1});
            
            if(f2>0)
                p1.push({f2,no2});
             
        }
        
        return ans;
    }
};