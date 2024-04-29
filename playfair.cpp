#include<bits/stdc++.h>
using namespace std;
#define MAX 30

void generateKeytable(char key[],int ks,char keyT[5][5]){
	int i,j,k;
	int dicty[26]={0};
	for(i=0;i<ks;i++){
		if(key[i]!='j'){
			dicty[key[i]-97]=2;
		}
	}
	dicty['j'-97]=1;
	i=0;
	j=0;
	for(k=0;k<ks;k++){
		if(dicty[key[k]-97]==2){
			
			keyT[i][j]=key[k];
			j++;
			if(j==5){
				i++;
				j=0;
			}
		}
	}
	for(k=0;k<26;k++){
		if(dicty[k]==0){
			keyT[i][j]=(char)(k+97);
			j++;
			if(j==5){
				i+=1;
				j=0;
			}
		}
	}
}

void search(char keyT[5][5],char a,char b,int arr[4]){
	int i,j;
	if (a=='j'){
		a='i';
	}
	else if (b=='j'){
		b='i';
	}
	
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			if(keyT[i][j]==a){
				arr[0]=i;
				arr[1]=j;
			}
			else if(keyT[i][j]==b){
				arr[2]=i;
				arr[3]=j;
			}
		}
	}
}

char encrypt(char plain[],char keyT[5][5],int ps){
	int i,a[4];
	for(i=0;i<ps;i+=2){
		search(keyT,plain[i],plain[i+1],a);
		if(a[0]==a[2]){
			plain[i]=keyT[a[0]][(a[1]+1)%5];
			plain[i+1]=keyT[a[0]][(a[3]+1)%5];
		}
		else if(a[1]==a[3]){
			plain[i]=keyT[(a[1]+1)%5][a[1]];
			plain[i+1]=keyT[(a[3]+1)%5][a[1]];
		}
		else{
			plain[i]=keyT[a[0]][a[3]];
			plain[i+1]=keyT[a[2]][a[1]];
		}
	}
}

char decrpyt(char cipher[],char keyT[5][5],int ps){
	int i,a[4];
	for(i=0;i<ps;i+=2){
		search(keyT,cipher[i],cipher[i+1],a);
		if(a[0]==a[2]){
			cipher[i]=keyT[a[0]][(a[1]-1+5)%5];
			cipher[i+1]=keyT[a[0]][(a[3]-1+5)%5];
		}
		else if(a[1]==a[3]){
			cipher[i]=keyT[(a[0]-1+5)%5][a[1]];
			cipher[i+1]=keyT[(a[2]-1+5)%5][a[1]];
		}
		else{
			cipher[i]=keyT[a[0]][a[3]];
			cipher[i+1]=keyT[a[2]][a[1]];
		}
	}
}
int main(){
	char plain[MAX],key[MAX];
	cout<<"Input the plain text: ";
	cin>>plain;
	cout<<"Input the key: ";
	cin>>key;
	int ks=strlen(key);
	if(strlen(plain)%2!=0){
		int l=strlen(plain);
		plain[l++]='z';
		plain[l]='\0';
	} 
	
	int ps=strlen(plain);
	
	char keyT[5][5];
	generateKeytable(key,ks,keyT);
	encrypt(plain,keyT,ps);
	cout<<"Encrypted plain text: "<<plain<<endl;
	ps=strlen(plain);
	decrpyt(plain,keyT,ps);
	cout<<"decrypted cipher text: "<<plain<<endl;
	return 0;
	
}
