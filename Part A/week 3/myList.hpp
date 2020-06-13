namespace MyList
{

    class ListElement
    {
    public:
        ListElement(int data, ListElement *next) : data(data), next(next) {}
        int getData()
        {
            return data;
        }
        ListElement *getNext()
        {
            return next;
        }

    private:
        int data;
        ListElement *next;
    };
    class List
    {
    public:
        List() : head(nullptr), cursor(nullptr) {}
        void prepend(int data);
        int getElement();
        void advance();
        void print();
        ~List();

    private:
        ListElement *head;
        ListElement *cursor;
    };
} // namespace MyList