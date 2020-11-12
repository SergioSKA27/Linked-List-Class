#include <iostream>
#include <string>
#include <cstdbool>
#include <cstdlib>
#include <vector>
#include <exception>
//node class
template <class type>
class Node
{
private:
    type Data;

public:
    Node *next;

    Node(type Data);

    Node();

<<<<<<< HEAD
    Node<type> &changedata(type newData);

    void showdata();

    type getdata();
=======
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
>>>>>>> 5b6fcb2d6110cfd99ac4a89e99cce7dab8791273

    ~Node();
};

template <class type>
Node<type>::Node(type Data)
{
    this->Data = Data;
    this->next = NULL;
};

template <class type>
Node<type>::Node()
{
    this->next = NULL;
};

template <class type>
Node<type> &Node<type>::changedata(type newData)
{ //cambia los datos del nodo
    Data = newData;
    return *this;
};

template <class type>
void Node<type>::showdata()
{ //muestra los datos del nodo
    std::cout << this->Data << std::endl;
};

template <class type>
type Node<type>::getdata()
{ //retorna la data como valor
    return this->Data;
};

template <class type>
Node<type>::~Node(){};

//linked list class

template <class ty>
class linkedlist
{
private:
    std::string Ltype;
    char ListType; //tipo de lista
    int size;      //tamaño de la lista
    bool emptys;

    Node<ty> *HeadrefS; // referencia a Head simple
    Node<ty> *TailrefS; // referencia al ultimo elemento de la lista
    Node<ty> *nde;      // nodos simples

public:
<<<<<<< HEAD
    linkedlist(char listType = 's');

    void push(ty Data); //colocar un elemento al principio de la lista

    void append(ty Data); //colocar un elemento al final de la lista

    void insert(int index, ty Data)
    {
        Node<ty> *tmp = HeadrefS, *ftail = HeadrefS;
        Node<ty> *prev = NULL, *sig = NULL;
        int k = 0;

        nde = new Node<ty>();
        nde->changedata(Data);
        if (HeadrefS == NULL)
        {
            nde->next = HeadrefS;
            HeadrefS = nde;
            TailrefS = nde;
            size += 1;
        }

        if (index > 0)
        {
            while (k < index && tmp != NULL)
            {
                tmp = tmp->next;
                k++;

                if (k == index - 1)
                    prev = tmp;

                if (k = index)
                    sig = tmp;
            }

            nde->next = sig;
            prev->next = nde;
            size += 1;

            while (ftail->next != NULL)
            {
                ftail = ftail->next;
            }
            TailrefS = ftail;
        }
    }

    Node<ty> *head(); //retorna un puntero a head(principio de la lista)

    Node<ty> *tail(); //retorna un puntero a tail(final de la lista)

    Node<ty> *at(int index); //acceder a un elemento de lista(los indices empiezan en 0)

    bool empty(); //saber si la lista esta vacia

    int listsize(); //tamaño de la lista

    void printlist(); //imprimir lista

    ~linkedlist();
};

template <class ty>
linkedlist<ty>::linkedlist(char listType)
{ // el constructor toma como parametros el tipo de lista que vamos a implementar

    this->ListType = ListType;
    this->size = 0;
    if (this->ListType == 's' || this->ListType == 'S')
    { //asignamos la cabercera de acuerdo al tipo de lista
        this->HeadrefS = NULL;
        this->TailrefS = NULL;
        this->emptys = true;
    }
};

template <class ty>
void linkedlist<ty>::push(ty Data)
{ // inserta un elemento al principio de la lista

    Node<ty> *tmp = this->HeadrefS;

    this->nde = new Node<ty>(); //crea un nuevo nodo

    this->nde->changedata(Data); //insertamos el dato
    this->emptys = false;
    this->nde->next = this->HeadrefS; // cambiamos la referencia al sig.
    this->HeadrefS = this->nde;
    this->size += 1; //aumentamos el tamaño de la lista por cada push

    tmp = nde;

    if (size == 1)
        this->TailrefS = this->nde;
    else
    {
        while (tmp->next != NULL)
        {
            tmp = tmp->next;
=======
    linkedlist(char listType)
    { // el constructor toma como parametros el tipo de lista que vamos a implementar

        this->ListType = ListType;
        this->size = 0;
        if (this->ListType == 's' || this->ListType == 'S')
        { //asignamos la cabercera de acuerdo al tipo de lista
            HeadrefS = NULL;
            TailrefS = NULL;
>>>>>>> 5b6fcb2d6110cfd99ac4a89e99cce7dab8791273
        }
        this->TailrefS = tmp;
    }
};

template <class ty>
void linkedlist<ty>::append(ty Data)
{ //inserta elementos al final de la lista
    Node<ty> *tmp;

<<<<<<< HEAD
    if (HeadrefS == NULL && TailrefS == NULL)
    {
        /*nde->next = tmp;
        tmp = nde;
        TailrefS = nde;*/
        this->append(Data);

        //emptys = false;
    }
    else
    {
        tmp = HeadrefS;
        nde = new Node<ty>();
        nde->changedata(Data);
        while (tmp->next != NULL)
        {
            tmp = tmp->next;
        }
        tmp->next = nde;
        TailrefS = tmp->next;
        size += 1;
        emptys = false;
    }
};

template <class ty>
Node<ty> *linkedlist<ty>::head()
{ // retorna un puntero a head

    this->HeadrefS->showdata(); // eliminalo si quieres
    return this->HeadrefS;
};

template <class ty>
Node<ty> *linkedlist<ty>::tail()
{ //retorna un puntero a tail(final de la lista)

    this->TailrefS->showdata(); // eliminalo si quieres
    return this->TailrefS;
};

template <class ty>
Node<ty> *linkedlist<ty>::at(int index)
{ //retorna el elemto de la lista indicado
    //los indices empiezan en 0

    Node<ty> *tmp = this->nde;
    int k = 0;

    while (k < index && tmp != NULL)
    {
        tmp = tmp->next;
        k++;
=======
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
>>>>>>> 5b6fcb2d6110cfd99ac4a89e99cce7dab8791273
    }
    tmp->showdata(); // eliminalo si quieres
    return tmp;
};

<<<<<<< HEAD
template <class ty>
bool linkedlist<ty>::empty()
{ //regresa true si la lista esta vacia
    if (emptys)
    {
        std::cout << "True\n";
        return true;
    }
    else
    {
        std::cout << "False\n";
        return false;
=======
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
>>>>>>> 5b6fcb2d6110cfd99ac4a89e99cce7dab8791273
    }
};

<<<<<<< HEAD
template <class ty>
int linkedlist<ty>::listsize()
{ //retorna el tamaño de la lista
    return this->size;
};

template <class ty>
void linkedlist<ty>::printlist()
{ // imprime la lista
    Node<ty> *tmp = nde;
    int k = 0;

    if (tmp == NULL)
    {
        std::cout << "empty list" << std::endl;
        return;
    }

    while (tmp != NULL)
=======
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
>>>>>>> 5b6fcb2d6110cfd99ac4a89e99cce7dab8791273
    {
        if (k == 0)
            std::cout << tmp->getdata();
        else
            std::cout << "-> " << tmp->getdata();
        tmp = tmp->next;
        k++;
    }
    std::cout << std::endl;
};

template <class ty>
linkedlist<ty>::~linkedlist(){};

int main(int argc, char const *argv[])
{
<<<<<<< HEAD

    linkedlist<int> List2, list;
    linkedlist<float> listf, L;
=======
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
>>>>>>> 5b6fcb2d6110cfd99ac4a89e99cce7dab8791273

    L.push(150);
    L.push(100.56546);
    L.push(500);
    L.push(10000);
    L.append(-5);
    L.append(-2);
    L.append(-1); //tail
    L.push(120);
    L.push(888); //head
    L.head();
    L.tail();
    L.printlist();
    L.at(5);
    List2.push(15);
    List2.push(10);
    List2.printlist();
    list.empty();
    listf.printlist();
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