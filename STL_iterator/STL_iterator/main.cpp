#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <functional>
using namespace std;
int main()
{
	cout << "����5������,������෴��" << endl;
	vector<int> s(5);
	for (int i = 0; i < 5; ++i)
	{
		cin >> s[i];
	}
	transform(s.begin(), s.end(), ostream_iterator<int>(cout, ""), negate<int>());
	cout << endl;
	system("pause");
	return 0;
}