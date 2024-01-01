def isprime(x):
    x = int(x) # convert floating to integer
    if x in [2,3,5]:
        return True
    if (x % 2) == 0 or (x % 3) == 0 or (x % 5) == 0:
        return False
    if (x < 49):
        return True
    if (x %  7) == 0 or (x % 11) == 0 or (x % 13) == 0 or (x % 17) == 0 or \
       (x % 19) == 0 or (x % 23) == 0 or (x % 29) == 0 or (x % 31) == 0 or \
       (x % 37) == 0 or (x % 41) == 0 or (x % 43) == 0 or (x % 47) == 0:
        return False
    if (x < 2809):
        return True
    if (x < 31417):
        return pow(2, x, x) == 2 and x not in [7957, 8321, 13747, 18721, 19951, 23377]
        # pow(x,y,z): (x^y) % z
    
#    from sympy.ntheory.generate import sieve as s
#    if n <= s._list[-1]:
#        l, u = s.search(n)
#        return l == u

    if x < 9080191:
        return mr(x, [31, 73])
    if x < 19471033:
        return mr(x, [2, 299417])
    if x < 38010307:
        return mr(x, [2, 9332593])
    if x < 316349281:
        return mr(x, [11000544, 31481107])
    if x < 4759123141:
        return mr(x, [2, 7, 61])

def mr(n, bases): # perform Miller-Rabin strong pseudoprime test
    n = int(n)
    s = trailing(n - 1)
    t = n >> s
    for base in bases:
        if base >= n:
            base %= n
        if base >= 2:
            if not _test(n, base, s, t):
                return False
    return True

def trailing(n):  # find the largest power of 2 that divides n
    power = 0
    while (n % 2 == 0):
        power += 1
        n = n >> 1
    return power

def _test(n, base, s, t):
    """Miller-Rabin strong pseudoprime test for one base.
    Return False if n is definitely composite, True if n is
    probably prime, with a probability greater than 3/4.

    """
    # do the Fermat test
    b = pow(base, t, n)
    if b == 1 or b == n - 1:
        return True
    else:
        for j in range(1, s):
            b = pow(b, 2, n)
            if b == n - 1:
                return True
            # see I. Niven et al. "An Introduction to Theory of Numbers", page 78
            if b == 1:
                return False
    return False


try:
    while True:
        x = input()
        prime = isprime(x)
        if prime == True:
            print("質數\n")
        else:
            print("非質數\n")
except EOFError:
    pass