template<class T>
class LinkedList
{
public:
    struct Node
    {
        T value;
        Node* next = nullptr;
        Node* prev = nullptr;
    };

    LinkedList()
    {
        std::cout << "Construct" << std::endl;
    }
    ~LinkedList()
    {
        std::cout << "Deconstruct" << std::endl;
    }

    void CreateFirst(T value)
    {
        Node* n = new Node();

        n->value = value;
        n->next = nullptr;
        n->prev = nullptr;

        m_first = n;
        m_last = n;

        std::cout << "value " << n->value << std::endl;
    }

    void PushBack(T value)
    {
        if (m_first == nullptr && m_last == nullptr)
        {
            std::cout << "push back: ";

            CreateFirst(value);
        }
        else
        {
            Node* n = new Node();

            n->value = value;
            n->next = nullptr;
            n->prev = nullptr;

            n->prev = m_last;
            m_last->next = n;
            m_last = n;

            std::cout << "push back: value " << n->value << std::endl;
            std::cout << "push back: prev " << n->prev->value << std::endl;
        }
    }
    void PopBack()
    {
        if (m_first == nullptr && m_last == nullptr)
        {

        }
        else if (m_first == m_last)
        {
            delete[] m_last;
            delete[] m_first;
            m_last = nullptr;
            m_first = nullptr;
        }
        else
        {
            m_last = m_last->prev;

            delete[] m_last->next;
            m_last->next = nullptr;
        }
        // std::cout << "pop back: last " << m_last->value << std::endl;
    }
    void PushFront(T value)
    {
        if (m_first == nullptr && m_last == nullptr)
        {
            std::cout << "push forward: ";

            CreateFirst(value);
        }
        else
        {
            Node* n = new Node();

            n->value = value;
            n->next = nullptr;
            n->prev = nullptr;


            n->next = m_first;
            m_first->prev = n;
            m_first = n;

            std::cout << "push forward: value " << n->value << std::endl;
            std::cout << "push forward: next " << n->next->value << std::endl;
        }
    }

    void PopFront()
    {
        if (m_first != nullptr)
        {

        }
        else if (m_first == m_last)
        {
            delete[] m_first->prev;
            m_first->prev = nullptr;
        }
        else
        {
            m_first = m_first->next;

            delete[] m_first->prev;
            m_first->prev = nullptr;

            std::cout << "pop back: first " << m_first->value << std::endl;
        }
    }
    void Sort()
    {
        // TODO
    }
    void Clear()
    {
        bool isOneLeft = false;

        // TODO:
        while (!isOneLeft)
        {
            if (m_first == m_last)
            {
                isOneLeft = true;
            }
            
            PopBack();
        }

        std::cout << "clear " << m_first->value << std::endl;
    }
    void Search(const T& value)
    {
    }

    

protected:
private:
    Node* m_first = nullptr;
    Node* m_last = nullptr;
};