// Bismillahir Rahmanir Rahim

#include<bits/stdc++.h>
using namespace std;

int main() {
    string s="1234567890qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM";
    int k=3;
    for(int i=0; i<s.size(); i++) {
        if(s[i]>='a' && s[i]<='z') s[i]='a'+char((s[i]-'a'+k)%26);
        else if(s[i]>='A' && s[i]<='Z') s[i]='A'+char((s[i]-'A'+k)%26);
        else if(s[i]>='0' && s[i]<='9') s[i]='0'+char((s[i]-'0'+k)%10);
        else;
    }
    cout<<"Encrypted: "<<s<<endl;
    for(int i=0; i<s.size(); i++) {
        if(s[i]>='a' && s[i]<='z') s[i]='a'+char((s[i]-'a'-k+26)%26);
        else if(s[i]>='A' && s[i]<='Z') s[i]='A'+char((s[i]-'A'-k+26)%26);
        else if(s[i]>='0' && s[i]<='9') s[i]='0'+char((s[i]-'0'-k+10)%10);
        else;
    }
    cout<<"Decrypted: "<<s;
}