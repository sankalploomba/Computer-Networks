#include <iostream>
#include <time.h>
using namespace std;

int n,w;
int i,k,l;
int z=11;
class frame
{
	public:		unsigned int sno,rno;
				int *a, *b;
				int size;
				bool ack=true;
				bool resend_flag=false, resend_receiver_flag=false;
				unsigned long beg;

				void sender()
				{
					cout<<endl<<"Enter size of the frame: ";
					cin>>size;
					
					a=new int[size];
					
					cout<<"Enter frame: ";
					for(int i=0;i<size;i++)
						cin>>a[i];
						
						
					if(l<w)
						sno=l;
					else
						sno=k%w;
					
					cout<<endl;
					cout<<"Sno: "<<sno<<" Frame: ";
					for(int i=0;i<size;i++)
						cout<<a[i];
						
					beg=(unsigned) clock();
					
					cout<<endl<<endl;
					cout<<"Sending Data."<<endl;
					cout<<"--------------------------------------------";
					cout<<endl<<endl;
					
					ack=false;
				}
				void receiver()
				{
					rno=sno;
					
					b=new int[size];
					for(int i=0;i<size;i++)
						b[i]=a[i];
					
					cout<<endl<<"Data Received in "<<(unsigned)clock()-beg<<"ms"<<endl;
					cout<<endl;
					cout<<"Rno: "<<rno<<" Frame: ";
					for(int i=0;i<size;i++)
						cout<<b[i];
					
					cout<<endl;
					cout<<"********************************************";
					cout<<endl<<endl;
					ack=true;
				}
				void resend()
				{
					cout<<endl;
					cout<<"Sno: "<<sno<<" Frame: ";
					for(int i=0;i<size;i++)
						cout<<a[i];
					
					beg=0;	
					beg=(unsigned) clock();
					
					cout<<endl<<endl;
					cout<<"Re-Sending Data."<<endl;
					cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";
					cout<<endl<<endl;
					
					ack=false;
				}
				unsigned long isOver(unsigned long seconds)
				{
					if(z>10)
					{
						z--;
						return true;
					}
					else
						return(seconds < ((unsigned) clock()-beg)/CLOCKS_PER_SEC);
				}
				void func(unsigned long seconds)
				{
					if(resend_flag==false)
						sender();
					else if(resend_flag==true)
						resend();
						
					if(isOver(seconds))
						func(seconds);
					else
						receiver();
				}
}*f;

int main()
{
	unsigned long seconds=10;
	
	cout<<"Enter the no. frames: ";
	cin>>n;
	
	cout<<"Enter the window size: ";
	cin>>w;
	
	f=new frame[n];
	
	for(i=0,k=w; i<(n-w+1); i++)
	{
		if(i==0)
		{
			for(l=0;l<w;l++)
				if(f[l].ack==true && f[l].sno==f[l].rno)
					f[l].sender();
			
			for(l=0;l<w;l++)
			{
				if(f[l].isOver(seconds))
				{
					for(int j=l;j<w;j++)
						f[j].resend();
					
				}
			}
			for(l=0;l<w;l++)
				f[l].receiver();
		}
		else
		{
			if(f[k].ack==true && f[k].rno==f[k].sno)
				f[k].func(seconds);
			k++;
		}
	}
	
return 0;
}
