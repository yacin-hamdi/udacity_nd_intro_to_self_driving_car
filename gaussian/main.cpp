#include<iostream>
#include "gaussian.h"


int main(){
     /*
TODO: Instantiate a Gaussian object called gaussianone.The object
should have mean = 40.0 and variance (aka sigma2) = 225.0
*/
Gaussian gaussianone(40, 225);

/*
TODO: Instantiate another Gaussian object called gaussiantwo. 
The object should have mean = 35.6 and variance = 12.25
*/

Gaussian gaussiantwo(35.6, 12.25);

/*
TODO:
Output to the terminal the following (hint: use the std namespace with cout or
use std::cout):
- the probability density function value for gaussianone when x = 10.5
- the probability density function value for gaussianone when x = 55.4
- the probability density function value for gaussiantwo when x = 35.6
- the probability density function value for gaussiantwo when x = 29.4
*/

std::cout << gaussianone.evaluate(10.5) << std::endl;
std::cout << gaussianone.evaluate(55.4) << std::endl;
std::cout << gaussiantwo.evaluate(35.6) << std::endl;
std::cout << gaussiantwo.evaluate(29.4) << std::endl;

/*
TODO:
- Change the mean value of gaussianone to mean = 45
- Change the variance of gaussiantwo to variance = 15.4
- Output the mean of gaussianone to the terminal
- Output the variance of gaussiantwo to the terminal
*/

std::cout << "-----------------------------------\n";

gaussianone.setMu(45);
gaussiantwo.setSigma2(15.4);
std::cout << gaussianone.getMu() << std::endl;
std::cout << gaussiantwo.getSigma2() << std::endl;

/*
TODO:
- Multiply gaussian one and gaussian two. Store the resulting gaussian
in a variable called gaussianthree
- Output the mean and variance of gaussianthree to the terminal
- Add gaussian one and gaussian two. Store the resulting gaussian in a 
variable called gaussianfour
- Output the mean and variance of gaussianfour to the terminal
*/

std::cout << "-----------------------------------\n";


Gaussian gaussianthree = gaussianone.multiply(gaussiantwo);
std::cout << gaussianthree.getMu() << ", " << gaussianthree.getSigma2() << std::endl;
Gaussian gaussianfour = gaussianone.add(gaussiantwo);
std::cout << gaussianfour.getMu() << ", " << gaussianfour.getSigma2() << std::endl;
    

	return 0;
}