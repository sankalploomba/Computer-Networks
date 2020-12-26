#include <iostream>
#include <time.h>
using namespace std;

int n;
int i,j,k,l;
int z=11;
class frame
{
	public:		unsigned int sno,rno;
				int *a, *b;
				int size;
				bool ack=true, resend_flag=false;
				unsigned long beg;
				
				void sender()
				{
					sno=k%2;
					
					cout<<"Enter size: ";
					cin>>size;
					
					a=new int[size];
					
					cout<<"Enter the frame: ";
					for(int i=0;i<size;i++)
						cin>>a[i];
					
					
					 cout<<endl;
					 cout<<"Sno: "<<sno<<" Frame: ";
					 for(int i=0;i<size;i++)
						cout<<a[i];
					
					
					 beg=(unsigned) clock();
					 
					cout<<endl<<endl;
					cout<<"Sending Data."<<endl;
					cout<<"--------------------------------------------";
					cout<<endl<<endl;
				}
				void receiver()
				{
					rno=sno;
					
					b=new int[size];
					
					for(int i=0;i<size;i++)
						b[i]=a[i];
					
					cout<<"Data Received in "<<(unsigned) clock()-beg<<"ms"<<endl;
					
					cout<<endl;
					cout<<"Rno: "<<rno<<" Frame: ";
					for(int i=0;i<size;i++)
						cout<<b[i];
					
					cout<<endl;
					cout<<"********************************************";
					cout<<endl<<endl;
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
				}
				unsigned long isOver(unsigned long seconds)
				{
					if(z>10)
					{
						z--;
						return true;
					}
					else
						return (seconds < ((unsigned) clock()-beg)/CLOCKS_PER_SEC);
				}
				void func(unsigned long seconds)
				{
					if(resend_flag==false)
						sender();
					else
						resend();
				
					
					if(isOver(seconds))
					{
						cout<<"TIMED OUT!"<<endl;
						resend_flag=true;
						func(seconds);
					}
					else
						receiver();
				}
}*f;
int main()
{
	unsigned long seconds=10;
	cout<<"Enter the no. of frames: ";
	cin>>n;
	
	f=new frame[n];
	
	for(k=0;k<n;k++)
		f[k].func(seconds);

return 0;		
}
