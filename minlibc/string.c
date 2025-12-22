unsigned long strlen(const char* str) {
    char const* s = str;
    while (*str) str++;
    unsigned long len = str - s;
    return len;
}