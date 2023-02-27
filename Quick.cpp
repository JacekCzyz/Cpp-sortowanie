#include <iostream>


template <typename T>
void transp(T *array, int first, int second)    //funkcja sluzaca do zamiany dwoch elementow w tablicy miejscami
{
    int temp = array[second];
    array[second] = array[first];
    array[first] = temp;
}

template <typename T>
int quick(T *array, int ind_f, int ind_l)
{
    if (ind_f >= ind_l) //jesli indeks pierwszego elementu tablicy jest wiekszy lub rowny(tablica 1-elementowa), koncze sortowac
        return 0;

    int pivot = array[((ind_f + ind_l) / 2)];   //element osiowy srodkowym elementem tablicy
    int count = ind_f;  //ustawiam licznik elementow mniejszych od pivota na indeks pierwszego elementu tablicy

    
    transp(array, ((ind_f + ind_l) / 2), ind_l);    //przenosze pivot na koniec
    for (int i = ind_f; i <= ind_l; i++)    //iteruje po wszystkich elementach tablicy z pivotem wlacznie
    {
        if (array[i] <= pivot)  //jesli element mniejszy od elementu osiowego, zamieniam miejscamiz elementem znajdujacym sie na indeksie rownym licznikowi mniejszych elementow
        {                       // i zwiekszam jego wartosc. rowniez pivot bedacy na koncu zostaje przeniesiony na miejsce ostatniego mniejszego elementu
            transp(array, i, count);
            count++;
        }
    }
    count--;    //zmniejszam counter, aby zrownal sie z indeksem pivotu

    quick(array, ind_f, count-1);   //ponownie wywoluje algorytm, pierwszy element taki sam jak wczesniej, ostatni to pozycja pivota - 1

    quick(array, count + 1, ind_l);     //ponownie wywoluje algorytm, pozycja pivota + 1, ostatni tak jak wczesniej

    return 0;
}