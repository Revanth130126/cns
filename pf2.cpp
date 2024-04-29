#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

#define SIZE 5

char keyTable[SIZE][SIZE];
int row1, row2, col1, col2;

void generateKeyTable(string key)
{
    int i = 0, k = 0;
    char vis[26] = {0};
    for (i = 0; i<key.length(); i++)
    {
        if (vis[key[i] - 'A'] == 0 && key[i] != 'J')
        {
keyTable[k / SIZE][k % SIZE] = key[i];
            vis[key[i] - 'A'] = 1;
            k++;
        }
    }
    char ch = 'A';
    for (int i = k; i< 25; i++)
    {
        while (vis[ch - 'A'] == 1 || ch == 'J')
ch++;
keyTable[k / SIZE][k % SIZE] = ch;
vis[ch - 'A'] = 1;
ch++;
        k++;
    }




cout<< "Key Table:" <<endl;
    for (i = 0; i< SIZE; i++)
    {
        int j;
        for (j = 0; j < SIZE; j++)
        {
            if (keyTable[i][j] == 'I')
cout<< "J/";
cout<<keyTable[i][j] << " ";
        }
cout<<endl;
    }
}

void findPosition(char &ch, int &row, int &col)
{
    if (ch == 'J')
ch = 'I';
    int i;
    for (i = 0; i< SIZE; i++)
    {
        int j;
        for (j = 0; j < SIZE; j++)
        {
            if (keyTable[i][j] == ch)
            {
                row = i;
                col = j;
                return;
            }
        }
    }
}






string encrypt(string plaintext){
    int len = plaintext.length(), i;
    string ciphertext;

    if (plaintext.length() % 2 != 0)
        plaintext += 'X';

    for (i = 0; i<len; i += 2)
    {
        char ch1 = plaintext[i];
        char ch2 = plaintext[i + 1];

        if (ch1 == ch2)
        {
            ch2 = 'X';
i--;
        }

findPosition(ch1, row1, col1);
findPosition(ch2, row2, col2);

        if (row1 == row2)
        {
            ciphertext += keyTable[row1][(col1 + 1) % SIZE];
            ciphertext += keyTable[row2][(col2 + 1) % SIZE];
        }

        else if (col1 == col2)
        {
            ciphertext += keyTable[(row1 + 1) % SIZE][col1];
            ciphertext += keyTable[(row2 + 1) % SIZE][col2];
        }

        else
        {
            ciphertext += keyTable[row1][col2];
            ciphertext += keyTable[row2][col1];
        }
    }
cout<< "Encrypted Text:" << ciphertext <<endl;
    return ciphertext;
}

string decrypt(string &ciphertext){
    int len = ciphertext.length(), i;
    string plaintext;

    for (i = 0; i<len; i += 2)
    {
        char ch1 = ciphertext[i];
        char ch2 = ciphertext[i + 1];

findPosition(ch1, row1, col1);
findPosition(ch2, row2, col2);

        if (row1 == row2)
        {
            plaintext += keyTable[row1][(col1 + SIZE - 1) % SIZE];
            plaintext += keyTable[row2][(col2 + SIZE - 1) % SIZE];
        }

        else if (col1 == col2)
        {
            plaintext += keyTable[(row1 + SIZE - 1) % SIZE][col1];
            plaintext += keyTable[(row2 + SIZE - 1) % SIZE][col2];
        }

        else
        {
            plaintext += keyTable[row1][col2];
            plaintext += keyTable[row2][col1];
        }
    }
plaintext.erase(remove(plaintext.begin(), plaintext.end(), 'X'), plaintext.end());
cout<< "Decrypted Text:" << plaintext <<endl;
    return plaintext;
}
int main()
{
    string key, plaintext;

cout<< "Enter the key (in uppercase):" <<endl;
cin>> key;

generateKeyTable(key);

cout<< "Enter the plaintext (in uppercase):" <<endl;
cin>> plaintext;

    string ciphertext = encrypt(plaintext);

    decrypt(ciphertext);
}
