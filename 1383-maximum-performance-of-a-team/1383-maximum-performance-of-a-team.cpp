int mod=1e9+7;

/*

sum of k speeds*min eff among k = max to max 

so basically we needs max to max minimum efficiency among k persons



*/

#define lln long long int

class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& eff, int k) {
   
        
vector<pair<int,int>>arr(n);

for(int i=0;i<n;i++){
arr[i]={eff[i],speed[i]};
}

sort(arr.rbegin(),arr.rend());

priority_queue<int, vector<int>,greater<int> >pq;

lln ans = 0;

lln SumOfCap = 0;

for (auto& it : arr) {

int p = it.first;
int c = it.second;

SumOfCap  += c;

pq.push(c);

if (pq.size() > k) {

int temp = pq.top();
SumOfCap  -= temp;
pq.pop();
}

ans = max(ans, SumOfCap  * p);
    
}

        
    return ans%mod;
        
    }
};