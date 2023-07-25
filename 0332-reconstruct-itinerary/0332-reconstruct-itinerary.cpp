/*

hame har edge sirf ekk baar hi traverse karni h

traversal "JFK" se start karna hoga 

traverse kaise karna h??

1=>jab tak proper sequence milta rhe vertex ko graph m se remove karke
(vector.pop_back() kaa use karo) stack m dalte rho

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
   sequence= ["SJC","SFO","LHR","MUC","JFK"]
   reverse it, ans= ["JFK","MUC","LHR","SFO","SJC"]  =============> EULER CIRCUIT
   
   different ans may be possible , we needs to return min sequence
   to ensur this:-
   ans[0]= sequence[n-1]=st.top()=g[x].back()=minimum
   so sort all vectors inside the adjacency list in decreasing order
*/

class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tick) {
        
         unordered_map<string,vector<string>>g;
        
        for(auto it:tick){
            g[it[0]].push_back(it[1]);
        }
        
        for(auto &it:g){
            sort(it.second.rbegin(),it.second.rend());
        }
        
        string start="JFK";
        
        stack<string>st;
        st.push(start);
        
        vector<string>seq;
        
        while(st.size()>0){
            
            string x=st.top();
            
            while(g[x].size()>0){  // x->y->.....
                string y=g[x].back();
                g[x].pop_back();
                st.push(y);
                x=y;
            }
            
            string last=st.top();  // sequence end ho gya iss node par
            st.pop();
            seq.push_back(last);
            
        }
        
        reverse(seq.begin(),seq.end());
        
        return seq;
    }
};