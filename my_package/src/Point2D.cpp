#include "Geometry/Point.hpp"
#include <iostream>
#include <cmath>

namespace Geometry
{
	class Point2D : public Geometry::Point
	{
		public :
		Point2D() : x_(0.0),y_(0.0){}
		~Point2D() override = default ;
		void initialize(double x, double y,double z) override{
		x_ = x;
		y_ = y;
		(void)z;
		}
		
		double magnitude() const override{
			return std::sqrt(x_*x_ + y_*y_);
		}
	
		double getX() const override { return x_; }
		double getY() const override { return y_; }
		double getZ() const override { return 0.0; }

		void setX(double x) override { x_ = x; }
		void setY(double y) override { y_ = y; }
		void setZ(double z) override { (void)z; }

		void display() const override {
    		std::cout << "2D Point: (" <<  x_ <<  ","  <<  y_<< ")" << std::endl;
		}
		
		protected :
		double x_,y_;
	};

}

#include <pluginlib/class_list_macros.hpp>

PLUGINLIB_EXPORT_CLASS(Geometry::Point2D, Geometry::Point)
