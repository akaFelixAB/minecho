# minecho 🪄

A tiny, minimal echo program written in C using direct Linux x86_64 syscalls. It prints a single command-line argument to stdout and is intended as a small demonstration of low-level syscall usage and a minimal program entrypoint.

Features
- Minimal single-file implementation (no libc for I/O) 🧩
- Custom `_start` entrypoint and naked `exit` using syscalls ⚙️
- Small and educational — great for learning or tiny containers 📦

Building

Preferred (CMake):

```sh
mkdir -p build
cd build
cmake ..
cmake --build .
```

Or explicitly with Ninja:

```sh
cmake -S . -B build -G Ninja
cmake --build build
```

Quick single-file compile (for development/testing):

```sh
gcc -nostdlib -static -o minecho main.c
```

Running

```sh
./minecho Hello
# => Hello
```

Notes
- This project targets Linux x86_64 (uses syscall ABI and numbers). 🐧
- The program expects exactly one argument; it prints a helpful message otherwise.

Contributing
- Feel free to open issues or PRs for improvements or portability changes. ✨

License
- See the `LICENCE` file for license details.

