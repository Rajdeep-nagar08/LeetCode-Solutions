/*

starting from source , now we needs to reach target from source using 
minimum no of bus stops

we needs to minimize the no of bus stops

starting bfs from source , we push all possible bus stops that can be reached from this stop
[donot take each bus again and again , donnot use ech bus stop again and again]

*/



class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& r, int src, int tar) {
        
        // needs to go from src => tar , using least no of buses
        
        // r[i] = route of ith bus
        
        // make a directed graph , 
        
        // NOTE: we needs to minimize the no of buses , not the distance between the src and tar
        
      unordered_map<int,vector<int>>g;
// stop => buses available from this stop  ( we needs to minimize the no of buses used)
     
        int n=r.size();  // no of buses available
        
        if(n==0 || src==tar)
            return 0;
    
        for(int i=0;i<n;i++){
            for(int j=0;j<r[i].size();j++){
                g[r[i][j]].push_back(i);
            }
        }
        
      vector<bool>visBus(n,false);  
      unordered_map<int,int>visStop;

        
     queue<pair<int,int>>q;   // station , bus count
     q.push({src,0});
    
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                int stop=q.front().first;
                int busCount=q.front().second;
                
                if(stop==tar)
                    return busCount;
                
                q.pop();
                visStop[stop]=1;
                
                for(int bus:g[stop]){
                    if(visBus[bus]==true)
                        continue;
                    visBus[bus]=true;
                    for(int i=0;i<r[bus].size();i++){
                        if(visStop.count(r[bus][i])==1)
                            continue;
                
                     q.push({r[bus][i],busCount+1});
                    }
                }
            }
        }
        
       return -1;
    }
};