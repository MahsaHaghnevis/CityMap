//
// City.cpp
// created by Yseeva
//
//

#include <iostream>
#include <Windows.h>
#include <Time.h>
//------------------
#define WIDTH  20
#define HEIGHT 20

int map[HEIGHT][WIDTH];

int randomNumber(int lb, int ub) 
{
    return (rand() % (ub - lb + 1)) + lb; //returns a random number to use in the map positions
}

void generateMap(int numberOfCrossroads, int numberOfCars)
{
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            map[i][j] = 0;
        }
    }
    for (int m = 0; m < numberOfCrossroads; m++) //here i generate the positions of all crossroads
    {
        while (1) 
        {
            int a = randomNumber(1, HEIGHT - 2); //-2 becuz we can't put crossroads at the sides of map
            int b = randomNumber(1, WIDTH  - 2); //same here
            if (map[a][b] == 0)
            {
                if ((map[a+1][b] == 0) && (map[a-1][b] == 0) && (map[a][b+1] == 0) && (map[a][b-1] == 0)) {
                    map[a][b] = 1;
                    break;
                }
            }
        }
    }
    for (int i = 0; i < numberOfCars; i++)
    {
        while (1)
        {
            int a = randomNumber(1, HEIGHT - 2);
            int b = randomNumber(1, WIDTH - 2);
            if (map[a][b] == 0)
            {
                if ((map[a + 1][b] == 0) && (map[a - 1][b] == 0) && (map[a][b + 1] == 0) && (map[a][b - 1] == 0)) 
                {
                    if (i % 2 == 0) 
                    {
                        map[a][b] = 2;
                    }
                    else 
                    {
                        map[a][b] = 3;
                    }
                    break;
                }
            }
        }
    }
}

void moveCars() 
{
    for (int i = 0; i < HEIGHT; i++) 
    {
        for (int j = 0; j < WIDTH; j++) 
        {
            if (map[i][j] == 2)
            {
                if (i % 2 == 0) {
                    if (j + 1 == WIDTH)
                    {
                        if (map[i + 1][j] == 0)
                        {
                            map[i + 1][j] = 4;
                            map[i][j] = 0;
                        }
                        else if (map[i - 1][j] == 0)
                        {
                            map[i - 1][j] = 4;
                            map[i][j] = 0;
                        }
                        else 
                        {
                            map[i][j] = 4;
                        }
                    }
                    else if (map[i][j + 1] == 0) 
                    {
                        map[i][j + 1] = 4;
                        map[i][j] = 0;
                    }
                    else if (map[i][j + 1] == 1)
                    {
                        map[i][j + 1] = 5;
                        map[i][j] = 0;
                    }
                    else 
                    {
                        map[i][j] = 4;
                    }
                }
                else {
                    if (j - 1 == -1) 
                    {
                        if (map[i + 1][j] == 0)
                        {
                            map[i + 1][j] = 4;
                            map[i][j] = 0;
                        }
                        else if (map[i - 1][j] == 0)
                        {
                            map[i - 1][j] = 4;
                            map[i][j] = 0;
                        }
                        else
                        {
                            map[i][j] = 4;
                        }
                    }
                    else if (map[i][j - 1] == 0) 
                    {
                        map[i][j - 1] = 4;
                        map[i][j] = 0;
                    }
                    else if (map[i][j - 1] == 1)
                    {
                        map[i][j - 1] = 5;
                        map[i][j] = 0;
                    }
                    else
                    {
                        map[i][j] = 4;
                    }
                }
            }
            else if (map[i][j] == 3)
            {
                if (j % 2 != 0) 
                {
                    if (i + 1 == HEIGHT)    
                    {
                        if (map[i][j + 1] == 0)
                        {
                            map[i][j + 1] = 6;
                            map[i][j] = 0;
                        }
                        else if (map[i][j - 1] == 0)
                        {
                            map[i][j - 1] = 6;
                            map[i][j] = 0;
                        }
                        else 
                        {
                            map[i][j] = 6;
                        }
                    }
                    else if (map[i + 1][j] == 0) 
                    {
                        map[i + 1][j] = 6;
                        map[i][j] = 0;
                    }
                    else if (map[i + 1][j] == 1)
                    {
                        map[i + 1][j] = 5;
                        map[i][j] = 0;
                    }
                    else
                    {
                        map[i][j] = 6;
                    }
                }
                else {
                    if (i - 1 == -1) 
                    {
                        if (map[i][j + 1] == 0)
                        {
                            map[i][j + 1] = 6;
                            map[i][j] = 0;
                        }
                        else if (map[i][j - 1] == 0)
                        {
                            map[i][j - 1] = 6;
                            map[i][j] = 0;
                        }
                        else
                        {
                            map[i][j] = 6;
                        }
                    }
                    else if (map[i - 1][j] == 0) 
                    {
                        map[i - 1][j] = 6;
                        map[i][j] = 0;
                    }
                    else if (map[i - 1][j] == 1)
                    {
                        map[i - 1][j] = 5;
                        map[i][j] = 0;
                    }
                    else
                    {
                        map[i][j] = 6;
                    }
                }
            }
        }
    }

    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            if (map[i][j] == 4 || map[i][j] == 6)
            {
                map[i][j] = map[i][j] / 2;
            }
        }
    }

    for (int i = 0; i < HEIGHT; i++) 
    {
        for (int j = 0; j < WIDTH; j++) 
        {
            if (map[i][j] == 5) 
            {
                srand(time(0));
                int r = randomNumber(2, 3);

                if (r == 2)
                {
                    if (i % 2 == 0) 
                    {
                        if (map[i][j + 1] == 0) 
                        {
                            map[i][j + 1] = 2;
                            map[i][j] = 1;
                        }
                    }
                    else {
                        if (map[i][j - 1] == 0)
                        {
                            map[i][j - 1] = 2;
                            map[i][j] = 1;
                        }
                    }
                }
                else 
                {
                    if (j % 2 != 0)
                    {        
                        if (map[i + 1][j] == 0)
                        {
                            map[i + 1][j] = 3;
                            map[i][j] = 1;
                        }
                    }
                    else {
                        if (map[i - 1][j] == 0)
                        {
                            map[i - 1][j] = 3;
                            map[i][j] = 1;
                        }
                    }
                }
            }
        }
    }
}

void printMap() 
{
    std::cout << "    ";
    for (int z = 0; z < WIDTH; z++) 
    {
        if (z % 2 == 0)
        {
            std::cout << " ";
        }
        else {
            std::cout << "v";
        }
    }
    std::cout << "\n";
    for (int i = 0; i < HEIGHT; i++)
    {
        if (i % 2 == 0)
        {
            std::cout << "->";
        }
        else {
            std::cout << "<-";
        }
        std::cout << "||";
        for (int j = 0; j < WIDTH; j++)
        {   
            switch (map[i][j])
            {
            case 0:
                std::cout << " ";
                break;
            case 1:
                std::cout << "#";
                break;
            case 2:
                std::cout << "*";
                break;
            case 3:
                std::cout << "*";
                break;
           // case 5:
             //   std::cout << "X";
               // break;
            default:
                break;
            }
        }
        std::cout << " || ";
        if (i % 2 == 0)
        {
            std::cout << "->";
        }
        else {
            std::cout << "<-";
        }
        std::cout <<std::endl;
    }
    std::cout << "    ";
    for (int z = 0; z < WIDTH; z++)
    {
        if (z % 2 == 0)
        {
            std::cout << " ";
        }
        else {
            std::cout << "v";
        }
    }
    std::cout <<std::endl;
}

void clearScreen() 
{
    system("cls");
}

int main()
{
	system("Color fc");
    int cars, crossroads, iteration;
    std::cout << "Number of Cross-Roads (#): ";
    std::cin >> crossroads;
    std::cout << "Number of Cars (*): ";
    std::cin >> cars;
    std::cout << "Number of iteration (I): ";
    std::cin >> iteration;

    srand(time(0));
    generateMap(crossroads, cars);

    while (iteration--)
    { 
        clearScreen();
        moveCars();
        printMap();
        std::cout << "\n#:" << crossroads << " *:" << cars <<std::endl;
        std::cout << "Iteration(s) left: " << iteration;
        Sleep(1000);
    }
}


