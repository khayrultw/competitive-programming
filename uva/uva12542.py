def isPrime(n):
    if n==2:
        return True
    if n==1 or n&1==0:
        return False
    
    i = int(3)
    while i*i<=n:
        if n%i==0:
            return False
        i = i+2
    return True

while True:
    n = str(input())
    if n == '0':
        break
    l = min(6, len(n))
    for i in range(0, l):
        k = l-i
        j = 0
        large = 0
        while j+k <= len(n):
            x = int(n[j:k+j])
            j = j+1
            if isPrime(x):
                if x<=100000 and x>large:
                    large = x
        if large!=0:
            print(large)
            break