#ifndef _ROCKET_SCIENCE_HPP_
#define _ROCKET_SCIENCE_HPP_

#include <math.h>

double GRAVITATIONAL_CONSTANT = 6.6743e-11;

class Rocket
{
 public:
	double x = 0, y = 0;
	double weight;
	double ds = 0, speed_x = 0, speed_y = 0;
	double rotation;

	double fuel_weight;
	double gas_outflow_speed;
	double fuel_combustion_rate;

	int frequency;
	double planet_mass;
	int planet_radius;

	Rocket(int frequency_,
		int rocket_mass_, double angle_,
		double fuel_weight_, double gas_outflow_speed_, double fuel_combustion_rate_,
		double planet_mass_, int planet_radius_)

		: frequency(frequency_)
		, weight(rocket_mass_)
		, rotation(angle_)

		, fuel_weight(fuel_weight_)
		, gas_outflow_speed(gas_outflow_speed_)
		, fuel_combustion_rate(fuel_combustion_rate_)

		, planet_mass(planet_mass_)
		, planet_radius(planet_radius_)

	{
	}

	void update()
	{
		update_speed();
		update_position();
		update_rotation();
	}

	void update_position()
	{
		x += speed_x / frequency;
		y += speed_y / frequency;
	}

	void update_speed()
	{
		gravity_effect();
		jet_effect();
	}

	void update_rotation()
	{
		rotation = atan2(speed_y, speed_x) * 180 / M_PI;
	}

	void gravity_effect()
	{
		speed_y -= g() / frequency;
	}

	double g()
	{
		return GRAVITATIONAL_CONSTANT * planet_mass / (planet_radius + y) / (planet_radius + y);
	}

	void jet_effect()
	{
		if (fuel_weight > 0)
		{
			ds = (fuel_combustion_rate / frequency) * gas_outflow_speed /
				(weight + fuel_weight - (fuel_combustion_rate / frequency));
			fuel_weight -= fuel_combustion_rate / frequency;
			speed_x += ds * cos(rotation / 180 * M_PI);
			speed_y += ds * sin(rotation / 180 * M_PI);
		}
	}

	void show()
	{
		std::cout << speed_x << "\t" << speed_y << std::endl;
	}
};


#endif //_ROCKET_SCIENCE_HPP_
