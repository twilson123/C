#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    char X[50];
    char Y[50];
    for (int i = 0;i < 10;i++)
    {
        cout << "Enter X: ";
        cin >> X;
        cout << "Enter Y: ";
        cin >> Y;

        int t = strlen(X);
        int w = strlen(Y);
        lcsAlgo(X, Y, t, w);
    }

void lcsAlgo(char* S1, char* S2, int t, int w) 
{
    int LCS_table[t + 1][w + 1];

    for (int i = 0; i <= t; i++)
    {
        for (int j = 0; j <= w; j++)
        {
            if (i == 0 || j == 0)
                LCS_table[i][j] = 0;
            else if (S1[i - 1] == S2[j - 1])
                LCS_table[i][j] = LCS_table[i - 1][j - 1] + 1;
            else
                LCS_table[i][j] = max(LCS_table[i - 1][j], LCS_table[i][j - 1]);
        }
    }

    int index = LCS_table[t][w];
    char lcsAlgo[index + 1];
    lcsAlgo[index] = '\0';

    int i = t, j = w;

    while (i > 0 && j > 0)
    {
        if (S1[i - 1] == S2[j - 1])
        {
            lcsAlgo[index - 1] = S1[i - 1];
            i--;
            j--;
            index--;
        }

        else if (LCS_table[i - 1][j] > LCS_table[i][j - 1])
            i--;
        else
            j--;
    }

   
    cout << "X : " << S1 << "\nY : " << S2 << "\nLCS: " << lcsAlgo << "\n\n";
}

int main() 
{
    char X[50];
    char Y[50];
    for (int i = 0;i < 10;i++)
    {
        cout << "Enter X: ";
        cin >> X;
        cout << "Enter Y: ";
        cin >> Y;
        int t = strlen(X);
        int w = strlen(Y);
        lcsAlgo(X, Y, t, w);
    }







