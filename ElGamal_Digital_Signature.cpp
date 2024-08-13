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

int main() {
    cpp_int p=23;
    cpp_int alp=5;
    cpp_int a=6;
    cpp_int m=9;
    cpp_int k=7;

    cpp_int beta=power(alp,a,p);

    cpp_int y1=power(alp,k,p);
    cpp_int k_inv=mod_inv(k,p-1);
    cpp_int y2=(k_inv*(m-a*y1))%(p-1);
    if(y2<0) y2+=p-1;
    cout<<"y1: "<<y1<<endl;
    cout<<"y2: "<<y2<<endl;

    cpp_int v1=power(beta,y1,p);
    cpp_int v2=power(y1,y2,p);
    cout<<"v1: "<<v1<<endl;
    cout<<"v2: "<<v2<<endl;

    cpp_int v=(v1*v2)%p;
    cpp_int h=power(alp,m,p);
    cout<<"v: "<<v<<endl;
    cout<<"h: "<<h<<endl;

    if(v==h) cout<<"valid"<<endl;
    else cout<<"invalid"<<endl;
}
