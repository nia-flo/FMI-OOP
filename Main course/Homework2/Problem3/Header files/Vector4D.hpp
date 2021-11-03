#pragma once

class Vector4D {
public:
    Vector4D();
    Vector4D(double, double, double, double);

    double& operator[](unsigned int);

    Vector4D operator+(const Vector4D&) const;
    Vector4D& operator+=(const Vector4D&);

    Vector4D operator-(const Vector4D&) const;
    Vector4D& operator-=(const Vector4D&);

    Vector4D operator*(const Vector4D&) const;
    Vector4D operator*(double) const;
    Vector4D& operator*=(const Vector4D&);
    Vector4D& operator*=(double);

    Vector4D operator/(const Vector4D&) const;
    Vector4D& operator/=(const Vector4D&);

    bool operator==(const Vector4D&) const;
    bool operator!=(const Vector4D&) const;
    bool operator<(const Vector4D&) const;
    bool operator>(const Vector4D&) const;
    bool operator<=(const Vector4D&) const;
    bool operator>=(const Vector4D&) const;

    friend Vector4D operator-(const Vector4D&);
    friend bool operator!(const Vector4D&);

private:
    static const int ELEMENTS_COUNT = 4;
    static const int DEFAULT_ELEMENT_VALUE = 0;

    double elements[ELEMENTS_COUNT];
};
