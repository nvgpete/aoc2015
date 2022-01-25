#include <stdio.h>
#include <string.h>
int best=999999;
struct game {
  char shield,poison,recharge,bhit,bdmg,hit;
  short mana,spent;
  };
void mv(struct game g);
void mvb(struct game g) {
  if (g.shield) { 
    g.shield--;
    g.hit+=7;
  }  
  if (g.poison) {
    g.poison--;
    g.bhit-=3;
    if (g.bhit<=0) {
      if (g.spent<best) best=g.spent;
      return;
    }
  }
  if (g.recharge) {
    g.recharge--;
    g.mana+=101;
  }
  g.hit-=g.bdmg;
  if (g.hit<=0) return;
  mv(g);
}  

void mv(struct game g) {
  struct game gg;
#ifdef PARTB
  g.hit--;
  if (g.hit==0) return;
#endif  
  if (g.shield) g.shield--;
  if (g.poison) {
    g.poison--;
    g.bhit-=3;
    if (g.bhit<=0) {
      if (g.spent<best) best=g.spent;
      return;
    }
  }
  if (g.recharge) {
    g.recharge--;
    g.mana+=101;
  }
  if (g.mana<53) return;
  gg=g;
  gg.mana-=53;
  gg.spent+=53;
  gg.bhit-=4;
  if (gg.bhit<=0) {     
    if (gg.spent<best) {
      best=gg.spent;
      return;
    }  
  } else mvb(gg);
  if (g.mana<73) return;
  gg=g;
  gg.mana-=73;
  gg.spent+=73;
  gg.hit+=2;
  gg.bhit-=2;
  if (gg.bhit<=0) {     
    if (gg.spent<best) {
      best=gg.spent;
      return;
    }  
  } else mvb(gg);
  if (g.mana<113) return;
  if (!g.shield) {
    gg=g;
    gg.mana-=113;
    gg.spent+=113;
    gg.shield=6;
    mvb(gg);
  }
  if (g.mana<173) return;
  if (!g.poison) {
    gg=g;
    gg.mana-=173;
    gg.spent+=173;
    gg.poison=6;
    mvb(gg);
  }
  if (g.mana<229) return;
  if (!g.recharge) {
    gg=g;
    gg.mana-=229;
    gg.spent+=229;
    gg.recharge=5;
    mvb(gg);
  }
}    
int main(int argc,char **argv) {
  FILE *f;
  char s[100];
  struct game g;
  memset(&g,0,sizeof(g));
  g.hit=50;
  g.mana=500;
  f=fopen("d22a.txt","r");
  fgets(s,sizeof(s),f);
  sscanf(s,"Hit Points: %hhu",&g.bhit);
  fgets(s,sizeof(s),f);
  sscanf(s,"Damage: %hhu",&g.bdmg);
  fclose(f); 
  mv(g);
#ifdef PARTB  
  printf("Part b (expert mode) Cheapest=%d\n",best);
#else  
  printf("Part a Cheapest=%d\n",best);
#endif
}
