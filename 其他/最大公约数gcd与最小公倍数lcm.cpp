
//最大公约数
//利用辗转相除法
//若gcd(a, b)==1，说明a与互质
int gcd(int a, int b)
{
	return b ? gcd(b, a % b) : a;
}

//lcm(a, b)*gcd(a, b) = a * b
int lcm(int a, int b)
{
	return a * b / gcd(a, b);
}
