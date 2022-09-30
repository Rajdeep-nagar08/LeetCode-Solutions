/*

for each reactangle [x1,x2,h] => [x1,-h] starting point , [x2,h] ending point

store all startimng and ending points in a list

sort all starting and ending points by x coordinate
if both starting at same point, greater height is picked first
if both ending at same point, lower height is picked first
if one starting and one ending, start should come first (i.e. 0 < 1)



At any point Its clear that skyline will be formed by highest building available at that point

if there is an starting point than include that in the set\if there is an end point than remove that building from the set

when moving from one building to another building , if max height changes than include that point in the ans


to keep track of max height points 
*/

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& b) {
        
        int n=b.size();
        
        vector<pair<pair<int,int>,int>>v;
        
        for(int i=0;i<n;i++){
            v.push_back({{b[i][0],b[i][2]},0});  // start point
            v.push_back({{b[i][1],b[i][2]},1});  // end point
           }
        
        sort(v.begin(),v.end(),comp);
        
        vector<vector<int>>ans;
        
        multiset<int,greater<int>>st;  
        // we needs to delete random elements, we needs greater element at top,we also needs to store duplicate elements
        
        
        int hmax=0;
        
        st.insert(0);
        
        for(int i=0;i<v.size();i++){
        
            pair<pair<int,int>,int>p1=v[i];
            int x=p1.first.first;
            int ht=p1.first.second;
            int loc=p1.second;
            
            if(loc==0){  // starting point of any rectangle
                st.insert(ht);
            }
            else{  // ending point of any rectangle
                auto it=st.find(ht);
                st.erase(it);
            }
            
            if(hmax!=*st.begin()){  // change in max height
                hmax=*st.begin();
                ans.push_back({x,hmax});
            }
        }
        
        return ans;
    }

static bool comp(pair<pair<int,int>,int>&a, pair<pair<int,int>,int>&b){
        //first sort by x-coordinate
        if(a.first.first != b.first.first)
            return a.first.first < b.first.first;
        //if both starting at same point, greater height is picked first
        if(a.second==0 && b.second==0)
            return a.first.second > b.first.second;
        //if both ending at same point, lower height is picked first
        if(a.second==1 && b.second==1)
            return a.first.second < b.first.second;
        //if one starting and one ending, start should come first (i.e. 0 < 1)
        return a.second < b.second;
  }
};