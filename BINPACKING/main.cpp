/* 
 * a better way to do this is to use intefaces
 * for diffrenting picking policies
 */

#include <cstdlib>
#include <vector>
#include <iostream>

using namespace std;


  int pickElement(vector<int> v) {
        int size = v.size();
        int index = (rand() % size) + 1;
        return v[index];
    }
int partition(vector<int>&v, int p, int r) {
  int x = v[r];
  int j = p - 1;
  for (int i = p; i < r; i++) {

    if (x >= v[i]) { //ascending order
      j = j + 1;
      int temp = v[j];
      v[j] = v[i];
      v[i] = temp;
    }
  }
  v[r] = v[j + 1];
  v[j + 1] = x;

  return (j + 1);
}


  void quickSort(vector<int>&v, int start, int stop) {
    if (stop > start) {
        int pivot = partition(v, start, stop); //for a better partitionning
        quickSort(v, start, pivot -1);
        quickSort(v, pivot + 1, stop);
    }
}


    vector<int>  binPacking(vector<int> elements, int binSize) {
        vector<int> w;
        quickSort(elements, 0, elements.size() - 1);        
        for(int i = 0; i < elements.size(); i++) {
            //int e = pickElement(elements);
            if( binSize > 0) {
                cout <<"Bin size = "<<binSize<<endl;
                cout <<"Elements = "<<elements[i]<<endl;
                binSize = binSize - elements[i];
                w.push_back(elements[i]);
            }
        }
        return w;
    }  
    
    void printVector(vector<int> v) {
        for(int i = 0; i < v.size(); i++) {
        cout <<v[i]<<"  ";
        }
        cout <<""<<endl;
    }

int main(int argc, char** argv) {
    int BIN_SIZE = 6;
    vector<int> set ; //= {1, 2, 5, 9, 10};
    set.push_back(2);
    set.push_back(1);
    set.push_back(9);
    set.push_back(5);
    set.push_back(10);


    printVector(set);

   vector<int> choice  =  binPacking(set, BIN_SIZE);
   printVector(choice);

    return 0;
}

