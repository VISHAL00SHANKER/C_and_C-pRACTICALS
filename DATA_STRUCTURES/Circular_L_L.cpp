#include<bits/stdc++.h>
using namespace std;

class Cnode
{
  Cnode *next, *cursor;
  int ele=0, size=0, num=0;

  public :
  Cnode* Create() // Creating CLL
  {
    Cnode *back=NULL;
    cout<<"\nNumber of nodes in CLL : ";
    cin>>size;
    for(int i=0; i<size; i++)
    {
      Cnode *one = new Cnode;
      cout<<"\nEnter value "<<i+1<<" : ";
      cin>>num;
      one->ele=num;
      
      if(back==NULL)
      {
        one->next=one;
        back=one;
        cursor=one;
      }
      else
      {
        one->next=cursor->next;
        cursor->next=one;
      }
    }
    return cursor;
  }

  void Insert_F() //insert at the front in CLL
  {
    Cnode *one=new Cnode();
    cout<<"\n\t#Insert at the Front of CLL#\nEnter value : ";
    cin>>num;

    one->ele=num;
    one->next=cursor->next;
    cursor->next=one;
  }

  void Insert_At() //insert at any position in CLL
  {
    Cnode *temp=cursor;
    Cnode *one=new Cnode();
    cout<<"\n\t#Insert node at any pos(!Front | !Last)#\nEnter pos : ";
    cin>>size;
    cout<<"Enter value : ";
    cin>>num;

    for(int i=0; i<size-1; i++)
      temp=temp->next;

    one->ele=num;
    one->next=temp->next;
    temp->next=one;
  }

  void Insert_L() //insert at the end in CLL
  {
    Cnode *temp=cursor;
    Cnode *one=new Cnode();
    cout<<"\n\t#Insert at the End of CLL#\nEnter value : ";
    cin>>num;

    one->ele=num;
    one->next=temp->next;
    temp->next=one;

    cursor=one;
  }
  
  void Delete(int a)
  {
    Cnode *temp=cursor, *Rem=NULL;
    if(cursor==NULL)
      cout<<"\n--Underflow--\n";
    
    if(a==1 | a==10) //delete first or any node
    {
      size=a;
      if(a==10)
      {
        cout<<"Enter node position to del : ";
        cin>>size;
      }
      for(int i=0; i<size-1; i++)
        temp=temp->next;
      Rem=temp->next;
      temp->next=temp->next->next;
    }
    if(a==0) // delete last node
    {
      do
      {
        temp=temp->next;
      }while(temp->next!=cursor);
      
      Rem=temp->next;
      temp->next=Rem->next; // Rem->next
      cursor=temp;
    }
    free(Rem);
  }

  void Display()
  {
    Cnode *temp=cursor;
    cout<<"\n\t#Output#\n";
    do
    {
      cout<<temp->ele<<endl;    
      temp=temp->next;
    }while(temp!=cursor);
  }

  void Search()
  {
    int pos = 0;
    bool flag = false;
    Cnode *temp=cursor;
  
    if(temp== NULL)
    {
      cout<<"List is empty--UNDERFLOW--"<<endl;
      return;
    }
    cout<<"Enter the value to be searched : ";
    cin>>num;
  
    do
    {
      pos++;
      if (temp->next->ele == num)
      {
        flag = true;
        cout<<"Element "<<num<<" is found at position : "<<pos<<endl;
      }
      temp=temp->next;
    }
    while (temp != cursor);
  
    if (!flag)
    cout<<"Element "<<num<<" not found in the list"<<endl;  
  }

  void Concate(Cnode *A, Cnode *B) // Concatinate two CLL
  {
    Cnode *temp=A, *temp2=B;
    while(A->next!=temp)
      A=A->next;
    A->next=B;

    while(B->next!=temp2)
      B=B->next;
    B->next=temp;

    cursor=temp;
  }  
};

int main()
{
  Cnode *head, *head2;
  Cnode obj;
  int choice=0;
  char c='Y';

  head=obj.Create();

  while(c=='y' | c=='Y')
  {
    cout<<"\n1]Insert at the front\n2]Insert at the last\n3]Insert at any posotion\n";
    cout<<"4]Delete the Front node\n5]Delete the last node\n6]Delete at any postion";
    cout<<"\n7]Search \n8]Concatenate\nYour choice : ";
    cin>>choice;
  
    switch(choice)
    {
      case 1 : obj.Insert_F();break;

      case 2 : obj.Insert_L();break;

      case 3 : obj.Insert_At();break;

      case 4 : obj.Delete(1);break;

      case 5 : obj.Delete(0);break;

      case 6 : obj.Delete(10);break;

      case 7 : obj.Search();break;

      case 8 : head2=obj.Create();
             obj.Concate(head, head2);break;
    } 
    obj.Display();
    cout<<"Continue(Y/N) : ";
    cin>>c;
  }
  return 0;
}
