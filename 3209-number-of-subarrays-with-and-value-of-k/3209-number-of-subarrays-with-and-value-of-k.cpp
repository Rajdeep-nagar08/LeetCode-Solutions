/*

standard approach that we used in finding no. of subrrays whsoe sum = target

like we make unordered map, store prefix sum in that map and at each prefix sum we check sum-target in the map


like here, we store [0....i] their prefix AND in map, with count

let [0.....4] & nums[7] == k (target)

as map contains AND of [0....4] it means AND of [0....4] != AND of [0.....6]

it means 



*/


#define lln long long int

class Solution {
public:
    lln countSubarrays(vector<int>& a, int k) {
        int n = a.size();
        lln c = 0;
        unordered_map<lln, lln> p,q;
        for (int i=0;i<n;i++) {
            q.clear();
            if(a[i]==k) {
                c++;
            }
            q[a[i]] = 1;
            for (auto it:p) {
                lln nAnd = it.first&a[i];
                if (nAnd==k) {
                    c+=it.second;
                }
                q[nAnd]+=it.second;
            }
            p=q;
        }

        return c;
    }
};
