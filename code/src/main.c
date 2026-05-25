#include <stdio.h>
#include <figure2_1.h>
#include <2_1_7.h>

int main( void ) {

    printf("figure 2.1 :\n");

    int x = 95;
    printf("\t showbytes(%d) ->", x);
    show_int(x);
    
    float y = 3.14159;
    printf("\t showbytes(%f) ->", y);
    show_float(y);

    void *p = &y;
    printf("\t showbytes(%p) ->", p);
    show_pointer(p);


    printf("example 2.1.7 :\n");
    int a = 15;
    int b = 20;
    printf("\t %d AND %d = %d\n",a, b, and_on_int(a, b));
    printf("\t %d OR %d = %d\n",a, b, or_on_int(a, b));
    printf("\t %d XOR %d = %d\n",a, b, xor_on_int(a, b));
    printf("\t %d NOT = %d\n",a, not_on_int(a));
}
