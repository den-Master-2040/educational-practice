#include <iostream>
#include <math.h>

bool hit_in(double R,double A, double x2, double y2)
{
    //центр окружности всегда в координатах 0 0

    //d^2 = (x2-x1)^2 +(y2-y1)^2 -формула длинны отрезка
    double d = sqrt(((x2 - 0)*(x2)) + ((y2 - 0)*(y2))); //расстояние от центра окружности до точки.
    // Нужно для того, чтобы определить, находится ли точка в окружности
    if(R == d)
    {
        std::cout << "Точка лежит на краю окружности" << std::endl;
        return false;
    }
    if(x2 == 0 || y2 ==0 || x2 == A)
    {
        std::cout << "Точка лежит на оси координат или на границе в окружности (А)" << std::endl;
        return false;
    }
    if(x2 > 0 && y2 > 0 && d < R)   //положительная четверть, или вторая четверть
    {
        return true;
    }
    if(y2 > 0 && x2 < A && d < R)    //первая четверть, Х ограничено от -R до А
    {
        return true;
    }
    return false;
}

int main() {
    double R = 0;   //радиус окружности
    double A = 0;   //граница в окружности
    double x,y = 0; //координаты точки пользователя
    std::cout << "Введите радиус окружности" << std::endl;
    std::cin >> R;
    std::cout << "Введите А - границу в окружности (А < R)" << std::endl;
    std::cin >> A;
    std::cout << "Введите координаты точки " << std::endl;
    std::cin >> x;
    std::cout << "";
    std::cin >> y;

    if(hit_in(R,A,x,y))
    {
        std::cout << "Точка в отмеченной зоне" << std::endl;
    }
    else
    {
        std::cout << "Точка за пределами отмеченной зоны" << std::endl;
    }
    return 0;
}


