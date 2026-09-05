bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n) {
    if(n == 0)
    return true;
    if(flowerbedSize == 1)
    {
        if(flowerbed[0] == 0)
        return true;
        else
        return false;
    }
    if(n != 0 && flowerbed[0] == 0 && flowerbed[1] == 0)
    {
        n--;
        flowerbed[0] = 1;
    }
    if(n != 0 && flowerbed[flowerbedSize -1] == 0 && flowerbed[flowerbedSize - 2] == 0)
    {
        n--;
        flowerbed[flowerbedSize - 1] = 1;
    }
    for(int i = 1; i < flowerbedSize - 1; i++)
    {
        if(n == 0)
        break; 
        if(flowerbed[i-1] == 0 && flowerbed[i] == 0 && flowerbed[i+1] == 0)
        {
            n--;
            i++;
        }
    }
    if(n == 0)
    return true;
    return false;
}