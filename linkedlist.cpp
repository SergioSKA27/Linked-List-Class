#include <iostream>
#include <string>
#include <cstdbool>
#include <cstdlib>
#include <vector>

template <class type>
class Node
{
private:
    type Data;

public:
    Node *next;

    Node(type Data)
    {
        this->Data = Data;
        this->next = NULL;
    }

    Node()
    {
        this->next = NULL;
    }

    Node<type> &changedata(type newData)
    {
        Data = newData;
        return *this;
    }

    void showdata()
    {
        std::cout << Data << std::endl;
    }

    type getdata()
    {
        return this->Data;
    }

    ~Node()
    {
    }
};

template <class ty>
class linkedlist
{
private:
    std::string Ltype;
    char ListType; //tipo de lista
    int size;      //tamaño de la lista

    Node<ty> *HeadrefS; // referencia a Head simple
    Node<ty> *nde;

public:
    linkedlist(char listType)
    { // el constructor toma como parametros el tipo de lista que vamos a implementar
        // y el tamaño de la misma si queremos que esta tenga un tamaño inicial
        this->ListType = ListType;
        this->size = 0;
        if (this->ListType == 's' || this->ListType == 'S')
        { //asignamos la cabercera de acuerdo al tipo de lista
            HeadrefS = NULL;
        }
    }

    void Push(ty Data)
    {

        nde = new Node<ty>();

        nde->changedata(Data);
        nde->next = HeadrefS;
        HeadrefS = nde;
        size += 1;
    }

    Node<ty> *Head()
    {
        HeadrefS->showdata();
        return this->HeadrefS;
    }

    int listsize()
    {
        return this->size;
    }
    ~linkedlist()
    {
    }
};

int main(int argc, char const *argv[])
{
    linkedlist<int> L('s');

    L.Push(150);
    L.Head();

    return 0;
}

/*nodos 
Node<int> N1(21);
    Node<int> *LN;

    LN = new Node<int>(2);

    LN[0].changedata(100);
    LN[1].changedata(1000);

    N1.showdata();
    N1.next = &LN[0];
    N1.next->showdata();
    LN[0].next = &LN[1];
    LN[0].next->showdata();*/