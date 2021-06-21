#include <iostream>
#include <sstream>

using namespace std;

template <typename T>
class SimpleVector{
    private: // the base address of the array
             T *item;
             // size of the array
             int size;
             // number of elements in the array
             int numElements;
    public:
       // Overloaded constructor
       SimpleVector(int size){
            this->size = size;
            this->numElements = 0;
            this->item = new T[this->size];

       }
       // default constructor
       SimpleVector():SimpleVector(10){

       }
       void pushBack(T);
       int getSize() const;
       int getNumElements() const;

       T& operator[](int);

       template<typename U>
       friend ostream& operator << (ostream &, const SimpleVector<U>&);

       ~SimpleVector(){
           delete [] item;
           cout << "Destructor called..." << endl;
       }

       SimpleVector<T>& operator=(const SimpleVector<T>& rho);
       SimpleVector(const SimpleVector<T>& rho);
};

template<typename T>
SimpleVector<T>::SimpleVector(const SimpleVector<T>& rho){
    this->item = new T[rho.size];
    this->size = rho.size;
    this->numElements = rho.numElements;
    for(int i = 0; i < this->size; ++i){
        this->item[i] = rho.item[i];
    }

}

template<typename T>
SimpleVector<T>& SimpleVector<T>::operator=(const SimpleVector<T>& rho){
    if (this != &rho){
        delete [] this->item;
        this->item = new T[rho.size];
        this->size = rho.size;
        this->numElements = rho.numElements;
        for(int i = 0; i < this->size; ++i){
            this->item[i] = rho.item[i];
        }
    }

}

template<typename U>
ostream& operator << (ostream &out, const SimpleVector<U>& sv){
    out << "[";
    for(int i = 0; i < sv.numElements; ++i){
        if (i == sv.numElements - 1)
            out << sv.item[i];
        else
            out << sv.item[i] << ", ";

    }
    out << "]";
    return out;
}

template<typename T>
T& SimpleVector<T>::operator[](int index){
        return item[index];
}

template<typename T>
int SimpleVector<T>::getSize() const{
    return this->size;
}

template<typename T>
int SimpleVector<T>::getNumElements() const{
    return this->numElements;
}

template<typename T>
void SimpleVector<T>::pushBack(T v){
    if (numElements >= size){
        // double  the size of the array
        // keeping the existing elements intact
        int newSize = size * 2;
        T *temp = new T[newSize];
        for(int i = 0; i < numElements; i++){
            temp[i] = item[i];
        }
        delete [] item;
        item = temp;
        this->size = newSize;
    }

    item[numElements++] = v;
}



int main()
{
   SimpleVector<int> sv1(3);
   sv1.pushBack(10);
   sv1.pushBack(20);
   cout << sv1 << endl;

   SimpleVector<string> sv2(3);
   sv2.pushBack("aaaa");
   sv2.pushBack("bbbb");
   cout << sv2 << endl;

   return 0;
}
