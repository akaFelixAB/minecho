#include "stdio.h"

#include "string.h"

#if defined(__linux__) && defined(__x86_64__)
#include "platforms/linux/linux_x64.h"
#elif defined(_WIN64)
#include "platforms/windows/windows_x64.h"
#endif

void print(const char* str) {
    syscall3(SYS_write, 1, (unsigned long)str, strlen(str));
}
