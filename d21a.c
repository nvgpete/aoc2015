#include <stdio.h>
#include <string.h>
int main(int argc,char **argv) {
  FILE *f;
  int ww[10],weap[9]={0,0,0,0,8,10,25,40,74},arm[6]={0,13,31,53,75,102},rings[8]={0,25,50,100,0,20,40,80};
  int pts,dmg,armor,dm,ar,i,hp,hpb,cost,most=0,least=1000;
  int w,a,r1,r2,win;
  f=fopen("d21a.txt","r");
  fscanf(f,"Hit Points: %d\n",&pts);
  fscanf(f,"Damage: %d\n",&dmg);
  fscanf(f,"Armor: %d\n",&armor);
  fclose(f);
  for (i=1;i<10;i++) {
    hp=100; hpb=pts;
    while (hp>0) {
      hpb-=i;
      if (hpb<=0) break;
      hp-=i;
    }
    ww[i]=(hp>0);
  }
  for (w=4;w<9;w++) for (a=0;a<6;a++) for (r1=0;r1<7;r1++) for (r2=r1+1;r2<8;r2++) {
    cost=weap[w]+arm[a]+rings[r1]+rings[r2];
    dm=w;
    if (r1<4) dm+=r1;
    if (r2<4) dm+=r2;
    ar=a;
    if (r1>3) ar+=r1-4;
    if (r2>3) ar+=r2-4;  
    hp=dm-armor; if (hp<1) hp=1;
    hpb=dmg-ar; if (hpb<1) hpb=1;
    win=(hp>hpb||(hp==hpb&&ww[hp]));
    if (win&&cost<least) least=cost;
    if (!win&&cost>most) most=cost;
  }  
  printf("Cheapest win=%d\n",least);
  printf("Expensive loss=%d\n",most); 
}
