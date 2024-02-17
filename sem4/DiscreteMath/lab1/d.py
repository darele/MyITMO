from fractions import *
from math import *

class pol:

    def __init__(self, n):
        self.c = [0 for i in range(n + 1)]

    def multiply(self, l2):
        ans = pol(len(self.c) + len(l2.c) - 1)
        for i in range(len(ans.c)):
            for j in range(i + 1):
                s1 = self.c[j] if j < len(self.c) else 0
                s2 = l2.c[i - j] if i - j < len(l2.c) else 0
                ans.c[i] += s1 * s2
        return ans

r, k = map(int, input().split())

P = list(map(int, input().split()))

result = pol(k)

dem = factorial(k) * r**k

for i in range(k + 1):
    cur = pol(0)
    cur.c[0] = P[i] * r**(k - i)
    for j in range(1, k + 1):
        temp = pol(1)
        temp.c[0] = j - i
        temp.c[1] = 1

        cur = cur.multiply(temp)

    for j in range(k + 1):
        result.c[j] += cur.c[j]

ans = [Fraction(i, dem) for i in result.c]

for i in ans:
    print(i.numerator,"/",i.denominator, sep="",end=" ")
print()