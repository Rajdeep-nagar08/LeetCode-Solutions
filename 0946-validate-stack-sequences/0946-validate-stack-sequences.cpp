class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int>st;
        int i=0,j=0;
        
        while(j<popped.size()){
            int no=popped[j];
            
            if(st.size()==0 && i<pushed.size()){
                st.push(pushed[i]);
                i++;
            }
            else if(st.size()==0 && i>=pushed.size())
                return false;
             
          while(st.top()!=no && i<pushed.size()){
                st.push(pushed[i]);
                i++;
            }
             if(st.top()==no){
                 st.pop();
                 j++;
             }
              else{
                  return false;
              }
        }
          
          return true;
    }
};