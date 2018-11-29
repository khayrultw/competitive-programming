t = int(input())
while t:
    t = t-1
    lst1 = []
    lst2 = []
    input()
    n = int(input())
    for i in range(0, n):
        a, b = input().split(" ")
        a = int(a)
        b = int(b)
        lst1.append(a)
        lst2.append(b)
    i = int(n-1)
    ans = []
    tmp = int(0)
    while i>=0:
        x = lst1[i]+lst2[i]+tmp;
        ans.append(x%10)
        tmp = x//10
        i = i-1
    if tmp!=0:
        ans.append(tmp);
    i = int(len(ans)-1)
    while i>=0:
        print(ans[i], end="")
        i = i-1
    print()
    if t:
        print()
    