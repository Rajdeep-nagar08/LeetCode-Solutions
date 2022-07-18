/*

will add extra student to a class which will increase pass ratio to  a maximum extent

let class[i]={pass,total}

pass ratio (p1)=pass/total

After adding one extra student to this class

class[i]={pass+1,total+1}

pass ratio (p2)= pass+1/total+1

increase in pass ratio=increase= p2-p1

so to increase average pass ratio, we needs to give extra student to a class whose increase in pass ratio is maximum

So to keep track max increase in pass ratio among all classes, we use max heap

*/


#define d double
class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& c, int e) {
      
        int n=c.size();

        priority_queue<pair<double,pair<int,int>>>pq;
        
        int pass,total;
        double p1,p2;
        double increase;
        for(int i=0;i<n;i++){
            pass=c[i][0];
            total=c[i][1];
            p1=(double)(pass)/(total);
            p2=(double)(pass+1)/(total+1);
            increase=p2-p1;
            pq.push({increase,{pass,total}});
        }
        
        while(e>0){
            auto it=pq.top();
            pq.pop();
            pass=it.second.first;
            total=it.second.second;
            pass++;
            total++;
            p1=(double)(pass)/(total);
            p2=(double)(pass+1)/(total+1);
            increase=p2-p1;
            pq.push({increase,{pass,total}});
            e--;
        }
        
        double sum=0.00000;
        
        while(pq.size()>0){
            pass=pq.top().second.first;
            total=pq.top().second.second;
            sum+=(double)(pass)/(total);
            pq.pop();
        }
        
        double averagePassRatio=(double)(sum)/(n);
        
        return averagePassRatio;
    }
};