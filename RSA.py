# https://www.w3challs.com/challenges/challenge20

import struct

def pwr_mod_recursive(base, pwr, mod):
    if 0 == pwr:
        return 1
    elif 0 == (pwr & 1):
        return pwr_mod((base * base) % mod , pwr >> 1, mod)
    else:
        return (base * pwr_mod((base * base) % mod, pwr >> 1, mod)) % mod

def pwr_mod(base, pwr, mod):
    retval = 1
    while pwr > 0:
        if 1 == (pwr & 1):
            retval = (retval * base) % mod
        base = (base * base) % mod
        pwr = pwr >> 1
    return retval

cipher_data = (309117097659990665453,
               125675338953457551017,
               524099092120785248852,
               772538252438953530955,
               547462544172248492882,
               28215860448757441963,
               543018082275730030658,
               585936545563088067075,
               131807465077304821584)

#N = 783340156742833416191 = 27789079547 * 28188776653
#E = 653

# p, q prime numbers (private)
p = 27789079547
q = 28188776653
# n (public)
n = p * q
# Phi(n) (private)
phin = (p-1) * (q-1)
# e (public)
e = 653 

print 'p      : ', p, '          , hex : ', hex(p)
print 'q      : ', q, '          , hex : ', hex(q)
print 'n      : ', n, ', hex : ', hex(n)
print 'Phi(n) : ', phin, ', hex : ', hex(phin)
print 'e      : ', e, '                  , hex : ', hex(e)

# d (private)
for i in xrange(e):
    if ((i * phin + 1)%e) == 0:
        print 'k      : ', i
        d = (i* phin + 1) / e
        break

print 'd      : ', d, ', hex : ', hex(d)
print 'decode:'
msg = ''
for c in cipher_data:
    print 'c  : ', str(c).zfill(21), '    , hex : ', hex(c)
    #m = (c ** d) % n
    m = pwr_mod(c, d, n)
    print 'm  : ', m, '      , hex : ', hex(m)
    msg = msg + struct.pack('Q', m)[::-1]
    gc = pwr_mod(m, e, n)
    print 'gc : ', str(c).zfill(21), '    , hex : ', hex(gc)
    print '--------'
print msg

