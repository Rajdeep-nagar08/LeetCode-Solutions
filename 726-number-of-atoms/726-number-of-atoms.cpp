class Solution {
public:
    string countOfAtoms(string form) {
       
        
        int n=form.size();
        
            
        stack<pair<string,int>>st;
        
        int i=0;
        
        while(i<n){
            
            
            if(form[i]=='('){
                st.push({"(",0});
                i++;
            }
            
            else if(form[i]==')'){
                
                int no=0;
                
                i++;
                
                while(i<n && isdigit(form[i])){  // total bracket no
                    no=no*10+(form[i]-'0');
                    i++;
                }
                
                if(no==0)
                    no=1;
                
                unordered_map<string,int>mp1;
                
                while(st.top().first!="("){
                    string str=st.top().first;
                    int cnt=st.top().second;
                  //  cout<<str<<" "<<cnt<<endl;
                    st.pop();
                   // mp[str]+=no*cnt;
                    mp1[str]+=cnt*no;
                    
                }
                
                st.pop();
                
                for(auto it:mp1){
                  st.push({it.first,it.second});
                }
                
            }
            
            else{
              
                string str;
                
                str.push_back(form[i]);
                
                i++;
                
    while(i<n && (form[i]!=')') && (form[i]!='(') && islower(form[i])){
        
                    str+=form[i];
        
                    i++;
        
                }
                
                int cnt=0;
                
                while(i<n && isdigit(form[i])){
                    cnt=cnt*10+(form[i]-'0');
                    i++;
                }
                
              //  mp[str]+=cnt;
                
                if(cnt==0)
                st.push({str,1});
                else
                    st.push({str,cnt});
                
            }
        }
        
        map<string,int>mp;
  
        while(st.size()>0){
            mp[st.top().first]+=st.top().second;
            st.pop();
        }
        
        
        string ans;
        
        for(auto it:mp){
            ans+=it.first;
            if(it.second>1)
            ans+=to_string(it.second);
            
        }
        
        return ans;
        
    }
};