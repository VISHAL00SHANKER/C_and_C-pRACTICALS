#include<iostream>
using namespace std;

void Bubble_sort(int arr[], int Size)
{
  for(int i=0; i<Size; i++)
    for(int y=0; y<Size-i; y++)
      if(arr[y+1] < arr[y])
        {
          arr[y+1]=arr[y+1]*arr[y];
          arr[y]=arr[y+1]/arr[y];
          arr[y+1]=arr[y+1]/arr[y];
        }
}

int Binary(int arr[],int Initial, int Final, int Value)
{
  int mid=(Initial+Final)/2;

  if(Initial>Final)
    return -1;
  else if(arr[mid]==Value)
    return mid;
  else
  {
    if(arr[mid]<Value)
      return Binary(arr, mid+1, Final, Value);
    else
      return Binary(arr, Initial, mid-1, Value);
  }
}

int Linear(int arr[], int Size, int Value)
{
  Size--;

  if(arr[Size]==Value)
    return Size;
  else if(Size<0)
    return -1;
  else
    return Linear(arr, Size, Value);
}

int main()
{
  int  array[10]={1,12, 23, 34, 45, 56, 67, 78, 89, 110};
  int Search_Element=0, Array_Size=0, Index=0, Choice=0;

  Array_Size = sizeof(array)/sizeof(int);
  // if array isn't in ascending nor decending order
  Bubble_sort(array, Array_Size);
  
  cout<<"\nEnter Element to be search : ";
  cin>>Search_Element;

  cout<<"1] Linear Search\n2] Binary Search\nEnter your Choice : ";
  cin>>Choice;

  switch(Choice)
  {
    case 1: Index=Linear(array, Array_Size, Search_Element);
            if(Index!=-1)
              cout<<"#Element found at Index : "<<Index<<"\n\n";
            else
              cout<<"#Element not found!\n\n";break;

    case 2: Array_Size--;
            Index=Binary(array, 0,  Array_Size, Search_Element);
            if(Index!=-1)
              cout<<"#Element found at Index : "<<Index<<"\n\n";
            else
              cout<<"#Element not found!\n\n";break;
    
    default : cout<<"**case not found!!**\n\n";  
  }
  
  
return 0;
}
