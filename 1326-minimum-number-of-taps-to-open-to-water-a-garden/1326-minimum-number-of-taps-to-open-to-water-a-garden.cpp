/*

ith tap can water from [i-ranges[i] , i+ranges[i]]

To minimize the minimum no of taps , we should first chosse the tap that cover more and more area starts from 0 or -ve range

So we sort the vector by their starting points , 
then in continouity of starting range[range whose start poit is <=0 and point is highest] we chosse the next range whose end point is as higher as possible and it will either next to previous range or some portion my collpase between them


*/
class Solution {
public:
    int minTaps(int n, vector<int>& range) {
      vector<vector<int>>v;
      for(int i=0;i<range.size();i++)
        v.push_back({i-range[i],i+range[i]});
      
      sort(v.begin(),v.end());
      
      int i=0;
      
      int end=-1;
      int count=0;
      while(i<v.size()){
        int l=v[i][0];
        int r=v[i][1];
        int idx=-1;
        
        if(end==-1)// initially , to choose the first range
          r=0;
        if(end>=n)
          return count;
        else{
          while(i<v.size() && v[i][0]<=r){
            cout<<v[i][0]<<" "<<v[i][1]<<endl;
            if(end<v[i][1]){
              end=v[i][1];
              idx=i;
            }
            i++;
          }
        }
        
    //    cout<<idx<<endl;
        if(idx==-1)
          break;
        
        i=idx;
        count++;
      }
      
      return -1;
    }
};