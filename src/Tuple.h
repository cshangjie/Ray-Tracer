#ifndef RT_TUPLE_H_
#define RT_TUPLE_H_

class Tuple
{
private:
  float x_, y_, z_, w_;

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
};

Tuple operator+(const Tuple lhs, const Tuple rhs);
Tuple operator-(const Tuple lhs, const Tuple rhs);
Tuple operator*(const Tuple t, float scalar);
Tuple operator/(const Tuple t, float div);
Tuple operator-(const Tuple neg);
bool operator==(const Tuple lhs, const Tuple rhs);

#endif /* RT_TUPLE_H_ */