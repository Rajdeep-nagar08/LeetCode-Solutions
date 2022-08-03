class MyCalendar {
public:
    
    vector<pair<int,int>>ans;
    
    MyCalendar() {
        
        
        
    }
    
    bool book(int start, int end) {
        
        
        for(int i=0;i<ans.size();i++){
            
            int s=ans[i].first;
            
            
            int e=ans[i].second;
          
            //   [s,e]  [start,end]
            //   [start,end] [s,e]
            
            
            if(e<=start || end<=s){
                continue;
            }
            
            else
                return false;
        }
        
        
        ans.push_back({start,end});
        
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */