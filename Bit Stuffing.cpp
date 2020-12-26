#include <iostream>
using namespace std;
int main()
{
	string s;
	cout<<"Enter the string of bits: ";
	getline(cin,s);
	
	int i,size=0;
	
	for(i=0;s[i]!='\0';i++)
	{
		if(s[i]!='0' && s[i]!='1')
		{
			cout<<"Invalid input!";
			exit(99);
		}
		size++;
	}
	
	for(i=0; s[i]!='\0'; i++)
	{
		if(s[i]=='0' && s[i+1]=='1' && s[i+2]=='1' && s[i+3]=='1' && s[i+4]=='1' && s[i+5]=='1')
		{
			s.insert((i+6),"0");
			i=i+6;
		}
	}
	int x=i-size;
	cout<<endl<<"Stuffed String: "<<s<<endl;
	cout<<"No. of bits stuffed: "<<x<<endl;
	
	for(i=0; s[i]!='\0'; i++)
	{
		if(s[i]=='0' && s[i+1]=='1' && s[i+2]=='1' && s[i+3]=='1' && s[i+4]=='1' && s[i+5]=='1')
		{
			s.erase((i+6),1);
		}
	}
	
	cout<<endl<<"De-Stuffed String: "<<s<<endl;
	cout<<"No. of bits de-stuffed: "<<x<<endl;
	
return 0;
}
