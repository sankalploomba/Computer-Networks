#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	int m,r,n;
	cout<<"Enter the size of the dataword (m): ";
	cin>>m;
	
	for(r=1;;r++)
	{
		if((m+r+1)<=pow(2,r))
			break;
	}
	cout<<"r: "<<r<<endl;
	n=m+r;

	int ar[r+1];
	int d[m+1];
	int c[n+1];

	int i,j,k,l,x;

	cout<<"Enter the dataword (d): ";
	for(i=1;i<=m;i++)
		cin>>d[i];

	cout<<endl;


	//CODEWORD ASSIGNMENT (Initial)
	for(i=1,j=0,k=1;i<=m;k++)
	{
		if(k==pow(2,j))
		{
			c[k]=9;
			j++;
		}
		else
		{
			c[k]=d[i];
			i++;
		}
	}

	cout<<"Codeword is (c): ";
	for(i=1;i<=n;i++)
		cout<<c[i];
	cout<<endl;

	//CALCULATION OF THE CHECK-BITS
	for(i=1,j=0;i<=n;i++)
	{
		
		if(i==pow(2,j))	
		{
			j++;
			
			for(k=0, l=pow(2,j-1), x=i; x<=n; k++)
			{	
				ar[k]=x;
				
				if(l==1)
				{
					if(x%l==l-1)
						x=x+pow(2,j);
					else
						x++;
				}
				else
				{
					if(x%l==l-1)
						x=x+pow(2,j)-1;
		
					else
						x++;				
				}
			}
			r=0;
			for(int y=1; y<k; y++)
				r^=c[ar[y]];
			
			cout<<"r: "<<r<<endl;
			for(int e=1;e<=n;e++)
			{
				if(c[e]==9)
				{
					c[e]=r;
					break;
				}
			}
		}
		
	}

	cout<<"Updated Codeword is (c): ";
	for(int i=1;i<=n;i++)
		cout<<c[i];
	cout<<endl;


return 0;
}
