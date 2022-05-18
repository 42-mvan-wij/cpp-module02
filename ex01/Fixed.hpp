#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed {
	public:
		Fixed();
		Fixed(int const val);
		Fixed(float const val);
		Fixed(Fixed const &src);
		Fixed &operator=(Fixed const &rhs);
		~Fixed();

		int getRawBits() const;
		void setRawBits(int const raw);

		float toFloat(void) const;
		int toInt(void) const;

	private:
		int fixedPointValue;
		static const int fractionalBits = 8;
};

std::ostream &operator<<(std::ostream &o, Fixed const &fixed );

#endif
