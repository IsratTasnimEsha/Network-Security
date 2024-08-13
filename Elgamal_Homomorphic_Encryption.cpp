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
    cpp_int p("100003100019100043100057100069");
    cpp_int g = 2;
    cpp_int y1 = 5;
    cpp_int y2 = 5;
    cpp_int x = 2;
    cpp_int m1=234;
    cpp_int m2=121;
    
    cpp_int h=power(g,x,p);
    
    cpp_int s1=power(h,y1,p);
    cpp_int s2=power(h,y2,p);
    cpp_int s=power(h, y1+y2, p);
    
    cpp_int c1_1=power(g,y1,p);
    cpp_int c1_2=(m1*s1)%p;
    cout<<"(c1_1,c1_2): ("<<c1_1<<","<<c1_2<<")"<<endl;
    
    cpp_int c2_1=power(g,y2,p);
    cpp_int c2_2=(m2*s2)%p;
    cout<<"(c2_1,c2_2): ("<<c2_1<<","<<c2_2<<")"<<endl;
    
    cpp_int c1=(c1_1*c2_1)%p;
    cpp_int c2=((m1*m2)*s)%p;
    cout<<"(c1,c2): ("<<c1<<","<<c2<<")"<<endl;
    
    cpp_int cur1=power(c1_1,x,p);
    cpp_int temp1=mod_inv(cur1,p);
    cpp_int ans1=(c1_2*temp1)%p;
    cout<<"decrypted1: "<<ans1<<endl;
    
    cpp_int cur2=power(c2_1,x,p);
    cpp_int temp2=mod_inv(cur2,p);
    cpp_int ans2=(c2_2*temp1)%p;
    cout<<"decrypted2: "<<ans2%p<<endl;
    cout<<"decrypted1 * decrypted2: "<<ans1*ans2<<endl;
    
    cpp_int cur=power(c1,x,p);
    cpp_int temp=mod_inv(cur,p);
    cpp_int ans=(c2*temp)%p;
    cout<<"decrypted: "<<ans<<endl;
}
