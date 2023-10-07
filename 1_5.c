#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

bool check_my_epsilon(char * str)
{

    int length = strlen(str);
    if (length >= 20)
    {
        return false;
    }

    int i = 0;
    int dot_count = 0;
    if (str[i] == '+')
    {
        i++;
    }

    if (str[i] == '.')
    {
        return false;
    }


    for (; i < length; i++)
    {
        if (str[i] == '.')
        {
            dot_count++;
        }
        else
        {
            if (str[i] < '0' || str[i] > '9')
            {
                return false;
            }
        }
    }


    if (dot_count != 1)
    {
        return false;
    }

    return true;
}

bool check_my_x(char* str)
{

    int length = strlen(str);
    if (length >= 20)
    {
        return false;
    }

    int i = 0;
    int dot_count = 0;
    if (str[i] == '+')
    {
        i++;
    }

    if (str[i] == '.')
    {
        return false;
    }


    for (; i < length; i++)
    {
        if (str[i] == '.')
        {
            dot_count++;
        }
        else
        {
            if (str[i] < '0' || str[i] > '9')
            {
                return false;
            }
        }
    }


    if (dot_count != 1)
    {
        return false;
    }

    return true;
}

double function_a(double x, double epsilon)
{
    double res = exp(x);
    return res;
}


double function_b(double x, double epsilon)
{
    double res = cos(x);
    return res;
}

double factorial(int n)
{
    double res = 1.0;
    for (int i = 1; i <= n; i++)
    {
        res *= i;
    }
    return res;
}



double function_c(double x, double epsilon)
{
    double sum = 0.0;
    int n = 0;
    double res = 1.0;

    while (fabs(res) > epsilon) 
    {
        res = (pow(3, 3 * n) * pow(factorial(n), 3) * pow(x, 2 * n)) / factorial(3 * n);
        sum += res;
        n++;
    }
    return sum;
}

double double_factorial(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
   else
    {
        return n * double_factorial(n-2);
    }

}

double function_d(double x, double epsilon)
{
    double sum = 0.0;
    double term = 0.0;
    int n = 1;

    do
    {
        term = (pow(-1, n) * double_factorial(2 * n - 1) * pow(x, 2 * n))/ double_factorial(2 * n);
        sum += term;
        n++;
    }
    while(fabs(term) > epsilon);

    return sum;
}


int main(int argc, char* argv[])
{
    if (argc != 3) 
    {
        printf("ERROR DETECTED! Please, enter epsilon and x!\n");
        return 1;
    }

    
    if (!check_my_epsilon(argv[1])) 
    {
        printf("Invalid epsilon input!\n");
        return 1;
    }
    double epsilon = atof(argv[1]);

    
    if (!check_my_x(argv[2])) 
    {
        printf("Invalid x input!\n");
        return 1;
    }
    double x = atof(argv[2]);

    double a_result = function_a(x, epsilon);
    printf("Result of a function is: %lf\n", a_result);

    double b_result = function_b(x, epsilon);
    printf("Result of b function is: %lf\n", b_result);

    double c_result = function_c(x, epsilon);
    printf("Result of c function is: %lf\n", c_result);

    double d_result = function_d(x, epsilon);
    printf("Result of d function is: %lf\n", d_result);

    return 0;
}