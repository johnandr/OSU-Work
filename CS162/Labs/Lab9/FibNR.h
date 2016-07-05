/*
 FibonacciNR.h
 
 Created on: Sep 11, 2010
 Author: julian
 */
 
#ifndef FIBONACCINR_H_
#define FIBONACCINR_H_
 
class FibonacciNR {
public:
 	FibonacciNR(const int &n);
 	virtual ~FibonacciNR();
	void PrintFibonacci();
private:
  	FibonacciNR();
 	int Fibonacci(const int &n);
 	const int* n_;
};
#endif /* FIBONACCINR_H_ */
