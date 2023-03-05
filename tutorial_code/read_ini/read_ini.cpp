#include <iostream>
#include <string>

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/ini_parser.hpp>

int main(int argc, char** argv) 
{
  boost::property_tree::ptree pt;
  boost::property_tree::ini_parser::read_ini("../../config.ini", pt);
  std::cout << std::stod(pt.get<std::string>("Global.InitDepth")) << std::endl;
  std::cout << pt.get<std::string>("Model.UpdatePointsMethod") << std::endl;

  return 0;
}