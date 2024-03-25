On major 32-bit platforms:

int is 32 bits
long is 32 bits 
long long is 64 bits


On major 64-bit platforms:

int is 32 bits
long is either 32 or 64 bits
long long is 64 bits

If you need a specific integer size for a particular application, rather than trusting the compiler to pick the size you want, #include <cstdint> so you can use these types:

int8_t and uint8_t
int16_t and uint16_t
int32_t and uint32_t
int64_t and uint64_t
