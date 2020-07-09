//
//  TestSorts.cpp
//  Practica3Kours_Task1_C
//
//  Created by Игорь Козлов on 09.07.2020.
//  Copyright © 2020 Игорь Козлов. All rights reserved.
//

#include "TestSorts.hpp"

#pragma mark TestSorts()
TestSorts:: TestSorts(){
    
    cout << "Input test array size: ";
    cin >> sizeArr;
    
    // memory allocation for test arrays
    arrQsort_random    = new int[sizeArr];
    arrHeapSort_random = new int[sizeArr];
    
    arrQsort_nearlySorted    = new int[sizeArr];
    arrHeapSort_nearlySorted= new int[sizeArr];
    
    arrQsort_reverse    = new int[sizeArr];
    arrHeapSort_reverse = new int[sizeArr];
    
#pragma mark Initial arrays
    //generate arrays
    int nearlySortedTemp;
    
    for( int i = 0; i < sizeArr; i++) {
        //random
        arrHeapSort_random[i] = i;
        
        //natural
        arrQsort_nearlySorted[i]    = i;
        arrHeapSort_nearlySorted[i] = i;
        if (i % (sizeArr / 10) == 1){
            
            nearlySortedTemp = arrQsort_nearlySorted[i];
            
            arrQsort_nearlySorted[i] =  nearlySortedTemp;
            arrHeapSort_nearlySorted[i] = nearlySortedTemp;
            
            arrQsort_nearlySorted[i-1] =  nearlySortedTemp;
            arrHeapSort_nearlySorted[i-1] = nearlySortedTemp;

            
        }
        
        //reverse
        arrQsort_reverse[sizeArr - i - 1]    = i;
        arrHeapSort_reverse[sizeArr - i - 1] = i;
        
    }
    
    
    #pragma mark Randomizing Arrays
    //next step - mix depending on the value of DigSorted
    srand(time(NULL));
    
    for(unsigned long int i = 0; i < 50 * sizeArr; i++) {
        
        unsigned long int tempI = rand() % sizeArr;//get random index [0...sizeArr]
        unsigned long int tempJ = rand() % sizeArr;//get random index [0...sizeArr]

        //swap
        int temporaryValue = arrHeapSort_random[tempI];
        arrHeapSort_random[tempI] = arrHeapSort_random[tempJ];
        arrHeapSort_random[tempJ] = temporaryValue;
    }

    //copy arrHeapSort into arrQSort
    
    for(int i = 0; i < sizeArr; i++) {
        arrQsort_random[i] = arrHeapSort_random[i];
    }
    //We get array for test
};

#pragma mark Freeing up memory
TestSorts:: ~TestSorts(){
    
    //free memory
    delete arrHeapSort_nearlySorted;
    delete arrQsort_nearlySorted;
    
    delete arrHeapSort_reverse;
    delete arrQsort_reverse;
    
    delete arrHeapSort_random;
    delete arrQsort_random;
};



#pragma mark TestingSorts
int TestSorts:: testingSorts(){
    
    double beginTime;
    double endTime;
    
    #pragma mark Test Quick Sort
    //Qsort here...
    
    int closure (const void *x1, const void *x2);
    
    //NearlySorted array for QSort
    beginTime = clock();
    qsort( arrQsort_nearlySorted, sizeArr, sizeof(int), closure);
    endTime = clock();
    timeExecQSort_nearlySorted = endTime - beginTime;
    
    //Random array for QSort
    beginTime = clock();
    qsort( arrQsort_random, sizeArr, sizeof(int), closure);
    endTime = clock();
    timeExecQSort_random = endTime - beginTime;
    
    //Reverse array for QSort
    beginTime = clock();
    qsort( arrQsort_reverse, sizeArr, sizeof(int), closure);
    endTime = clock();
    timeExecQSort_reverse = endTime - beginTime;
    
    //End Test Qsort
    
    
    
    #pragma mark Test Heap Sort
    //HeapSort here...
    
    //nearly sorted array for heap sort
    beginTime = clock();
    
    myHeap heap1(arrHeapSort_nearlySorted, sizeArr);
    heap1.heapSort();
    
    endTime = clock();
    timeExecHSort_nearlySorted = endTime - beginTime;
    
    //random array for heap sort
    beginTime = clock();

    myHeap heap2(arrHeapSort_random, sizeArr);
    heap2.heapSort();
       
    endTime = clock();
    timeExecHSort_random = endTime - beginTime;
       
    //reverse array for heap sort
    beginTime = clock();
    
    myHeap heap3(arrHeapSort_reverse, sizeArr);
    heap3.heapSort();
       
    endTime = clock();
    timeExecHSort_reverse = endTime - beginTime;
       
    //End HeapSort

    
#pragma mark Outpur results
    
    //test result of sorted
    cout << endl << endl << "Results:" << endl;
    
    int flag_random = true, flag_nearly = true, flag_reverse = true;
    
    //Test for matching sorted arrays
    for(int i = 0; i < sizeArr; i++){
        if (arrHeapSort_nearlySorted[i] != arrQsort_nearlySorted[i]) {
            flag_nearly = false;
        }
        
        if (arrHeapSort_reverse[i] != arrQsort_reverse[i]) {
            flag_reverse = false;
        }

        
        if (arrHeapSort_random[i] != arrQsort_random[i]) {
            flag_random = false;
        }

    }
    //out random
    cout << "Random arrays sort result:" << endl;
    cout<< "        Time Qsort: "<<timeExecQSort_random<<endl<<"        Time HeapSort: "<<timeExecHSort_random<<endl;
    cout<< "    Sorted arrays is Equal: ";
    flag_random ? cout <<"TRUE"<<endl<<endl : cout<<"FALSE"<<endl<<endl;
    
    //out reverse
       cout << "Reverse arrays sort result:" << endl;
       cout<< "        Time Qsort: "<<timeExecQSort_reverse<<endl<<"        Time HeapSort: "<<timeExecHSort_reverse<<endl;
       cout<< "    Sorted arrays is Equal: ";
       flag_reverse ? cout <<"TRUE"<<endl<<endl : cout<<"FALSE"<<endl<<endl;
    
    //out nearly sorted
       cout << "Nearly soted arrays sort result:" << endl;
       cout<< "        Time Qsort: "<<timeExecQSort_nearlySorted<<endl<<"        Time HeapSort: "<<timeExecHSort_nearlySorted<<endl;
       cout<< "    Sorted arrays is Equal: ";
       flag_random ? cout <<"TRUE"<<endl<<endl : cout<<"FALSE"<<endl<<endl;
    return 0;
};



#pragma mark Closure For QSort
int closure (const void *x1, const void *x2) {
    return (*(int *) x1 - *(int*) x2);
};



