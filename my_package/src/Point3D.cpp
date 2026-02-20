#include "Geometry/Point.hpp"
#include <iostream>
#include <cmath>

namespace Geometry{
	class Point3D:public Geometry::Point
	{
	public:
	Point3D(): x_(0.0),y_(0.0),z_(0.0){}
    	~Point3D() override= default;

	void initialize(double x, double y,double z) override{
		x_ = x;
		y_ = y;
		z_ = z;
	}

	double magnitude() const override {
            return std::sqrt(x_ * x_ + y_ * y_ + z_ * z_);
        }

	double getX() const override { return x_; }
	double getY() const override { return y_; }
	double getZ() const override { return z_; }

	void setX(double x) override { x_ = x; }
	void setY(double y) override { y_ = y; }
	void setZ(double z) override { z_ = z; }

	void display() const override {
    		std::cout << "3D Point: (" << x_ << ", " << y_ << ", " << z_ << ")" << std::endl;
    		}
    	protected: double x_,y_,z_;
	};
}
#include <pluginlib/class_list_macros.hpp>

PLUGINLIB_EXPORT_CLASS(Geometry::Point3D, Geometry::Point)
