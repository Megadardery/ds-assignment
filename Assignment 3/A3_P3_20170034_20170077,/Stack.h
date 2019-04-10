#ifndef STACK_H
#define STACK_H

template <typename P>
class Stack
{
public:
    Stack()
    {
        curr = 0;
        siz = 1;
        data = new P [siz];
    }
	 void push (const P& val)
    {
        ++curr;
        if (curr >= siz)
        {
            siz*=2;
            P* tmp = new P[siz];
            for (int i = 0 ; i<curr ; ++i)
                tmp[i] = data[i];
            delete [] data;
            data = tmp;
        }
        data[curr] = val;
    }
    Stack(const P& val , int sz)
    {
        while(sz--)
			push(val);
    }
    virtual ~Stack()
    {
        delete[] data;
    }
    P& top()
    {
        assert(curr!=0);
        return data[curr];
    }
    void pop()
    {
        if (curr) --curr;
    }
    size_t size()
    {
        return curr;
    }

protected:

private:
    P* data;
    size_t siz;
    size_t curr;
};

#endif // STACK_H
