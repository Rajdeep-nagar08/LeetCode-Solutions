
class Solution {
public:
    
    int ans=0;
    
    int maxLength(vector<string>& arr) {
    
    string str="";
        
    find(0,str,arr);
        
    return ans;
        
}
    
    void find(int i,string &str,vector<string>&arr){
        
        if(i>=arr.size()){
           
         //   cout<<str<<endl;
            
            vector<int>v(26,0);
            
            for(char ch:str){
                v[ch-'a']++;
                if(v[ch-'a']>1)
                  return;
            }
            
            ans=max(ans,(int)str.size());
            
            return;
        }
        
        find(i+1,str,arr);
    
        if((int)str.size()+(int)arr[i].size()<=26){
            
        str+=arr[i];
       
     //   cout<<str<<endl;
        
        find(i+1,str,arr);
        
        int sz=arr[i].size();
        
        int total=str.size();
                     
        str=str.substr(0,total-sz);
        
        }
        
    }
};