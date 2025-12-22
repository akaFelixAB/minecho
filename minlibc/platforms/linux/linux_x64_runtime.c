#include "linux_x64_runtime.h"

#include "linux_x64.h"

void exit(int status) {
    syscall1(SYS_exit, (unsigned long)status);
    while (1);
}

__attribute__((naked)) void _start() {
    asm volatile(
        "xor %rbp, %rbp\n"     // Clear base pointer
        "mov (%rsp), %rdi\n"   // argc
        "lea 8(%rsp), %rsi\n"  // argv
        "and $-16, %rsp\n"     // Align stack to 16 bytes
        "call main\n"
        "mov %rax, %rdi\n"  // Move return value of main to rdi
        "call exit\n");
}