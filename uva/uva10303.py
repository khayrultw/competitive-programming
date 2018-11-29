import sys
sys.setrecursionlimit(10000)
def catalan(n):
    if n == 0:
        return int(1)
    tmp = catalan(n-1)
    return int(((4*n-2)*tmp)//(n+1))

while True:
    try:
        n = int(input())
        print(catalan(n))
    except EOFError:
        break