// p2priorityqueue2.h
// FIFO-ish : highest priority first; where equal, first in, first out

template <typename ValueType, typename RankType>
struct PriorityQueue
{
    // hold data in an array,
    int count;  // number of things currently in PQ
    ValueType* data;  // pointer to array (to hold values)
    RankType* rank;  // pointer to array (to hold ranks)
    int size;   // size of current array
    
    // constructor : initialize values
    PriorityQueue()
    {
        size = 2;
        data = new ValueType[size];
        rank = new RankType[size];
        count = 0;
    }
    
    // destructor : destroy things
    ~PriorityQueue()
    {
        delete [] data;
        delete [] rank;
    }
    
    void push(ValueType value, RankType priority)
    {
        // if array is full, needs to grow
        if( count == size )
        {
            ValueType* tmpData = new ValueType[size*2];
            RankType*  tmpRank = new  RankType[size*2];
            for( int i = 0; i < count; i++ )
            {
                tmpData[i] = data[i];
                tmpRank[i] = rank[i];
            }
            delete [] data; // delete old array
            delete [] rank; // delete other old array
            data = tmpData; // point to new (larger) array
            rank = tmpRank; // point to new (larger) array
            size *= 2;  // remember size has doubled
        }
        data[count] = value;
        rank[count] = priority;
        count++;
    }
    
    ValueType pop()
    {
        // find index with highest (first) priority
        int highest = 0;
        for( int i = 1; i < count; i++ )
            if( rank[i] > rank[highest] )
                highest = i; // remember this index, highest seen so far
        
        // remember the value at the index with highest priority
        ValueType nextValue = data[highest];
        
        // shift array values over, to fill that hole
        for( int j = highest; j < size; j++ )
        {
            data[j] = data[j+1];
            rank[j] = rank[j+1];
        }
        count--; // one fewer value now
        
        return nextValue;
    }
    
    bool isEmpty()
    {
        return ( count == 0 );
    }
    
    int getSize()
    {
        return count;
    }
};
