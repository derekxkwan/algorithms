#python 3
n, k = [int(x) for x in input("Enter n (seq. length) and k (number of 1's) separated by a space: \n").split()]
if k > n:
    n = k

m = n-k

ret = ['1']*k+['0']*m
r = min(m, k)

while r > 1:
    rng = min(m,k)
    for i in range(rng):
        ret[i] += ret[i+k]
    newlen = len(ret)-rng
    ret = ret[:newlen]
    if m >= k:
        k,m = k, m-k
    else:
        k,m = m, k-m
    r = min(m,k)

retStr = ''.join(ret)
print(retStr)


