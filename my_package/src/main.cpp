#include "my_package/Point.hpp"
#include "my_package/Point2D.hpp"
#include "my_package/Point3D.hpp"
#include <vector>

int main() {

    Point2D p1; 
    p1.setX(5.0);
    
    Point3D p2(1.0, 2.0, 3.0);

    std::vector<Point*> myPoints;
    myPoints.push_back(&p1);
    myPoints.push_back(&p2);

    for (const auto& p : myPoints) {
        p->display();
    }

    return 0;
}
