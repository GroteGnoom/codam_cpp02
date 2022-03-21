#include <iostream>

class Fixed {
	public:
		Fixed();
		Fixed(const int);
		Fixed(const float);
		Fixed(const Fixed &fixed);
		Fixed &operator=(const Fixed &other);
		~Fixed();
		int getRawBits(void) const;
		void setRawBits( int const raw);
		int toInt( void ) const;
		float toFloat( void ) const;
	private:
		int _fp;
		static const int _fract = 8;
};

std::ostream &operator<<(std::ostream &out, const Fixed &f);
