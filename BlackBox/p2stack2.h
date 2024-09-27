// p2stack.h
// LIFO : last in, first out

template <typename StackType>
struct Stack
{
    // hold data in an array, with top being the index into the array
    int top;    // index showing next available index
    StackType* data;  // pointer to array (to hold values)
    int size;   // size of current array
    
    // constructor : initialize values
    Stack()
    {
        size = 2;
        data = new StackType[size];
        top = 0;
    }
    
    // destructor : destroy things
    ~Stack()
    {
        delete [] data;
    }
    
    void push(StackType value)
    {
        // if array is full, needs to grow
        if( top == size )
        {
            StackType* tmp = new StackType[size*2];
            for( int i = 0; i < top; i++ )
                tmp[i] = data[i];
            delete [] data; // delete old array
            data = tmp; // point to new (larger) array
            size *= 2;  // remember size has doubled
        }
        data[top++] = value;
    }
    
    StackType pop()
    {
        return data[--top];
    }
    
    bool isEmpty()
    {
        return ( top == 0 );
    }
    
    int getSize()
    {
        return top;
    }
};
