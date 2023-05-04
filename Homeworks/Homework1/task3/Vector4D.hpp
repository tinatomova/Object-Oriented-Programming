#pragma once
#include<iostream>

class Vector4D {
private:
    double vec[4];

public:
    Vector4D();
    Vector4D(double, double, double, double);
    Vector4D(const Vector4D&);

    Vector4D& operator=(const Vector4D&);
    double& operator[](unsigned int index);

    Vector4D operator+(const Vector4D&)const;
    Vector4D& operator+=(const Vector4D&);

    Vector4D operator-(const Vector4D& )const;
    Vector4D& operator-=(const Vector4D&);

    Vector4D operator*(const Vector4D&)const;
    Vector4D& operator*=(const Vector4D&);
    Vector4D operator*(double)const;
    Vector4D& operator*=(double);

    Vector4D operator/(const Vector4D&)const;
    Vector4D& operator/=(const Vector4D&);

    bool operator==(const Vector4D)const;
    bool operator!=(const Vector4D)const;
    bool operator<(const Vector4D)const;
    bool operator>(const Vector4D)const;
    bool operator<=(const Vector4D)const;
    bool operator>=(const Vector4D)const;
    bool operator!()const;

    Vector4D operator-()const;
    
    friend std::ostream& operator<<(std::ostream& out, const Vector4D& v);
};
std::ostream& operator<<(std::ostream& out, const Vector4D& vec);
