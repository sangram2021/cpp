
#include <iostream>
using namespace std;

template <typename T>
class Ex_Vector
{
    private:
       T *data;
       int size;
       int capacity;
       void reAllocate()
       {
           
           if(capacity == size)
           {
              capacity = size*2; 
              T *tmpData = new T[capacity];
              
              for(int i =0;i<size;i++)
                tmpData[i] = data[i];
                
                delete[] data;
                
              T *data = new T[capacity];
              
              for(int i =0;i<size;i++)
                  data[i]= tmpData[i];
           }
         
       }
    public:
    int vecSize()
    {
        return size;
    }    
    Ex_Vector()
    {
        
        size = 0;
        capacity = 4;
        data=new T[capacity];
    }


    Ex_Vector(Ex_Vector<T> &argVec)
    {
        data = new T[argVec.vecSize()];
        size = argVec.vecSize();
        capacity = argVec.vecSize()*2;
        for(int i =0;i<size;i++)
            data[i]= argVec.data[i];
    }
 
   Ex_Vector&  operator=(Ex_Vector<T> &argVec)
    {
        delete [] data;
        size = 0;
        
        data = new T[argVec.vecSize()];
        size = argVec.vecSize();
        capacity = argVec.vecSize()*2;
        for(int i =0;i<size;i++)
            data[i]= argVec.data[i];
        return *this;
    }   

    void push_back(T arg)
    {
        if(size == capacity)
        {
            reAllocate();
        }
        
        data[size] = arg;
        size++;
    }
    
    T& operator[](unsigned int arg)
    {
        return data[arg];
    }
    
    
};

int main()
{
    
    Ex_Vector<int> vec;
    
    vec.push_back(1);
    vec.push_back(2);
    Ex_Vector<int> vec1; 
    vec1 = vec;
    for(int i =0;i<vec1.vecSize();i++)
    cout<<" "<<vec1[i];

    return 0;
}