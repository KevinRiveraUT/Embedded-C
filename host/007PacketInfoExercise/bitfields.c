#include<stdint.h>
#include<stdio.h>

struct Packet
{
    uint32_t     crc        :2;
    uint32_t     status     :1;
    uint32_t     payload    :12;
    uint32_t     bat        :3;
    uint32_t     sensor     :3;
    uint32_t     longAddr   :8;
    uint32_t     shortAddr  :2;
    uint32_t     addrMode   :1;
};

int main()
{
    struct Packet myPacket;
    uint32_t myHex;

    printf("Enter a 32 bit value in hexadecimal: ");
    fflush(stdout);
	scanf("%x", &myHex);

    myPacket.crc = (uint8_t) (myHex & 0x3);
    myPacket.status = (uint8_t) ((myHex >> 2) & 0x1);
    myPacket.payload = (uint16_t) ((myHex >> 3) & 0xFFF);
    myPacket.bat = (uint8_t) ((myHex >> 15) & 0x7);
    myPacket.sensor = (uint8_t) ((myHex >> 18) & 0x7);
    myPacket.longAddr = (uint8_t) ((myHex >> 21) & 0xFF);
    myPacket.shortAddr = (uint8_t) ((myHex >> 29) & 0x3);
    myPacket.addrMode = (uint8_t) ((myHex >> 31) & 0x1);

    printf("CRC: %x\n", myPacket.crc);
    printf("Status: %x\n", myPacket.status);
    printf("Payload: %x\n", myPacket.payload);
    printf("Bat: %x\n", myPacket.bat);
    printf("Sensor: %x\n", myPacket.sensor);
    printf("LongAddr: %x\n", myPacket.longAddr);
    printf("ShortAddr: %x\n", myPacket.shortAddr);
    printf("AddrMode: %x\n", myPacket.addrMode);
    printf("Size of struct is: %d\n", sizeof(myPacket));

    return 0;
}