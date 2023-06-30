#include<stdint.h>
#include<stdio.h>

union Address
{
    uint16_t     shortAddr;
    uint32_t     longAddr;
};

int main()
{
    union Address addr;

    addr.shortAddr = 0xABCD;
    addr.longAddr = 0xEEEECCCC;
    printf("short addr is: %#X\n", addr.shortAddr);
    printf("long addr is: %#X\n", addr.longAddr);

    return 0;
}