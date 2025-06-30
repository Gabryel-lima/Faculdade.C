
#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Portuguese");
    wprintf(L"Olá, mundo!");

    return 0;
}
