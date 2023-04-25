class SmallestInfiniteSet {
public:
    
    vector<int>arr;
     

    SmallestInfiniteSet() {
       
        arr.resize(1000,-1);
    }
    
    int popSmallest() {
        for(int i=0;i<1000;i++){
            if(arr[i]!=0){
                arr[i]=0;
                
                
                
                return (i+1);
                
                
                
            }
        }
        return -1;
    }
    
    void addBack(int myNum) {
        
        
        int k=0;
        
        
        bool flag=false;
        
        
        arr[myNum-1]=1;
        
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(myNum);
 */