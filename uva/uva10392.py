import random

def bigMod(n, p, m):
    if p==0:
        return 1
    if p%2==0:
        x = bigMod(n, int(p/2), m)
        return (x*x)%m
    return  ((n%m)*bigMod(n, p-1, m))%m

def millar_robin(d, n):
    a=random.randint(2, n-3)
    x=bigMod(a, d, n)
    if x==1 or x==n-1:
        return True
    while(d!=n-1):
        d = d*2
        x = (x*x)%n;
        if x==1:
            return False
        if x==n-1:
            return True
    return False

def isPrime(n):
    if n==2 or n==3:
        return True
    if n==1 or n%2==0:
        return False
    d = n-1
    while d%2==0:
        d = int(d/2)
    
    k = 100
    while k>0:
        k = k-1
        if millar_robin(d, n)==False:
            return False
    return True

def gcd(a, b):
    if b==0:
        return a
    return gcd(b, a%b)

def pollard_rho(n):
    if n%2==0:
        return 2
    x = random.randint(2, n-2)
    y = x
    c = random.randint(1, n-1)
    d = 1
    while d==1:
        x = (bigMod(x, 2, n)+c+n)%n
        y = (bigMod(y, 2, n)+c+n)%n
        y = (bigMod(y, 2, n)+c+n)%n
        d = gcd(abs(x-y), n)
        if d==n:
            return pollard_rho(n)
    return d

lst = []
def facto(n):
    n = int(n)
    while isPrime(n)==False:
        p = pollard_rho(n)
        n = int(n/p)
        if isPrime(p)==False:
            facto(p)
        else:
            lst.append(p)
    lst.append(n)

while True:
    n = int(input())
    if n<0:
        break
    facto(n)
    lst.sort()
    for i in range(0, len(lst)):
        print("    %d"%(lst[i]))
    del lst[:]
    print("")