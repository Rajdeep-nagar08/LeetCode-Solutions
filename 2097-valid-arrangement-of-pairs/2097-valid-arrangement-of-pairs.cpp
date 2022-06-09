/*

hame har edge sirf ekk baar hi traverse karni h

agar graph cyclic h too ham kisi bhi node se traversal start kar sakte h 
otherwise hame aise node se traversal start karne padega jisme se agar n nodes nikalti h
(x--->) too usme n-1 nodes akar milti hooo (--->x)

traverse kaise karna h??

1=>jab tak proper sequence milta rhe vertex ko graph m se remove karke(vector.pop_back() kaa use karo) stack m dalte rho

2=>agar kisi end node par aa gye(joo kisi aur node se connect nhi h) iska matlab 
hamare ans ki list m yee node last m honi chaiyee too iss node ko sequ vector m add kar do
   => iss node ko stack m se nikal do
   => ek sequence iss node par akar finish ho gya ab hame naya sequence find out karna hoga
   => jin nodes ko ham already traverse kar chuke ham wo abhi stack ke ander h
       too ham new sequence pta lagane ke liye unhi nodes ko use karenge
   => jo node abhi stack ke top par ho use check karo ki usse koi new sequence mil sakta h         kiya 
       =>agar iss node se new sequence mil jata h too step 1 se process repeat karo
       =>agar iss node se koi aur sequence nhi milta too ye bhi ekk end node hi ban gayi
          too isse stack se nikal do aur seq, vector m daal do (step 2)
    => ye kaam jabtak karte rho tabtak stak khali naa ho jaye
    

=> now ans vector ke ander string m wo node h joo sequence ke last m honi chaiye too
   ans vector ko reverse kar doo
   sequence= [1,5,4,9,11]
   reverse it,  [11,9,4,5,1]  =============> EULER CIRCUIT
   return ans= [[11,9],[9,4],[4,5],[5,1]]

*/


class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& p) {
    
        unordered_map<int,vector<int>>g;
        
        unordered_map<int,int>indg,outdg;
        
        for(auto it:p){
            g[it[0]].push_back(it[1]);
            outdg[it[0]]++;
            indg[it[1]]++;
        }
        
        int start=p[0][0];
        for(auto it:outdg){
            int out=it.second;
            int in=indg[it.first];
            if(out==in+1){
                start=it.first;
                break;
            }
        }
        
        stack<int>st;
        st.push(start);
        vector<int>seq;
        
        while(st.size()>0){
            
            int x=st.top();
            
            while(g[x].size()>0){  // x->y->.....
                int y=g[x].back();
                g[x].pop_back();
                st.push(y);
                x=y;
            }
            
            int last=st.top();  // sequence end ho gya iss node par
            st.pop();
            seq.push_back(last);
            
        }
        
        reverse(seq.begin(),seq.end());
        
        int n=seq.size();
        
        vector<vector<int>>ans;
        
        for(int i=0;i<=n-2;i++){
            ans.push_back({seq[i],seq[i+1]});
        }
        
        
        return ans;
    }
    
};