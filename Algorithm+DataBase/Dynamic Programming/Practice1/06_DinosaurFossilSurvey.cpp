#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <algorithm>

using namespace std;

const vector<long long> schedule =
{
	1000000005,
	1000000006,
	1000000035,
	1000000002,
	1000000011,
	1000000005,
	1000000015,
	1000000025
};
unordered_map<long long, list<long long>> um;

long long HashFunc(const long long& key)
{
	return key % 10;
}

int main(void)
{
	for (int i = 0; i < schedule.size(); ++i)
	{
		long long hash = HashFunc(schedule[i]);
		um[hash].push_back(schedule[i]);
	}

	long long input;
	cin >> input;

	auto it = um.find(HashFunc(input));
	if (it != um.end())
	{
		list<long long>& l = (*it).second;
		int r = count(l.begin(), l.end(), input);

		cout << r;
	}

	return 0;
}