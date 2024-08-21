#include<bits/stdc++.h>
using namespace std;
int main()
{
   long long n,a,b,c,d,k;
   cin>>n;
   while(cin>>n>>k)
   {
	c=d=0;
	cin>>b;
	for(int i=1;i<n;b=a,i++)
	{
		cin>>a;
		if(2*a>b)c++;
		else c=0;
		d+=(c>=k);
	}
	cout<<d<<endl;
   }
   return 0;
}
