#include "linux_x64.h"

unsigned long syscall1(unsigned long number, unsigned long arg1) {
    unsigned long result;
    asm volatile("syscall\n"
                 : "=a"(result)
                 : "a"(number), "D"(arg1)
                 : "%rcx", "%r11", "memory");
    return result;
}

unsigned long syscall3(unsigned long number, unsigned long arg1,
                                     unsigned long arg2, unsigned long arg3) {
    unsigned long result;
    asm volatile("syscall\n"
                 : "=a"(result)
                 : "a"(number), "D"(arg1), "S"(arg2), "d"(arg3)
                 : "%rcx", "%r11", "memory");
    return result;
}
