#include <stdio.h>
#include <string.h>
int main(int argc,char **argv) {
  FILE *f;
  char s[100],*s2,on,toggle,xy[1000][1000];
  int i,j,i2,j2,i3,j3,count=0;
  memset(xy,0,sizeof(xy));
  f=fopen("d06a.txt","r");
  fgets(s,sizeof(s),f);
  while (!feof(f)) {
    if((s2=strchr(s,'\n'))) *s2=0;
    toggle=(s[6]==' ');
    on=(s[6]=='n');
    if (toggle) s2=s+7;
    else if(on) s2=s+8;
    else s2=s+9;
    sscanf(s2,"%d,%d through %d,%d",&i2,&j2,&i3,&j3);
    for (j=j2;j<=j3;j++) {
      if (toggle) for (i=i2;i<=i3;i++) xy[j][i]+=2;
      else if (on) for (i=i2;i<=i3;i++) xy[j][i]++;
      else for (i=i2;i<=i3;i++) if (xy[j][i]) xy[j][i]--;
    }   
    fgets(s,sizeof(s),f);
  }  
  fclose(f);
  for (j=0;j<1000;j++) for (i=0;i<1000;i++) count+=xy[j][i];
  printf("total brightnes =%d\n",count); 
}
