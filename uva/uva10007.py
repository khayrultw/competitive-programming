def factorial(n):
    if n==0:
        return 1
    return n*factorial(n-1)

while True:
    n = int(input())
    if n==0:
        break
    ans = factorial(2*n)//factorial(n+1)
    print(ans)