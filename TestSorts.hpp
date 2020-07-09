//
//  TestSorts.hpp
//  Practica3Kours_Task1_C
//
//  Created by Игорь Козлов on 09.07.2020.
//  Copyright © 2020 Игорь Козлов. All rights reserved.
//

#ifndef TestSorts_hpp

#define TestSorts_hpp

#include <iostream>
#include <cstdlib>

#include "myHeap.hpp"


using namespace std;

class TestSorts {
        
    int *arrQsort_random;
    int *arrHeapSort_random;
    
    int *arrQsort_reverse;
    int *arrHeapSort_reverse;
    
    int *arrQsort_nearlySorted;
    int *arrHeapSort_nearlySorted;
    
    double timeExecQSort_random;
    double timeExecHSort_random;
    
    double timeExecQSort_reverse;
    double timeExecHSort_reverse;
    
    double timeExecQSort_nearlySorted;
    double timeExecHSort_nearlySorted;
    
    int sizeArr;
public:
    TestSorts();// User Interface in constructor
    ~TestSorts();//Free mamory arrQsort & arrHeapSort
    
    int testingSorts();//calculate execution time sorts
    
};

#endif

