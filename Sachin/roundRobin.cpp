#include <bits/stdc++.h>

using namespace std;
int main()
{

    int n = 3;

    int time_quantum = 2;

    int at[n] = {0, 0, 0}; //{0, 1, 2, 4};

    int bt[n] = {10, 5, 8}; //{5, 4, 2, 1};

    int tat[n];

    int wt[n];

    int ct[n];

    int rem_bt[n];

    for (int i = 0; i < n; i++)
    {
        rem_bt[i] = bt[i];
    }

    queue<int>
        process_queue;

    int j = 0;

    int current_time = 0;

    int count = 0;

    while (current_time < at[0])
    {
        current_time++;
    }

    process_queue.push(j);

    j++;

    while (count < n)
    {
        int p_id = -1;

        int x = -1;

        if (!process_queue.empty())
        {
            p_id = process_queue.front();

            process_queue.pop();

            x = min(time_quantum, rem_bt[p_id]);

            rem_bt[p_id] -= x;
        }

        // cout << count << " ";
        current_time += x;

        while (j < n && at[j] <= current_time)
        {

            process_queue.push(j);

            j++;
        };

        if (rem_bt[p_id] != 0)
        {
            process_queue.push(p_id);
        }
        else
        {
            ct[p_id] = current_time;

            count++;
        }
    }

    for (auto i : ct)
    {
        cout << i << endl;
    }

    return 0;
}