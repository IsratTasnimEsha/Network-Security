# Bismillahir Rahmanir Rahim
# RSA Cryptosystem

def gcd(num1, num2):
    if(num2==0):
        return num1
    return gcd(num2, num1%num2)

p=11
q=13

n=p*q
print("n = ", n)

phi=(p-1)*(q-1)
print("phi = ", phi)

e=9
while e<phi:
    if gcd(e, phi)==1:
        break
    e=e+1
print("e = ", e)

d=3
while d<phi:
    if (e*d)%phi == 1:
        break
    d=d+1
print("d = ", d)

ms=6
print("msg = ", ms)

c=1
for i in range (e):
    c=c*ms

c=c%n
print("c = ", c)

m=1
for i in range (d):
    m=m*c

m=m%n
print("m = ", m)