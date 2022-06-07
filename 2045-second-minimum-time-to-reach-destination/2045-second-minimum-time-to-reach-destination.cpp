/*
        
        time to traverse the edge = time
        
        time to change the color of signal = change
        
        [color changes as : green=>red=>green=>red after each "change" minute]
        
        Note: Question Understanding
        
        Let
        A=>B (move time= 2 min , and signal change time = 2 min)
        it means when we reaches at B we take 2 min and in 2 min its color changes from green to red so to move ahead from B we needs to wait at B for further 2 mins so that its color becomes green
        
        A=>B=>C=>D (move time= 4 min , and signal change time = 6 min)
        
        move A=>B in 4 min than color of B remains green for further 2 min,so 
        move from B to C in 4 min, person reaches at C in 8 min
        after 8 min , color of A,B,C all is 6+2(red) is red for further 4 min
        
        so wait at C for 4 min than move to D
        Total time taken= 4+4+4(wait)+4 = 12 mins
   -------------------------------------------------------------------------
   
        so color of all nodes after time t is :
       
        if (t < change)  all nodes are green
        
        if(t%change==0){
          t1=t/change
          if(t1%2==1)
            all are red, they will green after time=change , at time= t+change
            
          otherwise all are green, person will move
        }
        
        if(t%change !=0){
    
             t1=t/change
             
             if(t1%2==1)
             all are red
             it will green after time:
            
               t2= (t1+1)*change-t
            
               all nodes will green after time t2 or all node will green at time
               t+(t1+1)*change-t= (t1+1)*change
            
               so to move, wait for t2 min
            
            else if(t1%2==0)
            all nodes are green,person will move
            
               
        moving out from vertex if it is green is must (as per the question)
        
        Needs to move from from 1----->n
        
        if min. time to do this = 5 min
        
        second min time is = 7 min
        
        Ans= second min time = 7 min
        
        
        Intially all signals are green
        
        We Can visit any vertex any no of time
        
        We can use BFS algorith to find second shortest path
 --------------------------------------------------------------------------
 
        For BFS, two cases arises
        
       if for any node, its curr time < its firstMinTime , than update its firstMinTime and secondMinTime 
       
       for for any node , its curr time > Its firstMinTime and 
       its curr time < its SecindMinTime , than update its secondMinTime and push it into the queue
       
        if currTime > firstMinTime and currTime > secondMinTime than no needs to push into queue becouse now there is no possiblity of any lower time        
        
    */

class Solution {
    public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        
        vector<vector<int>> g(n + 1);
        for (auto &e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        
         vector<int> time1(n+1, INT_MAX);  // store firstMinTime
         vector<int>time2(n+1, INT_MAX);   // store secondMinTime
        
        
        time1[1] = 0;
        
        queue<pair<int,int>> q; 
        
        q.push({0,1});
        
        while (!q.empty()) {
            
            int currTime= q.front().first;
            int x=q.front().second;
            q.pop();
            
            for (int y: g[x]) {
                
 // update currtime so that all signals get green and we can move from x to y
             
                int t1;
                
                int newTime=currTime;
            
            if(currTime<change)  // signals are green , move ahead
                 newTime+=time;
            
            else if(currTime%change==0){
                t1=currTime/change;
                if(t1%2==1)        // signals are red making them green
                    newTime+=change;
               
                newTime+=time;    // now signals are green so move ahead
            }
            
            else{
                
               t1=currTime/change; 
                if(t1%2==1)         // signals are red , making them green
                    newTime=(t1+1)*change;
                
                newTime+=time;      // now signals are green so move ahed
            }
      
        
				// update two distances.
                if (time1[y] > newTime){
                    time2[y] = time1[y]; 
                    time1[y] = newTime;
                    q.push({newTime, y});
                } 
                else if (newTime > time1[y] && newTime < time2[y] ) {
                    time2[y] = newTime;
                    q.push({newTime, y});
                }
                else
                    continue;
            }
        }
        return time2[n];
    }
};

