//
// Created by Ethan's Macbook on 9/26/23.
//

#include "InsufficientFundsException.h"

#include <iostream>

  InsufficientFundsException::InsufficientFundsException() {
     std::cout << "Insufficient Funds" << std::endl;
     exit(0);
}