#include <iostream>
#include <map>
#include <cmath>
#include <chrono>

int main() {
    system("chcp 65001");
    int codeLength = 4;
    int clippingValue = 2;
    std::map<std::pair<int, int>, int> map;

    std::cout << "Введите длину сообщения (количество бит):";
    std::cin >> codeLength;

    std::cout << "Введите минимальное кодовое расстояние (минимальная допустимая поразрядная разница сообщений):";
    std::cin >> clippingValue;

    int numberCount = int(pow(2, codeLength));

    auto start = std::chrono::system_clock::now();

    for (int i=0; i<numberCount; i++)
    {
        for (int j=i; j<numberCount; j++)
        {
            int x = i;
            int y = j;
            int differences = 0;

            while ((x>0) or (y>0))
            {
                if (x%2 != y%2)
                    differences++;
                x/=2;
                y/=2;
            }
            map.insert(std::pair<std::pair<int,int>,int>(std::pair<int, int>(i, j), differences));
        }
    }
    auto end = std::chrono::system_clock::now();

    for (auto item:map)
    {
        if (item.second >= clippingValue)
            std::cout<<item.first.first<<" <-> "<<item.first.second<<" = "<< item.second << std::endl;
    }

    std::cout<<"elapsed computation time: " << (( std::chrono::duration<double>)(end-start)).count()<<" s."<<std::endl;

    system("pause");
}
