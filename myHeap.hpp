//
//  myHeap.hpp
//  Practica3Kours_Task1_C
//
//  Created by Игорь Козлов on 09.07.2020.
//  Copyright © 2020 Игорь Козлов. All rights reserved.
//

#ifndef myHeap_hpp

#define myHeap_hpp


#include <cmath>

class myHeap {
    
    /*View 6 elemet heap[0...5], for example:
     
            root(heap[0])         =| --1
            /           \          |
           /             \         |
          \/             \/         \ sizeHeap  = HigthTree = log2( sizeArr) = 3
        heap[1]         heap[2]     / --2
        /     \           /        |
       /       \         /         |
      \/       \/       \/         |
  heap[3]    heap[4]  heap[5]     =| --3
     
     heap[i] must be <= all subTree elements
     */
    
    int *heap;
    int sizeArr;
        
public:

    myHeap(int *ptr, int size): heap(ptr), sizeArr(size){
        
        //generate max-heap
        for( int i = sizeArr/2 - 1; i >= 0; i--){
            heapify(i);
        }
    };
    
    void heapSort();
    int heapify(int i);

};

#endif

