/*Есть два манипулятора.Их инструменты находятся в точках О1 и О2 в декартовой
системе координат(X, Y).У каждого манипулятора есть свой радиус эффективного
действия R1 и R2.
Есть целевая точка P1
Определите, каким манипулятором оптимальнее дойти до точки P1.
Если оба манипулятора не могут достать, то вывести сообщение: “OUT OF RANGE”.
Если точка доступна одному манипулятору – использовать его.*/

#include <iostream>

struct Point {
    double x;
    double y;
};

struct Manipulator : public Point {
    double length;
};

int main()
{
    Manipulator firstManip;
    Manipulator secondManip;

    std::cin >> firstManip.x >> firstManip.y;
    std::cin >> secondManip.x >> secondManip.y;

    std::cin >> firstManip.length >> secondManip.length;

    Point targetPoint;
    std::cin >> targetPoint.x >> targetPoint.y;

    double firstManipDistance = sqrt(pow(firstManip.x + (targetPoint.x - firstManip.x), 2) + 
        pow(firstManip.y + (targetPoint.y - firstManip.y), 2));
    double secondManipDistance = sqrt(pow(secondManip.x + (targetPoint.x - secondManip.x), 2) +
        pow(secondManip.y + (targetPoint.y - secondManip.y), 2));

    if (firstManipDistance == secondManipDistance) {
        if (firstManip.length > firstManipDistance && secondManip.length > secondManipDistance) {
            std::cout << "in equal access";
            return 0;
        }
    }

    if (firstManipDistance < secondManipDistance) {
        if (firstManip.length > firstManipDistance) {
            std::cout << "first manipulator";
            return 0;
        }
        else if(secondManip.length > secondManipDistance){
            std::cout << "second manipulator";
            return 0;
        }
        else {
            std::cout << "OUT OF RANGE";
            return 0;
        }
    }

    else {
        if (secondManip.length > secondManipDistance) {
            std::cout << "second manipulator";
            return 0;
        }
        else if (firstManip.length > firstManipDistance) {
            std::cout << "first manipulator";
            return 0;
        }
        else {
            std::cout << "OUT OF RANGE";
            return 0;
        }
    }
}