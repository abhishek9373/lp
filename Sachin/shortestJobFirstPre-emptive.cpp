#include <bits/stdc++.h>

using namespace std;
int main()
{

    int n = 5;

    int time_quantum = 1;

    int at[n] = {0, 1, 2, 4, 5};

    int bt[n] = {3, 8, 6, 4, 2};

    int tat[n];

    int wt[n];

    int ct[n];

    int rem_bt[n];

    for (int i = 0; i < n; i++)
    {
        rem_bt[i] = bt[i];
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;

    int j = 0;

    int current_time = 0;

    int count = 0;

    while (current_time < at[0])
    {
        current_time++;
    }

    heap.push(make_pair(bt[j], j));

    j++;

    while (count < n)
    {
        pair<int, int> p_id;

        int x;

        if (!heap.empty())
        {

            // for (auto i : rem_bt)
            // {
            //     cout << i << " ";
            // }

            p_id = heap.top();

            heap.pop();

            x = min(time_quantum, rem_bt[p_id.second]);

            rem_bt[p_id.second] -= x;
        }

        // cout << count << " ";
        current_time += x;

        while (j < n && at[j] <= current_time)
        {

            heap.push(make_pair(bt[j], j));

            j++;
        };

        if (rem_bt[p_id.second] != 0)
        {
            heap.push(make_pair(rem_bt[p_id.second], p_id.second));
        }
        else
        {
            ct[p_id.second] = current_time;

            count++;
        }

        // cout << endl;
    }

    for (auto i : ct)
    {
        cout << i << endl;
    }

    return 0;
}