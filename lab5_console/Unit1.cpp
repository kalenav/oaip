//---------------------------------------------------------------------------

#include <vcl.h>
#include <conio.h>
#include <iostream.h>
#include <math.h>
#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
int main(int argc, char* argv[])
{
        int n;
        cout << "Array size = ";
        cin >> n;
        int choice;
        cout << "0 - Input by hand; 1 - Randomize" << endl;
        cin >> choice;
        int a[50];
        if(choice)
        {
                cout << "The array is ";
                for(int i = 0; i <= n-1; i++)
                {
                        a[i] = random(19)-9;
                        cout << a[i] << " ";
                }
        }
        else
        {
                for(int i = 0; i <= n-1; i++)
                {
                        cout << "Input element " << i << ": ";
                        cin >> a[i];
                        cout << endl;
                }
        }
        int fneg = -1;
        for(int i = 0; i <= n-1; i++)
        {
                if(a[i] < 0)
                {
                        fneg = i;
                        break;
                }
        }
        if(fneg == -1)
        {
                cout << "No negative elements found!";
                getch();
                return 0;
        }
        if(fneg == n-1)
        {
                cout << "No elements after the first negative one!";
                getch();
                return 0;
        }
        int sum = 0;
        for(int i = fneg+1; i <= n-1; i++)
        {
                sum += fabs(a[i]);
        }
        cout << "The sum is " << sum;
        getch();
        return 0;
}
//---------------------------------------------------------------------------
 