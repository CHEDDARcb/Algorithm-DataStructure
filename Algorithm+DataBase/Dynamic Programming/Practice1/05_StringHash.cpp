#include <iostream>

using namespace std;

long long HornorsMethod(string& id)
{
	long long r = 0;
	const int d = 26;
	for (int i = 0; i < id.size(); ++i)
	{
		r *= d;
		r += id[i];
	}

	return r;
}

int main(void)
{
	string id;

	cin >> id;

	long long id_encryption = HornorsMethod(id);

	cout << id_encryption;
}