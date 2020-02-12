#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;

#define MAX 10001

pair<double, double> A[MAX];

long double CCW(pair<double, double> a, pair<double, double>b, pair<double, double>c) {
	return (a.first*b.second + b.first*c.second + c.first* a.second) - (a.second*b.first + b.second*c.first + c.second*a.first);
}

int main() {
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> A[i].first;
		cin >> A[i].second;
	}

	long double sum = 0;

	for (int i = 1; i < N-1; i++) {
		sum += (CCW(A[0], A[i], A[i + 1]));
	}
	printf("%.1Lf", fabs(sum)/2.0);

	return 0;

}