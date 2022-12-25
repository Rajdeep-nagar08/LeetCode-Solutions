


class Solution {
public:
    vector<int> answerQueries(vector<int>& myNums, vector<int>& q) {
        

        stack<char>myStack;

        
        int n=myNums.size();
        
        
        int k=0;
        
        for(int i=0;i<1;i++){
            k++;
        }
        
        int m=q.size();
        
        vector<int>ans(m);
        
        
        for(int i=0;i<m;i++){
            
            int no=q[i];
            
             for(int i=0;i<1;i++){
            k++;
        }
        
            
            vector<int>myTemp;
            
            for(int j=0;j<n;j++){
                
                if(myNums[j]<=no)
                    myTemp.push_back(myNums[j]);
                
            }
            
            
            int sz=0;

            
            int mySum=0;
            
            
            
            
            sort(myTemp.begin(),myTemp.end());

            

            
            for(int x:myTemp){
                
                
                if(mySum+x>no)
                    break;
                
                mySum+=x;
                sz++;
                
            }
            
            
            
             for(int i=0;i<1;i++){
            k++;
        }
        
            
            ans[i]=sz;
        }
        
        
        
             for(int i=0;i<1;i++){
            k++;
        }
        
        
        return ans;
    }
};