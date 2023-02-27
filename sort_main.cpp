#include <chrono>
#include <fstream>
#include <iostream>
#include <algorithm>
#include "fill.cpp"
#include "kopc.cpp"
#include "head.hh"

int main()
{
    srand(time(NULL)); // pozwala to na nowy 'seed' dla funkcji rand, dzieki czemu za kazdym razem mam inne liczby losowe
    int sort[3] = {1, 2, 3};
    int size = 100000;
    double percent = 25;
    bool incl = true;
    std::ofstream file("wyniki.txt"); // otwarcie strumienia plikowego

    int *array = new int[size]; // dynamiczna alokacja tablicy o zadanym rozmiarze
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            fill_arr(array, size, percent, true);               // wypelniam tablice liczbami
            auto t_start = std::chrono::steady_clock::now(); // zaczynam mierzyć czas
            switch (sort[i])
            {
            case 1:
            {
                quick(array, 0, size - 1);
                break;
            }
            case 2:
            {
                heap(array, size);
                break;
            }

            case 3:
            {
                shell(array, size, 1);
                break;
            }
            }
            auto t_end = std::chrono::steady_clock::now(); // zatrzymanie czasu
            for (int i = 0; i < size-1; i++)
            {
                if (array[i] > array[i + 1])
                {
                    std::cout << "nieposortowane" << std::endl;
                    return 0;
                }
            }
            file << std::chrono::duration_cast<std::chrono::milliseconds>(t_end - t_start).count() << std::endl; // zapisuje wynik do pliku
        }
        file << "------------------------------------" << std::endl;
    }
    delete[] array; // usuwam zalokowana wczesniej tablice
    
    return 0;
}