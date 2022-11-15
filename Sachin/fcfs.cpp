#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n = 4;

    int at[n] = {0, 1, 5, 6};

    int bt[n] = {2, 2, 3, 4};

    int ct[n];

    int tat[n];

    int wt[n];

    ct[0] = bt[0];

    int count = 0;

    int current = 0;

    while (count < n)
    {
        if (at[count] <= current)
        {
            ct[count] = current + bt[count];

            current += bt[count];

            count++;
        }
        else
        {
            current++;
        }
    }

    for (int i = 1; i < n; i++)
    {
    }

    for (int i = 0; i < n; i++)
    {
        tat[i] = abs(ct[i] - at[i]);
    }

    for (int i = 0; i < n; i++)
    {
        wt[i] = abs(tat[i] - bt[i]);
    }

    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += wt[i];
    }

    int total_turn_around_time = 0;

    accumulate(tat, tat + n, total_turn_around_time);

    int average_tat = (sum / 3);

    cout << average_tat << " " << sum << "\n";

    for (int i = 0; i < n; i++)
    {
        cout << at[i] << "     " << bt[i] << "       " << ct[i] << "      " << tat[i] << "      " << wt[i] << "       ";
        cout << "\n";
    }

    return 0;
}