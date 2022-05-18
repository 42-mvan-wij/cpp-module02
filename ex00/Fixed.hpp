#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed {
	public:
		Fixed();
		Fixed(Fixed const &src);
		Fixed &operator=(Fixed const &rhs);
		~Fixed();

		int getRawBits() const;
		void setRawBits(int const raw);


	private:
		int fixedPointValue;
		static const int fractionalBits = 8;
};

#endif
