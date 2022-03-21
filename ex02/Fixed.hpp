#include <iostream>

class Fixed {
	public:
		Fixed();
		Fixed(const int);
		Fixed(const float);
		Fixed(const Fixed &fixed);
		Fixed &operator=(const Fixed &other);
		Fixed &operator++();
		Fixed operator++(int); /*int is only there to indicate post-fix */
		Fixed operator*(const Fixed &other);
		bool operator>(const Fixed &other);
		~Fixed();
		int getRawBits(void) const;
		void setRawBits( int const raw);
		int toInt( void ) const;
		float toFloat( void ) const;
		static const Fixed &max(const Fixed &f1, const Fixed &f2);
		static Fixed &max(Fixed &f1, Fixed &f2);
	private:
		int _fp;
		static const int _fract = 8;
};

std::ostream &operator<<(std::ostream &out, const Fixed &f);
