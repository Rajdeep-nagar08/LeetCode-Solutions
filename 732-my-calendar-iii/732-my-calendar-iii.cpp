/*

return maximum no of events that have some common point of time 

([10,19]  -- [10,39] -- [5,14]) common time=[10,14]
                           |
                         [5,9]  common time=[5,9]
                         

[50,59]

[25,55]



Brute force approach:

use prefix sum of diffrenece tech. over vector of size 1e9

at each step , ans= max prefix sum


Opttimal approach:-

instead of using vector , we use ordered map

than size of map <=400 always
*/

class MyCalendarThree {
public:
    
    map<int,int>mp;
    
    MyCalendarThree() {
        
        
    }
 
    // at most 400 calls will be made to book
    
    int book(int start, int end) {
        
        mp[start]++;
        
        mp[end]--;
        
        int mx=1;
        
        int sum=0;
        
        for(auto it:mp){
           sum+=it.second;
           mx=max(mx,sum);
        }
        
        return mx;
    }
};

