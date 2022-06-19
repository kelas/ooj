#include<stdlib.h> //malloc
#include<stdio.h>  //fgets printf
#include<string.h> //strlen

typedef void _;typedef char C,*S;typedef long I;typedef struct a{I t,r;I d[3];I p[2];}*K;K st[26];

#define O printf
#define R return
#define W(a...)          while(({a;}))                           //!< while
#define N(n,a...)        {I _n=(n),i=-1;W(++i<_n){a;}}           //!< no stinking loops
#define P(b,a...)        if(b)R({a;});                           //!< "bail early" predicate aka panic
#define Z(b,a...)        if(b){a;}else                           //!< be sure to terminate dangling else
#define K1(f) K f(K w)
#define K2(f) K f(K a,K w)

I*ma(I n){R(I*)malloc(n*8);}_ mv(I*d,I*s,I n){N(n,d[i]=s[i]);}
I tr(I r,I*d){I z=1;N(r,z=z*d[i]);R z;}
K ga(I t,I r,I*d){K z=(K)ma(5+tr(r,d));z->t=t,z->r=r,mv(z->d,d,r);R z;}
K1(iota){I n=*w->p;K z=ga(0,1,&n);N(n,z->p[i]=i)R z;}
K2(plus){I r=w->r,*d=w->d,n=tr(r,d);K z=ga(0,r,d);
 N(n,z->p[i]=a->p[i]+w->p[i])R z;}
K2(mul){I r=w->r,*d=w->d,n=tr(r,d);K z=ga(0,r,d);
 N(n,z->p[i]=a->p[i]*w->p[i])R z;}
K2(from){I r=w->r-1,*d=w->d+1,n=tr(r,d);
 K z=ga(w->t,r,d);mv(z->p,w->p+(n**a->p),n);R z;}
K1(box){K z=ga(1,0,0);*z->p=(I)w;R z;}
K2(cat){I an=tr(a->r,a->d),wn=tr(w->r,w->d),n=an+wn;
 K z=ga(w->t,1,&n);mv(z->p,a->p,an);mv(z->p+an,w->p,wn);R z;}
K2(find){R O("nyi\n"),(K)0;}
K2(rsh){I r=a->r?*a->d:1,n=tr(r,a->p),wn=tr(w->r,w->d);
 K z=ga(w->t,r,a->p);mv(z->p,w->p,wn=n>wn?wn:n);
 if(n-=wn)mv(z->p+wn,z->p,n);R z;}
K1(sha){K z=ga(0,1,&w->r);mv(z->p,w->d,w->r);R z;}
K1(size){K z=ga(0,0,0);*z->p=w->r?*w->d:1;R z;}
K1(fst){K z=ga(0,0,0);*z->p=*w->p;R z;}
K1(rev){I r=w->r,*d=w->d,n=tr(r,d);K z=ga(0,r,d);
 N(n,z->p[i]=w->p[n-i-1])R z;}
K1(id){R w;}

I sI(S a,I*n){C c;I i=0,r=*n=0;
 W((c=*a++)&&(c>='0'&&c<='9'))i++,r=r*10u+((I)c-'0');R*n=i,r;}
_ pi(I i){O("%ld ",i);}_ nl(){O("\n");}_ pt(){O(" ");}
_ pr(K w){I r=w->r,*d=w->d,n=tr(r,d);
 Z(w->t,N(n,O("< ");pr((K)w->p[i])))N(n,pi(w->p[i]));}

C vt[]="+{!<#,*|";
K(*vd[])()={0,plus,from,find,0,  rsh,cat,mul,0},
 (*vm[])()={0,id,  size,iota,box,sha,0  ,fst,rev};

C qp(I a){R a>='a'&&a<='z';}C qv(I a){R a<'a';}

K ex(K*e){I a=(I)*e;
 Z(qp(a),P(':'==(I)e[1],st[a-'a']=ex(e+2))a=(I)st[a-'a']);
 R qv(a)?(*vm[a])(ex(e+1)):e[1]?(*vd[(I)e[1]])(a,ex(e+2)):(K)a;}
K noun(S*a){K z;I l;C c=**a;P(c<'0'||c>'9',(K)0);
 z=ga(0,0,0);*z->p=sI(*a,&l);*a+=l-1;R z;}
K verb(C c){I i=0;C r;W(r=vt[i++])P(r==c,(K)i)R 0;}
K*wd(S s){K a,*e;C c;I n=strlen(s);P(!n,(K*)0);s[--n]=0;e=(K*)ma(n+1);n=0;
 W(c=*s){e[n++]=(a=noun(&s))?a:(a=verb(c))?a:((K)(I)c);s++;}R e[n]=0,e;}

int main(){C s[99];W(pt(),fgets(s,99,stdin))pr(ex(wd(s))),nl();R 0;}

//:~
