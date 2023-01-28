class SummaryRanges {
public:
    

    unordered_map<int,int>mp1,mp2,mp3;
    
    vector<vector<int>>ans;
    
    SummaryRanges() {
        
        
        
    }
    
    void addNum(int value) {
        
        if(mp3.count(value)==1)
            return;
        
        mp3[value]++;
        
        int l=-1,r=-1;
        
        if(mp1.count(value-1)==1){
            l=mp1[value-1];
        }
    
        if(mp2.count(value+1)==1){
            r=mp2[value+1];
        }
          
        
       // cout<<value<<" "<<l<<" "<<r<<endl;
        
        if(l==-1 && r==-1){
            
            mp1[value]=value;
            mp2[value]=value;
            
             vector<int>v={value,value};

             auto i1=lower_bound(ans.begin(),ans.end(),v)-ans.begin();
            
            for(int j=i1;j<ans.size();j++){
                
                vector<int>v1=ans[j];
                
                ans[j]=v;
                
                v=v1;
            }
            
            ans.push_back(v);
        
        }
        
        else if(l!=-1 && r==-1){
            mp2[value]=value;
            mp1[value]=l;
            mp2[l]=value;
            
            // [l,value-1] => [l,value]
            
            vector<int>v={l,value-1};
            
            auto i1=lower_bound(ans.begin(),ans.end(),v)-ans.begin();
            
            ans[i1]={l,value};
        }
        
        else if(l==-1 && r!=-1){
            
            mp1[r]=value;
            
            mp2[value]=r;
            
            mp1[value]=value;
            
           // cout<<value<<" "<<mp2[value]<<endl;
            
            // [value+1,r] => [value,r] 

             vector<int>v={value+1,r};
            
            auto i1=lower_bound(ans.begin(),ans.end(),v)-ans.begin();
            
            ans[i1]={value,r};
            
        }
        
        else{
            
            
            // [l,value-1] , [value+1,r] => [l,r]
            
            mp2[l]=r;
            
            mp1[r]=l;
                         
            vector<int>v={l,value-1};

             auto i1=lower_bound(ans.begin(),ans.end(),v)-ans.begin();
            
            ans[i1]={l,r};
            
          //  cout<<value<<" "<<l<<" "<<r<<endl;
            
            for(int j=i1+1;j<ans.size()-1;j++){
                ans[j]=ans[j+1];
            }
            
            ans.pop_back();
            
        }
        
    }
    
    
    vector<vector<int>> getIntervals() {
        
        
        return ans;
        
    }
    
    
};



/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */