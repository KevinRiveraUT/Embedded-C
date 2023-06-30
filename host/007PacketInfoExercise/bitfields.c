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

uint16_t getData(uint32_t *pPacket, uint8_t startingBit, uint32_t mask);

int main()
{
    struct Packet myPacket;
    uint32_t myHex;

    printf("Enter a 32 bit value in hexadecimal: ");
    fflush(stdout);
	scanf("%x", &myHex);

    // Tedious so as to not use math.h?
    // Instructor approach:
    // myPacket.payload = (uint16_t) ((myHex >> 3) & 0xFFF);
    myPacket.crc = getData(&myHex, 0, 0b11);
    myPacket.status = getData(&myHex, 2, 0b1);
    myPacket.payload = getData(&myHex, 3, 0b111111111111);
    myPacket.bat = getData(&myHex, 15, 0b111);
    myPacket.sensor = getData(&myHex, 18, 0b111);
    myPacket.longAddr = getData(&myHex, 21, 0b11111111);
    myPacket.shortAddr = getData(&myHex, 27, 0b11);
    myPacket.addrMode = getData(&myHex, 30, 0b1);

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

uint16_t getData(uint32_t *pPacket, uint8_t startingBit, uint32_t mask)
{
    uint16_t myValue = *pPacket & (mask << startingBit) >> startingBit; 
    return myValue;
}