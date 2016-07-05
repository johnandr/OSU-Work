/*
  2   * FibonacciR.h
  3   *
  4   *  Created on: Sep 10, 2010
  5   *      Author: julian
  6   */

#ifndef FIBONACCIR_H_
#define FIBONACCIR_H_
 
class FibonacciR {
public:
	FibonacciR(const int &n);
	virtual ~FibonacciR();
	void PrintFibonacci();
private:
	FibonacciR();
	int Fibonacci(const int &n);
	const int *n_;
};

#endif /* FIBONACCIR_H_ */
