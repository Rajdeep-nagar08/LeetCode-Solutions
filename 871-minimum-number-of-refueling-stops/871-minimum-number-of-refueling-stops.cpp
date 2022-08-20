/*

one litre of gas for one mile

maximum 500 stations


min. no of refueling stops the car must make to reach destination ?


thinking greedly => we moves forward until we have a fuel and when we donot have sufficient fuel to move forward we stops and using the fuel of a station that is max. among all the visisted stations (to get max fuel, as we are moving forward we keep storing the fuel of each visted station in a max heap)

*/

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        
        // remember , fuel needs= distance travelled 
        
     
        int n=stations.size();
    
        
        priority_queue<int>pq;
        
        // using startFuel, we can travel a distance = startFuel
        
        int distance=startFuel;
        
        if(n==0){
            if(distance>=target)
                return 0;
            
            return -1;
        }
        
        // at this distance , we have 0 fuel
        
        // if our current diastance < first station , then we never reaches to our first station , so return -1
        

        if(distance<stations[0][0])
            return -1;
        
        int i=0;
        
        int stops=0;
        
        while(distance<target){
            
            // keep moving forward till we have sufficient fuel, and keep storing their fuels in max heap so that we can pick max. fuel in future whenever we needs that
            
            while(i<n){
                
                if(distance<stations[i][0])  // not able to reach ith station
                    break;
        
                pq.push(stations[i][1]);
                
                i++;
            }
            
            // we are not able to move ahead, so we collect some fuel, we take a mx fuel
            
            if(pq.size()==0)  // no fuel to use
                return -1;
            
            distance+=pq.top();
            
            pq.pop();
            
            stops++;
            
        }
        
        return stops;
        
    }
};