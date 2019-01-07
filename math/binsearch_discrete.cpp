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
    long double m = (l + r) / 2;
    if(f(m) < need) l = mid;
    else r = mid;
}

//Now answer is l. Check it!
