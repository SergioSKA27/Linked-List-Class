#include <iostream>
#include <string>
#include <cstdbool>
#include <cstdlib>
#include <vector>
#include <exception>

/*Created By : Sergio :v 

Solamente Dios y yo sabiamos lo que haciamos al escribir este codigo, 
ahora solo Dios lo sabe , Suerte si intentas modificarlo :). 
*/
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

    Node<type> &changedata(type newData);

    void showdata();

    type getdata();

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

// Nodo doble
template <class tp>
class NodeD
{
private:
    tp Data;

public:
    NodeD *next;
    NodeD *prev;

    NodeD(tp Data);

    NodeD();

    NodeD<tp> &changedata(tp newData);

    void showdata();

    tp getdata();

    ~NodeD();
};

template <class tp>
NodeD<tp>::NodeD(tp Data)
{
    this->Data = Data;
    this->next = NULL;
    this->prev = NULL;
};

template <class tp>
NodeD<tp>::NodeD()
{
    this->next = NULL;
    this->prev = NULL;
};

template <class tp>
NodeD<tp> &NodeD<tp>::changedata(tp newData)
{ //cambia los datos del nodo
    Data = newData;
    return *this;
};

template <class tp>
void NodeD<tp>::showdata()
{ //muestra los datos del nodo
    std::cout << this->Data << std::endl;
};

template <class tp>
tp NodeD<tp>::getdata()
{ //retorna la data como valor
    return this->Data;
};

template <class tp>
NodeD<tp>::~NodeD(){};

//linked list class

template <class ty>
class linkedlist
{
private:
    int size; //tamaño de la lista
    bool emptys;

    Node<ty> *HeadrefS; // referencia a Head simple
    Node<ty> *TailrefS; // referencia al ultimo elemento de la lista
    Node<ty> *nde;      // nodos simples

public:
    linkedlist();

    void push(ty Data); //colocar un elemento al principio de la lista

    void append(ty Data); //colocar un elemento al final de la lista

    void insert(int index, ty Data); //inserta un nodo en el indice

    void insert_after(int index, ty Data); //inserta un nodo despues del indice

    Node<ty> *head(); //retorna un puntero a head(principio de la lista)

    Node<ty> *tail(); //retorna un puntero a tail(final de la lista)

    Node<ty> *at(int index); //acceder a un elemento de lista(los indices empiezan en 0)

    bool empty(); //saber si la lista esta vacia

    int listsize(); //tamaño de la lista

    virtual void printlist(); //imprimir lista

    void pop_front(); //elimina el elemento al principio de la lista.

    void pop_back(); //elimina el elemento al final

    ~linkedlist();
};

template <class ty>
linkedlist<ty>::linkedlist()
{ // el constructor toma como parametros el tipo de lista que vamos a implementar
    this->size = 0;
    this->HeadrefS = NULL;
    this->TailrefS = NULL;
    this->nde = NULL;
    this->emptys = true;
};

template <class ty>
void linkedlist<ty>::push(ty Data)
{ // inserta un elemento al principio de la lista

    Node<ty> *tmp = this->HeadrefS;

    this->nde = new Node<ty>(); //crea un nuevo nodo

    this->nde->changedata(Data);      //insertamos el dato
    this->emptys = false;             //cambiamos el estado de empty
    this->nde->next = this->HeadrefS; // cambiamos la referencia al sig.
    this->HeadrefS = this->nde;
    this->size += 1; //aumentamos el tamaño de la lista por cada push

    tmp = this->HeadrefS;

    if (size == 1)
        this->TailrefS = this->nde;
    else
    {
        while (tmp->next != NULL)
        {
            tmp = tmp->next;
        }
        this->TailrefS = tmp;
    }
};

template <class ty>
void linkedlist<ty>::append(ty Data)
{ //inserta elementos al final de la lista
    Node<ty> *tmp = NULL;

    if (this->HeadrefS == NULL && this->TailrefS == NULL)
    { //si la lista esta vacia hacemos push
        this->push(Data);
    }
    else
    {
        tmp = this->TailrefS;        //referencia al ultimo de la lista
        this->nde = new Node<ty>();  //creamos el nuevo nodo
        this->nde->changedata(Data); //insertamos la data en el nodo

        tmp->next = nde;            // el sig. del final es el nuevo nodo
        this->TailrefS = tmp->next; //cambiamos la ref. al ultimo
        this->size += 1;            //aumentamos el tamaño
        this->emptys = false;
    }
};

template <class ty>
void linkedlist<ty>::insert(int index, ty Data)
{ //inserta un nodo el el indice señalado
    Node<ty> *fnext = NULL, *findprev = NULL, *ftail = NULL;
    Node<ty> *tmp = NULL;
    int k = 0;

    if (index == 0)
    { //si el index es 0
        this->push(Data);
    }
    else if (index == this->size - 1)
    { //si el index es el ultimo de la lista
        this->append(Data);
    }
    else
    { //elementos intermedios
        tmp = this->HeadrefS;
        this->nde = new Node<ty>(); //creamos el nuevo nodo
        this->nde->changedata(Data);

        while (k < this->size - 1 && tmp != NULL)
        {                       //buscamos el previo y el sig. para insertar
            if (k == index - 1) //previo
                findprev = tmp;
            if (k == index)
                fnext = tmp; //siguiente

            tmp = tmp->next; //iteramos la lista
            k++;
        }

        findprev->next = this->nde; // el sig. del previo es el nuevo nodo
        this->nde->next = fnext;    // el sig. del nuevo nodo es el sig. del previo
        this->size += 1;            //aumentamos el tamaño
        this->emptys = false;

        ftail = this->HeadrefS;
        while (ftail->next != NULL)
        { //buscamos el nuevo tail
            ftail = ftail->next;
        }
        this->TailrefS = ftail; //actualizamos el nuevo tail
    }
}

template <class ty>
void linkedlist<ty>::insert_after(int index, ty Data)
{ //inserta un nodo despues del indice
    Node<ty> *fnext = NULL, *findprev = NULL, *ftail = NULL;
    Node<ty> *tmp = NULL;
    int k = 0;

    if (index == this->size - 1)
    { //si el index es el ultimo de la lista
        this->append(Data);
    }
    else
    { //resto del los elementos
        tmp = this->HeadrefS;
        this->nde = new Node<ty>(); //creamos el nuevo nodo
        this->nde->changedata(Data);

        while (k < this->size - 1 && tmp != NULL)
        { //buscamos el previo y el sig. para insertar

            if (k == index) //previo
                findprev = tmp;
            if (k == index + 1)
                fnext = tmp; //siguiente

            tmp = tmp->next; //iteramos la lista
            k++;
        }

        findprev->next = this->nde; // el sig. del previo es el nuevo nodo
        this->nde->next = fnext;    // el sig. del nuevo nodo es el sig. del previo
        this->size += 1;            //aumentamos el tamaño
        this->emptys = false;

        ftail = this->HeadrefS;
        while (ftail->next != NULL)
        { //buscamos el nuevo tail
            ftail = ftail->next;
        }
        this->TailrefS = ftail; //actualizamos el nuevo tail
    }
}

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
    Node<ty> *tmp = this->HeadrefS;
    int k = 0;

    if (index)

        if (index == 0)
            //para ingresar el primer elemento
            return this->HeadrefS;
    if (index == this->size - 1 || index == -1)
        //para ingresar al ultimo elemento puedes usar el indice -1 o el tamaño total de la lista.
        return this->TailrefS;
    while (k < index && tmp != NULL)
    { //para acceder a otra posicion
        tmp = tmp->next;
        k++;
    }
    tmp->showdata(); // eliminalo si quieres
    return tmp;
};

template <class ty>
bool linkedlist<ty>::empty()
{ //regresa true si la lista esta vacia
    if (emptys)
    {
        std::cout << "True\n"; //eliminalo si quieres
        return true;
    }
    else
    {
        std::cout << "False\n"; //^same
        return false;
    }
};

template <class ty>
int linkedlist<ty>::listsize()
{ //retorna el tamaño de la lista
    return this->size;
};

template <class ty>
void linkedlist<ty>::printlist()
{ // imprime la lista
    Node<ty> *tmp = this->HeadrefS;
    int k = 0;

    if (tmp == NULL)
    {
        std::cout << "empty list" << std::endl;
        return;
    }

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
};

template <class ty>
void linkedlist<ty>::pop_front()
{ //elimina un elemento al principio de la lista
    Node<ty> *tmp = NULL;
    if (this->HeadrefS == NULL)
        return;
    else
    {
        tmp = this->HeadrefS;
        this->HeadrefS = this->HeadrefS->next;
        delete tmp;
        this->size -= 1;
        if (this->HeadrefS == NULL) // si la lista esta vacia
            this->emptys = true;
    }
}

template <class ty>
void linkedlist<ty>::pop_back()
{ //elimina el elemento al final de la lista
    Node<ty> *tmp = NULL, *fnwt = NULL, *prev = NULL;
    int k = 0;

    if (this->TailrefS == NULL)
        return;
    else
    {
        prev = this->HeadrefS;
        tmp = this->TailrefS;
        while (prev != NULL && k < this->size - 2)
        {
            prev = prev->next;
            k++;
        }
        prev->next = NULL;
        delete tmp;
        this->size -= 1;
        fnwt = this->HeadrefS;
        while (fnwt->next != NULL)
        {
            fnwt = fnwt->next;
        }
        this->TailrefS = fnwt;
    }
}

template <class ty>
linkedlist<ty>::~linkedlist(){

    /* while (this->HeadrefS != NULL)
    {
        this->pop();
    }*/
};
//lista doblemente ligada
template <class t>
class linkedlistD
{
private:
    //tipo de lista
    int sz; //tamaño de la lista
    bool emptys;

    NodeD<t> *HeadrefD; // referencia a Head simple
    NodeD<t> *TailrefD; // referencia al ultimo elemento de la lista
    NodeD<t> *nodes;    // nodos simples

public:
    linkedlistD();

    void push(t Data); //colocar un elemento al principio de la lista

    void append(t Data); //colocar un elemento al final de la lista

    void insert(int index, t Data); //inserta un nodo en el indice

    void insert_after(int index, t Data); //inserta un nodo despues del indice

    NodeD<t> *head(); //retorna un puntero a head(principio de la lista)

    NodeD<t> *tail(); //retorna un puntero a tail(final de la lista)

    NodeD<t> *at(int index); //acceder a un elemento de lista(los indices empiezan en 0)

    bool empty(); //saber si la lista esta vacia

    int listsize(); //tamaño de la lista

    void printlist(); //imprimir lista

    void pop_front();

    void pop_back();

    ~linkedlistD();
};

template <class t>
linkedlistD<t>::linkedlistD()
{
    this->HeadrefD = NULL;
    this->TailrefD = NULL;
    this->nodes = NULL;
    this->sz = 0;
    this->emptys = true;
};

template <class t>
void linkedlistD<t>::push(t Data)
{

    NodeD<t> *tmp = this->HeadrefD;

    this->nodes = new NodeD<t>();
    this->nodes->changedata(Data);

    this->nodes->next = this->HeadrefD;
    this->nodes->prev = NULL;
    if (this->HeadrefD != NULL)
        this->HeadrefD->prev = this->nodes;
    this->HeadrefD = this->nodes;
    this->sz += 1;
    this->emptys = false;

    if (this->sz == 1)
    {
        this->TailrefD = this->HeadrefD;
    }
    else
    {

        while (tmp->next != NULL)
        {
            tmp = tmp->next;
        }
        this->TailrefD = tmp;
    }
};

template <class t>
void linkedlistD<t>::append(t Data)
{
}

//template <class t>

//template <class t>

//template <class t>

//template <class t>

//template <class t>

template <class t>
void linkedlistD<t>::printlist()
{

    NodeD<t> *tmp = this->HeadrefD;
    int k = 0;
    if (tmp == NULL)
    {
        std::cout << "empty list\n";
        return;
    }

    while (tmp != NULL)
    {
        if (k == 0)
            std::cout << tmp->getdata();
        else
            std::cout << " <=> " << tmp->getdata();

        tmp = tmp->next;
        k++;
    }
    std::cout << std::endl;
};

template <class t>
linkedlistD<t>::~linkedlistD(){};

int main(int argc, char const *argv[])
{

    linkedlist<int> List2, list; //listas simples
    linkedlist<float> listf, L;
    linkedlistD<int> listadoble;

    listadoble.push(10);
    listadoble.push(18);
    listadoble.push(17);
    listadoble.push(16);
    listadoble.push(15);
    listadoble.printlist();

    /*L.push(15);
    L.empty();
    L.pop();
    L.empty();*/

    L.append(-1);
    L.push(150);
    L.push(100.56546);
    L.push(500);
    L.push(10000);
    L.insert(1, -99);
    L.insert_after(0, -100);
    L.printlist();
    L.pop_back();
    L.printlist();
    L.append(-5);
    L.append(-2);
    L.pop_front();
    L.printlist();
    L.tail();
    L.at(L.listsize() - 1);
    L.append(-1); //tail
    L.push(120);
    L.push(888); //head
    L.printlist();
    L.head();
    L.tail();
    //L.~linkedlist();
    L.printlist();
    L.at(5);
    List2.push(15);
    List2.push(10);
    List2.printlist();
    list.empty();
    listf.insert(0, 1);
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