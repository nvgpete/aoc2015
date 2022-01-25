#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc,char **argv) {
  FILE *f;
  char s[100],*s2,used=0,c2,c3,c4,c5,c6,c7;
  int i,i2,i3,i4,i5,i6,i7,i8,tot,best=999999,worst=0;
  int dist[10][10];
  f=fopen("d09a.txt","r");
  fgets(s,sizeof(s),f);
  i=0; i2=1;
  while (!feof(f)) {
    if((s2=strchr(s,'\n')))*s2=0;
    s2=strchr(s,'='); 
    dist[i][i2]=dist[i2][i]=atoi(s2+1);
    i2++;
    if (i2>7) {
      i++;
      i2=i+1;
    }  
    fgets(s,sizeof(s),f);
  }  
  fclose(f); 
  for (i=0;i<8;i++) {
    used=1<<i;
    for (i2=0;i2<8;i2++) {  
      c2=1<<i2;
      if(used & c2) continue;
      used|=c2;
      tot=dist[i][i2];
      for (i3=0;i3<8;i3++) {
        c3=1<<i3;
        if(used & c3) continue;
        used|=c3;
        tot+=dist[i2][i3];
        for (i4=0;i4<8;i4++) {
          c4=1<<i4;
          if(used & c4) continue;
          used|=c4;
          tot+=dist[i3][i4];
          for (i5=0;i5<8;i5++) {
            c5=1<<i5;
            if(used & c5) continue;
            used|=c5;
            tot+=dist[i4][i5];
            for (i6=0;i6<8;i6++) {
              c6=1<<i6;
              if(used & c6) continue;
              used|=c6;
              tot+=dist[i5][i6];
              for (i7=0;i7<8;i7++) {
                c7=1<<i7;
                if(used & c7) continue;
                used|=c7;
                tot+=dist[i6][i7];
                for (i8=0;i8<8;i8++) {
                  if(used & (1<<i8)) continue;
                  if (best>tot+dist[i7][i8]) best=tot+dist[i7][i8];
                  if (worst<tot+dist[i7][i8]) worst=tot+dist[i7][i8];  
                }
                tot-=dist[i6][i7];
                used^=c7;
              }   
              tot-=dist[i5][i6];
              used^=c6;
            }  
            tot-=dist[i4][i5];
            used^=c5;
          }  
          tot-=dist[i3][i4];
          used^=c4;
        }
        tot-=dist[i2][i3];    
        used^=c3;
      }
      used^=c2;
    }    
  }
  printf("Min distance = %d\n",best);    
  printf("Max distance = %d\n",worst);    
}
