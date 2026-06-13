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

```
a & b = [0 1 0 1 1 0 1 1 0 0]
      & [1 0 0 1 0 0 0 1 0 1]
        [0 0 0 1 0 0 0 1 0 0]
```
```
A ∩ B = [3, 7]
```
```
a | b = [0 1 0 1 1 0 1 1 0 0]
      | [1 0 0 1 0 0 0 1 0 1]
        [1 1 0 1 1 0 1 1 0 1]
```
```
A ∪ B = [0, 1, 3, 4, 6, 7, 9]
```
```
~a = [1 0 1 0 0 1 0 0 1 1]
```
```
S \ A = [0, 2, 5, 8, 9]
```

### Bit shifts :
logical right shift pads the left bits with 0s while
arithmetic right shift pads the left bits with 1s :
```
    Operation           Value1      Value2
    Argument x          [01100011]  [10010101]
    x << 4              [00110000]  [01010000]
    x >> 4 (1ogical)    [00000110]  [00001001]
    x >> 4 (arithmetic) [00000110]  [11111001]
```
In C in general unsigned values use logical right shifting
while signed values use arithmetic right shiftinng

Shifting by values bigger than the amount of bits in a data type is undefined.
However most machines will compute the value k mod w where k is the shift and w is the bit size

### Operator precedence :
in C :
1.  `++`, `--`, `+`(Unary) , `-`(Unary) , `!`, `~`, `(cast)`
2.  `*`(dereference), `&`(address of), `sizeof`
3.  `*`, `/`, `%`, (arithmetic operators)
4.  `+`, `-`, (arithmetic operators)
5.  `<<`, `>>`, (bitwise shift)
6.  `<`, `<=`, `>`, `>=`, (relational operators)
7.  `==`, `!=`, (relational operators)
8.  `&` (bitwise AND)
9.  `^` (bitwise XOR)
10. `|` (bitwise OR)
11. `&&` (logical AND)
12. `||` (logical OR)
13. `?:` (ternary condition), `=`, `+=`, `+-`
14. `*=`, `/=`, `%=`, `<<=`, `>>=`, `&=`, `^=`, `|=`
15. `,`(comma)

### 2.2 Integral data types :
#### Binary to unsigned encodings :

for bit vector `x = [x_(w-1), x_(w-2), ..., x_0]`  
`B2U_w(x) = Σ(i=0->w-1) x_i*2^i`
Ex: `x = [10101100]` so `B2U_w(x) = 0*1 + 0*2 + 1*4 + 1*8 + 0*16 + 1*32 + 0*64 + 1*128 = 172`
#### Binary to two's completment encodings :

for bit vector x = [x_(w-1), x_(w-2), ..., x_0]
B2U(x) = -x_(w-1)*2^(w-1) Σ(i=0->w-2) x_i*2^i
Ex1: x = [00101100] so B2T(x) = 0*1 + 0*2 + 1*4 + 1*8 + 0*16 + 1*32 + 0*64 - 0*128 = 44
Ex2: x = [10101100] so B2T(x) = 0*1 + 0*2 + 1*4 + 1*8 + 0*16 + 1*32 + 0*64 - 1*128 = -84
#### Conversion between signed and unsigned :

when converting between types of the same size the bit representation stays the same so :
```C
    short int  v = -12345;FLOAT
    unsigned short uv = (unsigned short)v;
    printf("v = %d, uv = %u\n", v, uv);
```
will print : v = -12345, uv = 53191
#### Non-intuitive results of implicit conversions :
When an operation is performed where one operand is signed and the other is unsigned, C
implicitly casts the signed argument to unsigned and performs the operations :
```
Expression                      Type       Evaluation
0 == 0U                         Unsigned        1
-1 < 0                          Signed          1
-1 < 0U                         Unsigned        0 *
2147483647 > -2147483647 - 1    Signed          1
2147483647U > -2147483647 - 1   Unsigned        0 *
2147483647 > (int)2147483648U   Signed          1 *
-1 > -2                         Signed          1
(unsigned)-1 > -2               Unsigned        1
```

### 2.3 Integer arithmetic


## Chapter 3 Machine level representation of programs

### 3.1 A Historical perspective
x86 refers to the old naming convention of intel processors (8086, 80286, i386, i486)
so x86-64 are intel compatible 64 bit processors.
From 1975 till 2015 there has been an exponential growth in x86 microprocesser complexity but there has been
a slowdown in cpu performance progress since the mid 2010s

### 3.2 Program encodings
```shell
gcc -Og -o p p1.c p2.c
```
the `-Og` flag instructs gcc to generate machine code that is similar in structure to the code
while `-O1` or `-O2` can optimize so heavily that the machine code and original code become quit different
gcc executes a series of actions to turn c code into machine code:
1. the *preprocessor* expands code in `#include` clauses and expands macros
2. the *compiler* generates assembly versions `p1.s` and `p2.s` of the the source file
3. the *assembler* converts the assembly code into binary *object-code* files `p1.o` and `p2.o`
4. the *linker*  merges the two object files along with code impleplementing library functions
and generates a final executable `p` which is the machine code that will be executed by the cpu



### 3.4
An x86-64 cpu contains 16 general purpose registers storing 64 bit values 

