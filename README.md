# minecho 🪄

A tiny, minimal echo program written in C using direct Linux x86_64 syscalls. It prints a single command-line argument to stdout and is intended as a small demonstration of low-level syscall usage and a minimal program entrypoint.

## ✨ Features
- Custom minimal C library implementation (minlibc) with modular architecture 🧩
- Platform-specific runtime support (Linux x86_64, with Windows foundation) 🖥️
- Custom `_start` entrypoint and `exit` using syscalls ⚙️
- No libc dependency for I/O operations 🚫
- Small and educational — great for learning or tiny containers 📦

## 🏗️ Building

Preferred (CMake with Clang):

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

The build uses clang with flags: `-ffreestanding -nostdlib -nostartfiles -static`

## ⚡️ Running

```sh
./build/minecho Hello
# => Hello
```

## 🧐 Notes
- This project targets Linux x86_64 (uses syscall ABI and numbers). 🐧
- The code is structured to support multiple platforms through conditional compilation
- The program expects exactly one argument; it prints a helpful message otherwise
- Uses Clang compiler with freestanding environment flags

## 🎉 Contributing
- Feel free to open issues or PRs for improvements or portability changes. ✨

## 📄 License
- See the `LICENCE` file for license details.

