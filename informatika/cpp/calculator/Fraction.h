#ifndef FRACTION_H_
#define FRACTION_H_

#include <iostream>
#include <string>

#include "utils.h"

class Fraction {
public:
	Fraction() {fract=0;};
	virtual ~Fraction() {};
	void set_value_from_string(std::string fraction_string);
	void set_fract(float f);
	float get_fract() const;
	friend std::istream& operator>>(std::istream& in, Fraction& p);
	friend std::ostream& operator<<(std::ostream& out, const Fraction& p);
	Fraction operator + (const Fraction& f2);
	Fraction operator - (const Fraction& f2);
	Fraction operator * (const Fraction& f2);
	Fraction operator / (const Fraction& f2);
	std::string get_fraction_string();
private:
	float fract;
};


#endif /* FRACTION_H_ */
