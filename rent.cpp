#include "rent.h"

//accessors
double tenant::getUtils() { return utils; }
double tenant::getDev() { return dev; }
std:: string tenant::getName() { return name; }

//mutators
void tenant::setUtils(double x) { utils = x; }
void tenant::setName(std::string x) {name = x; }
void tenant::setDev(double x) { dev = x; }
//positive dev means overpaid
