class LockingTree {
public:
    
    unordered_map<int,vector<int>>g;
    
    unordered_map<int,int>lckNode; // node => userLocked
    
    int n;
    
    LockingTree(vector<int>& par) {
     
        n=par.size();
        
        for(int i=1;i<n;i++){
            g[par[i]].push_back(i);
        }
        
    }
    
    bool lock(int num, int user) {
        
        if(lckNode.count(num)==1)
            return false;
        
        lckNode[num]=user;
        
        return true;
        
    }
    
    bool unlock(int num, int user) {
        
        
        if(lckNode.count(num)!=1)
            return false;
        
        if(lckNode[num]!=user)
            return false;
        
        lckNode.erase(num);
        
        return true;
        
    }
    
    bool upgrade(int num, int user) {
        
        // upgrade node "num"
        
        
        if(lckNode.count(num)==1)
            return false;
        
        
        
        
    
        queue<int>q;
        
        
         q.push(num);
        
        // To unlock all descendent of num
        int c=0;
        
        vector<int>v;
        
        while(!q.empty()){
            int x=q.front();
            q.pop();
            if(lckNode.count(x)==1){
                // lckNode.erase(x);
                v.push_back(x);
                c++;
            }
            
            for(int y:g[x]){
                q.push(y);
            }
        }
        
        
        // no descendent is locked
        if(c==0)
            return false;
        
        
        
        // Checking Is there any ancestor of num that is locked ? if locked then return false
                
        vector<bool>vis(n,false);

        
        for(auto it:lckNode){
            q.push(it.first);
            vis[it.first]=true;
        }
        
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                int x=q.front();
                q.pop();
                
                if(x==num){
                    return false;
                }
                
                for(int y:g[x]){
                    if(vis[y]==false){
                        vis[y]=true;
                        q.push(y);
                    }
                }
            }
        }
    
        for(int i=0;i<v.size();i++){
            lckNode.erase(v[i]);
        }
                
        lckNode[num]=user;

        return true;
        
    }
};

