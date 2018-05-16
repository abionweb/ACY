#include "Fraction.h"
#include <iostream>
#include <string>
#include <algorithm>

void Fraction::set_fract(float f) {
	fract = f;
}

float Fraction::get_fract() const {
	return fract;
}

void Fraction::set_value_from_string(std::string fraction_string) {
	fract = 0;

		std::string::size_type slash_position = fraction_string.find('/');
		std::string::size_type dot_position   = fraction_string.find('.');
		std::string::size_type comma_position = fraction_string.find(',');

		if ( comma_position != std::string::npos ) {
			std::replace( fraction_string.begin(), fraction_string.end(), ',', '.' );
			fract = std::atof(fraction_string.c_str());
		}
		if ( dot_position != std::string::npos ) {
			fract = std::atof(fraction_string.c_str());
		}
		if ( slash_position != std::string::npos ) {
			double op1, op2;
			op1 = std::atof(fraction_string.substr( 0, comma_position ).c_str());
			op2 = std::atof(fraction_string.substr( (slash_position + 1), fraction_string.length() ).c_str());
			this->fract = op1 / op2;
		}
		if ((comma_position == std::string::npos) && (dot_position == std::string::npos) && (slash_position == std::string::npos)) {
			this->fract = std::atof(fraction_string.c_str());
		}
};

std::istream& operator >> (std::istream& in, Fraction& f) {

	std::string fraction_string;
	in >> fraction_string;
	return in;
}

std::ostream &operator << (std::ostream& out, const Fraction& f) {
	std::cout << f.fract;
	return out;
}

Fraction Fraction::operator + (const Fraction& f2) {
	Fraction result;
	result.set_fract(fract + f2.get_fract());
	return result;
}

Fraction Fraction::operator - (const Fraction& f2) {
	Fraction result;
	result.set_fract(fract - f2.get_fract());
	return result;
}

Fraction Fraction::operator * (const Fraction& f2) {
	Fraction result;
	result.set_fract(fract * f2.get_fract());
	return result;
}

Fraction Fraction::operator / (const Fraction& f2) {
	Fraction result;
	result.set_fract(fract / f2.get_fract());
	return result;
}

std::string Fraction::get_fraction_string() {
	//Делим число на дробную и целую части
	float f_celaya, f_drob;
	f_drob = std::modf(fract, &f_celaya);
	int i_cel = (int)f_celaya;

	//Вычисляем десятичный знаменатель
	std::string s_drob = std::to_string(f_drob);
	int i_pow = s_drob.length()-2;
	int i_znam = pow(10, i_pow);

	//Вычисляем числитель
	int i_chisl = (int)( f_drob * i_znam );

	//Сокращаем дробь
	int nod = get_NOD(i_chisl, i_znam);
	i_chisl = (int)(i_chisl / nod);
	i_znam  = (int)(i_znam  / nod);

	std::string result;
	if (i_chisl == 0) {
		result = std::to_string(i_cel);
	} else {
		if (i_cel != 0) result = std::to_string(i_cel) + " + ";
		result += std::to_string(i_chisl) + "/" + std::to_string(i_znam);
	}
	return result;
}


