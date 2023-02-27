#include <iostream>
#include <cmath>
#include "Quick.cpp"
#include "head.hh"


template <typename T>
int shell(T *array, int size, int exp)
{
    int inter = size / (pow(2, exp));   //ustawiam wartosc odstepu(interwalu) wg wzoru rozmiar/(2^k)

    for (int j = inter; j < size; j++)  //iteruje tak dlugo, az bede odliczal od ostatniego elementu
    {
        for (int k = j - inter; k >= 0; k -= inter) //petla tak dlugo, az cofne sie do ostatniego mozliwego elementu oddalonego o odstep
        {
            if (array[k + inter] >= array[k])   //jesli element jest mniejszy od poprzedniego w iteracji, nic nie robie
                break;
            else
                transp(array, (k + inter), k);  //jesli element jest wiekszy od poprzedniego w iteracji, zamieniam miejscami
        }
    }

    if (inter == 1)
        return 0;

    shell(array, size, exp + 1);    //ponownie wywoluje algorytm zwiekszajac potege, a tym samym zmniejszajac dlugosc odstepu

    return 0;
}