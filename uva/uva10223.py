import sys
sys.setrecursionlimit(10000)
cat = []
def catalan():
    cat.append(1)
    for i in range(1, 25):
        cat.append((4*i-2)*cat[i-1]//(i+1))

catalan()
while True:
    try:
        n = int(input())
        i = 1
        while i<25:
            if cat[i]>=n:
                print(i)
                break
            i = i+1
    except EOFError:
        break