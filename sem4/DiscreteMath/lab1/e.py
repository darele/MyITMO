from math import *
import operator as op
from functools import reduce

def ncr(n, r):
    r = min(r, n-r)
    numer = reduce(op.mul, range(n, n-r, -1), 1)
    denom = reduce(op.mul, range(1, r+1), 1)
    return numer // denom  # or / in Python 2

class pol:
    def __init__(self, deg=None):
        if (deg is not None):
            self.c = [0 for i in range(deg + 1)]
        else:
            self.c = [0]
 
    def norm(self):
        for i in range(len(self.c) - 1, -1, -1):
            if (self.c[i] == 0):
                self.c.pop()
            else:
                break

    def get(self, i):
        return self.c[i] if len(self.c) > i >= 0 else 0
    
    def limit(self, n):
        while (len(self.c) > n):
            self.c.pop()
     
    def add(self, other):
        n = max(len(self.c), len(other.c))
        while (len(self.c) < n):
            self.c.apped(0)
        for i in range(len(other.c)):
            self.c[i] += other.c[i]
        self.norm()
 
    def multiply(self, o):
        n = len(self.c) + len(o.c)
        ans = pol(n-1)
        for i in range(n):
            for j in range(i + 1):
                f1 = self.get(j)
                f2 = o.get(i - j)
                ans.c[i] += f1 * f2
        ans.norm()
        self.c = ans.c

    def scalar(self, num):
        for i in range(len(self.c)):
            self.c[i] *= num
        self.norm()

    def ev(self, n, r):
        ans = self.c[0]
        for i in range(1, len(self.c)):
            ans += (self.c[i] * (n**i))
        ans *= r**n
        return ans

    def __str__(self):
        string = str(len(self.c) - 1) + "\n"
        for i in self.c:
            string += (str(i) + " ")
        return string

r = int(input())
d = int(input())

inputarr = list(map(int, input().split()))

An = pol(d)

for i in range(len(inputarr)):
    An.c[i] = inputarr[i]

At = pol(d + 2)

for i in range(len(inputarr)):
    At.c[i] = An.ev(i, r)

Q = pol(d + 1)

for i in range(d + 2):
    Q.c[i] = ((-r)**i)*(ncr(d + 1, i))

At.multiply(Q)

At.limit(d + 1)

print(At)
print(Q)