#include <bits/stdc++.h>
using namespace std;
int main()
{
    int framesize;
    cout << "Enter the number of frames \n";
    cin >> framesize;
    int n;
    cout << "Enter the page string length \n";
    cin >> n;
    int pages[n];
    cout << "Enter the string:\n";
    for (int i = 0; i < n; ++i)
    {
        cin >> pages[i];
    }
    int mark[n];
    queue<int> Q;
    int faults = 0, hits = 0;
    for (int i = 0; i < n; ++i)
    {
        if (mark[pages[i]] == true)
        {
            hits++;
        }
        else
        {
            Q.push(pages[i]);
            mark[pages[i]] = true;
            if (Q.size() > framesize)
            {
                int p = Q.front();
                mark[p] = false;
                Q.pop();
            }
            faults++;
        }
    }
    cout << "Number of page faults are " << faults << endl;
    cout << "Number of page hits are " << hits << endl;
    cout << "Page faults ratio =  " << float(faults) / float(n) * 100 << endl;
    cout << "Page hit ratio =  " << float(hits) / float(n) * 100 << endl;

    return 0;
}