#include <stdio.h>
#include <string.h>

struct IPv4 {
    unsigned int version;
    unsigned int ihl;
    unsigned char ttl;
    unsigned char protocol;
    unsigned char data[1024];
};

void update_val(struct IPv4 s) {
    strcpy((char *)s.data, "update_val");
}

void update_ptr(struct IPv4 *s) {
    strcpy((char *)(*s).data, "update_ptr");
}

int main(void) {
    struct IPv4 s1;
    struct IPv4 s2;

    strcpy((char *)s1.data, "origin");
    strcpy((char *)s2.data, "origin");

    update_val(s1);
    update_ptr(&s2);

    printf("%s\n", s1.data);
    printf("%s\n", s2.data);

    return 0;
}
