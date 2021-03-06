  /*
        
        no of groups of cars that comes together at destination
        
        
        speed=distance/time
        
        time= distance/speed
        
        find the time taken by each cars to reach destination
        
        target=12
        [10,8,5,3,0]=> distance need to cover [2,4,7,9,12] (sorted) [2,4,1,3,1]
        
        time = [1,1,7,3,12]
        
        clearly 1 comes first
        next 1 will catch it just at destination
        
        7 > 1 , cannot catch them, start new group from here [7]
        3 will catch 7 so both 3 and 7 comes in group
        
        12 will not catch 7 , so it makes another group
        
        Total group formed = 3
        
        */
        
        
        
class Solution {
public:
    int carFleet(int tar, vector<int>& pos, vector<int>& sp) {
        
        int n=pos.size();
        
        vector<vector<int>>v(n,vector<int>(2));
        
        for(int i=0;i<n;i++){
            v[i]={tar-pos[i],sp[i]};
        }
        
        sort(v.begin(),v.end());
        
        vector<double>time(n);
        
        for(int i=0;i<n;i++){
            if(sp[i]!=0)
            time[i]=((double)v[i][0]/(double)v[i][1]);
            else
             time[i]=10000000.000000;
        }
              
        double t=time[0];
        
        int i=1;
        
        int group=1;
        
        while(i<n){
            if(time[i]<=t)
                i++;
            else{
                group++;
                t=time[i];
                i++;
            }
        }
        
        return group;
    }
    
    
    
    /*
    
10
[6,8] , [3,2]  => [4,2]  => sort [2,4] pos,  [2,3] speed


time : [1.0,1.33]

*/
    
    
};