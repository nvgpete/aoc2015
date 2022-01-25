#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc,char **argv) {
  FILE *f;
  char s[100],*s2;
  int sz[20],i=0,j,x,count=0,count2,sum,nc,ncmin=20;
  f=fopen("d17a.txt","r");
  fgets(s,sizeof(s),f);
  while (!feof(f)) {
    if((s2=strchr(s,'\n')))*s2=0;
    x=atoi(s);
    j=i;
    while (j>0 && sz[j-1]<x) {
      sz[j]=sz[j-1];
      j--;
    }
    sz[j]=x;
    i++;   
    fgets(s,sizeof(s),f);
  }  
  fclose(f);
  for (i=0;i<1048576;i++) {
    sum=0;
    nc=0;
    for (j=0;j<20;j++) {
      if ((1<<j)&i) {
        sum+=sz[j];
        nc++;
        if (sum>150) break;
      }
    }
    if (sum==150) { 
      count++;
      if (nc<ncmin) {
        ncmin=nc;
        count2=0;
      } 
      if (nc==ncmin) count2++;
    }    
  }
  printf("%d different ways\n",count);
  printf("%d different ways for %d containers\n",count2,ncmin);        
}
