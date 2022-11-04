/*13. Write a program to implement first-fit, best-fit and worst-fit allocation strategies*/
//		FIRST/ BEST/ WORST FIT Algo.

#include<bits/stdc++.h>
#include<unistd.h>
using namespace std;

class Memory
{
  int size1, size2;
  int Physical_Memo[20], Prcs_Segment[20], F1[20], F2[20], W1[20], W2[20], B1[20], B2[20];
  public :

  void Input_Prcs()
  {
    cout<<"Enter Total number of processes : ";
    cin>>size1;

    cout<<"\nEnter each process value(KB) : \n";
    for(int i=0; i<size1; i++)  
    {
      cout<<"P"<<i<<" : ";
      cin>>Prcs_Segment[i];
      F1[i]=Prcs_Segment[i];;
      W1[i]=Prcs_Segment[i];;
      B1[i]=Prcs_Segment[i];;
    }

    cout<<"Enter Total number of memory paritions : ";
    cin>>size2;
    cout<<"\nGive required memory partitions(KB) : \n";
    for(int i=0; i<size2; i++)  
    {
      cout<<"S"<<i<<" : ";
      cin>>Physical_Memo[i];
      F2[i]=Physical_Memo[i];
      W2[i]=Physical_Memo[i];
      B2[i]=Physical_Memo[i];
    }
  }

  void FirstFit();
  void WorstFit();
  void BestFit();
  void Print(int *Memo, string *S, int *Prcs);

};

void Memory :: FirstFit()
  {
    int flag=0;
    string S[20];
    for(int i=0; i<size1; i++)
    {
      for(int j=0; j<size2; j++)
        if(F1[i] <= F2[j] && i<size1)
        {
          F2[j]-=F1[i]; 
          F1[i]=-1;
          S[j]+=" P"+ to_string(i) + ",";
          if(j==size2-1)
          {
          }
          else
            i++;
        }
        
    }
    Print(F2, S, F1);
  }
void Memory :: WorstFit()
  {
    int flag=0;
    string S[20];
    
    for(int i=0; i<size1; i++)
    {
      for(int j=0; j<size2; j++)
        if(W1[i]<=W2[j])
        {
          flag=j;
          for(int z=j+1; z<size2; z++)
          {
            if(W2[flag]<W2[z])
              flag=z;
          }
          W2[flag]-=W1[i]; 
          W1[i]=-1;
          S[flag]+=" P"+ to_string(i) + ",";
          break;
        }
    }
    Print(W2, S, W1);
  }
void Memory :: BestFit()
  {
    int flag=0;
    string S[20];
    
    for(int i=0; i<size1; i++)
    {
      for(int j=0; j<size2; j++)
        if(B1[i]<=B2[j])
        {
          flag=j;
          for(int z=j+1; z<size1; z++)
          {
            if(B2[flag]>B2[z] && B1[i]<=B2[z])
              flag=z;
          }
          B2[flag]-=B1[i]; 
          B1[i]=-1;
          S[flag]+=" P"+ to_string(i) + ",";
          break;
        }
    }
    Print(B2, S, B1);
  }
 
void Memory:: Print(int *Memo, string *S, int *Prcs)
  {
    cout<<"\nSegments\t\tMain memory(LEFTOVER)\n";
    
    for(int i=0; i<size2; i++)
      cout<<"\tS"<<i<<"\t\t\t\t\t"<<Memo[i]<<"("<<S[i]<<")"<<endl;
      
     for(int i=0; i<size1; i++)
     {
      if(Prcs[i]!=-1)
        cout<<"\n*P"<<i<<" : UNALLOCATED";
     }
    cout<<endl;
  }
int main()
{
  Memory obj;
  obj.Input_Prcs();

  cout<<"\n\t#MEMORY ALLOCATION#";
  cout<<"\n\n3) First Fit";
  obj.FirstFit();
  cout<<"\n\n1) Best Fit";
  obj.BestFit();
  cout<<"\n\n2) Worst Fit";
  obj.WorstFit();
  
  return 0;
}
