class Solution {
public:
    double minAreaFreeRect(vector<vector<int>>& p) {
        
        
        int n=p.size();
        
        double mn=INT_MAX;
    
        map<vector<pair<int,int>>,vector<pair<int,int>>>mp;
        
        for(int i=0;i<n;i++){
            
            for(int j=i+1;j<n;j++){
                
                for(int k=j+1;k<n;k++){
                    
                    int x1=p[i][0],y1=p[i][1];
                    
                    int x2=p[j][0],y2=p[j][1];
                    
                    int x3=p[k][0],y3=p[k][1];
                    
                       
//                 cout<<x1<<" "<<y1<<endl;
//                 cout<<x2<<" "<<y2<<endl;
//                 cout<<x3<<" "<<y3<<endl;
             //   cout<<x4<<" "<<y4<<endl;
                    
                //    cout<<i<<" "<<j<<" "<<k<<endl;
                    // y2
                    if(((y2-y1)*(y2-y3))==(-1)*((x2-x1)*(x2-x3))){
                       
                    //    cout<<j<<endl;
                      //  cout<<x2<<"-"<<y2<<endl;
                         vector<pair<int,int>>v;
                        
                        v.push_back({x1,y1});
                        
                        v.push_back({x3,y3});
                        
                        sort(v.begin(),v.end());
                        
                        mp[v].push_back({x2,y2});
                        
                        
                    } // y3
                    else if(((y3-y1)*(y3-y2))==(-1)*((x3-x1)*(x3-x2))){
                        
                        
                      //  cout<<k<<endl;
                        
                        //cout<<x3<<"-"<<y3<<endl;
                        
                          vector<pair<int,int>>v;
                        
                        v.push_back({x2,y2});
                        
                        v.push_back({x1,y1});
                        
                        sort(v.begin(),v.end());
                        
                        mp[v].push_back({x3,y3});
                        
                    }
                    // y1
                    else if(((y1-y2)*(y1-y3))==-1*(x1-x2)*(x1-x3)){
                        
                      //  cout<<i<<endl;
                        
                     //   cout<<x1<<"-"<<y1<<endl;
                        
                        vector<pair<int,int>>v;
                        
                        v.push_back({x2,y2});
                        
                        v.push_back({x3,y3});
                        
                        sort(v.begin(),v.end());
                        
                        mp[v].push_back({x1,y1});
                        
                        
                    }
                    
                  //  cout<<endl;
                }
            }
        }
        
 //       cout<<endl;
        
        for(auto it:mp){
            
            if(it.second.size()>=2){
                
                vector<pair<int,int>>v1=it.first;
                
                int x1=v1[0].first,y1=v1[0].second;
                
                int x2=v1[1].first,y2=v1[1].second;
                
                vector<pair<int,int>>v2=it.second;
                
                int m=v2.size();
                
                for(int i=0;i<m;i++){
                    
                    for(int j=i+1;j<m;j++){
                        
                    
                int x3=v2[i].first,y3=v2[i].second;
                
                int x4=v2[j].first,y4=v2[j].second;
                
//                 cout<<x1<<" "<<y1<<endl;
//                 cout<<x2<<" "<<y2<<endl;
//                 cout<<x3<<" "<<y3<<endl;
//                 cout<<x4<<" "<<y4<<endl;
                
                if((x1+x2)==(x3+x4) && ((y1+y2)==(y3+y4))){
                    
                
                double d1=(x3-x1)*(x3-x1)+(y3-y1)*(y3-y1);
                
                double d2=(x3-x2)*(x3-x2)+(y3-y2)*(y3-y2);
                
                double a=d1*d2;
                
                double ans=sqrt(a)*1.00000;
               // cout<<ans<<endl;
                
                mn=min(mn,ans);
                    
                }
            }
        }
                
            }
            
        }
        
        if(mn==INT_MAX)
            return 0;
        
        return mn;
    }
};

/*

[[3,3],[2,3],[0,0],[2,2],[2,1],[3,2],[0,2]]

*/