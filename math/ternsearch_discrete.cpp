//Your function
long double f(long double x) {
  //...
}

...

const long double eps = 1e-6;
long double l = 0, r = 1e9;
long double need;

//YOUR CHOICE:
//while(r - l > eps) {
//for(int i = 0; i < 400; i++) {
    long double m1 = l + (r - l) / 3;
    long double m2 = r - (r - l) / 3;
    if(f(m1) < f(m2)) l = m1;
    else r = m2;
}

//Now answer is l. Check it!
