cmake_minimum_required(VERSION 3.16)

project(minecho VERSION 1.0.0 LANGUAGES C)

# C standard
set(CMAKE_C_STANDARD 11)

# Default to Release build type
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

# Source files
set(MINLIBC_SOURCES
  minlibc/stdio.c
  minlibc/string.c
)

# Platform-specific sources
if(UNIX)
  list(APPEND MINLIBC_SOURCES
    minlibc/platforms/linux/linux_x64_runtime.c
    minlibc/platforms/linux/linux_x64.c
  )
elseif(WIN32)
  list(APPEND MINLIBC_SOURCES
    minlibc/platforms/windows/windows_x64_runtime. c
    minlibc/platforms/windows/windows_x64.c
  )
endif()

# Create minlibc static library
add_library(minlibc STATIC ${MINLIBC_SOURCES})
target_include_directories(minlibc PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/minlibc)
target_compile_options(minlibc PRIVATE -ffreestanding -fno-builtin -O2)
target_compile_definitions(minlibc PUBLIC MINLIBC=1)

# Create minecho executable
add_executable(minecho main.c)
target_link_libraries(minecho PRIVATE minlibc)
target_compile_options(minecho PRIVATE -ffreestanding -O2)
target_link_options(minecho PRIVATE -nostdlib -nostartfiles -static)
