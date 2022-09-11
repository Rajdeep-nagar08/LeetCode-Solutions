int mod=1e9+7;

/*

sum of k speeds*min eff among k = max to max 

max sum (scratch it using min heap ) * max eff (make it sure using sorting)

*/

#define lln long long int

class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& eff, int k) {
   
        
vector<pair<int,int>>arr(n);

for(int i=0;i<n;i++){
arr[i]={eff[i],speed[i]};
}

sort(arr.rbegin(),arr.rend());   // eff , speed

priority_queue<int, vector<int>,greater<int> >pq;

lln ans = 0;

lln sum = 0;

for (auto& it : arr) {

int e = it.first; // minimum eff till now
int s = it.second;

sum  += s;

pq.push(s);

if (pq.size() > k) {

int temp = pq.top();
sum  -= temp;           // not taking minimum contributing speed
pq.pop();
    
}

ans = max(ans, sum  * e);        // max sum * min eff till now
    
    // NOTE: that pair will not affect the ans which have low speed even if we are considering its efficiency
    
    
}

        
    return ans%mod;
        
    }
};


/*
eff/speed

[[10,6],[2,7],[1,3]] , k=2

*/