## Chapter 1.
### Amdahl's Law :
```text
S = 1 / ((1 - α) + α / k)
S is total speedup
k is partial speedup
α is part getting sped up
```


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
```text
~ is NOT 1 ->0, 0->1
& is AND 1&1->1, 0&1->0 -> 0&0->0
| is OR 1&1->1, 0&1->1 -> 0&0->0
^ is XOR 1&1->0, 0&1->1 -> 0&0->0
```

### Bit vectors :
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

### Bit shifts :
```text
logical right shift pads the left bits with 0s while
arithmetic right shift pads the left bits with 1s :
Operation           Value1      Value2
Argument x          [01100011]  [10010101]
x << 4              [00110000]  [01010000]
x >> 4 (1ogical)    [00000110]  [00001001]
x >> 4 (arithmetic) [00000110]  [11111001]

In C in general unsigned values use logical right shifting
while signed values use arithmetic right shiftinng

Shifting by values bigger than the amount of bits in a data type is undefined.
However most machines will compute the value k mod w where k is the shift and w is the bit size
```


