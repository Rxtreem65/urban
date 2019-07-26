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

void vcr(int bcd[10][9], int len)
{
	int xr;
	for (int i = 0; i < len; ++i)
	{
		xr = bcd[i][0];
		for (int j = 1; j < 8; ++j) 
		{
			xr = xr ^ bcd[i][j];
		}
		bcd[i][8] = xr;
	}
}

int main()
{
	char str[10];
	cout << "enter a string max 10 characters:" << endl;
	cin >> str;
	const int len = strlen(str);
	int bcd[10][9];

	decToBcd(str, bcd,len);
	vcr(bcd, len);
	
	cout << "char" << '\t' << "vrc" << '\t' << "bcd value" << endl;

	for (int i = 0; i <len;++i)
	{	
		cout << str[i] << '\t';
		for (int j = 8; j >= 0; --j)
		{
			if(j==8)
				cout << bcd[i][j]<<'\t';
			else
				cout << bcd[i][j];
		}
		cout << endl;
	}
		
	return 0;
}
