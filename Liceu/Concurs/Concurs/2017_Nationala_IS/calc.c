#include<stdio.h>

#define SQR(x) x*x

int main()
{
  int t;
  long long a, b, c, x, y;

  scanf("%d", &t);

  while(t)
  {
    scanf("%lld%lld%lld", &a, &b, &c);

    x = SQR(a + c);
    y = SQR(b - c);

    printf("%lld\n", x + y);

    t--;
  }

  return 0;
}
