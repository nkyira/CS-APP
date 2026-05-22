#include <stdio.h>
#include <figure2_1.h>

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
}
