#include<stdint.h>
#include<stdio.h>

struct Packet
{
    uint8_t     crc;
    uint8_t     status;
    uint16_t    payload;
    uint8_t     bat;
    uint8_t     sensor;
    uint8_t     longAddr;
    uint8_t     shortAddr;
    uint8_t     addrMode;
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

    return 0;
}

uint16_t getData(uint32_t *pPacket, uint8_t startingBit, uint32_t mask)
{
    uint16_t myValue = *pPacket & (mask << startingBit) >> startingBit; 
    return myValue;
}