#ifndef QUEUE_H
#define QUEUE_H

template <typename P>
class Queue
{
public:
    Queue()
    {
        siz = 1 ;
        curr = frnt = 0;
        data = new P[siz];

    }
    void push(const P& val)
    {
        if (curr+1 >= siz)
        {
            siz*=2;
            P* tmp = new P[siz];
            for (int i = frnt ; i<curr ; ++i)
                tmp[i] = data[i];
            delete [] data;
            data = tmp;
        }
        data[curr++] = val;
    }
    void pop()
    {
        ++frnt;
    }
    P& front()
    {
        return data[frnt];
    }
    Queue (const P& val, int sz)
    {
        while(sz--)
            push(val);
    }
    virtual ~Queue()
    {
        delete[] data;
    }

private:
    P* data;
    size_t  siz;
    size_t frnt;
    size_t curr;
};

#endif // QUEUE_H
