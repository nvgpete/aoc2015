#include <stdio.h>
#include <string.h>
int main(int argc,char **argv) {
  FILE *f;
  char s[105],*s2,xy[102][102],xy2[102][102];
  int i,j=1,n,cnt;
  memset(xy,0,sizeof(xy));
  memset(xy2,0,sizeof(xy2));
  f=fopen("d18a.txt","r");
  fgets(s,sizeof(s),f);
  while (!feof(f)) {
    if((s2=strchr(s,'\n')))*s2=0;
    for (i=0;i<100;i++) if (s[i]=='#') xy[j][i+1]=1;
    j++;
    fgets(s,sizeof(s),f);
  }  
  fclose(f);
  xy[1][1]=xy[1][100]=xy[100][1]=xy[100][100]=1;
  for (n=0;n<100;n++) {
    for (j=1;j<101;j++) for (i=1;i<101;i++) {
      cnt=xy[j-1][i-1]+xy[j-1][i]+xy[j-1][i+1]+xy[j][i-1]+
          xy[j][i+1]+xy[j+1][i-1]+xy[j+1][i]+xy[j+1][i+1];
      if (cnt==3 || (cnt==2&&xy[j][i])) xy2[j][i]=1;
    }
    memcpy(xy,xy2,sizeof(xy));
    xy[1][1]=xy[1][100]=xy[100][1]=xy[100][100]=1;
    memset(xy2,0,sizeof(xy2));
  }
  cnt=0;
  for (j=1;j<101;j++) for (i=1;i<101;i++) cnt+=xy[j][i];
  printf("%d lights on\n",cnt);     
}
