#include<iostream>
using namespace std;



class MinHeap
{
    int **heap; 
    int capacity; 
    int heap_size; 
public:
    
    MinHeap(int cap)
    {
        heap_size = 0;
        capacity = cap;
        heap = new int*[cap];
        for(int i=0;i<cap;i++)
        {
            heap[i]=new int[2];
        }
    }
  
    void MinHeapify(int i)
    {
        int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < heap_size && heap[l][0] < heap[i][0])
        smallest = l;
    if (r < heap_size && heap[r][0] < heap[smallest][0])
        smallest = r;
    if (smallest != i)
    {
        int temp1=heap[i][0];
        int temp2=heap[i][1];
        heap[i][0]=heap[smallest][0];
        heap[i][1]=heap[smallest][1];
        heap[smallest][0]=temp1;
        heap[smallest][1]=temp2;
        MinHeapify(smallest);
    }
    }
  
    int parent(int i) { 
        return (i-1)/2;
     }
  
    int left(int i) 
    { 
        return (2*i + 1); 
    }
  
    int right(int i) { 
        return (2*i + 2); 
    }
  
    int extractMin(){
         if (heap_size <= 0)
        return 0;
    if (heap_size == 1)
    {
        heap_size--;
        return heap[0][0];
    }
  
        int root = heap[0][0];
        heap[0][0] = heap[heap_size-1][0];
        heap[0][1]=heap[heap_size-1][1];
        heap_size--;
        MinHeapify(0);
  
        return root;
    }
  
  

    int getMin() { 
        return heap[0][0]; 
    }
  
    int indexMin()
    {
        return heap[0][1];
    }
    void insertKey(int k,int index)
    {
        if (heap_size == capacity)
    {
        
        int **temp=new int*[2*capacity];
        for(int i=0;i<capacity;i++)
        {
            for(int j=0;j<2;j++)
            {
                temp[i][j]=heap[i][j];
            }
        }
        
        capacity=2*capacity;
        heap=temp;
        heap_size++;
    int i = heap_size - 1;
    temp[i][0]=k;
    temp[i][1]=index;
    heap=temp;
    while (i != 0 && heap[parent(i)][0] > heap[i][0])
    {
       int temp1=heap[i][0];
        int temp2=heap[i][1];
        heap[i][0]=heap[parent(i)][0];
        heap[i][1]=heap[parent(i)][1];
        heap[parent(i)][0]=temp1;
        heap[parent(i)][1]=temp2;
        i = parent(i);
    }
    return;
    }
  
    
    heap_size++;
    int i = heap_size - 1;
    heap[i][0]=k;
    heap[i][1]=index;

  
    
    while (i != 0 && heap[parent(i)][0] > heap[i][0])
    {
       int temp1=heap[i][0];
        int temp2=heap[i][1];
        heap[i][0]=heap[parent(i)][0];
        heap[i][1]=heap[parent(i)][1];
        heap[parent(i)][0]=temp1;
        heap[parent(i)][1]=temp2;
        i = parent(i);
    }
    }
};
  


void merging(int arr[], int p, int q, int r) {

  int n1 = q - p + 1;
  int n2 = r - q;

  int La[n1], Ma[n2];

  for (int i = 0; i < n1; i++)
    La[i] = arr[p + i];
  for (int j = 0; j < n2; j++)
    Ma[j] = arr[q + 1 + j];

  
  int i, j, k;
  i = 0;
  j = 0;
  k = p;

  while (i < n1 && j < n2) {
    if (La[i] <= Ma[j]) {
      arr[k] = La[i];
      i++;
    } else {
      arr[k] = Ma[j];
      j++;
    }
    k++;
  }

  
  while (i < n1) {
    arr[k] = La[i];
    i++;
    k++;
  }

  while (j < n2) {
    arr[k] = Ma[j];
    j++;
    k++;
  }
}


void mergeSorting(int arr[], int l, int r) {
  if (l < r) {

    
    int m = l + (r - l) / 2;

    mergeSorting(arr, l, m);
    mergeSorting(arr, m + 1, r);


    merging(arr, l, m, r);
  }
}



int main() {
  int n,k;
  cin>>n>>k;
  int arr[n];
  int a,maxsum;
  maxsum=0;
  int b[k];
  for(int i=0;i<n;i++)
  {
    cin>>a;
    if(a<0)
        a=-a;
    else{
        maxsum+=a;
    }
    arr[i]=a;
  }
    b[0]=maxsum;
  
  mergeSorting(arr, 0, n - 1);

  for(int i=2;i<=k;i++)
  {
    MinHeap m(n);

  m.insertKey(arr[0],1);

  int current;
  current=0;
  int min_k=i;
  min_k--;
  while(current<=min_k)
  {
    current++;
    int top;
    int index=m.indexMin();
    
    top=m.extractMin();
    
    if(current==min_k)
           {
             b[min_k]=maxsum-top;
             break;
           }
    if(index !=n)
    {
        
        int index1=m.indexMin();
    
        int x=m.getMin();
    
         x-=arr[index1-1];
         
         m.insertKey(x+arr[index1],index1+1);
        
         x+=arr[index1-1];
        
         m.insertKey(x+arr[index1],index1+1);
        
    }
  }
  
  }

for(int i=0;i<k;i++)
{
    
    cout<<b[i]<<" ";

}
cout<<endl;

  return 0;
}