#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc,char **argv) {
  FILE *f;
  char s[100],*s2;
  int i,t,max,spd[10],fly[10],rest[10],dist[10],timer[10],pts[10];
  f=fopen("d14a.txt","r");
  fgets(s,sizeof(s),f);
  i=0;
  while (!feof(f)) {
    if((s2=strchr(s,'\n')))*s2=0;
    s2=strstr(s,"fly")+3;
    spd[i]=atoi(s2);
    s2=strstr(s2,"for")+3;
    fly[i]=atoi(s2);
    s2=strstr(s2,"for")+3;
    rest[i]=atoi(s2);
    i++;
    fgets(s,sizeof(s),f);
  }  
  fclose(f);
  memset(dist,0,sizeof(dist));
  memset(pts,0,sizeof(pts));
  for (i=0;i<9;i++) timer[i]=fly[i];
  for (t=0;t<2503;t++) {
    for (i=0;i<9;i++) {
      if (timer[i]>0) {
        dist[i]+=spd[i];
        timer[i]--;
        if (timer[i]==0) timer[i]=-rest[i];
      } else {
        timer[i]++;
        if (timer[i]==0) timer[i]=fly[i];
      }
    }  
    max=dist[0];
    for(i=1;i<9;i++) if (max<dist[i]) max=dist[i];
    for(i=0;i<9;i++) if (dist[i]==max) pts[i]++;
  }
  max=dist[0];
  for(i=1;i<9;i++) if (max<dist[i]) max=dist[i];
  printf("Farthest=%d\n",max);       
  max=pts[0];
  for(i=1;i<9;i++) if (max<pts[i]) max=pts[i];
  printf("Most points=%d\n",max);       
}
