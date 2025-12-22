#if defined(__linux__) && defined(__x86_64__)
#include "minlibc/platforms/linux/linux_x64_runtime.h"
#elif defined(_WIN64)
#include "minlibc/platforms/windows/windows_x64_runtime.h"
#endif

#include "minlibc/stdio.h"

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
