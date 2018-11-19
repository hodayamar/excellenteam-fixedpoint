#include <iostream>  
#include <math.h>     

template <class T = int, unsigned int SIZE = 2>
class Price
{

public:

	explicit Price(T dollar = 0, T cent = 0);

	operator double() { return double(m_price) / DOLLAR_IN_CENT; }

	const Price operator+(const Price& )const;
	const Price operator-(const Price& )const;
	const Price operator/(const Price& )const;
	const Price operator*(const Price& )const;
	const Price operator%(const Price& )const;

	Price* operator=(T);
	Price& operator+=(const Price& );
	Price& operator*=(const Price& );
	Price& operator/=(const Price& );
	Price& operator-=(const Price& );
	Price& operator%=(const Price& );
	Price& operator++();
	Price& operator--();
	const Price& operator-();
	Price operator++(int);
	Price operator--(int);


	bool operator==(const Price& )const;
	bool operator!=(const Price& )const;
	bool operator>=(const Price& )const;
	bool operator<=(const Price& )const;
	bool operator<(const Price& )const;
	bool operator>(const Price& )const;

	friend std::ostream& operator<<(std::ostream&os, const Price<T, SIZE>&pr) {
		os << pr.m_price / pr.DOLLAR_IN_CENT << "." << abs(pr.m_price % pr.DOLLAR_IN_CENT) << "\n";
		return os;
	};
private:

	const T DOLLAR_IN_CENT;
	T m_price;

};

template <class T, unsigned int SIZE>
inline Price<T, SIZE>::Price(T dollar_part, T cent_part): 
	DOLLAR_IN_CENT(pow(10, SIZE)), m_price(dollar_part * DOLLAR_IN_CENT + cent_part)
{}

template <class T, unsigned int SIZE>
inline const Price<T, SIZE> Price<T, SIZE>::operator+(const Price<T, SIZE>& other) const
{
	T sum = other.m_price + m_price;
	return Price(sum / DOLLAR_IN_CENT, sum % DOLLAR_IN_CENT);
}

template <class T, unsigned int SIZE>
inline const Price<T, SIZE> Price<T, SIZE>::operator-(const Price<T, SIZE>& other) const
{
	int sum = m_price - other.m_price;
	return Price(sum / DOLLAR_IN_CENT, sum % DOLLAR_IN_CENT);
}

template <class T, unsigned int SIZE>
inline const Price<T, SIZE> Price<T, SIZE>::operator/(const Price<T, SIZE>& other) const
{
	T sum = (double(m_price) / (double)other.m_price) * DOLLAR_IN_CENT;
	return Price(sum / DOLLAR_IN_CENT, sum % DOLLAR_IN_CENT);
}

template <class T, unsigned int SIZE>
inline const Price<T, SIZE> Price<T, SIZE>::operator*(const Price<T, SIZE>& other) const
{
	T sum = (m_price * other.m_price) / DOLLAR_IN_CENT;
	return Price(sum / DOLLAR_IN_CENT, sum % DOLLAR_IN_CENT);
}

template <class T, unsigned int SIZE>
inline const Price<T, SIZE> Price<T, SIZE>::operator%(const Price<T, SIZE>& other) const
{
	T sum = m_price % other.m_price;
	return Price(sum / DOLLAR_IN_CENT, sum % DOLLAR_IN_CENT);
}

template <class T, unsigned int SIZE>
inline Price<T, SIZE>* Price<T, SIZE>::operator=(T i)
{

	m_price = i;

	return this;
}

template <class T, unsigned int SIZE>
inline Price<T, SIZE>& Price<T, SIZE>::operator+=(const Price<T, SIZE>& other)
{
	m_price += other.m_price;
	return *this;
}

template <class T, unsigned int SIZE>
inline Price<T, SIZE>& Price<T, SIZE>::operator*=(const Price<T, SIZE>& other)
{
	T sum = (m_price * other.m_price) / DOLLAR_IN_CENT;
	m_price = sum;
	return *this;

}

template <class T, unsigned int SIZE>
inline Price<T, SIZE>& Price<T, SIZE>::operator/=(const Price<T, SIZE>& other)
{
	T sum = (m_price / other.m_price) * DOLLAR_IN_CENT;
	m_price = sum;
	return *this;

}

template <class T, unsigned int SIZE>
inline Price<T, SIZE>& Price<T, SIZE>::operator-=(const Price<T, SIZE>& other)
{
	m_price -= other.m_price;
	return *this;

}


template <class T, unsigned int SIZE>
inline Price<T, SIZE>& Price<T, SIZE>::operator%=(const Price<T, SIZE>& other)
{
	m_price %= other.m_price;
	return *this;

}

template <class T, unsigned int SIZE>
inline Price<T, SIZE>& Price<T, SIZE>::operator++()
{
	m_price += DOLLAR_IN_CENT;
	return *this;
}

template <class T, unsigned int SIZE>
inline Price<T, SIZE> Price<T, SIZE>::operator++(int)
{
	Price t_price(*this);
	m_price += DOLLAR_IN_CENT;
	return t_price;
}

template <class T, unsigned int SIZE>
inline Price<T, SIZE> Price<T, SIZE>::operator--(int)
{
	Price t_price(*this);
	m_price -= DOLLAR_IN_CENT;
	return t_price;
}

template <class T, unsigned int SIZE>
inline Price<T, SIZE>& Price<T, SIZE>::operator--()
{
	m_price -= DOLLAR_IN_CENT;
	return *this;
}


template <class T, unsigned int SIZE>
inline const Price<T, SIZE>& Price<T, SIZE>::operator-()
{
	m_price *= (-1);
	return *this;
}

template <class T, unsigned int SIZE>
inline bool Price<T, SIZE>::operator==(const Price<T, SIZE>& other) const
{
	return m_price == other.m_price;
}


template <class T, unsigned int SIZE>
inline bool Price<T, SIZE>::operator!=(const Price<T, SIZE>& other) const
{
	return this == other;
}

template <class T, unsigned int SIZE>
inline bool Price<T, SIZE>::operator>=(const Price<T, SIZE>& other) const
{
	return m_price >= other.m_price;
}

template <class T, unsigned int SIZE>
inline bool Price<T, SIZE>::operator<=(const Price<T, SIZE>& other) const
{
	return m_price <= other.m_price;
}

template <class T, unsigned int SIZE>
inline bool Price<T, SIZE>::operator<(const Price<T, SIZE>& other) const
{
	return m_price < other.m_price;
}

template <class T, unsigned int SIZE>
inline bool Price<T, SIZE>::operator>(const Price<T, SIZE>& other) const
{
	return m_price > other.m_price;
}



