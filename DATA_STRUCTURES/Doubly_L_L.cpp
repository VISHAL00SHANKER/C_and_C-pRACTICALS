#include<bits/stdc++.h>
using namespace std;

class Node
{
  int ele, size, num;
  Node *next, *prev;
  Node *Head;
  public:

  Node* Create_Node(Node *a)
  {
    Head=NULL;
    Node *temp;

    cout<<"Number of Elements in #DLL# : ";
    cin>>size;
    cout<<"\nEnter Values : \n";
    for(int i=0; i<size; i++)
    {
      Node* one = new Node();
      cout<<i+1<<" : ";
      cin>>num;
      one->ele=num;
      if(Head==NULL)
      {
        Head=one;
        a=Head;
        temp=Head;
        Head->prev=NULL;
        Head->next=NULL;
        temp->next=NULL;
      }
      if(i>0)
      {
        one->next=temp->next;
        temp->next=one;
        one->prev=temp;
        temp=temp->next;
        temp->next=NULL;
      }
    }
    return a;
  }

  void Insertion_Last()
  {
    Node *A=Head;
    int num=0;

    cout<<"\nHow many nodes u want : ";
    cin>>size;
    cout<<"\nEnter Values : \n";

    while(A->next!=NULL)
    {
        A=A->next;
    }
    for(int i=0; i<size; i++)
    {
      Node* one = new Node();
      cout<<i+1<<" : ";
      cin>>num;
      one->ele=num;
      if(A->prev!=NULL & A->next==NULL)
      {
        one->next=A->next;
        A->next=one;
        one->prev=A;
        A=A->next;
        A->next=NULL;
      }
    }
  }

  void Insertion_Beg()
  { 
    Node *A=Head;
    cout<<"\nHow many nodes u want : ";
    cin>>size;
    cout<<"\nEnter Values : \n";

    for(int i=0; i<size; i++)
    {
      Node* one = new Node();
      cout<<i+1<<" : ";
      cin>>num;
      one->ele=num;
      if(A->prev==NULL)
      {
        one->next=A;
        one->prev=NULL;
        A=one;
      }
    }
    Head=A;
  }

  void Insertion_At_I()
  {
    Node *temp=Head;
    Node *one= new Node();
    cout<<"Give the position for new node : ";
    cin>>size;
    cout<<"New node value : ";
    cin>>num;
    
    for(int i=0; i<size-1; i++)
    {
      temp=temp->next;
    }
  
    one->ele=num;
    temp->next->prev=one;
    one->next=temp->next;
    temp->next=one;
    one->prev=temp;
  }

  void Delete_At_I()
  {
    Node *temp=Head, *Rem;
    cout<<"Delete node Position : ";
    cin>>size;

    if(Head==NULL)
      cout<<"underflow Detected\n";
    
    if(size==1)// beg
    {
      Rem=temp;
      Head=temp->next;
      Head->prev=NULL;
    }
    else
    {
      for(int i=0; i<size-2; i++)
      {
        temp=temp->next;
      }

      if(temp->next->next==NULL)//last
      {
        Rem=temp->next;
        temp->next=NULL;
      }
      else // i position
      {
        Rem=temp->next;
        temp->next=Rem->next;
        Rem->next->prev=temp;
      }
    }
    
    free(Rem);
    cout<<"Element deleted successfully!\n";
  }

  void Concatenate(Node *A,Node *B)
  {
    Head=A;
    while(A->next!=NULL)
      A=A->next;   

    A->next=B;
    B->prev=A;
  }

  Node* Search()
  {
    Node *temp=Head;
    cout<<"Enter element you want to search : ";
    cin>>size;
    while(temp!=NULL)
    {
      if(size==temp->ele)
        return temp;break;
    
      temp=temp->next;
    }
    return temp;
  }

  void Display()
  {
    Node *temp=Head;
    cout<<"Output : \n";
    while(temp!=NULL)
    {
      cout<<temp->ele<<endl;
      temp=temp->next;
    }
  }
};

int main()
{
  Node* head, *head2, *head3;
  int choice=0;
  char c='y';

  Node obj;
  head=obj.Create_Node(head);
  
  while(c=='y' | c=='Y')
  {
     cout<<"\t--**FUNCTIONALITY**--\n1] Insertion in the Beginning\n2] Insertion in the end\n3] Insertion at the Ith pos\n4] Search\n5] Delete_Position\n6] Concatenate\n7]Display\nChoose any one option : ";
    cin>>choice;

    switch(choice)
    {
      case 1: obj.Insertion_Beg();break;
      
      case 2: obj.Insertion_Last();break;
      
      case 3: obj.Insertion_At_I();break;
      
      case 4: head3=obj.Search();
              cout<<"Element found successfully! at :  "<<head3<<endl;break;

      case 5: obj.Delete_At_I();break;

      case 6: cout<<"\nDouble link_List_2 values \n ";
              head2=obj.Create_Node(head2);
              obj.Concatenate(head, head2);break;
      
      case 7: obj.Display();break;
    }
    cout<<"Continue(Y/N) : ";
    cin>>c;
  }
  return 0;
}
