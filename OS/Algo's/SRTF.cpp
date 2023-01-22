#include<iostream>
using namespace std;
// also called preemptive SJF
class SRTF
{
int size, arrival[20], waiting[20], burst[20], completion[20], burst1[20];

public :
  SRTF(int ss)
  {
    size=ss;
  }  

  void input()
  {
    cout<<"\nEnter ARRIVAL time for each process:-\n";
    for(int i=0; i<size; i++)
      {
        cout<<"p["<<i+1<<"] : ";
        cin>>arrival[i];
      }

    cout<<"\nEnter BURST time for each process:-\n";
    for(int i=0; i<size; i++)
      {
        cout<<"p["<<i+1<<"] : ";
        cin>>burst[i];
        burst1[i]=burst[i];
      }
  }

  void output()
  {
    float flag1=0, flag2=0, flag3=0;
  
    cout<<"\n\nArrival\t\tBurst.T\t\tWaiting.T\t\tCompletion.T\n";
    for(int i=0; i<size; i++)
      {
        cout<<arrival[i]<<"\t\t\t"<<burst1[i]<<"\t\t\t"<<waiting[i]<<"\t\t\t\t"    
        <<completion[i]<<endl;
        flag1+=waiting[i];
        flag2+=burst1[i];
        flag3+=(completion[i]-arrival[i]);
      }
     
    cout<<"\nAverage Waiting time : "<<flag1/size;
    cout<<"\nThroughPut : "<<flag2/size;
    cout<<"\nTurnAround : "<<flag3/size<<endl<<endl;
  }

  void Algo()
  {
    for(int i=0; i<completion[size-1]; i++)
    {
      cout<<"i = "<<i<<endl;
      if(i==0)
        waiting[i]=0;
        
      else
      {
        for(int j=0; j<size; j++)
          {
            if((i+1)==arrival[j] )
            {
            for(int k=0; k<size; k++)
              {
                if(k!=j && burst[k]>0)
                {
                  waiting[k]++;
                }
                else
                {
                  if((i+1)>=arrival[j] | burst[j]>0)
                    burst[j]--;
                }
              }
          }
          else
          {
            if(arrival[j]>i+1)
              waiting[j]++;
          }
        }
      }   
    }

    for(int i=1; i<size; i++)
      waiting[i]=completion[i-1]-arrival[i];
    
  }

  /*void sort()
  {
    int temp=0;
    
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
}*/

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
};
  

int main()
{
  int s=0;
  cout<<"Enter total number of process: ";
  cin>>s;
    
  SRTF obj(s);

  obj.input();
  //obj.sort();
  obj.Completion_T();
  obj.Algo();
  obj.output();

  return 0;  
}
