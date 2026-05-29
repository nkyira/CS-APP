## Chapter 1.
### Amdahl's Law :
`S = 1 / ((1 - α) + α / k)`  
S is total speedup  
k is partial speedup  
α is part getting sped up  

## Chapter 2.
### Byte ordering :
```
for number 0x12345678
little endian is :  0x100   0x101   0x102   0x103
                    78      56      34      12
big endian is :     0x100   0x101   0x102   0x103
                    12      34      56      78
```

### Boolean algebra :
`~` is NOT ~1 = 0, ~0 = 1  
`&` is AND 1&1 = 1, 0&1 = 0, 0&0 = 0  
`|` is OR 1&1 = 1, 0&1 = 1, 0&0 = 0  
`^` is XOR 1&1 = 0, 0&1 = 1, 0&0 = 0

### Bit vectors :
Let S be:
[0, 1, 2, 3, 4, 5, 6, 7, 8, 9]

a = [0 1 0 1 1 0 1 1 0 0]
b = [1 0 0 1 0 0 0 1 0 1]

A = [1, 3, 4, 6, 7]
B = [0, 3, 7, 9]

`
a & b = [0 1 0 1 1 0 1 1 0 0]
      & [1 0 0 1 0 0 0 1 0 1]
        [0 0 0 1 0 0 0 1 0 0]
`

`A ∩ B = [3, 7]`
```
a | b = [0 1 0 1 1 0 1 1 0 0]
      | [1 0 0 1 0 0 0 1 0 1]
        [1 1 0 1 1 0 1 1 0 1]
```
A ∪ B = [0, 1, 3, 4, 6, 7, 9]

~a = [1 0 1 0 0 1 0 0 1 1]

S \ A = [0, 2, 5, 8, 9]

### Bit shifts :
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

### Operator precedence :
    in C :
    1  ++, --, +(Unary) , -(Unary) , !, ~, (cast)
    2  *(dereference), &(address of), sizeof
    3  *, /, %, (arithmetic operators)
    4  +, -, (arithmetic operators)
    5  <<, >>, (bitwise shift)
    6  <, <=, >, >=, (relational operators)
    7  ==, !=, (relational operators)
    8  & (bitwise AND)
    9  ^ (bitwise XOR)
    10 | (bitwise OR)
    11 && (logical AND)
    12 || (logical OR)
    13 ?: (ternary condition), =, +=, +-
    14 *=, /=, %=, <<=, >>=, &=, ^=, |=
    15 ',' (comma)

### Integral data types :
#### Binary to unsigned encodings :
    for bit vector x = [x_(w-1), x_(w-2), ..., x_0]
    B2U_w(x) = Σ(i=0->w-1) x_i*2^i
    Ex: x = [10101100] so B2U_w(x) = 0*1 + 0*2 + 1*4 + 1*8 + 0*16 + 1*32 + 0*64 + 1*128 = 172
#### Binary to two's completment encodings :
    for bit vector x = [x_(w-1), x_(w-2), ..., x_0]
    B2U(x) = -x_(w-1)*2^(w-1) Σ(i=0->w-2) x_i*2^i
    Ex1: x = [00101100] so B2T(x) = 0*1 + 0*2 + 1*4 + 1*8 + 0*16 + 1*32 + 0*64 - 0*128 = 44
    Ex2: x = [10101100] so B2T(x) = 0*1 + 0*2 + 1*4 + 1*8 + 0*16 + 1*32 + 0*64 - 1*128 = -84
#### Conversion between signed and unsigned :
    when converting between types of the same size the bit representation stays the same so :
```C
    short int  v = -12345;
    unsigned short uv = (unsigned short)v;
    printf("v = %d, uv = %u\n", v, uv);
```
    will print : v = -12345, uv = 53191
#### Non-intuitive results of implicit conversions :
    When an operatfon is performed where one operand is signed and the other is unsigned, C
    implicitly casts the signed argument to unsigned and performs the operations :
    
