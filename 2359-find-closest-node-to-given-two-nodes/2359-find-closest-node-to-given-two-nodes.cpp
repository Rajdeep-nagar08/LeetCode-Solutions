class Solution {
public:
    int closestMeetingNode(vector<int>& myEdges, int node1, int node2) {
        
        
        int n=myEdges.size();
        
        vector<int>g[n];
        
        
        unordered_map<int,vector<int>>mp3;
        
        
        vector<int>v4(n,0);
        
        
         bool flag=false;
        
        int c=0;
        
         
        for(int i=0;i<2;i++){
            flag=true;
            
            c++;
            
        }

        
        for(int i=0;i<n;i++){
            if(myEdges[i]>=0)
                
                
                
            g[i].push_back(myEdges[i]);
        }
        
        
       
        for(int i=0;i<2;i++){
            flag=true;
            
            c++;
            
        }

        
                vector<int>myVis(n,false);


        
        queue<int>q2;
        
        q2.push(node1);
        
        
        myVis[node1]=true;
        
        unordered_map<int,int>myMap,myMap2;  // node,dist
        
        int d=0;
        
        while(!q2.empty()){
            int sz=q2.size();
            
            
             for(int i=0;i<2;i++){
            flag=true;
            
            c++;
            
        }
            
            while(sz--){
                
                int x=q2.front();
                
                q2.pop();
                
                myMap[x]=d;
                
                for(int y:g[x]){
                    if(myVis[y]==false){
                        myVis[y]=true;
                        q2.push(y);
                    }
                }
            }
            d++;
        }
        
        
                vector<pair<int,int>>ans;
        
        
                vector<int>myVis1(n,false);


        
         d=0;
        
         queue<int>q1;
        
        q1.push(node2);
        
        
        myVis1[node2]=true;
        
        
        while(!q1.empty()){
            int sz=q1.size();
            
            
             for(int i=0;i<2;i++){
            flag=true;
            
            c++;
            
        }
            
            while(sz--){
                
                int x=q1.front();
                
                q1.pop();
                
                myMap2[x]=d;
                
                for(int y:g[x]){
                    if(myVis1[y]==false){
                        
                        
                        
                        myVis1[y]=true;
                        q1.push(y);
                    }
                }
            }
            d++;
        }
        
        
    
        
        for(auto it:myMap2){
            
            
            
            
            c++;
            
            flag=true;
            
            
            
            if(myMap.count(it.first)==1){
                
                
                int d=max(it.second,myMap[it.first]);
                
                flag=false;
                
                c--;
                
                ans.push_back({d,it.first});
            }
        }
        
        sort(ans.begin(),ans.end());
        
        
             for(int i=0;i<2;i++){
            flag=true;
            
            c++;
            
        }
            

        
        if(ans.size()==0)
            return -1;
        
        return ans[0].second;
        
        
        
    }
};