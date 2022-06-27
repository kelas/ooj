#include"j.h"

J WS=0;

J*ma(J n){n=n*8,WS+=n;R(J*)malloc(n);}_ mv(J*d,J*s,J n){N(n,d[i]=s[i]);}
J tr(J r,J*d){J z=1;N(r,z=z*d[i]);R z;}K i(C c,S s){J i=0;C r;W(r=s[i++])P(r==c,(K)i)R 0;}
K ga(J t,J r,J*d){K z=(K)ma(6+tr(r,d));zt=t,zr=r,mv(zd,d,r);R z;}K1(id){R x;}
K1(ri){R xc++,x;}K1(rd){R xc--,x;}
K1(r0){Z(!x,R(K)0)Z(!xc,WS-=8*(6+tr(xr,xd));free(x);R(K)0)R x;}
K2(x0){R r0(x),rd(y);}K3(xy0){r0(x);r0(y);R rd(z);}

K1(iota){J n=*xp;K z=ri(ga(0,1,&n));N(n,zp[i]=i)R x0(x,z);}
K2(plus){J r=yr,*d=yd,n=tr(r,d);K z=ri(!xc?x:!yc?y:ga(0,r,d));
 N(n,zp[i]=xp[i]+yp[i])R xy0(x,y,z);}
K2(mul){J r=yr,*d=yd,n=tr(r,d);K z=ri(!xc?x:!yc?y:ga(0,r,d));
 N(n,zp[i]=xp[i]*yp[i])R xy0(x,y,z);}
K2(from){J r=yr-1,*d=yd+1,n=tr(r,d);
 K z=ri(ga(yt,r,d));mv(zp,yp+(n**xp),n);R xy0(x,y,z);}
K1(box){K z=ga(1,0,0);ri(x);*zp=(J)x;R z;}
K2(cat){J an=tr(xr,xd),wn=tr(yr,yd),n=an+wn;
 K z=ri(ga(yt,1,&n));mv(zp,xp,an);mv(zp+an,yp,wn);R xy0(x,y,z);}
K2(find){R O("nyi\n"),(K)0;}
K2(rsh){J r=xn,n=tr(r,xp),wn=tr(yr,yd);
 K z=ri(ga(yt,r,xp));mv(zp,yp,wn=n>wn?wn:n);
 if(n-=wn)mv(zp+wn,zp,n);R xy0(x,y,z);}
K1(sha){K z=ri(ga(0,1,&xr));mv(zp,xd,xr);R x0(x,z);}
K1(size){K z=ri(ga(0,0,0));*zp=xn;R x0(x,z);}
K1(fst){K z=ri(ga(0,0,0));*zp=*xp;R x0(x,z);}
K1(rev){J r=xr,*d=xd,n=tr(r,d),i=0;K z=ri(ga(0,r,d));
 N(n,zp[i]=xp[n-i-1])R x0(x,z);}

C vt[]="+{!<#,*|",at[]="\\/";
K(*vd[])(K,K)={0,plus,from,find,0,  rsh,cat,mul,0},
 (*vm[])(K  )={0,id,  size,iota,box,sha,0  ,fst,rev},
 (*va[])(K,K)={0,scan,over};

K2(over){P(Ay,y)K z=ga(0,0,0);J r=0;N(yn,r+=yp[i]);R*zp=r,z;}
K2(scan){P(Ay,y)K z=ga(0,yr,yd);J r=0;N(yn,zp[i]=(r+=yp[i]))R z;}

J sI(S a,J*n){C c;J i=0,r=*n=0;
 W((c=*a++)&&(c>='0'&&c<='9'))i++,r=r*10u+((J)c-'0');R*n=i,r;}
_ pi(J i){O("%lld ",i);}_ nl(){O("\n");}_ pt(){O(" ");}
_ pr(K x){J r=xr,*d=xd,n=tr(r,d);
 Z(xt,N(n,O("< ");pr((K)xp[i])))N(n,pi(xp[i]));r0(x);}
C qp(J a){R a>='a'&&a<='z';}C qv(J a){R a<'a';}
K adv(C c){R i(c,at);}K verb(C c){R i(c,vt);}
K noun(S*a){K z;J l;C c=**a;P(c<'0'||c>'9',(K)0);
 z=ga(0,0,0);*zp=sI(*a,&l);*a+=l-1;R z;}

K ex(K*e){J a=(J)*e,b=(J)e[1];C o;
 Z(qp(a),P(':'==b,K x=st[a-'a'];r0(x?rd(x):x);ri(st[a-'a']=ex(e+2)))a=(J)st[a-'a']);
 P(qv(a)&&adv(b),(*va[(J)adv(b)])((K)a,ex(e+2)))
 R qv(a)?(*vm[a])(ex(e+1)):b?(*vd[b])((K)a,ex(e+2)):(K)a;}

K*wd(S s,J*n){K a,*e;C c;*n=strlen(s);
 P(!n,(K*)0);s[(*n)-1]=0;e=(K*)ma(*n);J i=0;
 W(c=*s){e[i++]=(a=noun(&s))?a:(a=verb(c))?a:((K)(J)c);s++;}
 R e[i]=0,e;}

int main(){C s[99];K *e;J n;W(//O("WS: %llu\n",WS),
 pt(),fgets(s,99,stdin))pr(ex(e=wd(s,&n))),nl(),free(e),WS-=8*n;R 0;}

//:~
