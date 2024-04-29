#include<iostream>
using namespace std;
string encrypt(string plain,int key){
    string res="";
    for(int i=0;i<plain.length();i++){
        if(int(toupper(plain[i]))>=65 && int(toupper(plain[i]))<=92){
            if(isupper(plain[i])){
                res+=char((int(plain[i])+key-65)%26 +65);
            }
            else{
                res+=char((int(plain[i])+key-97)%26 +97);
            }
        }
        else{
            res+=plain[i];
        }
    }
    return res;

}
string decrypt(string encrypted,int key){
    string res="";
    for(int i=0;i<encrypted.length();i++){
        if(int(toupper(encrypted[i]))>=65 && int(toupper(encrypted[i]))<=92){
            if(isupper(encrypted[i])){
                res+=char((int(encrypted[i])-key-65+26)%26 +65);
            }
            else{
                res+=char((int(encrypted[i])-key-97+26)%26 +97);
            }
        }
        else{
            res+=encrypted[i];
        }
    }
    return res;

}

int main(){
    string plain,Encrypted;
    int key;
    cout<<"Input the plain text: ";
    getline(cin,plain);
    cout<<"Input the key: ";
    cin>>key;
    Encrypted=encrypt(plain,key);

    cout<<"Encrypted text: "<<Encrypted<<endl;
    cout<<"decrypted text: "<<decrypt(Encrypted,key);
    return 0;

}
