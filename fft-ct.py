from cmath import exp, pi

def fft(x):
    N = len(x)
    if N == 1:
        return x
    Xk = [0 for x in range(N//2)]
    XkpNd2 = [0 for x in range(N//2)]
    even = x[0::2]
    odd = x[1::2]
    E = fft(even)
    O = fft(odd)

    for k in range(N//2):
        oMult = exp(-2j*pi*k/N)*O[k]
        Xk[k] = E[k] + oMult
        XkpNd2[k] = E[k] - oMult
    X = Xk + XkpNd2
    return X
