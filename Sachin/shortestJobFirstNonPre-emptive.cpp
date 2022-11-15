
#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n = 4;

    int at[] = {2, 5, 1, 0, 4};

    int bt[] = {6, 2, 8, 3, 4};

    int tat[n];
    int wt[n];
    int ct[n];

    vector<pair<int, int>> v;

    for (int i = 0; i < n; i++)
    {
        v.push_back(make_pair(at[i], i));
    }

    // for (auto i : v)
    // {
    //     cout << i.first << " " << i.second;
    //     cout << endl;
    // }

    sort(v.begin(), v.end());

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;

    int current_time = 0;

    int m = 0;

    for (int i = 0; i < n; i++)
    {

        while (m < n && v.at(m).first <= current_time)
        {
            heap.push(make_pair(bt[v.at(m).second], v.at(m).second));
            // cout << bt[v.at(m).second] << "  " << v.at(m).second << "   " << current_time << endl;
            m++;
            // cout << m << endl;
        }

        // cout << "a" << endl;
        pair<int, int> p = heap.top();

        // cout << p.second << endl;

        heap.pop();

        ct[p.second] = current_time + p.first;
        cout << ct[p.second] << " " << p.second << endl;

        current_time += p.first;
    }
    // cout << current_time;
    cout << endl;

    for (auto i : ct)
        cout << i << endl;

    return 0;
}