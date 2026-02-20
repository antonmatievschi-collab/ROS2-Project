#include <pluginlib/class_loader.hpp>
#include "Geometry/Point.hpp" // Matches your include directory structure
#include <iostream>
#include <memory>

int main(int argc, char** argv)
{
  (void) argc;
  (void) argv;

  pluginlib::ClassLoader<Geometry::Point> loader("my_package", "Geometry::Point");

  try
  {
    // 3. Load Point2D
    std::cout << "--- Loading Point2D ---" << std::endl;
    std::shared_ptr<Geometry::Point> p2d = loader.createSharedInstance("Geometry::Point2D");
    p2d->initialize(3.0, 4.0); // Z defaults to 0.0
    p2d->display();
    std::cout << "Magnitude: " << p2d->magnitude() << std::endl;

    std::cout << "\n--- Loading Point3D ---" << std::endl;
    // 4. Load Point3D
    std::shared_ptr<Geometry::Point> p3d = loader.createSharedInstance("Geometry::Point3D");
    p3d->initialize(3.0, 4.0, 5.0);
    p3d->display();
    std::cout << "Magnitude: " << p3d->magnitude() << std::endl;
    
    // 5. Test the setters
    std::cout << "\n--- Updating Point3D via Setters ---" << std::endl;
    p3d->setZ(10.0);
    p3d->display();
    std::cout << "New Magnitude: " << p3d->magnitude() << std::endl;

  }
  catch (pluginlib::PluginlibException& ex)
  {
    // If the names in plugins.xml don't match, it will crash here
    std::cerr << "The plugin failed to load: " << ex.what() << std::endl;
    return 1;
  }

  return 0;
}
