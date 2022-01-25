#include <stdio.h>
#include <string.h>
int main(int argc,char **argv) {
  FILE *f;
  char s[100],*s2,s3[3],c;
  int dbl,rpt,nice=0;
  f=fopen("d05a.txt","r");
  fgets(s,sizeof(s),f);
  s3[2]=0;
  while (!feof(f)) {
    if((s2=strchr(s,'\n')))*s2=0;
    dbl=0;
    rpt=0;
    s2=s;
    s3[0]=*s2++;
    s3[1]=*s2++;
    while ((c=*s2)) {
      if (c==s3[0]) dbl=1;
      if (strstr(s2,s3)) rpt=1;
      s3[0]=s3[1];
      s3[1]=c;
      s2++;
    }
    nice+=(dbl && rpt);  
    fgets(s,sizeof(s),f);
  }  
  fclose(f); 
  printf("%d nice strings\n",nice);
}
