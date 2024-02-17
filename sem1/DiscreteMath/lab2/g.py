def resta(num1, dem1, num2, dem2):
    ans = num1 * dem2 - num2 * dem1
    return ans

def tobinary(p, q):
    ans = ""
    i = 0
    while (i < q):
        ans += str(p % 2)
        p = p // 2
        i += 1
    ans = ans[::-1]
    return ans

n = int(input())
s = input()
m = len(s)
print(n)
rep = [0 for i in range(n)]
numrangos = [0 for i in range(n + 1)]
dem = m
for i in range(m):
    rep[ord(s[i]) - ord('a')] += 1
for i in range(n - 1):
    print(rep[i], end = " ")
print(rep[n - 1])
for i in range(n):
    numrangos[i + 1] = numrangos[i] + rep[i]
for i in range(m):
    numrangos[0] = numrangos[ord(s[i]) - ord('a')]
    numrangos[n] = numrangos[ord(s[i]) - ord('a') + 1]
    largo = numrangos[n] - numrangos[0]
    numrangos[n] *= m
    numrangos[0] *= m
    dem *= m
    for j in range(n):
        numrangos[j + 1] = numrangos[j] + largo * rep[j]

band = True
for i in range(1, 1000000000000000):
    if (band == False): break
    ini, fin = 0, 2**i - 1
    tam = fin + 1
    while ini <= fin:
        mid = (ini + fin) // 2
        temp1 = resta(numrangos[n], dem, mid, tam)
        temp2 = resta(numrangos[0], dem, mid, tam)
        if (temp1 >= 0 and temp2 <= 0):
            print(tobinary(mid, i))
            band = False
            break
        elif (temp1 < 0):
            fin = mid - 1
        else:
            ini = mid + 1
