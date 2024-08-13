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

cpp_int mod_inv(cpp_int a, cpp_int m) {
    cpp_int org_m=m;
    cpp_int y=0, x=1;

    if(m==1) return 1;

    while(a>1) {
        cpp_int q=a/m;
        cpp_int temp=m;

        m=a%m;
        a=temp;
        temp=y;

        y=x-q*y;
        x=temp;
    }

    if(x<0) x+=org_m;
    return x;
}

int main() {
    cpp_int e=10000019, n=20000900009, m=20000000000;
    cpp_int c=power(m,e,n);
    cpp_int d=6283524500;
    while(1) {
        if(power(c,d,n)==m) break;
        else d++;
    }
    cout<<d<<endl;
}
