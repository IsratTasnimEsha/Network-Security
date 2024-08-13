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

int main() {
    cpp_int p=23;
    cout<<"Primitives of "<<p<<":"<<endl;
    for(cpp_int a=2; a<p; a++) {
        map<cpp_int, cpp_int>mp;
        cpp_int flag=1;
        for(cpp_int i=1; i<p-1; i++) {
            mp[power(a, i, p)]++;
        }
        for(auto i: mp) {
            if(i.second>1){
                flag=0;
                break;
            }
        }
        if(flag==0);
        else cout<<a<<" ";
    }
}
