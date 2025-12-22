#pragma once

#define SYS_exit 60

void exit(int status);

__attribute__((naked)) void _start();