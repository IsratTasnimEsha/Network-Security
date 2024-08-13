// Bismillahir Rahmanir Rahim

#include<bits/stdc++.h>
#include<boost/multiprecision/cpp_int.hpp>

using namespace std;
using namespace boost::multiprecision;

cpp_int power(cpp_int b, cpp_int p, cpp_int m) {
    b=b%m;
    if(p==0) return 1;

    cpp_int j=power(b, p/2, m);
    j=(j*j)%m;

    if(p%2==1) j=(j*b)%m;
    return j;
}

cpp_int mod_inv(cpp_int a, cpp_int m)
{
    cpp_int origin_m=m;
    cpp_int y=0, x=1;

    if(m==1) return 0;

    while(a>1){
        cpp_int q=a/m;
        cpp_int temp=m;

        m=a%m;
        a=temp;
        temp=y;

        y=x-q*y;
        x=temp;
    }

    if(x<0) x+=origin_m;
    return x;
}

cpp_int gcd(cpp_int a, cpp_int b){
    if(b==0) return a;
    else return gcd(b, a%b);
}

int main() {
    cpp_int p=11, q=13;
    cpp_int n=p*q;
    cpp_int phi=(p-1)*(q-1);
    cpp_int e=9;
    while(e<phi) {
        if(gcd(e, phi)==1) break;
        else e++;
    }
    cout<<"e: "<<e<<endl;
    cpp_int d=mod_inv(e,phi);
    cout<<"d: "<<d<<endl;
    cpp_int ms=6;
    cpp_int c=power(ms,e,n);
    cout<<c<<endl;
    cpp_int m=power(c,d,n);
    cout<<m<<endl;
}