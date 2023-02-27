template <typename T>
void fill_arr(T *array, int size, double percent, bool inc)
{

    for (int i = 0; i < size; i++)
    {
        array[i] = (rand() % 10000) + 1;    //wupelniam tablice losowymi elementami z zakresu 1 do 10000
    }

    if (percent > 0)   //sortuje pewien procent tablicy jesli 
    {
        if (inc == true)    
            std::sort(array, array + (int)(percent * size / 100));      //jesli true, sortuje rosnaco
        else    
            std::sort(array, array + size, std::greater<T>());      //jesli false, sortuje malejaco
    }
}