class Solution {
public:
    int maximumGain(string s, int x, int y) {
        
        
       // ab , than ba
        int ans1=0;
        string str1;
        
        solveAB(s,x,y,str1,ans1);
        
        solveBA(str1,x,y,str1,ans1);
        
        // ba m than ab
        
        int ans2=0;
        string str2;
        
        solveBA(s,x,y,str2,ans2);
        
        solveAB(str2,x,y,str2,ans2);
        
    
        return max(ans1,ans2);
        
    }
    
    void solveAB(string s,int x,int y,string &str,int &ans1){
        
        stack<char>st1;
                
        int i=0;
        
        int n=s.size();
        
        // ab
        
         while(i<n){
            if(s[i]=='b'){
              if(st1.size()==0 || st1.top()!='a')
                  st1.push(s[i]);
                else{
                    st1.pop();
                    ans1+=x;
                }
            }
            else
                st1.push(s[i]);
            
            i++;
        }
        
        
        
          while(st1.size()>0){
            str+=st1.top();
              
              st1.pop();
        }
        
        reverse(str.begin(),str.end());
        
      //  cout<<str<<endl;
        
        
    }
    
    
    void solveBA(string s,int x,int y,string &str,int &ans2){
        
        stack<char>st2;
        
        int i=0;
        
        int n=s.size();
        
        
          while(i<n){
            if(s[i]=='a'){
              if(st2.size()==0 || st2.top()!='b')
                  st2.push(s[i]);
                else{
                    st2.pop();
                    ans2+=y;
                }
            }
            else
                st2.push(s[i]);
            
            i++;
        }
        
        
        
        
         while(st2.size()>0){
          
             str+=st2.top();
             
             st2.pop();
        }
        
        
        reverse(str.begin(),str.end());
        
        
    }

};