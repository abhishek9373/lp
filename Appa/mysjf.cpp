#include<bits/stdc++.h>
using namespace std;

int main(){
    cout<<"Enter the number of processes\n";
    int n;
    cin>>n;
    int burst[n],waiting[n],arrival[n];
    cout<<"Enter the burst time of processes \n";
    for(int i=0;i<n;++i)
        cin>>burst[i];
    cout<<"Enter the arrival time of processes \n";
    for(int i=0;i<n;++i)
        cin>>arrival[i];

    int t=0,st=0,wt[n],ta[n],ct[n];
    float twt=0,tat=0;
    while(true)
    {
        int c=n,min=999;
        if(t==n)
        {
            break;
        }
        for(int i=0;i<n;++i)
        {
            if(arrival[i]<=st && burst[i]<min)
            {
                min=burst[i];
                c=i;
            }
        }
        if(c==n)
            st++;
        else
        {
            ct[c]=st+burst[c];
            st+=burst[c];
            ta[c]=ct[c]-arrival[c];
            wt[c]=ta[c]-burst[c];
            t++;
        }

    }
    cout<<"Process\tArrivalTime\tBurstTime\tCompletionTime\tTurnAround\tWaiting\n";
    for(int i=0;i<n;++i)
    {
        cout<<i+1<<"\t"<<arrival[i]<<"\t"<<burst[i]<<"\t"<<ct[i]<<"\t"<<ta[i]<<"\t"<<wt[i]<<"\n";
        twt+=wt[i];
        tat+=ta[i];
    }
    cout<<"Total waiting time = "<<twt<<endl;
    cout<<"Total turnaround time = "<<tat<<endl;
    cout<<"Average waiting time = "<<(float)twt/float(n)<<endl;
    cout<<"Average turnaround time = "<<(float)twt/(float)n<<endl;
    return 0;
}