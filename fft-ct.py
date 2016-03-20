import math
from cmath import exp, pi
import numpy.fft as npf

def reverse(x, n):
    result = 0
    for i in xrange(n):
        if (x >> i) & 1: result |= 1 << (n - 1 - i)
    return result

def fft_it(x):
    n = len(x)
    q = int(round(math.log(n)/math.log(2)))
    for i in range(n//2):
        rev = reverse(i, q)
        x[i],x[rev] = x[rev], x[i]
    w = exp(-2j*pi/n)
    for j in range(0,q):
        m = 2**j
        mrev = 2**(q-j)
        #print("j: " + str(j) + ", m: " + str(m))
        for k in range(0,2**(q-j-1)):
            s = k*2*m
            e = (k+1)*2*m #end not inclusive
            r = s + (e-s)/2
           # print("k: " + str(k) + ",s: " + str(s) + ", e: " + str(e) + ", r: " + str(r) + ", mrev*0.5/n:" + str(mrev*0.5/n))
            for idx in range(s,r):
                halfidx = idx - s
                #print("halfidx:" + str(halfidx) + ", r+halfidx:" + str(r+halfidx))
                wloc = w**(mrev * 0.5 * halfidx) * x[r+halfidx]
                x[idx] = x[idx]+wloc
                x[halfidx+r] = x[idx]-wloc
    return x

