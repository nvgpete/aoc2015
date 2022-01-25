#include <stdio.h>
#include <string.h>
int main(int argc,char **argv) {
  FILE *f;
  int count,i=100,j=100,i2=100,j2=100,xy[200][200];
  char s[10000],*s2,c;
  f=fopen("d03a.txt","r");
  fgets(s,sizeof(s),f);
  if((s2=strchr(s,'\n'))) *s2=0;
  fclose(f);
  memset(xy,0,sizeof(xy));
  s2=s;
  while ((c=*s2++)) {
    switch (c) {
      case '^': xy[j++][i]++;
                if (j>199) printf("Too high %ld\n",s2-s);
                break; 
      case 'v': xy[j--][i]++;
                if (j<0) printf("Too low %ld\n",s2-s);
                break; 
      case '>': xy[j][i++]++;
                if (i>199) printf("Too left %ld\n",s2-s);
                break; 
      case '<': xy[j][i--]++;
                if (i<0) printf("Too right %ld\n",s2-s);
    }
    if (!(c=*s2++)) break;
    switch (c) {
      case '^': xy[j2++][i2]++;
                if (j2>199) printf("Too high %ld\n",s2-s);
                break; 
      case 'v': xy[j2--][i2]++;
                if (j2<0) printf("Too low %ld\n",s2-s);
                break; 
      case '>': xy[j2][i2++]++;
                if (i2>199) printf("Too left %ld\n",s2-s);
                break; 
      case '<': xy[j2][i2--]++;
                if (i2<0) printf("Too right %ld\n",s2-s);
    }
  }
  xy[j2][i2]++;    
  xy[j][i]++;
  count=0;
  for(j=0;j<200;j++) for(i=0;i<200;i++) count+=(xy[i][j]!=0);
  printf("%d houses found\n",count);
}
