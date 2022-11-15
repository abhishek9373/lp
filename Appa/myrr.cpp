#include<bits/stdc++.h>
using namespace std;

int main(){ 
    int n;
    cout<<"Enter the number of processes : \n";
    cin>>n;
    int burst[n];
    for(int i=0;i<n;++i)
    {
        cout<<"Enter the burst time of prcoees "<<i+1<<endl;
        cin>>burst[i];
    }
    int wt[n],ta[n];
    int rembt[n],quantum;
    cout<<"Enter the time quantum\n";
    cin>>quantum;
    for (int i = 0; i < n; i++)
    {
        rembt[i]=burst[i];
    }
    int twt=0,tat=0,ct=0;
    while(true)
    {
        bool flag=true;
        for(int i=0;i<n;++i)
        {
            if(rembt[i]>0)
            {
                flag=false;
                if(rembt[i]>quantum)
                {
                    ct+=quantum;
                    rembt[i]-=quantum;
                }
                else
                {
                    ct+=rembt[i];
                    wt[i]=ct-burst[i];
                    rembt[i]=0;
                }
            }
        }
        if(flag==true)
        {
            break;
        }
    }
    for (int i = 0; i < n; i++)
        ta[i] = burst[i] + wt[i];
    
    cout<<"Process\t\tBurst Time\t\tWaiting Time\t\tTurn Around time\n";
    for(int i=0;i<n;i++)
    {
        twt+=wt[i];
        tat+=ta[i];
        cout<<i+1<<"\t\t"<<burst[i]<<"\t\t"<<wt[i]<<"\t\t"<<ta[i]<<endl;
    }
    cout << "Total waiting time = "
         << (float)twt ;
    cout << "\nTotal turn around time = "
         << (float)tat <<endl;
    cout << "Average waiting time = "
         << (float)twt / (float)n;
    cout << "\nAverage turn around time = "
         << (float)tat / (float)n;  
    return 0;
}
