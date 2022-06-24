#pragma once
#include<stdlib.h> //malloc
#include<stdio.h>  //fgets printf
#include<string.h> //strlen

typedef void _;typedef char C,*S;typedef long long J;typedef struct a{J t,r;J d[3];J p[2];}*K;static K st[26];

#define O printf
#define R return
#define W(a...)          while(({a;}))                           //!< while
#define N(n,a...)        {J _n=(n),i=-1;W(++i<_n){a;}}           //!< no stinking loops
#define P(b,a...)        if(b)R({a;});                           //!< "bail early" predicate aka panic
#define Z(b,a...)        if(b){a;}else                           //!< be sure to terminate dangling else

#define K1(f) K f(K x)
#define K2(f) K f(K x,K y)

#define xt x->t
#define xr x->r
#define xd x->d
#define xp x->p

#define yt y->t
#define yr y->r
#define yd y->d
#define yp y->p

#define zt z->t
#define zr z->r
#define zd z->d
#define zp z->p

//:~
