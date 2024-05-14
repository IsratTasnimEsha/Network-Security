// Bismillahir Rahmanir Rahim
// Primitive Elements

#include <bits/stdc++.h>
using namespace std;

// Function to calculate (base^exp) % mod
long long int power(long long int base, long long int exp, long long int mod) {
    long long int result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * base) % mod;
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return result;
}

int main() {
    long long int p = 23;
    for (int a = 2; a < p; a++) {
        int flag = 1;
        map<long long int, long long int> mp;
        for (long long int i = 1; i < p - 1; i++) {
            long long int s = power(a, i, p);
            mp[s]++;
        }
        for (auto i : mp) {
            // cout << i.first << " " << i.second << endl;
            if (i.second != 1) {
                flag = 0;
                break;
            }
        }
        if (flag == 1)
            cout << a << " is primitive." << endl;
        else
            cout << a << " is not primitive." << endl;
        // cout << endl << endl;
        flag = 1;
    }
    return 0;
}