#include <iostream>
#include <unistd.h>			//use windows.h if using windows as OS and change sleep() to Sleep()
#include <time.h>
using namespace std;
int main()
{
	srand(time(NULL));
	int *gen, *frame, *checksum;
	int size_gen, size_frame, y;
	int i,j;
	
	cout<<"Enter size of the generator (divisor): ";
	cin>>size_gen;
	
	gen=new int[size_gen];
	cout<<"Enter generator: ";
	for(i=0;i<size_gen;i++)
		cin>>gen[i];
	
	cout<<endl;
	cout<<"Enter size of the frame: ";
	cin>>size_frame;
	
	y = size_frame + (size_gen-1);
	
	frame=new int[y];
	cout<<"Enter frame: ";
	for(i=0;i<size_frame;i++)
		cin>>frame[i];
	
	
	for(i=size_frame;i<y;i++)		//Appending 0s
		frame[i]=0;
	
	
	cout<<endl<<endl;
	cout<<"Generator is: ";
	for(i=0;i<size_gen;i++)
		cout<<gen[i];
	
	cout<<endl<<endl;
	cout<<"Frame is: ";
	for(i=0;i<size_frame;i++)
		cout<<frame[i];
	
	
	
	//CHECKSUM CALCULATION
	
	checksum=new int[y];
	for(i=0;i<y;i++)
		checksum[i]=frame[i];	
	
	for(i=0;i<size_frame;i++)
	{
		if(frame[i]==0)
		{
			for(j=0;j<size_gen;j++)
			{
				if(frame[i+j]==0)
					frame[i+j]=0;
				
				else
					frame[i+j]=1;
			}
		}
		else
		{
			for(j=0;j<size_gen;j++)
			{
				if(frame[i+j]==gen[j])
					frame[i+j]=0;
				
				else
					frame[i+j]=1;
			}
		}
	}
	
	for(i=size_frame;i<y;i++)		//Copying last digits
		checksum[i]=frame[i];
		
	
	cout<<endl<<endl;
	cout<<"------------------------------------------------------"<<endl;
	cout<<"SENDING DATA."<<endl<<endl;
	sleep(3);
	cout<<"DATA RECEIVED."<<endl;
	cout<<"------------------------------------------------------";
	cout<<endl<<endl;
	
	
	//INTRODUCING ERROR
	int r=rand()%30;
	cout<<"r: "<<r<<endl;
	for(i=0;i<y;i++)
	{
		if(i==r)
			checksum[i]=!checksum[i];
	}
	
	cout<<"Received checksum: ";
	for(i=0;i<y;i++)
		cout<<checksum[i];
	cout<<endl;
	
	//Checking Checksum at receiver side
	for(i=0;i<size_frame;i++)
	{
		if(checksum[i]==0)
		{
			for(j=0;j<size_gen;j++)
			{
				if(checksum[i+j]==0)
					checksum[i+j]=0;
				
				else
					checksum[i+j]=1;
			}
		}
		else
		{
			for(j=0;j<size_gen;j++)
			{
				if(checksum[i+j]==gen[j])
					checksum[i+j]=0;
				
				else
					checksum[i+j]=1;
			}
		}
	}
	
	int s=0;
	for(i=size_frame;i<y;i++)
		s+=checksum[i];
		
	if(s==0)
		cout<<"No error.";
		
	else
		cout<<"Error!";

return 0;
}
