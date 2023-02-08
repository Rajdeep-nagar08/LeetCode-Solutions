/*

either take char from left or take from right

*/

class Solution {
public:
   
    int takeCharacters(string s, int k) {
        
        if(k==0)
            return 0;
        
        int n=s.size();
   
        vector<int>a1(n,0),b1(n,0),c1(n,0);
        
        int mn=n+1;
        
        a1[0]=s[0]=='a'?1:0;
        b1[0]=s[0]=='b'?1:0;
        c1[0]=s[0]=='c'?1:0;
        
        
        for(int i=1;i<n;i++){
             a1[i]+=a1[i-1];
            b1[i]+=b1[i-1];
            c1[i]+=c1[i-1];
            if(s[i]=='a'){
                a1[i]+=1;
            }
            else if(s[i]=='b'){
                b1[i]+=1;
            }
            else{
                c1[i]+=1;
            }
            
            if(a1[i]>=k && b1[i]>=k && c1[i]>=k)
                mn=min(mn,i+1);
        }
        
        
        
        vector<int>a2(n,0),b2(n,0),c2(n,0);
                
        a2[n-1]=s[n-1]=='a'?1:0;
        b2[n-1]=s[n-1]=='b'?1:0;
        c2[n-1]=s[n-1]=='c'?1:0;
        
        
        for(int i=n-2;i>=0;i--){
            a2[i]+=a2[i+1];
            b2[i]+=b2[i+1];
            c2[i]+=c2[i+1];
            if(s[i]=='a'){
                a2[i]+=1;
            }
            else if(s[i]=='b'){
                b2[i]+=1;
            }
            else{
                c2[i]+=1;
            }
            
            if(a2[i]>=k && b2[i]>=k && c2[i]>=k)
                mn=min(mn,n-i);
        }
        
        reverse(a2.begin(),a2.end());
        
        reverse(b2.begin(),b2.end());
        
        reverse(c2.begin(),c2.end());
        
        for(int i=0;i<n;i++){
            
            int aNeed=max(0,k-a1[i]);
            
            int j1=lower_bound(a2.begin(),a2.end(),aNeed)-a2.begin();
            
            int bNeed=max(0,k-b1[i]);
            
            int k1=lower_bound(b2.begin(),b2.end(),bNeed)-b2.begin();

            int j=max(j1,k1);
            
            int cNeed=max(0,k-c1[i]);
            
            int l=lower_bound(c2.begin(),c2.end(),cNeed)-c2.begin();

//             cout<<aNeed<<" "<<bNeed<<" "<<cNeed<<endl;
            
//             cout<<i<<" "<<j1<<" "<<k1<<" "<<l<<endl;
            
            j=max(j,l);
            
            int j2=n-j;
            
            if(i<j2){
                mn=min(mn,i+j+2);
            }
            
        }
        if(mn==n+1)
            return -1;
        
        return mn;
    }
};