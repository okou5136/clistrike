#include<stdio.h>
#include<wchar.h>
#include<locale.h>

int main(int argv, char ** argc) {
    setlocale(LC_ALL, "");

    int offset = 0x2800;

    int value = 0x19;

    wchar_t character = (wchar_t)(offset + value);

    value = 0x26;

    wchar_t charactertwo = (wchar_t)(offset + value);

    wprintf(L"%lc%lc\n", character, charactertwo);
}
