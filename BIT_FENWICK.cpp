int n = 1000000;

int BIT[1000001];

void update(int x, int delta)
{
      for(; x <= n; x += x&-x)
        BIT[x] += delta;
}

int query(int x)
{
     int sum = 0;
     for(; x > 0; x -= x&-x)
        sum += BIT[x];
     return sum;
}
