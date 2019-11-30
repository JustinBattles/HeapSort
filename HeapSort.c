#define SIZE 300000
#include<stdio.h>
#include<time.h>

long a[SIZE];
int n;  //filled indices 1, 2, ... , n

void siftDown(int indx) {
  if (2*indx>n) return;
  int largest = 2*indx;
  if (2*indx+1<=n)
    if (a[2*indx+1]>a[2*indx])
      largest = 2*indx+1;
  //
  if (a[largest]>a[indx]) {
    int tmp = a[largest];
    a[largest]=a[indx];
    a[indx] = tmp;
    siftDown(largest);
  }
}

int main() {
  //read numbers into the array
  FILE *fp = fopen("num2", "r");
  int n=1;
  while( fscanf(fp, "%ld", a+n)==1)
    n++;
  n--;
  printf("%d\n", n);  
  int n0=n;
  //
//sort
  long t0 = time(0);
  printf("%ld\n", t0);
  //build the heap
  int i;
  for(i=n/2; i>0; i--)
    siftDown(i);
  //
  while(n>1) {
    //swap(1, n);  //fix this
    long tmp = a[1];
    a[1] = a[n];
    a[n] = tmp;
    //
    n--;
    //rebuild the heap
    siftDown(1);
  }
  printf("%ld\n", time(0)-t0);
  for(i=2; i<=n; i++)
     if (a[i]<a[i-1]) printf("Not sorted\n");
}
