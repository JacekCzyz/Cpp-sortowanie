#include <iostream>
#include "shell.cpp"

template <typename T>
void build_maxheap(T *array, int size, int root)
{
    if ((2 * root + 1) < size && (2 * root + 2) >= size)    // sprawdzam tylko 'lewego' potomnego korzenia jesli prawy jest poza zakresem
    {
        if (array[(2 * root + 1)] > array[root])    // jesli wiekszy od korzenia, zamieniam miejscami
        {
            transp(array, root, (2 * root + 1));
            build_maxheap(array, size, (2 * root + 1));
        }
    }

    else if ((2 * root + 1) < size && (2 * root + 2) < size)  // sprawdzam tylko sprawdzam oba elementy potomne jesli mieszcza sie w tablicy
    {
        if (array[(2 * root + 1)] > array[(2 * root + 2)]) //sprawdzam ktory wiekszy
        {
            if (array[(2 * root + 1)] > array[root])
            {
                transp(array, root, (2 * root + 1));    // jesli wiekszy od korzenia, zamieniam miejscami
                build_maxheap(array, size, (2 * root + 1)); //ponownie ksztaltuje kopiec dla elementu ktory zostal przestawiony
            }
        }
        else
        {
            if (array[(2 * root + 2)] > array[root])
            {
                transp(array, root, (2 * root + 2));    // jesli wiekszy od korzenia, zamieniam miejscami
                build_maxheap(array, size, (2 * root + 2));     //ponownie ksztaltuje kopiec dla elementu ktory zostal przestawiony
            }
        }
    }
}


template <typename T>
int heap(T *array, int size)
{

    for (int i = (size / 2) - 1; i >= 0; i--)   //zeby moc zaczac, musze juz miec strukture kopca
    {
        build_maxheap(array, size, i);
    }
    for (int i = size - 1; i >= 0; i--)
    {
        transp(array, 0, i);    // pierwszy, najwiekszy element kopca na koniec
        build_maxheap(array, i, 0);    //ponownie ukladam kopiec, pomijajac najwiekszy element znajdujacy sie juz na koncu
    }

    return 0;
}