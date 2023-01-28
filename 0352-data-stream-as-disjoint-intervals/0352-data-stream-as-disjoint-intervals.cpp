class SummaryRanges {
public:
    

    unordered_map<int,int>mp1,mp2,mp3;
    
    /*

    l=mp1[value]= starting number of any range that is ending at 'value'
    or any range like [l...value]
    
    r=mp2[value]= last number of any range that is starting from 'value'
    or any range like [value....r]
    
    So there can be 4 cases:
    
    case 1:
    
      
      'value' cannot be part of any range
      so push [value,value] in the range
      
     case 2:
       there is a range of type [l....value-1] but there is no range that is starting from value+1
       
       so add 'value' at the last of [l...value-1]
       
       and replace the range [l...value-1] by [l,value]
       
      case3:
      
        there is no range like [l....value-1], but there is a range like [value+1.....r]
        so add 'value' at the starting of range [value+1....r]
        
        and replace the range [value+1,r] by [value,r]
    
       case 4:
       
        there are two ranges like [l....value-1]  and [value+1....r]
        
        so add 'value' at the middle of both
        
        and replace both the ranges by [l,r]
        
        
    
    
    mp3[value] , whether value is already present in range or not
    
    if value is already a part of any range, then avoid it
    
    
    */
    
    
    
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
                        
            vector<int>v={l,value-1};
            
            auto i1=lower_bound(ans.begin(),ans.end(),v)-ans.begin();
            
            ans[i1]={l,value};
        }
        
        else if(l==-1 && r!=-1){
            
            mp1[r]=value;
            
            mp2[value]=r;
            
            mp1[value]=value;
            
             vector<int>v={value+1,r};
            
            auto i1=lower_bound(ans.begin(),ans.end(),v)-ans.begin();
            
            ans[i1]={value,r};
            
        }
        
        else{
                        
            mp2[l]=r;
            
            mp1[r]=l;
                         
            vector<int>v={l,value-1};

             auto i1=lower_bound(ans.begin(),ans.end(),v)-ans.begin();
            
            ans[i1]={l,r};
                        
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