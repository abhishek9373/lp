#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout<<"Enter the number of processes : \n";
    cin>>n;
    int burst[n];
    for(int i=0;i<n;++i){
        cout<<"Enter the burst time of process "<<i+1<<endl;
        cin>>burst[i];
    }
    cout<<endl;
    int waiting[n],tat[n];
    int wt=0,tt=0;
    waiting[0]=0;
    for(int i=1;i<n;++i){
        waiting[i]=burst[i-1]+waiting[i-1];
    }
    for(int i=0;i<n;++i){
        tat[i]=waiting[i]+burst[i];
    }
    cout<<"Process\tBurst Time\tWaiting Time\tTurn around time\n";
    for(int i=0;i<n;++i){
        wt+=waiting[i];
        tt+=tat[i];
        cout<<i+1<<"\t"<<burst[i]<<"\t"<<waiting[i]<<"\t"<<tat[i]<<endl;
    }
    cout<<"Total waiting time = "<<wt<<endl;
    cout<<"Total turnaround time = "<<tt<<endl;
    cout<<"Average waiting time = "<<float(wt)/float(n)<<endl;
    cout<<"Average turnaround time = "<<float(tt)/float(n)<<endl;

    return 0;
}