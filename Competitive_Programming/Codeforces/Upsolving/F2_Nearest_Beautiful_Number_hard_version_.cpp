#include <bits/stdc++.h>
using namespace std;

// Ref: https://codeforces.com/blog/entry/94009

string solve()
{
	string n;
	int k;
	cin >> n >> k;

	while (true)
	{
		set<char> s;
		for (auto c : n) s.insert(c);
		if (s.size() <= k) return n;

		s.clear();
		for ( int ptr = 0; ptr < n.size() ; ptr++)
		{
			s.insert(n[ptr]);
			if (s.size() > k)
			{
				while (n[ptr] == '9')
					ptr--;
				n[ptr]++;
				for (int i = ptr + 1; i < n.size(); i++)
					n[i] = '0';
				break;
			}
		}
	}
}

int main()
{
	int t;
	cin >> t;

	while (t--)
		cout << solve() << '\n';
	
	return 0;
}