// FunctionGraphPrintV2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
using namespace std;

class Plane
{
private:
    int* width;
    int* height;
    char** plane;
public:
    Plane()
    {
        width = new int;
        height = new int;
        plane = new char*;
    }

    Plane(int _height, int _width)
    {
        width = new int;
        *width = _width;
        height = new int;
        *height = _height;
        plane = new char*[*height];
        for (int i = 0; i < *height; i++)
        {
            plane[i] = new char[*width];
        }
        clearPlane();
        drawAxis();
    }

    ~Plane()
    {
        delete width, height;
        delete[] plane;
    }

    void clearPlane()
    {
        for (int i = 0; i < *height; i++)
        {
            for (int j = 0; j < *width; j++)
            {
                plane[i][j] = ' ';
            }
        }
    }

    void drawAxis()
    {
        for (int i = 0; i < *width; i++)
        {
            plane[*height / 2][i] = '-';
        }
        for (int i = 0; i < *height; i++)
        {
            plane[i][*width / 2] = '|';
        }

        plane[0][*width / 2] = '^';
        plane[*height / 2][*width - 1] = '>';
        plane[*height / 2][*width / 2] = '+';
    }

    void drawPlane()
    {
        for (int i = 0; i < *height; i++)
        {
            cout << setw(10);
            for (int j = 0; j < *width; j++)
            {
                cout <<plane[i][j];
            }
            cout << endl;
        }
    }

    void drawFgraph(double(f)(double))
    {
        for (double x = -*width / 2.; x < *width / 2.; x += 0.01)
        {
            if (f(x) <= *height / 2. && f(x) >= -(*height / 2.))
            {
                int i = -f(x) + *height / 2.;
                int j = x + *width / 2.;
                /*
                if (f(x - 1) < f(x))
                {
                    if (f(x) < 0.5 && f(x) > -0.5)
                    {
                        plane[i][j] = '=';
                    }
                    else if ((f(x) > 1 || f(x) < -1) && x < 1 && x > -1)
                    {
                        plane[i][j] = '|';
                    }
                    else plane[i][j] = '/';
                }
                else if (f(x - 1) > f(x))
                {
                    if (f(x) < 0.5 && f(x) > -0.5)
                    {
                        plane[i][j] = '=';
                    }
                    else if ((f(x) > 1 || f(x) < -1) && x < 1 && x > -1)
                    {
                        plane[i][j] = '|';
                    }
                    else plane[i][j] = '\\';
                }
                else
                    */
                    plane[i][j] = '*';
            }
        }
    }
};


double f1(double x)
{
    //return 0;
    //return 
    //return 10*sin(2 * sin(2 * sin(2 * sin(x * 0.1))));
    //return 10*sin(x*0.1);
    //return 10*cos(x*0.1);
    //return 1 / tan(x);
    //return tan(x*0.1);
    //return 5*tan(x*0.1);
    return log(x*2);
    //return x * x * x;
    //return x*x;
    //return x;
    //return sqrt(x*2);
    //return -sqrt(x);
    //if (x == 0 ) { return x; } return 15/x;
}



int main()
{
    Plane plane(41, 141);
    plane.drawFgraph(f1);
    plane.drawPlane();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
