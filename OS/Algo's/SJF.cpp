#include<iostream>
using namespace std;

class SJF_ALGO
{
int size, arrival[20], waiting[20], burst[20], completion[20];
string P[20];

public :
  SJF_ALGO(int ss)
  {
    size=ss;
  }  
  void input()
  {
    string c;
    cout<<"\nEnter ARRIVAL time for each process:-\n";
    for(int i=0; i<size; i++)
      {
        cout<<"p["<<i+1<<"] : ";
        cin>>arrival[i];
        c=to_string(i);
        P[i]=("P"+c);
      }

    cout<<"\nEnter BURST time for each process:-\n";
    for(int i=0; i<size; i++)
      {
        cout<<"p["<<i+1<<"] : ";
        cin>>burst[i];
      }
  }

  void Algo()
  {
    for(int i=0; i<size; i++)
      {
        if(i==0)
          waiting[i]=0;
        else
          waiting[i]=completion[i-1]-arrival[i];
      }
  }

  void sort()
  {

  // sorting acc to arrival time
  int temp=0;
  string temp1;
  
  for(int j=0; j<size-1; j++)
   for(int i=0; i<size-j-1; i++)
    if(arrival[i]>arrival[i+1])
    {
      temp=burst[i];
      burst[i]=burst[i+1];
      burst[i+1]=temp;
     
      temp=arrival[i];
      arrival[i]=arrival[i+1];
      arrival[i+1]=temp;

      temp1=P[i];
      P[i]=P[i+1];
      P[i+1]=temp1;
    }
    
  for(int j=0; j<size-2; j++)
    for(int i=1; i<size-1-j; i++)
      if(burst[i]>burst[i+1])
        {
          temp=burst[i];
          burst[i]=burst[i+1];
          burst[i+1]=temp;

          temp=arrival[i];
          arrival[i]=arrival[i+1];
          arrival[i+1]=temp;
        }
}

void Completion_T()
{
  for(int i=0; i<size; i++)
    {
      if(i==0)
        completion[i]=burst[i];
      else
        completion[i]=burst[i]+completion[i-1];
    }
}

void output()
{
  float flag1=0, flag2=0, flag3=0;
  
  cout<<"\n\nProcess\t\tArrival\t\t\tBurst.T\t\tWaiting.T\t\tCompletion.T\n";
  for(int i=0; i<size; i++)
  {
    cout<<P[i]<<"\t\t\t"<<arrival[i]<<"\t\t\t"<<burst[i]<<"\t\t\t"<<waiting[i]<<"\t\t\t\t"        <<completion[i]<<endl;
    flag1+=waiting[i];
    flag2+=burst[i];
    flag3+=(completion[i]-arrival[i]);
  }
     
  cout<<"\nAverage Waiting time : "<<flag1/size;
  cout<<"\nThroughPut : "<<flag2/size;
  cout<<"\nTurnAround : "<<flag3/size<<endl<<endl;
}
};
  

int main()
{
  int s=0;
  cout<<"Enter total number of process: ";
  cin>>s;
    
  SJF_ALGO obj(s);

  obj.input();
  obj.sort();
  obj.Completion_T();
  obj.Algo();
  obj.output();

  return 0;  
}
