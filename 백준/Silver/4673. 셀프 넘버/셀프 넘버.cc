#include <iostream>
using namespace std;

int arr[10'002];

int main()
{
    ios_base::sync_with_stdio(false);
	for (int i = 1; i <= 10'000; i++)
	{

		int dn = i;

		int tmp = dn;
		while (tmp > 0)
		{
			dn += tmp % 10;
			tmp = tmp / 10;
		}
        if(dn <=10000)
		    arr[dn] = 1;
	}

	for (int i = 1; i <= 10'000; i++)
		if (arr[i] == 0)
			cout << i << endl;

}
