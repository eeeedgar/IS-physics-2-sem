#include <iostream>
#include <fstream>
#include "rocket_science.hpp"
#include <math.h>

using namespace std;

int main()
{
	ifstream fin("config.txt");

	int frequency;
	double earth_mass;
	int earth_radius;

	int rocket_mass;
	double fuel_weight;
	double gas_outflow_speed;
	double fuel_combustion_rate;
	double angle;
	int height_limit;

	fin
	>> frequency
	>> earth_mass
	>> earth_radius
	>> rocket_mass
	>> fuel_weight
	>> gas_outflow_speed
	>> fuel_combustion_rate
	>> angle
	>> height_limit;
	fin.close();

	Rocket rocket = Rocket(
		frequency, rocket_mass, angle,
		fuel_weight, gas_outflow_speed, fuel_combustion_rate,
		earth_mass, earth_radius);


	ofstream fout("plot.txt");
	while (rocket.y < height_limit and rocket.y > -100)
	{
		fout
		<< rocket.x << " " << rocket.y << '\n';

		rocket.update();
	}
	fout.close();


	return 0;
}
