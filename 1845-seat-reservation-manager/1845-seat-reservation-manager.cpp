class SeatManager {
public:
      
    priority_queue<int,vector<int>,greater<int>>unresvd;
        
    SeatManager(int n) {
        
        for(int i=1;i<=n;i++){
            unresvd.push(i);
        }
    }
  
    
    int reserve() {
        
        int x=unresvd.top();
                
        unresvd.pop();
        
        return x;
        
    }
    
    void unreserve(int seatNumber) {
        
        unresvd.push(seatNumber);
        
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */