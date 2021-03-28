#include <iostream>
#include <math.h>

double functionToApprox(double x)
{
    return sin(x) * sin(x) - 3 * cos(x);
}

double approx(double a, double b, double q, double epsilon)
{
    double xprev, xcurr, temp;
    xprev = a;
    xcurr = a - functionToApprox(a) * q / (functionToApprox(a) - functionToApprox(a - q));
    while (fabs(xcurr - xprev) >= epsilon)
    {
        temp = xcurr;
        xcurr = xprev - functionToApprox(xprev) * q / (functionToApprox(xprev) - functionToApprox(xprev - q));
        xprev = temp;
    }
    return xcurr;
}

int main()
{
    printf("Input a, b, h, epsilon: ");
    double a, b, h, epsilon;
    scanf_s("%lf %lf %lf %lf", &a, &b, &h, &epsilon);
    printf("Here's a list of approximate roots of (sin(x))^2 - 3cos(x) on the interval %lf to %lf:\n", a, b);
    for (double x = a; x <= b; x += h)
    {
        if (functionToApprox(x) * functionToApprox(x + h) < 0) printf("%lf\n", approx(x, x + h, h, epsilon));
    }
    return 0;
}
