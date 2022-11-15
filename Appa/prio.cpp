#include <iostream>

using namespace std;
int main()
{
    int arrival[10], b[10], x[10];
    int waiting[10], turnaround[10], completion[10], p[10];
    int i, j, smallest, count = 0, time, n;
    double avg = 0, tt = 0, end;
 
    cout << "\nEnter the number of Processes: \n";
    cin >> n;
    cout << "Enter arrival time of processes : ";
    for (i = 0; i < n; i++)
    {
        cin >> arrival[i];
    }
    cout << "\nEnter burst time of processes : ";
    for (i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    cout << "\nEnter priority of processes : ";
    for (i = 0; i < n; i++)
    {
        cin >> p[i];
    }
    for (i = 0; i < n; i++)
        x[i] = b[i];

    p[9] = -1;
    for (time = 0; count != n; time++)
    {
        smallest = 9;
        for (i = 0; i < n; i++)
        {
            if (arrival[i] <= time && p[i] > p[smallest] && b[i] > 0)
                smallest = i;
        }
        b[smallest]--;

        if (b[smallest] == 0)
        {
            count++;
            end = time + 1;
            completion[smallest] = end;
            waiting[smallest] = end - arrival[smallest] - x[smallest];
            turnaround[smallest] = end - arrival[smallest];
        }
    }
    cout << "Process\t"
         << "\tPriority"
         << "\tburst-time"
         << "\t"
         << "arrival-time"
         << "\t"
         << "waiting-time"
         << "\t"
         << "turnaround-time"
         << "\t"
         << "completion-time"
         << "\t"
         << endl;
    for (i = 0; i < n; i++)
    {
        cout << "p" << i + 1 << "\t\t" << p[i] << "\t\t" << x[i] << "\t\t" << arrival[i] << "\t\t" << waiting[i] << "\t\t" << turnaround[i] << "\t\t" << completion[i] << "\t\t" << endl;
        avg = avg + waiting[i];
        tt = tt + turnaround[i];
    }
    cout << "\nTotal waiting time =" << avg;
    cout << "  Total Turnaround time =" << tt << endl;
    cout << "\nAverage waiting time =" << avg / n;
    cout << "  Average Turnaround time =" << tt / n << endl;
    return 0;
}
