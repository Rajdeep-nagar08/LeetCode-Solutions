class MyStack {
 //   queue<int>q1;
   // queue<int>q2;
    deque<int>dq;
public:
    MyStack() {
        
    }
    
    void push(int x) {
       // q1.push(x);
        dq.push_back(x);
    }
    
    int pop() {
      /*  while(q1.size()>1){
            q2.push(q1.front());
            q1.pop();
        } 
        
        int ans=q1.front();
        q1.pop();
        
        while(q2.size()>0){
            q1.push(q2.front());
            q2.pop();
        }
        
        return ans;
        */
        int ans=dq.back();
        dq.pop_back();
        return ans;
    }
    
    int top() {
     /*   
        while(q1.size()>1){
            q2.push(q1.front());
            q1.pop();
        } 
        
        int ans=q1.front();
        q1.pop();
        q2.push(ans);
        
        while(q2.size()>0){
            q1.push(q2.front());
            q2.pop();
        }
        
        return ans;
        */
        return dq.back();
        
    }
    
    bool empty() {
      //  return !q1.size();
        return !dq.size();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */