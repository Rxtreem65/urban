#include <iostream>
#include <string>

using namespace std;

void decToBcd(string ch, int bcd[10][9], int len)
{
	int x;
	for (int i = 0; i < len; ++i)
	{
		x = ch[i] - 48;

		for (int j = 0; j < 8; ++j)
		{
			bcd[i][j] = x % 2;
			x = x / 2;
		}
	}
}

void lrc(int bcd[10][9], int len)
{
	int xr;
	for (int j = 0; j < 8; ++j)
	{
		xr = bcd[0][j];
		for (int i = 1; i < len ; ++i)
		{
			xr = xr ^ bcd[i][j];
		}
		bcd[len][j] = xr;
	}
}

int main()
{
	char str[10];
	cout << "enter a string max 10 characters:" << endl;
	cin >> str;
	const int len = strlen(str);
	int bcd[10][9];

	decToBcd(str, bcd, len);
	lrc(bcd, len);

	cout << "char" << '\t' << "bcd value" << endl;

	for (int i = 0; i < len; ++i)
	{
		
		cout << str[i] << '\t';
		for (int j = 7; j >= 0; --j)
		{
			cout << bcd[i][j] << '\t';
		}
		cout << endl;

	}

	cout << "lrc" << '\t';
	for (int j = 7; j >= 0; --j)
		cout << bcd[len][j] << '\t';

	return 0;
}
