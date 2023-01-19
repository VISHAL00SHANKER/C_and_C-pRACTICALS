#include<iostream>
using namespace std;
class Node
{
  Node*next, *head;
  int value, size, num;
public:

Node* Create()
  {
    head=NULL;
    Node *temp;
    
    cout<<"\nNumber of nodes in SLL : ";
    cin>>size;
    
    for(int i=0; i<size; i++)
    {
      Node *one = new Node;
      cout<<"\nEnter value "<<i+1<<" : ";
      cin>>num;
      one->value=num;
      
      if(head==NULL)
      {
        head=one;
        temp=head;
      }
      else
      {
        temp->next=one;
        temp=temp->next;
      }
    }
    Display();
    return head;
  }
void Insertion_Beg()
{
  cout<<"\nEnter Value : ";
  cin>>num;
  Node* one = new Node();  
  one->value=num;
  
  if(head==NULL)
    {
      head=one;
      one->next=NULL;
    }
    else
    {
      one->next=head;
      head=one;
    }
    Display();
}

void Insertion_At()
{
  Node *temp=head;
  Node* one = new Node();

  cout<<"\nEnter new Node position() : ";
  cin>>size;
  cout<<"\nEnter Values : ";
  cin>>num;
  one->value=num;
    
  if(size==1)
  {
    one->next=head;
    head=one;
  }
  else
  {
    for(int i=0; i<size-2; i++)
        temp=temp->next;
        
    one->next=temp->next;
    temp->next=one;
  }
  Display();
}

void Display()
{
  Node *a=head;
  cout<<"\nOutput : ";
  while(a!=NULL)
  {
    cout<<a->value<<"\t";
    a=a->next;
  }
  cout<<endl<<endl;
}

void Search()
{
  int pos = 0;
  bool flag = false;
  Node *temp=head;
  
  if(temp == NULL)
  {
    cout<<"--List is empty--"<<endl;
    return;
  }
  
  cout<<"Enter the value to be searched : ";
  cin>>num;
  while (temp != NULL)
  {
    pos++;
    if (temp->value == num)
    {
      flag = true;
      cout<<"Element "<<temp->value<<" is found at position : "<<pos<<endl;
    }
    temp = temp->next;
  }
  
  if (!flag)
    cout<<"Element "<<num<<" not found in the list"<<endl;  
}

void Delete_Pos()
{
  Node *temp=head, *d;
  
  if(temp==NULL)
  {
    cout<<"\n--*UNDERFLOW**--\n";
    return ;
  }
  else
  {
    cout<<"Enter the Position of the value : ";
    cin>>size;
  }
  
  if(size==1)
  {
    d=head;
    head=head->next;
  }
  else
  {
   for(int i=0; i<size-2; i++)
        temp=temp->next;
        
    d=temp->next;
    temp->next=d->next;
  }
    free(d);
    cout<<"\nElement deleted successfully!\n";
    Display();
}

void Concatenate(Node *a,Node *b)
{
  head=a;
  if(a==NULL | b==NULL )
    cout<<"\n--EMPTY LIST\n";
  
  while(a->next != NULL)
    a=a->next;  

  a->next=b;
  Display();
}

};

int main()
{
  Node* head, *head2;
  int siz=0, choice=0;
  Node obj;
  char c='y';

  head=obj.Create();
  
  while(c=='y' | c=='Y')
  {
    cout<<"\t--**FUNCTIONALITY**--\n1] Insertion in the Beginning\n2] Insertion At\n3] Search\n4] Delete_Position\n5] Concatenate\nChoose any one option : ";
    cin>>choice;

    switch(choice)
    {
      
      case 1: obj.Insertion_Beg();break;
      
      case 2: obj.Insertion_At();break;
      
      case 3: obj.Search();break;

      case 4: obj.Delete_Pos();break;

      case 5: head2=obj.Create();
              obj.Concatenate(head, head2);break;
      
    }
    cout<<"Continue(Y/N) : ";
    cin>>c;
  }
  return 0;
}
