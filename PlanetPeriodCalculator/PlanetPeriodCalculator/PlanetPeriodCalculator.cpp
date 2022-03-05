
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdio>

using namespace std;

double get_variance(vector<double> v) {

	int ss = v.size();
	if (ss == 0) {
		return 0.0;
	}

	double result = 0;
	double m = 0;
	for (int i = 0; i != ss; i++) {
		m += v[i];
	}
	m /= static_cast<double>(ss);

	for (int i = 0; i != ss; i++) {
		double x = v[i] - m;
		x *= x;
		result += x;
	}
	result /= static_cast<double>(ss);

	return result;
}

void calculatePeriod(vector<double> v) {

	clock_t start, middle;
	start = clock();

	int ss = v.size();
	if (ss == 0) {
		return;
	}
	vector<double> v2(v);
	vector<int> v2_i(ss);
	double lowest_error = get_variance(v2);

	while (true) {

		int lowest = 0;
		for (int i = 0; i != ss; i++) {
			if (v2[i] < v2[lowest]) {
				lowest = i;
			}
		}

		v2[lowest] += v[lowest];
		v2_i[lowest]++;
		double error = get_variance(v2);

		if (error </* 5 * (lowest_error - numeric_limits<double>::min())*/0.3) {
			if (error < lowest_error - numeric_limits<double>::min()) {
				lowest_error = error;
			}

			cout << error << endl << endl;
			for (int i = 0; i != ss; i++) {
				printf("%30.15lf * %7d = %30.15lf\n", v[i], v2_i[i] + 1, v2[i]);
			}
			cout << endl << endl;

			if (error == 0.0) {
				return;
			}
		}

		middle = clock();
		if ((static_cast<double>(middle - start) / static_cast<double>(CLOCKS_PER_SEC)) > 20) {
			return;
		}
	}

}

int main() {


	int n;
	cin >> n;

	vector<double> v;

	for (int i = 0; i != n; i++) {

		while (true) {
			double d;
			cin >> d;
			if (d > 0.0) {
				v.push_back(d);
				break;
			}
		}
	}

	calculatePeriod(v);

	cout << "end" << endl;

	return 0;

}
