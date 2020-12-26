//Input IP Address, Outputs Dotted Decimal IP Address and Class of IP Address
#include <iostream>
#include <bitset>
using namespace std;
int main()
{
	unsigned int ip[4];
	cout<<"Enter the IP Address: ";
	for(int i=0;i<4;i++)
	{
		cin>>ip[i];
		
		if(ip[i]>256)
		{
			cout<<"Invalid Input! Program will exit now.";
			exit(99);
		}
	}
	
	cout<<"Dotted Decimal: ";
	for(int i=0;i<4;i++)
	{
		cout<<bitset<8> (ip[i]);
		
		if(i!=3)
			cout<<".";
	}
	cout<<endl;
	
	if(ip[0]<128)
		cout<<"Class A";
		
	else if(ip[0]>=128 && ip[0]<192)
		cout<<"Class B";
		
	else if(ip[0]>=192 && ip[0]<224)
		cout<<"Class C";
		
	else if(ip[0]>=224 && ip[0]<240)
		cout<<"Class D";
		
	else
		cout<<"Class E";
	
return 0;		
}
