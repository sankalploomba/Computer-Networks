#include <iostream>
#include <time.h>
using namespace std;
int n,w;				//n=no. of frames	w=window size
int i,j,k,l;			//i,j,k,l are iterators
int z=11;
class frame
{
	public:		unsigned int sno,rno;
				int *a, *b;
				int size;
				bool ack=true;
				bool resend_receiver_flag=false, resend_flag=false;
				unsigned long beg;
				
				void sender()
				{
					
					if(l<w)
						sno=l;
					else
						sno=k%w;
					
					cout<<endl<<endl;
					cout<<"Enter the size of the frame: ";
					cin>>size;
					
					a=new int[size];
					cout<<"Enter the frame: ";
					for(int i=0;i<size;i++)
						cin>>a[i];
					
					cout<<"Sno: "<<sno<<" Frame: ";
					for(int i=0;i<size;i++)
						cout<<a[i];
					
					beg=(unsigned) clock();
					
					cout<<endl<<endl;
					cout<<"Sending data."<<endl;
					cout<<"---------------------------------------------";
					cout<<endl<<endl;
					
					ack=false;
				}
				
				void receiver()
				{
					rno=sno;
					b=new int[size];
					
					for(int i=0;i<size;i++)
						b[i]=a[i];
					
					cout<<endl<<endl;
					
					cout<<"Data Received in "<<((unsigned)clock()-beg)<<"ms"<<endl<<endl;
					cout<<"Rno: "<<rno<<" Frame: ";
					for(int i=0;i<size;i++)
						cout<<a[i];
					
					cout<<endl;
					cout<<"****************************************";
					cout<<endl<<endl;
					
					ack=true;
				}
				
				void resend()
				{
					cout<<endl<<endl;
					cout<<"Sno: "<<sno<<" Frame: ";
					for(int i=0;i<size;i++)
						cout<<a[i];
					
					beg=0;
					beg=(unsigned) clock();
					
					cout<<endl<<endl;
					cout<<"RE-Sending data."<<endl;
					cout<<"---------------------------------------------";
					cout<<endl<<endl;
					
					ack=false;
				}
				
				unsigned long isOver(unsigned long seconds)
				{
					if(z>10)				//TO INTRODUCE ERROR AND CHECK RESENDING
					{
						z--;
						return true;
					}
					else
						return (seconds < ((unsigned)clock()-beg)/CLOCKS_PER_SEC);
				}
			
				void func(unsigned int seconds)
				{
					if(resend_flag==false)
						sender();
					
					else if(resend_flag==true)
						resend();
						
					if(isOver(seconds))
					{
						resend_flag=true;
						func(seconds);
					}
					else
						receiver();
				}
}*f;
int main()
{
	unsigned int seconds=10;
	
	cout<<"Enter no. of frames: ";
	cin>>n;
	
	cout<<"Enter window size: ";
	cin>>w;
	
	f=new frame[n];
	
	for(i=0,k=w; i<(n-w+1); i++)
	{
		if(i==0)
		{
			for(l=0;l<w;l++)
				if(f[l].ack==true && f[l].rno==f[l].sno)
					f[l].sender();
			
			for(l=0;l<w;l++)
			{
				if(f[l].isOver(seconds))
				{
					cout<<"if isover: "<<l<<endl;
					f[l].resend();
					f[l].resend_receiver_flag=true;
				}
				else
					f[l].receiver();
			}
			
			for(l=0;l<w;l++)
				if(f[l].resend_receiver_flag==true)
					f[l].receiver();
					
		}
		else
		{
			if(f[k].ack==true && f[k].sno==f[k].rno)
				f[k].func(seconds);
			k++;
		}
	}

return 0;
}
