## Chapter 1.
### Amdahl's Law :
S = 1 / ((1 - α) + α / k)\
S is total speedup\
k is partial speedup\
α is part getting sped up


## Chapter 2.
### Byte ordering :
```text
for number 0x12345678
little endian is :  0x100   0x101   0x102   0x103
                    78      56      34      12
big endian is :     0x100   0x101   0x102   0x103
                        12      34      56      78
```

### Boolean algebra :
~ is NOT 1 ->0, 0->1\
& is AND 1&1->1, 0&1->0 -> 0&0->0\
| is OR 1&1->1, 0&1->1 -> 0&0->0\
^ is XOR 1&1->0, 0&1->1 -> 0&0->0

### Bit vectors
```text
Let S be:
[0, 1, 2, 3, 4, 5, 6, 7, 8, 9]

a = [0 1 0 1 1 0 1 1 0 0]
b = [1 0 0 1 0 0 0 1 0 1]

A = [1, 3, 4, 6, 7]
B = [0, 3, 7, 9]

a & b = [0 1 0 1 1 0 1 1 0 0]
      & [1 0 0 1 0 0 0 1 0 1]
        [0 0 0 1 0 0 0 1 0 0]

A ∩ B = [3, 7]

a | b = [0 1 0 1 1 0 1 1 0 0]
      | [1 0 0 1 0 0 0 1 0 1]
        [1 1 0 1 1 0 1 1 0 1]

A ∪ B = [0, 1, 3, 4, 6, 7, 9]

~a = [1 0 1 0 0 1 0 0 1 1]

S \ A = [0, 2, 5, 8, 9]
```
