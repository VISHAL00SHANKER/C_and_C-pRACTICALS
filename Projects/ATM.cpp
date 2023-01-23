#include<bits/stdc++.h>
using namespace std;

class ATM
{
  double bal=10000.365;

  public:
  void Balance_Enquiry()
  {
    cout<<" Bank Balance : "<<bal<<endl;
  }
  void Cash_Withdraw()
  {
    int minus=0; 
    cout<<"Enter Amount : ";
    cin>>minus;
    cout<<"Your Cash "<<minus<<" Withdrawn Successfully\n";
    bal-=minus;
    cout<<"Current Bank Balance  : "<<bal<<endl;
  }
  void Deposit_Cash()
  {
    int plus=0; 
    cout<<"Enter Amount : ";
    cin>>plus;
    cout<<"Your Cash "<<plus<<" Deposited Successfully\n";
    bal+=plus;
    cout<<"Current Bank Balance  : "<<bal<<endl;

  }
};

int main()
{
  int choice=0;
  char Rep='Y';
  ATM obj;
  
  cout<<"Enter any option to be served:-\n";
  while(Rep=='y' || Rep =='Y')
    {
      cout<<"1) Balance Enquiry\n2) Cash Withdraw\n3) Deposit Cash\n4) Exit";
      cout<<"\nchoice : ";
      cin>>choice;

      switch(choice)
        {
          case 1 : obj.Balance_Enquiry();break;
          case 2 : obj.Cash_Withdraw();break;
          case 3 : obj.Deposit_Cash();break;
          case 4 : exit(0);break;
          default : cout<<"\n Invalid Input\n";
        }
      cout<<"Want another transaction(Y/N) : ";
      cin>>Rep;
    }
  return 0;
}
