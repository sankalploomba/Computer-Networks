#include <iostream>
#include <unistd.h>				//use windows.h if using windows as OS and change sleep() to Sleep()
#include <time.h>
using namespace std;
int main()
{
	int i;
	srand(time(NULL));
	int size;
	cout<<"Enter size of dataword: ";
	cin>>size;
	
	int d[size];
	int c[size+1];
	
	cout<<"Enter the dataword: ";
	for(i=0;i<size;i++)
	{
		cin>>d[i];
		c[i]=d[i];
	}
	
	int bit=0;
	cout<<"The dataword is: ";
	for(i=0;i<size;i++)
	{
		cout<<d[i];
		bit^=d[i];	
	}
	c[i]=bit;
	cout<<endl<<endl;
	
	
	cout<<"The codeword is: ";
	for(i=0;i<size+1;i++)
		cout<<c[i];
	
	
	cout<<endl<<endl;
	cout<<"------------------------------------------------------------";
	cout<<endl<<"Sending Data."<<endl;
	sleep(3);
	cout<<endl<<"Data Received."<<endl;
	cout<<"------------------------------------------------------------";
	cout<<endl<<endl;
	
	int r=rand()%size;
	for(i=0;i<size;i++)
		if(i==r)
			c[i]=!c[i];
	
	cout<<"Codeword received: ";
	for(i=0;i<size;i++)
	{
		cout<<c[i];
		bit^=c[i];	
	}
	cout<<c[i]<<endl<<endl;
	
	if(c[i]!=bit)
		cout<<"Error!";
	else
		cout<<"No error.";

return 0;
}
