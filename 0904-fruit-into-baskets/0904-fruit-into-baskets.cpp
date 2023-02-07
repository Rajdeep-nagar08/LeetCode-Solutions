class Solution {
public:
    int totalFruit(vector<int>& frut) {
        
        int n=frut.size();
        
        int i=0;
        
        unordered_map<int,int>mp;
        
        while(i<n){
            
            mp[frut[i]]++;
            
            i++;

            if(mp.size()==2)
                break;
            
        }
                
       // cout<<i<<endl;
        
        int ans=0;
        
        if(mp.size()<=2)
            ans=i;
        
        int j=0;
        
        while(i<n){
            
            mp[frut[i]]++;

            if(mp.size()==3){
                
                while(j<i){
                    if(mp[frut[j]]==1){
                        mp.erase(frut[j]);
                        j++;
                        break;
                    }
                    else
                        mp[frut[j]]--;
                    
                    j++;
                }
            }
                        

            if(mp.size()==2){
              //  cout<<j<<" "<<i<<endl;
                ans=max(ans,i-j+1);
            }
            
            i++;
                        
        }
        
        return ans;
    }
};