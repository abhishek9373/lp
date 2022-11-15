#include <bits/stdc++.h>
using namespace std;

int solve(int pages[], int n, int fr)
{
	unordered_set<int> s;
	unordered_map<int, int> indexes;
	int faults = 0;
	for (int i = 0; i < n; ++i)
	{
		if (s.size() < fr)
		{
			if (s.find(pages[i]) == s.end())
			{
				s.insert(pages[i]);
				faults++;
			}
			indexes[pages[i]] = i;
		}
		else
		{
			if (s.find(pages[i]) == s.end())
			{
				int lru = INT_MAX, val;
				for (auto it = s.begin(); it != s.end(); it++)
				{
					if (indexes[*it] < lru)
					{
						lru = indexes[*it];
						val = *it;
					}
				}
				s.erase(val);
				s.insert(pages[i]);
				faults++;
			}
			indexes[pages[i]] = i;
		}
	}
	return faults;
}

int main()
{
	int fr;
	cout << "Enter the frame size : \n";
	cin >> fr;
	int n;
	cout << "Enter total length of string\n";
	cin >> n;
	int pages[n];
	cout << "Enter the string\n";
	for (int i = 0; i < n; ++i)
	{
		cin >> pages[i];
	}

	int j = solve(pages, n, fr);

	cout << "Number of page faults = " << j << endl;
	cout << "Number of page hits= " << n - j << endl;
	cout << "Page fault ratio = " << float(j) / float(n) * 100 << endl;
	cout << "Page hit ratio= " << float(n - j) / float(n) * 100 << endl;

	return 0;
}

/*OUTPUT:
Enter total length of string
13
Enter the string
7
0
1
2
0
3
0
4
2
3
0
3
2
Enter the frame size :
3
Number of page faults = 9
Number of page hits= 4
Page fault ratio = 69.2308
Page hit ratio= 30.7692
*/
