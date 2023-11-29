#include <iostream>
#include <fstream>
#include <string>
#include "FiniteFunctions.h"

int main()
{
  std::ifstream inputFile("Outputs/data/MysteryData10060.txt");
  if (!inputFile.is_open()) {
    std::cerr << "Error: Unable to open the file Outputs/data/MysteryData03330.txt for reading." << std::endl;
    return 1;
  }
  std::vector<double> MData;
  double DVal;
  while (inputFile >> DVal) {
    MData.push_back(DVal);
  } 

  // Remember to close the file                                                                                                                                                  
  inputFile.close();

  std::cout << "Simulating 1/(1+x^2) distribution" << std::endl;
  double range_min = -5.0;
  double range_max = 5.0;
  FiniteFunction MyFunction = FiniteFunction(range_min,range_max,"MyInvXsq");
  double test_val = 1.5;
  double func_at = MyFunction.callFunction(test_val);
  std::cout << "1/(1+x^2) function at " << test_val << " is: " << func_at << std::endl;
  //double Integral = MyFunction.integral(10000);                                                                                                                                
  MyFunction.printInfo();
  MyFunction.plotFunction();
  MyFunction.plotData(MData,21,true);
  std::cout << std::endl;

  return 0;
}