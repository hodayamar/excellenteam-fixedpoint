//
// Created by hodaya on 11/22/18.
//

#ifndef EXCELLENTEAM_ELLA_CPP_FIXEDPOINT_HODAYAMAR_FIXED_POINT_H
#define EXCELLENTEAM_ELLA_CPP_FIXEDPOINT_HODAYAMAR_FIXED_POINT_H

#include <limits>

#include <iostream>
#include <cmath>


template<unsigned int power>
struct compilation_pow
{
    static const size_t value = compilation_pow<power - 1>::value * 10 ;
};

template <>
struct compilation_pow<0>
{
    static const size_t value = 1 ;
};


template<unsigned int num>
struct compilation_fib
{
    static const size_t value = compilation_fib<num - 1>::value + compilation_fib<num - 2>::value;
};

template <>
struct compilation_fib<0>
{
    static const size_t value = 1;
};

template <>
struct compilation_fib<1>
{
    static const size_t value = 1;
};

template <unsigned int SIZE , typename T = int>
class FixedPoint
{

public:

    explicit FixedPoint(T dollar = 0, T cent = 0);

    operator double() { return double(m_price) / DOLLAR_IN_CENT; }

    const FixedPoint operator+(const FixedPoint& )const;
    const FixedPoint operator-(const FixedPoint& )const;
    const FixedPoint operator/(const FixedPoint& )const;
    const FixedPoint operator*(const FixedPoint& )const;
    const FixedPoint operator%(const FixedPoint& )const;

    FixedPoint* operator=(T);
    FixedPoint& operator+=(const FixedPoint& );
    FixedPoint& operator*=(const FixedPoint& );
    FixedPoint& operator/=(const FixedPoint& );
    FixedPoint& operator-=(const FixedPoint& );
    FixedPoint& operator%=(const FixedPoint& );
    FixedPoint& operator++();
    FixedPoint& operator--();
    const FixedPoint& operator-();
    FixedPoint operator++(int);
    FixedPoint operator--(int);


    bool operator==(const FixedPoint& )const;
    bool operator!=(const FixedPoint& )const;
    bool operator>=(const FixedPoint& )const;
    bool operator<=(const FixedPoint& )const;
    bool operator<(const FixedPoint& )const;
    bool operator>(const FixedPoint& )const;

    typedef T theType;
    enum {PRECISION = SIZE};

    friend std::ostream& operator<<(std::ostream&os, const FixedPoint<SIZE, T>&pr) {

        os << pr.m_price / pr.DOLLAR_IN_CENT << "." << abs(pr.m_price % pr.DOLLAR_IN_CENT) << "\n";
        return os;
    };
private:

    static const T DOLLAR_IN_CENT = compilation_pow<SIZE>::value;
    T m_price;

};


template <unsigned int SIZE, typename T>
inline FixedPoint<SIZE, T>::FixedPoint(T dollar_part, T cent_part): m_price(dollar_part * DOLLAR_IN_CENT + cent_part)
{}

template <unsigned int SIZE, typename T>
inline const FixedPoint<SIZE, T> FixedPoint<SIZE, T>::operator+(const FixedPoint<SIZE, T>& other) const
{
    T sum = other.m_price + m_price;
    return FixedPoint(sum / DOLLAR_IN_CENT, sum % DOLLAR_IN_CENT);
}

template <unsigned int SIZE, typename T>
inline const FixedPoint<SIZE, T> FixedPoint<SIZE, T>::operator-(const FixedPoint<SIZE, T>& other) const
{
    int sum = m_price - other.m_price;
    return FixedPoint(sum / DOLLAR_IN_CENT, sum % DOLLAR_IN_CENT);
}

template <unsigned int SIZE, typename T>
inline const FixedPoint<SIZE, T> FixedPoint<SIZE, T>::operator/(const FixedPoint<SIZE, T>& other) const
{
    T sum = (double(m_price) / (double)other.m_price) * DOLLAR_IN_CENT;
    return FixedPoint(sum / DOLLAR_IN_CENT, sum % DOLLAR_IN_CENT);
}

template <unsigned int SIZE, typename T>
inline const FixedPoint<SIZE, T> FixedPoint<SIZE, T>::operator*(const FixedPoint<SIZE, T>& other) const
{
    T sum = (m_price * other.m_price) / DOLLAR_IN_CENT;
    return FixedPoint(sum / DOLLAR_IN_CENT, sum % DOLLAR_IN_CENT);
}

template <unsigned int SIZE, typename T>
inline const FixedPoint<SIZE, T> FixedPoint<SIZE, T>::operator%(const FixedPoint<SIZE, T>& other) const
{
    T sum = m_price % other.m_price;
    return FixedPoint(sum / DOLLAR_IN_CENT, sum % DOLLAR_IN_CENT);
}

template <unsigned int SIZE, typename T>
inline FixedPoint<SIZE, T>* FixedPoint<SIZE, T>::operator=(T i)
{

    m_price = i;
    return this;
}

template <unsigned int SIZE, typename T>
inline FixedPoint<SIZE, T>& FixedPoint<SIZE, T>::operator+=(const FixedPoint<SIZE, T>& other)
{
    m_price += other.m_price;
    return *this;
}

template <unsigned int SIZE, typename T>
inline FixedPoint<SIZE, T>& FixedPoint<SIZE, T>::operator*=(const FixedPoint<SIZE, T>& other)
{
    T sum = (m_price * other.m_price) / DOLLAR_IN_CENT;
    m_price = sum;
    return *this;

}

template <unsigned int SIZE, typename T>
inline FixedPoint<SIZE, T>& FixedPoint<SIZE, T>::operator/=(const FixedPoint<SIZE, T>& other)
{
    T sum = (m_price / other.m_price) * DOLLAR_IN_CENT;
    m_price = sum;
    return *this;

}

template <unsigned int SIZE, typename T>
inline FixedPoint<SIZE, T>& FixedPoint<SIZE, T>::operator-=(const FixedPoint<SIZE, T>& other)
{
    m_price -= other.m_price;
    return *this;

}


template <unsigned int SIZE, typename T>
inline FixedPoint<SIZE, T>& FixedPoint<SIZE, T>::operator%=(const FixedPoint<SIZE, T>& other)
{
    m_price %= other.m_price;
    return *this;

}

template <unsigned int SIZE, typename T>
inline FixedPoint<SIZE, T>& FixedPoint<SIZE, T>::operator++()
{
    m_price += DOLLAR_IN_CENT;
    return *this;
}

template <unsigned int SIZE, typename T>
inline FixedPoint<SIZE, T> FixedPoint<SIZE, T>::operator++(int)
{
    FixedPoint t_price(*this);
    m_price += DOLLAR_IN_CENT;
    return t_price;
}

template <unsigned int SIZE, typename T>
inline FixedPoint<SIZE, T> FixedPoint<SIZE, T>::operator--(int)
{
    FixedPoint t_price(*this);
    m_price -= DOLLAR_IN_CENT;
    return t_price;
}

template <unsigned int SIZE, typename T>
inline FixedPoint<SIZE, T>& FixedPoint<SIZE, T>::operator--()
{
    m_price -= DOLLAR_IN_CENT;
    return *this;
}


template <unsigned int SIZE, typename T>
inline const FixedPoint<SIZE, T>& FixedPoint<SIZE, T>::operator-()
{
    m_price *= (-1);
    return *this;
}

template <unsigned int SIZE, typename T>
inline bool FixedPoint<SIZE, T>::operator==(const FixedPoint<SIZE, T>& other) const
{
    return m_price == other.m_price;
}


template <unsigned int SIZE, typename T>
inline bool FixedPoint<SIZE, T>::operator!=(const FixedPoint<SIZE, T>& other) const
{
    return this == other;
}

template <unsigned int SIZE, typename T>
inline bool FixedPoint<SIZE, T>::operator>=(const FixedPoint<SIZE, T>& other) const
{
    return m_price >= other.m_price;
}

template <unsigned int SIZE, typename T>
inline bool FixedPoint<SIZE, T>::operator<=(const FixedPoint<SIZE, T>& other) const
{
    return m_price <= other.m_price;
}

template <unsigned int SIZE, typename T>
inline bool FixedPoint<SIZE, T>::operator<(const FixedPoint<SIZE, T>& other) const
{
    return m_price < other.m_price;
}

template <unsigned int SIZE, typename T>
inline bool FixedPoint<SIZE, T>::operator>(const FixedPoint<SIZE, T>& other) const
{
    return m_price > other.m_price;
}





template <typename T>
class numeric_limits
{
public:
    static const bool is_specialized = false;
};

template<>
template<unsigned int SIZE, typename T>
class numeric_limits<FixedPoint<SIZE, T> >
{
public:
    static const bool is_specialized = false;

    static FixedPoint<SIZE, T> min( )
    {

        T Min = std::numeric_limits<T>::min();
        return FixedPoint<SIZE, T>(0, Min);
    }

    static FixedPoint<SIZE, T> max()
    {

        T Max = std::numeric_limits<T>::max();
        return FixedPoint<SIZE, T>(0, Max);
    }
};

#endif //EXCELLENTEAM_ELLA_CPP_FIXEDPOINT_HODAYAMAR_FIXED_POINT_H
