#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed {
	public:
		Fixed();
		Fixed(int const val);
		Fixed(float const val);
		Fixed(Fixed const &src);
		Fixed &operator=(const Fixed &rhs);
		~Fixed();

		bool operator>(Fixed const &rhs) const;
		bool operator<(Fixed const &rhs) const;
		bool operator>=(Fixed const &rhs) const;
		bool operator<=(Fixed const &rhs) const;
		bool operator==(Fixed const &rhs) const;
		bool operator!=(Fixed const &rhs) const;

		Fixed operator+(Fixed const &rhs);
		Fixed operator-(Fixed const &rhs) const;
		Fixed operator*(Fixed const &rhs);
		Fixed operator/(Fixed const &rhs);

		Fixed &operator++(void);
		Fixed &operator--(void);
		Fixed operator++(int);
		Fixed operator--(int);

		static Fixed &min(Fixed &a, Fixed &b);
		static Fixed const &min(Fixed const &a, Fixed const &b);
		static Fixed &max(Fixed &a, Fixed &b);
		static Fixed const &max(Fixed const &a, Fixed const &b);

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
