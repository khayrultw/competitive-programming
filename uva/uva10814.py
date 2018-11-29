def gcd(a, b):
    if b==0:
        return a;
    return gcd(b, a%b)

t = int(input())
while t:
    a, b = input().split(" / ")
    a, b = int(a), int(b)
    gc = gcd(a,b);
    a, b = a//gc, b//gc
    print("%d / %d"%(a,b))
    t = t-1
