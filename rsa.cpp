#include<bits/stdc++.h>
using namespace std;
int gcd(int a, int h){
	int temp;
	while(1){
		temp=a%h;
		if(temp==0){
			return h;
		}
		a=h;
		h=temp;
	}
}
int main(){
	float p,q;
	p=3;
	q=7;
	float n=p*q;
	float pi=(p-1)*(q-1);
	float enc=2;
	while(enc<pi){
		if(gcd(enc,pi)==1){
			break;
		}
		else
			enc++;
	}
	int k=2;
	float dec=(1+(k*pi))/enc;
	float msg=12;
	float c=fmod(pow(msg,enc),n);
	float d=fmod(pow(c,dec),n);
	cout<<"Cipher text: "<<c<<endl;
	cout<<"Plain text after decrypting: "<<d<<endl;
	return 0;
}
