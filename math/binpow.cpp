int bpow(int n, int p) {
    if(p == 0) return 1;
    if(p % 2 == 0) return bpow(n * n, p / 2);
    else return bpow(n, p - 1) * n;
}
