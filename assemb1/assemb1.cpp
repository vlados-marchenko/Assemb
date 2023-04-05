#include <iostream>

/*Вариант 20: образовать строку, повторив фрагмент исходной строки
с заданной позиции данной длины требуемое число раз.*/

char* str_repeat_part(const char*, int, int, int);

int main()
{
    const char* arr = "123456";
    int position = 3;
    int len = 3;
    int rep_count = 2;
    char* res = str_repeat_part(arr, position, len, rep_count);
    std::cout << "\nStr: ";
    std::cout << res << std::endl;

}

char* str_repeat_part(const char* arr, int position, int len, int rep_count) {
    
    int n = len * rep_count;
    char* res = new char[n];
    for (int i = 0; i < n; i++) {
        res[i] = 0;
    }

    if ((position >= 0) && (len) > 0 && ((strlen(arr) - position) >= len) && (position <= strlen(arr))) {
        _asm {
            mov ebx, rep_count
            mov edi, res
        blok1 :
            cmp ebx, 0
            je exit
            mov ecx, len
            mov esi, arr
            add esi, position
        blok2 :
            mov al, [esi]
            mov[edi], al
            inc edi
            inc esi
            loop blok2
            dec ebx
            cmp ebx, 0
            ja blok1

        exit : mov[edi], 0

        }
    }
    return res;
}


