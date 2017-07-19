#ifndef RENT
#define RENT
#include <string>

class tenant{
 public: 
  double getUtils();
  double getDev();
  std::string getName();
  void setUtils(double);
  void setDev(double x);
  void setName(std::string);
 private:
  std::string name;
  double dev;
  double utils;
    };

#endif
