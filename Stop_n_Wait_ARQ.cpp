#include <iostream>
#include <time.h>
#include <unistd.h>			//use windows.h if using windows as OS and change sleep() to Sleep()
using namespace std;
int f,r,k;
unsigned int rno,sno;
int *a, *b;
int z=11;
bool ack=true;

class timer
{
	private:	bool resetted;
				bool running;
				float beg; 
				float end;
					
	public:		timer()
				{
					resetted=true;
					running=false;
					beg=0; 
					end=0;
				}
				void start()
				{
					if(!running)
					{
						if(resetted)
							beg= (unsigned long) clock();
						else
							beg -= end - (unsigned long) clock();
						
						running=true;
						resetted=false;
					}
				}
				
				void stop()
				{
					if(!running)
					{
						end=(unsigned long) clock();
						running=false;
					}
				}
				
				void reset()
				{
					bool wereRunning=running;
					if(wereRunning)
						stop();
					
					resetted=true;
					beg=0;
					end=0;
					
					if(wereRunning)
						start();
				}
				/*
				bool isRunning()
				{
					return running;
				}
				*/
				unsigned long getTime()
				{
										
					if(running)
					{	
						//cout<<"z: "<<z<<endl;
						//return z--;
						return ((unsigned long)clock() - beg)/CLOCKS_PER_SEC;
					}
					else
					{
						cout<<"TWO"<<endl<<(end - beg)/CLOCKS_PER_SEC<<endl;
						return (end - beg)/CLOCKS_PER_SEC;
					}
				}
				
				bool isOver(unsigned long seconds)
				{
					return seconds<getTime();
				}
};
timer t;

void sender()
{
		cout<<"\n---------------------------------------------------------------\n";
		cout<<"\nEnter the SIZE of FRAME: ";
		cin>>r;
		
		a=new int[r];
		sno=k%2; 
		
		cout<<"\nEnter the FRAME: ";
		for(int i=0;i<r;i++)
			cin>>a[i];
			
		cout<<"Sno: "<<sno;
		cout<<" The FRAME is: ";
		for(int i=0;i<r;i++)
			cout<<a[i];
		
		cout<<endl;

		cout<<endl<<endl<<"***********************************************************"<<endl;
		cout<<"SENDING DATA...";
		
		cout<<"\n***********************************************************"<<endl;
		ack=false;
}

void receiver()
{
		b=new int[r];

		rno=sno;
			
		for(int i=0;i<r;i++)
		b[i]=a[i];
		
		cout<<"DATA RECEIVED."<<endl;
		cout<<"***********************************************************"<<endl;
	
		cout<<"Rno: "<<rno;
		cout<<" RECEIVED DATA IS: ";
		for(int i=0;i<r;i++)
			cout<<b[i];
		
		cout<<endl<<endl;
		ack=true;
}

void resend()
{
	cout<<"Sno: "<<sno;
	cout<<" The FRAME is: ";
	for(int i=0;i<r;i++)
		cout<<a[i];
	
	cout<<endl;

	cout<<endl<<endl<<"***********************************************************"<<endl;
	cout<<"RE-SENDING DATA...";
	
	cout<<"\n***********************************************************"<<endl;

}

void func(unsigned long seconds)
{
	sender();
	sleep(1);
				
	if(t.isOver(seconds))
	{
		t.reset();
		resend();
	}
	else
		receiver();
}

int main()
{
	unsigned long seconds=10;
	
	cout<<"\nEnter number of FRAMES: ";
	cin>>f;
	
	for(k=0;k<f;k++)
	{
		//cout<<"k: "<<i<<endl<<endl;
		t.start();
		if(ack==true && rno==sno%2)
			func(seconds);
		
		else if(ack==false && rno==sno%2)
		{
			receiver();
			k--;
		}	
		else
			cout<<"empty iteration."<<endl;
	}

return 0;
}
