#include<stdint.h>
#include<stdio.h>

union Packet
{
    uint32_t packetValue;
    struct
    {
        uint32_t     crc        :2;
        uint32_t     status     :1;
        uint32_t     payload    :12;
        uint32_t     bat        :3;
        uint32_t     sensor     :3;
        uint32_t     longAddr   :8;
        uint32_t     shortAddr  :2;
        uint32_t     addrMode   :1;
    }packetFields; 
};

int main()
{
    union Packet packet;

    printf("Enter a 32 bit value in hexadecimal: ");
    fflush(stdout);
	scanf("%x", &packet.packetValue);

    printf("CRC: %x\n", packet.packetFields.crc);
    printf("Status: %x\n", packet.packetFields.status);
    printf("Payload: %x\n", packet.packetFields.payload);
    printf("Bat: %x\n", packet.packetFields.bat);
    printf("Sensor: %x\n", packet.packetFields.sensor);
    printf("LongAddr: %x\n", packet.packetFields.longAddr);
    printf("ShortAddr: %x\n", packet.packetFields.shortAddr);
    printf("AddrMode: %x\n", packet.packetFields.addrMode);
    printf("Size of struct is: %I64u\n", sizeof(packet));

    return 0;
}