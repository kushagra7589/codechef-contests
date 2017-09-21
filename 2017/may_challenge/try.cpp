#include <cmath>
#include <iostream>

using namespace std;

int main() 
{
	long double a = log10(100001);
	long double b = log10(100000);
	int c = a*1e5;
	int d = b*1e5;
	printf("%.18Lf %.18Lf %d %d\n", a, b, c, d);
	// cout << a << " " << b << " " << c << " " << d << endl;
	return 0;
}