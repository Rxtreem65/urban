#include <iostream>
#include <string>

using namespace std;

void decToBcd (char ch, int bcd[10])
{
	int x = ch - 48;
	for (int j = 0 ; j < 10 ; ++j)
	{
		if (j > 7)
		{
			bcd[j] = 0;
			cout << bcd[j];

		}
		else
		{
			bcd[j] = x % 2;
			x = x / 2;
			cout << bcd[j];
		}
			
	}
	cout << endl;
}

void crc(int bcd[10], int divisor[4],int cr[3])
{
	int temp[10];
	for (int j = 0; j < 10; ++j)
		temp[j] = bcd[j];

	int i = 0;
	int rem=1;
	while (i<7)
	{	
		if (temp[i] == 1)
		{
			cout << "rem" << rem++ << ":";
			for (int j = 0; j < 4; ++j)
			{
				temp[i+j] = (temp[i + j] ^ divisor[j]);
				cout <<temp[i + j];
			}
			cout << endl;
		}
		++i;
	}

	for (int j = 0; j < 3; ++j,++i)
	{
		cr[j] = temp[i];
		
	}
}

int main()
{
	char ch;
	int divisor[4];
	int cr[3] = {0,0,0};
	cout << "enter a characters:" << endl;
	cin >> ch;
	cout << "enter the divisor(max 4 bit):" << endl;
	for (int i = 0; i < 4; ++i)
	{
		cin >> divisor[i];
	}

	int bcd[10];
	decToBcd(ch, bcd);
	crc(bcd, divisor, cr);

	cout << "the new bit stream is:";
	for (int i = 0; i < 7 ; ++i)
	{
		cout << bcd[i];
	}
	cout << '\t';
	for (int i = 0; i < 3; ++i)
	{
		cout << cr[i];
	}
	return 0;
}