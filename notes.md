## Chapter 1.
### Amdahl's Law :
S = 1 / ((1 - α) + α / k)\
S is total speedup\
k is partial speedup\
α is part getting sped up\


## Chapter 2.
### Byte ordering :
for number 0x12345678\
little endian is :  0x100   0x101   0x102   0x103\
                    78      56      34      12\
big endian is :     0x100   0x101   0x102   0x103\
                        12      34      56      78\

### Boolean algebra :
~ is NOT 1 ->0, 0->1\
& is AND 1&1->1, 0&1->0 -> 0&0->0\
| is OR 1&1->1, 0&1->1 -> 0&0->0\
^ is XOR 1&1->0, 0&1->1 -> 0&0->0\

### Bit vectors :
Bit vectors can be used to represent finite sets.\
Let S be        [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]\
bit vector a is [0  1  0  1  1  0  1  1  0  0]\
bit vector b is [1  0  0  1  0  0  0  1  0  1]\
then A is [1, 3, 4, 6, 7]\
and B is [0, 3, 7, 9]\
a & b is    [0  1  0  1  1  0  1  1  0  0]\
           &[1  0  0  1  0  0  0  1  0  1]\
            [0  0  0  1  0  0  0  1  0  0]\
so A inter B is [3, 7]\
\
a | b is    [0  1  0  1  1  0  1  1  0  0]\
           |[1  0  0  1  0  0  0  1  0  1]\
            [1  1  0  1  1  0  1  1  0  1]\
so A union B is [0, 1, 3, 4, 6, 7, 9]\
\
~a is       [1  0  1  0  0  1  0  0  1  1]\
\
so S/A is [0, 2, 5, 8, 9]\
