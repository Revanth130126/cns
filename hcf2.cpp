#include<bits/stdc++.h>
using namespace std;
float a[2][2],c[2][2],encrypt[2],decrypt[2],mes[2];
string enc="";
string decr="";
void encryption();
void decryption();
void inverse();
void getInput()
{
	string msg;
	cout<<"enter message:"<<endl;
	cin>>msg;
	cout<<"Enter key matrix:"<<endl;
	for(int i=0;i<2;i++)
	 for(int j=0;j<2;j++)
	 {
	 	cin>>a[i][j];
	 	c[i][j]=a[i][j];
	 }
	 inverse();
	 enc="";
	 decr="";
	 for(int i=0;i<msg.length();i++)
	 {
	 	mes[i%2]=msg[i]-97;
	 	if(i%2)
	 	{
	 		encryption();
	 		decryption();
		}
	 }
}
void inverse()
{
	c[0][1]=-1*c[0][1];
	c[1][0]=-1*c[1][0];
	float temp;
	temp=c[1][1];
	c[1][1]=c[0][0];
	c[0][0]=temp;
	temp=(a[0][0]*a[1][1])-(a[0][1]*a[1][0]);
	for(int i=0;i<2;i++)
	 for(int j=0;j<2;j++)
	   c[i][j]=c[i][j]/temp;
}
void encryption()
{
	for(int i=0;i<2;i++)
	  encrypt[i]=0;
	for(int i=0;i<2;i++)
	  for(int k=0;k<2;k++)
	   encrypt[i]=encrypt[i]+a[i][k]*mes[k];
	cout<<"Encrypted string:\n";
	for(int i=0;i<2;i++)
	{
		char ch=(char)(fmod(encrypt[i],26)+97);
		cout<<ch;
		enc+=ch;
	}
	cout<<endl;
}
void decryption()
{
	for(int i=0;i<2;i++)
	  decrypt[i]=0;
	for(int i=0;i<2;i++)
	  for(int k=0;k<2;k++)
	   decrypt[i]=decrypt[i]+c[i][k]*encrypt[k%2];
	cout<<"Encrypted string:\n";
	for(int i=0;i<2;i++)
	{
		char ch=(char)(fmod(decrypt[i],26)+97);
		cout<<ch;
		decr+=ch;
	}
	cout<<endl;
}
int main()
{
	getInput();
	cout<<"Encrypted msg:"<<enc<<endl;
	cout<<"Decrypted msg:"<<decr<<endl;
}
