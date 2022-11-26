//Just Like Mob :

#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    unsigned long long n,m,k,x;
	    cin>>n>>m>>k>>x;
	    unsigned long long cm = n + m, cn = (k-1)*n;
	    x= x%(cm+cn);
	    if(x==0 || x>cn)
	        cout<<"YES"<<endl;
	    else
	        cout<<"NO"<<endl;

	}
	return 0;
}
