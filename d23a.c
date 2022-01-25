#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc,char **argv) {
  FILE *f;
  char s[100],*s2,ops[60],rr[60],offs[60];
  unsigned long reg[2];
  int pc=0,maxpc,k;
  f=fopen("d23a.txt","r");
  fgets(s,sizeof(s),f);
  while (!feof(f)) {
    if((s2=strchr(s,'\n')))*s2=0;
    if (strncmp(s,"inc",3)==0) ops[pc]='i';
     else if (strncmp(s,"tpl",3)==0) ops[pc]='t';
     else if (strncmp(s,"hlf",3)==0) ops[pc]='h';
     else if (strncmp(s,"jmp",3)==0) ops[pc]='j';
     else if (strncmp(s,"jio",3)==0) ops[pc]='o';
     else if (strncmp(s,"jie",3)==0) ops[pc]='e';
     if (ops[pc]!='j') rr[pc]=(s[4]=='b');
      else offs[pc]=atoi(s+4);
     if (ops[pc]=='o' || ops[pc]=='e') offs[pc]=atoi(s+6);  
    pc++;
    fgets(s,sizeof(s),f);
  }  
  fclose(f);
  maxpc=pc;
  for (k=0;k<2;k++) {
    pc=0;
    reg[0]=k; reg[1]=0;
    while (pc<maxpc) {
      switch (ops[pc]) {
       case 'i': reg[rr[pc]]++;
                 break;
       case 't': reg[rr[pc]]*=3;
                 break;
       case 'h': reg[rr[pc]]/=2;
                 break;
       case 'e': if ((reg[rr[pc]]&1)==1) break;
                 pc+=offs[pc]-1;
                 break;
       case 'o': if (reg[rr[pc]]!=1) break;
       case 'j': pc+=offs[pc]-1;
    }
    pc++;
    }
    printf("Initial a=%d, Reg b=%lu\n",k,reg[1]);
  }                                       
}
