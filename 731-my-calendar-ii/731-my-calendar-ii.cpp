/*

adding the event no cause triple booking (3 events have some common time)




*/

class MyCalendarTwo {
public:
    
    map<int,int>mp;  // using ordered map to keep times in sorted order
    
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
    
        // adding [start,end]
        
        // check , there should not be 2 events already have some common point in range [start,end]
        
        int sum=0;
        
        int mx=0;
        
        mp[start]++;
        
        mp[end]--;
        
        for(auto it:mp){
            sum+=it.second;
            
            if(it.first>=start && it.first<end){
                mx=max(mx,sum);
            }
        }
        
        if(mx==3){
            mp[start]--;
            mp[end]++;
            return false;
        }
        
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */