#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int countobj(char **s) {
  char c,*s2;
  int red=0,n=0;
  s2=*s;
  while ((c=*s2++)!='}') {
    if (c=='{') n+=countobj(&s2); 
    else if (c=='-' || (c>='0' && c<='9')) {
      n+=atoi(s2-1);
      while (*s2>='0' && *s2<='9') s2++;
    }
    else if (c==':') {
      if (strncmp(s2,"\"red\"",5)==0) red=1;
    }  
  }
  *s=s2;
  if (red) return 0; else return n; 
}  
int main(int argc,char **argv) {
  FILE *f;
  char s[30000],*s2,c;
  int n=0;
  f=fopen("d12a.txt","r");
  fgets(s,sizeof(s),f);
  if((s2=strchr(s,'\n')))*s2=0;
  fclose(f);
  s2=s;
  while ((c=*s2++)) {
    if (c=='{') n+=countobj(&s2); 
    else if (c=='-' || (c>='0' && c<='9')) {
      n+=atoi(s2-1);
      while (*s2>='0' && *s2<='9') s2++;
    }
  }
  printf("Sum of numerics=%d\n",n);    
}
