#include <stdio.h>

union U {
    float f;
    unsigned char c[4];
};

int main(void) {
    union U u;
    int i;

    u.f = 3.14f;

    for (i = 0; i < 4; i++) {
        printf("%x\n", (unsigned)u.c[i]);
    }

    return 0;
}
