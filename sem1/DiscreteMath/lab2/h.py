def resta(num1, dem1, num2, dem2):
    ans = num1 * dem2 - num2 * dem1
    return ans

def frombinary(num):
    q = len(num)
    i = q - 1
    ans = 0
    while (i >= 0):
        ans += int(num[i]) * 2 ** (q - i - 1)
        i -= 1
    return ans

n = int(input())
rep = list(map(int, input().split()))
num = input()
p = frombinary(num)
q = len(num)
q = 2 ** q
numrangos = [0 for i in range(n + 1)]
numrangos[n] = 1
m = sum(rep)
dem = m
ant = -1
band = True
for i in range(n):
    numrangos[i + 1] = numrangos[i] + rep[i]
    if (band and rep[i] > 0 and resta(numrangos[i + 1], dem, p, q) >= 0):
        print(chr(i + ord('a')), end = '')
        ant = i
        band = False
for i in range(m - 1):
    numrangos[0] = numrangos[ant]
    numrangos[n] = numrangos[ant + 1]
    largo = numrangos[n] - numrangos[0]
    numrangos[n] *= m
    numrangos[0] *= m
    dem *= m
    band = True
    for j in range(n):
        numrangos[j + 1] = numrangos[j] + largo * rep[j]
        if (band and rep[j] > 0 and resta(numrangos[j + 1], dem, p, q) >= 0):
            print(chr(j + ord('a')), end = '')
            ant = j
            break