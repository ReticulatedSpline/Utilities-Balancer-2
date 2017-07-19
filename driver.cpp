#include "rent.h"
#include <list>
#include <iostream>
#include <cmath>

std::list<tenant> list;
int n = 0;
double total = 0, paid = 0, temp = 0, ave = 0;
std::string name;
tenant* ptr;
std::list<tenant>::iterator it;

std::list<tenant>::iterator findMaxDev() {
  std::list<tenant>::iterator ptr = list.begin();
  for (it = list.begin(); it != list.end(); ++it) {
    if (it->getDev() > ptr->getDev()) {
      ptr = it;
    }
  }
  return ptr;
}

std::list<tenant>::iterator findMinDev() {
  std::list<tenant>::iterator ptr = list.begin();
  for (it = list.begin(); it != list.end(); ++it) {
      if (it->getDev() < ptr->getDev()) {
	ptr = it;
      }
    }
  return ptr;
}

int main() {
  std::cout << "----------|   Utilies balancer v2.0   |----------" << std::endl
	    << "How many tenants exist? -> ";
  std::cin >> n;
  std::cout  << std::endl;
  
  for (int i = 0; i < n; ++i) {
    
    ptr = new tenant;
    
    std::cout << "Enter the name of tenant " << i+1 << ": ";
    std::cin >> name;
    ptr->setName(name);
    
    std::cout << "Enter the utlities paid for this tenant: ";
    std::cin >> temp;
    ptr->setUtils(temp);
    total += temp;
    list.push_front(*ptr);
  }

  //calculate and display average  
  std::cout << std::endl;
  ave = total / n;
  std::cout << "Average utilities cost is $" << ave <<"."
	    << std::endl << std::endl;

  //set deviations  
  for (it = list.begin(); it != list.end(); ++it ) {
    it->setDev( it->getUtils() - ave);
  }

  //max deviation overpaid most
  while ( findMaxDev()->getDev() != 0
	  && findMinDev()->getDev() != 0) {

    if (findMaxDev()->getDev() > std::abs(findMinDev()->getDev())) {
      temp = std::abs(findMinDev()->getDev()); }
    else temp = findMaxDev()->getDev();

    std::cout << findMinDev()->getName() << " should pay "
	 << findMaxDev()->getName() << " $"
	 << floor(temp*100)/100 << ".\n";
    
    findMaxDev()->setDev(findMaxDev()->getDev() - temp);
    findMinDev()->setDev(findMinDev()->getDev() + temp);
  }
  std::cout <<"\nBalancing finished.\n\n";
  return 0;
}
