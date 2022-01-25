#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MOD 33554393
#define MULT 252533
int main(int argc,char **argv) {
  FILE *f;
  char s[100],*s2;
  int row,col,rc,c;
  unsigned long x=20151125;
  f=fopen("d25a.txt","r");
  fgets(s,sizeof(s),f);
  s2=strstr(s,"row")+4;
  row=atoi(s2);
  fgets(s,sizeof(s),f);
  s2=strstr(s,"column")+7;
  col=atoi(s2);
  fclose(f);
  for (rc=2; rc<row+col; rc++) for (c=1; c<rc+1; c++) {
    x=(x*MULT)%MOD;
    if (rc<6) printf("r=%d c=%d %lu\n",rc-c+1,c,x);
    if (col==c && row==rc-c+1) {
      printf("CODE=%lu\n",x);
      return 0;
    }  
  }
}
