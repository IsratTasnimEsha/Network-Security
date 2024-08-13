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
    cpp_int p("212559481678916012965440078089");
    cpp_int g=2;
    cpp_int x=5;
    cpp_int y=5;
    cpp_int m=121;
    cpp_int h=power(g,x,p);
    cpp_int s=power(h,y,p);
    cpp_int c1=power(g,y,p);
    cpp_int c2=(m*s)%p;
    cout<<"c1: "<<c1<<endl;
    cout<<"c2: "<<c2<<endl;
    cpp_int cur=power(c1,x,p);
    cpp_int temp=mod_inv(cur,p);
    cpp_int ans=(c2*temp)%p;
    cout<<"decrypted: "<<ans<<endl;
}