//
//  myHeap.cpp
//  Practica3Kours_Task1_C
//
//  Created by Игорь Козлов on 09.07.2020.
//  Copyright © 2020 Игорь Козлов. All rights reserved.
//

#include "myHeap.hpp"

int myHeap:: heapify(int i){
    
    int left, right,  lergest;
    int temp;

      while( i < sizeArr ) {
          
          lergest = i;
          left = 2 * i + 1;
          right = left + 1;
          
          if (left < sizeArr && heap[left] > heap[lergest])
              lergest = left;
    
          if (right < sizeArr && heap[right] > heap[lergest])
              lergest = right;
    
          if (lergest == i) return 0;
          
          temp = heap[i];
          heap[i] = heap[lergest];
          heap[lergest] = temp;
          
          i = lergest;
          
      }
    
    return 0;
};


void myHeap:: heapSort(){
    int temp;
    sizeArr--;
    while( sizeArr >= 0 ){
        //swap
        temp = heap[0];
        heap[0] = heap[sizeArr];
        heap[sizeArr] = temp;
        
        heapify(0);
        sizeArr--;
    }
    
};

