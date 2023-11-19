// FunctionGraphicsPrint.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <iomanip>
using namespace std;

int f(int x)
{
    //return 10*sin(2 * sin(2 * sin(2 * sin(x * 0.1))));
    //return 10*sin(x*0.1);
    //return 1 / tan(x);
    //return 5*tan(x*0.1);
    //return log(x);
    //return x * x * x;
    //return x*x;
    //return x;
    //return sqrt(x);
    //return -sqrt(x);
    //if (x == 0) { return 0; } return 15/x;
}


void drawFunction(char** arr, int h, int w)
{

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (f((j-w/2)) == (h / 2 - i))
            {
                arr[i][j] =  '*';
            }
        }
    }
}

void clearPlane(char** arr, int h, int w)
{
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            arr[i][j] = ' ';
        }
    }
}

void drawAxis(char** arr, int h, int w)
{

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (i == h / 2 && j == w/2)
            {
                arr[i][j] = '+';
            }
            else if (i == h / 2)
            {
                arr[i][j] = '-';
            }
            else if (j == w / 2)
            {
                
                arr[i][j] = '|';
            }
        }
    }
    arr[h / 2][w - 1] = '>';
    arr[0][w / 2] = '^';
}

void printArr(char** arr, int h, int w)
{
    for (int i = 0; i < h; i++)
    {
        cout << setw(10);
        for (int j = 0; j < w; j++)
            cout << arr[i][j];
        cout << endl;
    }
}


int main()
{
    int w = 151;
    int h = 41; 
    char** plane = new char*[h];
    for (int i = 0; i < h; i++)
    {
        plane[i] = new char[w];
    }
    clearPlane(plane, h, w);
    drawFunction(plane, h, w);
    drawAxis(plane, h, w);
    printArr(plane, h, w);

    delete[] plane;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
