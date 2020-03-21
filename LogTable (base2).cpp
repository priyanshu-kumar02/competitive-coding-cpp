// OR JUST USE
// |ceil(log2(x))|  :-)

for (int i = 2;i <= n;++i)
        lg[i] = lg[i/2] + 1;