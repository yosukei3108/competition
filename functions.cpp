#include <bits/stdc++.h>
using namespace std;

double distance (double x1, double x2, double y1, double y2) {
  return sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
}

double heron (double a, double b, double c) {
  double s = (a + b + c) / 2.0;
  return sqrt(s * (s - a) * (s - b) * (s - c));
}

#define PI 3.141592653589793

// 角度(degree)からラジアン(radian)に変換
double radian = degree * PI / 180.0;

// ラジアン(radian)から角度(degree)に変換
double degree = radian * 180.0 / PI;

// 10 進数の各桁の和を求める関数
int summationOfDigits(int n) {
    int sum = 0;

    while(n > 0) {
        sum += n % 10;
        n /= 10;
    }

    return sum;
}

int main (void) {
  return 0;
}
