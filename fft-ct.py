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

def ifft(X):
    #must normalize by 1/N at end
    N = len(X)
    if N == 1:
        return X
    xk = [0 for x in range(N//2)]
    xkpNd2 = [0 for x in range(N//2)]
    even = X[0::2]
    odd = X[1::2]
    E = ifft(even)
    O = ifft(odd)

    for k in range(N//2):
        oMult = exp(2j*pi*k/N)*O[k]
        xk[k] = (E[k] + oMult)
        xkpNd2[k] = (E[k] - oMult)
    x = xk + xkpNd2
    return x
