class FrontMiddleBackQueue {
public:
    
    deque<int>q;
    
    FrontMiddleBackQueue() {
        
    }
    
    void pushFront(int val) {
        q.push_front(val);
         return;
    } 
    
    
    void pushMiddle(int val) {
        
        int sz=q.size();
        
        if(sz==0){
            q.push_back(val);
            return;
        }
        
        if(sz==1){
            q.push_front(val);
            return;
        }
    
            int x1=sz/2;

            int x=x1;
            while(x>0){
                q.push_back(q.front());
                q.pop_front();
                x--;
            }
            q.push_front(val);
            while(x!=x1){
                q.push_front(q.back());
                q.pop_back();
                x++;
            }
            return;
        
    }
    
    
    void pushBack(int val) {
        q.push_back(val);
        return;
    }
    
    
    int popFront() {
        int sz=q.size();
        if(sz==0)
            return -1;
        int val=q.front();
        q.pop_front();
        return val;
    }
    
    
    int popMiddle() {
        
         int sz=q.size();
        if(sz==0){
            return -1;
        }
    
            int x1=sz%2==0?sz/2:sz/2 +1;
        
            int x=x1;
            while(x>0){
                q.push_back(q.front());
                q.pop_front();
                x--;
            }
         
            int val=q.back();
        
            q.pop_back();
        
            while(x!=(x1 -1)){
                q.push_front(q.back());
                q.pop_back();
                x++;
            }
        
        
            return val;
        
    }
    
    
    int popBack() {
         int sz=q.size();
        if(sz==0)
            return -1;
        int val=q.back();
        q.pop_back();
        return val;
    }
    
    
};


