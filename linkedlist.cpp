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
    { //cambia los datos del nodo
        Data = newData;
        return *this;
    }

    void showdata()
    { //muestra los datos del nodo
        std::cout << Data << std::endl;
    }

    type getdata()
    { //retorna la data como valor
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
    Node<ty> *TailrefS; // referencia al ultimo elemento de la lista
    Node<ty> *nde;      // nodos simples

public:
    linkedlist(char listType)
    { // el constructor toma como parametros el tipo de lista que vamos a implementar

        this->ListType = ListType;
        this->size = 0;
        if (this->ListType == 's' || this->ListType == 'S')
        { //asignamos la cabercera de acuerdo al tipo de lista
            HeadrefS = NULL;
            TailrefS = NULL;
        }
    }

    void push(ty Data)
    { // inserta un elemento al principio de la lista

        Node<ty> *tmp = HeadrefS;

        nde = new Node<ty>(); //crea un nuevo nodo

        nde->changedata(Data); //insertamos el dato
        nde->next = HeadrefS;  // cambiamos la referencia al sig.
        HeadrefS = nde;
        size += 1; //aumentamos el tamaño de la lista por cada push

        tmp = nde;

        if (size == 1)
            TailrefS = nde;
        else
        {
            while (tmp->next != NULL)
            {
                tmp = tmp->next;
            }
            TailrefS = tmp;
        }
    }

    void append(ty Data)
    { //inserta elementos al final de la lista
        Node<ty> *tmp = HeadrefS;
        nde = new Node<ty>();
        nde->changedata(Data);

        if (TailrefS == NULL)
        {
            nde->next = HeadrefS;
            HeadrefS = nde;
            TailrefS = nde;
            size += 1;
        }
        else
        {
            while (tmp->next != NULL)
            {
                tmp = tmp->next;
            }
            tmp->next = nde;
            TailrefS = tmp->next;
            size += 1;
        }
    }

    Node<ty> *head()
    { // retorna un puntero a head

        HeadrefS->showdata(); // eliminalo si quieres
        return this->HeadrefS;
    }

    Node<ty> *tail()
    { //retorna un puntero a tail(final de la lista)

        TailrefS->showdata(); // eliminalo si quieres
        return this->TailrefS;
    }

    Node<ty> *at(int index)
    { //retorna el elemto de la lista indicado
        //los indices empiezan en 0

        Node<ty> *tmp = nde;
        int k = 0;

        while (k < index && tmp != NULL)
        {
            tmp = tmp->next;
            k++;
        }
        tmp->showdata(); // eliminalo si quieres
        return tmp;
    }

    int listsize()
    { //retorna el tamaño de la lista
        return this->size;
    }

    void printlist()
    { // imprime la lista
        Node<ty> *tmp = nde;
        int k = 0;

        while (tmp != NULL)
        {
            if (k == 0)
                std::cout << tmp->getdata();
            else
                std::cout << "-> " << tmp->getdata();
            tmp = tmp->next;
            k++;
        }
        std::cout << std::endl;
    }

    ~linkedlist()
    {
    }
};

int main(int argc, char const *argv[])
{
    linkedlist<double> L('s');

    L.push(150); //tail
    L.push(100.56546);
    L.push(500);
    L.push(10000);
    L.append(-5);
    L.append(-2);
    L.append(-1);
    L.push(120); //head
    L.head();
    L.tail();
    L.printlist();
    L.at(L.listsize() - 1);

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