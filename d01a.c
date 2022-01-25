#include <stdio.h>
#include <string.h>
int main(int argc,char **argv) {
  FILE *f;
  char s[10000],*s2,c;
  int floor=0,bsmt=0;
  f=fopen("d01a.txt","r");
  fgets(s,sizeof(s),f);
  if((s2=strchr(s,'\n'))) *s2=0;
  fclose(f); 
  s2=s;
  while (*s2) {
    if (*s2=='(') floor++;
    else if (*s2==')') { 
      floor--;
      if (floor<0 && bsmt==0) bsmt=s2-s+1;
    }  
    s2++;
  }
 printf("Floor=%d\n",floor);
 printf("First in basement at step %d\n",bsmt);   
}
