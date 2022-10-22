#ifndef TUPLE_HPP
#define TUPLE_HPP

class Tuple
{
public:
  Tuple(){};
  Tuple(float x, float y, float z, float w);
  ~Tuple() = default;

  float x() const { return x_; }
  float y() const { return y_; }
  float z() const { return z_; }
  float w() const { return w_; }
  void SetW(float w) { w_ = w; };

  bool IsPoint() const;
  bool IsVector() const;
  float Magnitude() const;
  Tuple Normalize() const;
  float Dot(Tuple secondTuple) const;
  Tuple Cross(Tuple secondTuple) const;

private:
  float x_, y_, z_, w_;
};

Tuple operator+(const Tuple lhs, const Tuple rhs);
Tuple operator-(const Tuple lhs, const Tuple rhs);
Tuple operator*(const Tuple t, float scalar);
Tuple operator/(const Tuple t, float div);
Tuple operator-(const Tuple neg);
bool operator==(const Tuple lhs, const Tuple rhs);

Tuple Point(float x, float y, float z);
Tuple Vector(float x, float y, float z);

#endif /* TUPLE_HPP */