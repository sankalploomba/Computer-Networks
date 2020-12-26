#include <iostream>
#include <bitset>
using namespace std;
int main()
{
	int i;
	int* a=new int[4];
	
	cout<<"Enter the IP Address: ";
	for(i=0;i<4;i++)
		cin>>a[i];
		
	cout<<"Inputted IP Address is : ";
	for(i=0;i<4;i++)
	{
		cout<<a[i];
		
		if(i!=3)
			cout<<".";
	}	
	cout<<endl;
	
	cout<<"Dotted Binary of the inputted IP Address is: ";
	for(i=0;i<4;i++)
	{
		cout<< bitset<8> (a[i]);
		
		if(i!=3)
			cout<<".";		
	}
	
return 0;
}
