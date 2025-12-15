#define SYS_exit 60
#define SYS_write 1

static inline unsigned long syscall1(unsigned long number, unsigned long arg1) {
    unsigned long result;
    asm volatile("syscall\n"
                 : "=a"(result)
                 : "a"(number), "D"(arg1)
                 : "%rcx", "%r11", "memory");
    return result;
}

static inline unsigned long syscall3(unsigned long number, unsigned long arg1,
                                     unsigned long arg2, unsigned long arg3) {
    unsigned long result;
    asm volatile("syscall\n"
                 : "=a"(result)
                 : "a"(number), "D"(arg1), "S"(arg2), "d"(arg3)
                 : "%rcx", "%r11", "memory");
    return result;
}

unsigned long strlen(const char* str) {
    char const* s = str;
    while (*str)
        str++;
    unsigned long len = str - s;
    return len;
}

void print(const char* str) {
    syscall3(SYS_write, 1, (unsigned long)str, strlen(str));
}

int main(int argc, char const* argv[]) {
    if (argc == 1) {
        print("Please provide an argument.\n");
        return 1;
    } else if (argc == 2) {
        print(argv[1]);
        print("\n");
    } else {
        print("Please provide only one argument.\n");
        return 1;
    }
    return 0;
}

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