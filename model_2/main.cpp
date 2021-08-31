#include <iostream>
#include <math.h>
#include <fstream>

using namespace std;

double v;
double r_2, r_1, h, l;
double eps;
double u;
double q = -1.6e-19, m = 9.1e-31;

int frequency = 100000;


double f(double r)
{
	return (q * u / (r * log(r_2 / (r_2 - h))));
}



int main()
{
	ifstream fin("config.txt");
	fin
	>> u
	>> r_2 >> h
	>> l
	>> eps
	>> v;
	fin.close();

	double v_x, v_y;
	v_x = v;
	v_y = 0;

	r_1 = r_2 - h;
	double r = (r_2 + r_1) / 2;
	double x = 0, y = r - r_1, a_y = 0;

	ofstream fout_y_x("y_x.txt");
	ofstream fout_y_t("y_t.txt");
	ofstream fout_v_t("v_t.txt");
	ofstream fout_a_t("a_t.txt");

	for (long long dt = 0; x <= l and r < r_2 and r > r_1; dt++)
	{
		double v_ = sqrt(v_x * v_x + v_y * v_y);

		fout_y_x << r << " " << x << endl;
		fout_y_t << y << " " << (double)dt / frequency << endl;
		fout_v_t << v_ << " " << (double)dt / frequency << endl;
		fout_a_t << a_y << " " << (double)dt / frequency << endl;



		a_y = f(r) / m;
		v_y += a_y / frequency;
		r += v_y / frequency;

		x += v_x / frequency;
		y = r - r_1;
	}

	fout_y_x.close();
	fout_y_t.close();
	fout_v_t.close();
	fout_a_t.close();

	return 0;
}
