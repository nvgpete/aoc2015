#include <stdio.h>
#include <string.h>
int main(int argc,char **argv) {
  FILE *f;
  char s[100],*s2,last,c;
  int dbl,v,nice=0;
  f=fopen("d05a.txt","r");
  fgets(s,sizeof(s),f);
  while (!feof(f)) {
    if((s2=strchr(s,'\n')))*s2=0;
    v=(*s=='a'||*s=='e'||*s=='i'||*s=='o'||*s=='u');
    dbl=0;
    s2=s;
    last=*s2++;
    while ((c=*s2++)) {
      if (c==last) dbl=1;
      if (c=='a'||c=='e'||c=='i'||c=='o'||c=='u') v++;
      if (last=='a'&&c=='b') {v=0; break;}
      if (last=='c'&&c=='d') {v=0; break;}
      if (last=='p'&&c=='q') {v=0; break;}
      if (last=='x'&&c=='y') {v=0; break;}
      last=c;
    }
    nice+=(dbl && v>=3);  
    fgets(s,sizeof(s),f);
  }  
  fclose(f); 
  printf("%d nice strings\n",nice);
}
