class BrowserHistory {
public:
    
    
    vector<string>v;
    
    int end=0, last=0;
    
    BrowserHistory(string homepage) {
        
        
       v.push_back(homepage); 
       
    }
    
    void visit(string url) {
        
       int sz=v.size();
        
       if(end==sz-1){
           v.push_back(url);
           end++;
           last=end;
       }
        
        else{
            v[end+1]=url;
            end++;
            last=end;
        }
        
    }
    
    string back(int steps) {
       
        end=max(0,end-steps);
        
        return v[end];
    }
    
    string forward(int steps) {
       
        int sz=v.size();
        
        
        end=min(last,end+steps);
        
        return v[end];
        
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */