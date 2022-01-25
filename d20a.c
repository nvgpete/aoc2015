#include <stdio.h>
#include <string.h>
#define PRESENTS 33100000
int main(int argc,char **argv) {
  int k,n,np=PRESENTS/10,sv[1000000];
  for (n=1;n<500000;n++) sv[n]=1;
  for (n=500000;n<1000000;n++) sv[n]=n+1;
  for (n=2;n<500000;n++) for (k=n;k<1000000;k+=n) sv[k]+=n;
  for (k=1;k<1000000;k++) if (sv[k]>np) break;
  printf("House %d, presents=%d\n",k,sv[k]*10);  
}
