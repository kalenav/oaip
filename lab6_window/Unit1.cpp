//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
bool created;
int n,m;
int** a;

__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
        Edit1->Text = "3";
        Edit2->Text = "5";
        created = false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
        Label2->Caption = "";
        n = StrToFloat(Edit1->Text);
        m = StrToFloat(Edit2->Text);
        StringGrid1->Height = (n+1) * 31;
        StringGrid1->Width = (m+1) * 31;
        StringGrid1->RowCount = n + 1;
        StringGrid1->ColCount = m + 1;
        if(n < 1 || m < 1)
        {
                Label2->Caption = "Please enter \n positive numbers!";
                created = false;
                return;
        }
        if(n == 1)
        {
                for(int j = 1; j <= m; j++) StringGrid1->Cells[j][1] = random(19)-9;
                Label2->Caption = "Matrix contains \n only 1 line!";
                return;
        }
        a = new int* [n];
        for(int i = 0; i < n; i++)
        {
                a[i] = new int [m];
                StringGrid1->Cells[0][i+1] = "i = " + IntToStr(i+1);
                for(int j = 0; j < m; j++)
                {
                        a[i][j] = random(19)-9;
                        StringGrid1->Cells[j+1][i+1] = a[i][j];
                }
        }
        created = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
        if(!created)
        {
                Label2->Caption = "No matrix \n to sort!";
                return;
        }
        int* nums = new int [n];
        for(int i = 0; i < n; i++)
        {
                nums[i] = i;
                StringGrid1->Cells[1][i+1] = nums[i];
        }
        int* maxs = new int [n];
        for(int i = 0; i < n; i++)
        {
                int max = a[i][0];
                for(int j = 1; j < m; j++)
                {
                        if(a[i][j] > max) max = a[i][j];
                }
                maxs[i] = max;
                StringGrid1->Cells[2][i+1] = maxs[i];
        }
        for(int i = 1; i < n; i++)
        {
                if(maxs[i] > maxs[i-1])
                {
                        int tempnum = nums[i];
                        int tempmax = maxs[i];
                        nums[i] = nums[i-1];
                        nums[i-1] = tempnum;
                        maxs[i] = maxs[i-1];
                        maxs[i-1] = tempmax;
                        i-=2;
                }
        }
        for(int i = 0; i < n; i++)
        {
                for(int j = 0; j < m; j++)
                {
                        StringGrid1->Cells[j+1][i+1] = IntToStr(a[nums[i]][j]);
                }
        }
}
//---------------------------------------------------------------------------


