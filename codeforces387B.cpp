#include<iostream>

#define ll long long
using namespace std;
int main()
{
    ll n,m,x,i,j,cnt,ans=0;
    while(cin>>n>>m)
    {
        ll *a = new ll[n+1];
        ll *b = new ll[m+1];
        
        for(i=0;i<n;i++)
            cin>>a[i]; 
        for(j=0;j<m;j++)
            cin>>b[j];
        j=0;cnt=0;
        for(i=0;i<n;i++){
            while(j<m){
                if(b[j]>=a[i])
                {
                    cnt++;
                    i++;
                }
                j++;
            }
        }
        cout<<max(ans,n-cnt)<<endl;
    }
    return 0;
}