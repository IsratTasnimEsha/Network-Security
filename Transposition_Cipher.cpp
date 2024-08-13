// Bismillahir Rahmanir Rahim

#include<bits/stdc++.h>
using namespace std;

int main()
{
    string msg, key;
    //cin>>msg>>key;
    msg="GIVEMESOMEFOOD";
    key="MONEY";

    int row, col;
    col=key.size();
    if(msg.size()%key.size()==0) row=msg.size()/key.size();
    else row=msg.size()/key.size()+1;
    //cout<<row<<" "<<col<<endl;
    for(int i=0; i<row*col-msg.size(); i++) msg+='*';
    //cout<<msg;
    
    cout<<"Table:"<<endl;
    char m[100][100];
    int l=0;
    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {
            m[i][j]=msg[l++];
            cout<<m[i][j];
        }
        cout<<endl;
    }

    cout<<endl<<"Key:"<<endl;   
    map<char, int>mp;
    for(int i=0; i<col; i++)mp[key[i]]=i;
    l=0;
    int ky[100];
    char kya[100];
    for(auto i: mp) {
        cout<<i.first<<" "<<i.second<<endl;
        kya[l]=i.first;
        ky[l]=i.second;
        l++;
    }

    cout<<endl<<"Encrypted:"<<endl;
    char en[100][100];
    for(int i=0; i<col; i++) {
        for(int j=0; j<row; j++) {
            en[i][j]=m[j][ky[i]];
            cout<<en[i][j];
        }
        cout<<endl;
    }

    cout<<endl<<"Serial w.r.t map:"<<endl;
    int main[100];
    for(int i=0; i<col; i++) {
        for(int j=0; j<col; j++) {
            if(key[i] == kya[j]) {
                main[i]=j;
                cout<<kya[j]<<" "<<main[i]<<endl;
            }
        }
    }

    cout<<endl<<endl<<"Decrypted:"<<endl;
    for(int i=0; i<col; i++) {
        for(int j=0; j<row; j++) {
            cout<<en[main[i]][j];
        }
        cout<<endl;
    }
}