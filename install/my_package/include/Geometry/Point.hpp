#ifndef MY_PACKAGE_POINT_HPP
#define MY_PACKAGE_POINT_HPP

namespace Geometry
{
	class Point{

	public :
	virtual ~Point()=default;
	
	virtual void display() const=0;
	virtual double getX() const=0;
	virtual double getY() const=0;
	virtual double getZ() const=0;
	virtual double magnitude() const = 0;
	
	virtual void setX(double x) =0;
	virtual void setY(double y) =0;
	virtual void setZ(double z) =0;
	virtual void initialize (double x, double y, double z =0.0) =0;
	
	
	protected:
	
	Point(){}
	};

}

#endif
