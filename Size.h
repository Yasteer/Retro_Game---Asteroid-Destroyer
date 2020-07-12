#ifndef SIZE_H
#define SIZE_H


class Size
{
    public:
        Size();
        virtual ~Size();

        unsigned int GetLength() { return Length; }
        void SetLength(unsigned int val) { Length = val; }
        unsigned int GetHeight() { return Height; }
        void SetHeight(unsigned int val) { Height = val; }

    protected:

    private:
        unsigned int Length;
        unsigned int Height;
};

#endif // SIZE_H
