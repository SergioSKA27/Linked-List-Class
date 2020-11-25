#include <iostream>
#include <string>
#include <cstdbool>
#include <cstdlib>
#include <vector>
#include <exception>

/*Created By : Sergio xd 

Solamente Dios y yo sabiamos lo que haciamos al escribir este codigo, 
ahora solo Dios lo sabe , Suerte si intentas modificarlo :). 
*/
//NODO SIMPLE
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
//.............................................................................................
template <class type>
Node<type>::Node(type Data)
{
    this->Data = Data;
    this->next = NULL;
};
//.............................................................................................
template <class type>
Node<type>::Node()
{
    this->next = NULL;
};
//.............................................................................................
template <class type>
Node<type> &Node<type>::changedata(type newData)
{ //cambia los datos del nodo
    Data = newData;
    return *this;
};
//.............................................................................................
template <class type>
void Node<type>::showdata()
{ //muestra los datos del nodo
    std::cout << this->Data << std::endl;
};
//.............................................................................................
template <class type>
type Node<type>::getdata()
{ //retorna la data como valor
    return this->Data;
};
//.............................................................................................
template <class type>
Node<type>::~Node(){};
//#############################################################################################
// NODO DOBLE
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
//.............................................................................................
template <class tp>
NodeD<tp>::NodeD(tp Data)
{
    this->Data = Data;
    this->next = NULL;
    this->prev = NULL;
};
//.............................................................................................
template <class tp>
NodeD<tp>::NodeD()
{
    this->next = NULL;
    this->prev = NULL;
};
//.............................................................................................
template <class tp>
NodeD<tp> &NodeD<tp>::changedata(tp newData)
{ //cambia los datos del nodo
    Data = newData;
    return *this;
};
//.............................................................................................
template <class tp>
void NodeD<tp>::showdata()
{ //muestra los datos del nodo
    std::cout << this->Data << std::endl;
};
//.............................................................................................
template <class tp>
tp NodeD<tp>::getdata()
{ //retorna la data como valor
    return this->Data;
};
//.............................................................................................
template <class tp>
NodeD<tp>::~NodeD(){};

//#############################################################################################
//LISTA SIMPLEMENTE LIGADA
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
    //CONSTRUCTORES

    linkedlist();

    //METODOS

    void push(ty Data); //colocar un elemento al principio de la lista

    void append(ty Data); //colocar un elemento al final de la lista

    void insert(int index, ty Data); //inserta un nodo en el indice

    void insert_after(int index, ty Data); //inserta un nodo despues del indice

    Node<ty> *head(); //retorna un puntero a head(principio de la lista)

    Node<ty> *tail(); //retorna un puntero a tail(final de la lista)

    Node<ty> *at(int index); //acceder a un elemento de lista(los indices empiezan en 0)

    bool empty(); //saber si la lista esta vacia

    int listsize(); //tamaño de la lista

    void printlist(); //imprimir lista

    void pop_front(); //elimina el elemento al principio de la lista.

    void pop_back(); //elimina el elemento al final

    void del(int index); //elimina el elemento del indice proporcionado

    void clear(); //elimina todos los elementos de la lista

    void search_and_del(ty element); //busca el elemento lo elimina

    int search(ty element); //busca un elemento y retorna su posicion(indice), si no retorna -1

    void reverselist(); //invierte una lista(la cambia)

    linkedlist<ty> reverse(); //retorna la lista invertida y conserva la original

    //OPERADORES

    linkedlist<ty> &operator=(const linkedlist<ty> &list); //copiar una lista en otra

    linkedlist<ty> &operator+=(const linkedlist<ty> &list); //operador union(añade una lista a la actual)

    linkedlist<ty> operator+(const linkedlist<ty> &list); //une dos lista y retorna la lista unida(no modifica las listas unidas)

    bool operator==(const linkedlist<ty> &list) const; //compara si dos listas son iguales

    ty operator[](const int &index); //operador de acceso con corchetes

    //DESTRUCTOR

    ~linkedlist();
};
//.............................................................................................
template <class ty>
linkedlist<ty>::linkedlist()
{
    this->size = 0;
    this->HeadrefS = NULL;
    this->TailrefS = NULL;
    this->nde = NULL;
    this->emptys = true;
};
//.............................................................................................
/*INSERTA UN ELEMENTO AL PRINCIPIO DE LA LISTA*/
template <class ty>
void linkedlist<ty>::push(ty Data)
{
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
    { //buscamos el tail(final de la lista)
        while (tmp->next != NULL)
        {
            tmp = tmp->next;
        }
        this->TailrefS = tmp;
    }
};
//.............................................................................................
/*INSERTA UN ELEMENTO AL FINAL DE LA LISTA*/
template <class ty>
void linkedlist<ty>::append(ty Data)
{
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
//.............................................................................................
/*INSERTA UN EL ELEMENTO EN LA POSICION INDICADA(INDICES EMPIEZAN EN 0)*/
template <class ty>
void linkedlist<ty>::insert(int index, ty Data)
{
    Node<ty> *fnext = NULL, *findprev = NULL;
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
    }
}
//.............................................................................................
/*INSERTA UN ELEMENTO DESPUES DE LA POSICION INDICADA(INDICES EMPIEZAN EN 0)*/
template <class ty>
void linkedlist<ty>::insert_after(int index, ty Data)
{
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
//.............................................................................................
/*RETORNA UN PUNTERO A HEAD (PRINCIPIO DE LA LISTA)*/
template <class ty>
Node<ty> *linkedlist<ty>::head()
{
    //this->HeadrefS->showdata(); // eliminalo si quieres
    return this->HeadrefS;
};
//.............................................................................................
/*RETORNA UN PUNTERO A TAIL(FINAL DE LA LISTA)*/
template <class ty>
Node<ty> *linkedlist<ty>::tail()
{
    //this->TailrefS->showdata(); // eliminalo si quieres
    return this->TailrefS;
};
//.............................................................................................
/*RETORNA UN PUNTERO A LA POSICION INDICADA(INDICES EMPIEZAN EN 0)*/
template <class ty>
Node<ty> *linkedlist<ty>::at(int index)
{
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
//.............................................................................................
/*DETERMINA SI LA LISTA ESTA VACIA*/
template <class ty>
bool linkedlist<ty>::empty()
{
    if (emptys)
    {
        //std::cout << "True\n"; //eliminalo si quieres
        return true;
    }
    else
    {
        //std::cout << "False\n"; //^same
        return false;
    }
};
//.............................................................................................
/*RETORNA EL TAMAÑO DE LA LISTA*/
template <class ty>
int linkedlist<ty>::listsize()
{
    return this->size;
};
//.............................................................................................
/*IMPRIME LA LISTA*/
template <class ty>
void linkedlist<ty>::printlist()
{
    Node<ty> *tmp = this->HeadrefS;
    int k = 0;

    if (tmp == NULL)
    { //si la lista esta vacia
        std::cout << "empty list" << std::endl;
        return;
    }

    while (tmp != NULL)
    { //recorremos la lista e imprimimos los elementos

        if (k == 0) //si es el primer elemento lo imprimimos
            std::cout << tmp->getdata();
        else //si no ponemos una flecha antes de imprimir
            std::cout << "-> " << tmp->getdata();
        tmp = tmp->next;
        k++;
    }
    std::cout << std::endl;
};
//.............................................................................................
/*ELIMINA EL PRIMER ELEMENTO DE LA LISTA*/
template <class ty>
void linkedlist<ty>::pop_front()
{
    Node<ty> *tmp = NULL;
    if (this->HeadrefS == NULL)
        return;
    else
    {
        tmp = this->HeadrefS;                  //guardamos el head actual
        this->HeadrefS = this->HeadrefS->next; //el nuevo head es el sig. del head actual(tmp)
        delete tmp;                            //eliminamos  el head(tmp)
        this->size -= 1;                       //reducimos el tamaño de la lista
        if (this->HeadrefS == NULL)            // si la lista esta vacia
            this->emptys = true;
    }
}
//.............................................................................................
/*ELIMINA EL ULTIMO ELEMENTO DE LA LISTA*/
template <class ty>
void linkedlist<ty>::pop_back()
{
    Node<ty> *tmp = NULL, *prev = NULL;
    int k = 0;

    if (this->TailrefS == NULL) //si la lista esta vacia
        return;
    else
    {
        prev = this->HeadrefS;
        tmp = this->TailrefS;
        while (prev != NULL && k < this->size - 2)
        { //buscamos el previo al ultimo
            prev = prev->next;
            k++;
        }
        prev->next = NULL;     //quitamos  la referencia al sig.
        delete tmp;            //eliminamos el ultimo
        this->size -= 1;       //reducimos el tamaño de la lista
        this->TailrefS = prev; //el nuevo tail es el previo al ultimo
    }
}
//.............................................................................................
/*ELIMINA EL ELEMENTO EN LA POSICION INDICADA DE LA LISTA*/
template <class ty>
void linkedlist<ty>::del(int index)
{
    Node<ty> *tmp = NULL, *prev = NULL;
    int k = 0;

    if (index == 0)
    { //si quieren eliminar el primero
        this->pop_front();
        return;
    }
    if (index == this->size - 1)
    { //si el elemeto elemento es el ultimo
        this->pop_back();
        return;
    }
    tmp = this->HeadrefS;

    while (tmp != NULL)
    { //iteramos la lista
        if (k == index - 1)
            prev = tmp; //guardamos el previo al elemento a eliminar
        if (k == index)
            break; //cuando llegamos al elemento detenemos el ciclo

        tmp = tmp->next;
        k++;
    }

    prev->next = tmp->next;
    delete tmp;
    this->size -= 1;
}
//.............................................................................................
/*BUSCA UN ELEMENTO SI LO ENCUENTRA LO ELIMINA*/
template <class ty>
void linkedlist<ty>::search_and_del(ty element)
{
    Node<ty> *tmp = this->HeadrefS, *prev = NULL;
    bool found = false;

    if (this->HeadrefS->getdata() == element)
    { //si el elemento es el primero de la lista
        this->pop_front();
        return;
    }
    if (this->TailrefS->getdata() == element)
    { //si el elemento es el ultimo de la lista
        this->pop_back();
        return;
    }

    while (tmp != NULL)
    {
        if (tmp->next->getdata() == element)
            //si el sig. es el elemento guardamos como previo
            prev = tmp;

        if (tmp->getdata() == element)
        { //si encontramos el elemento rompemos el ciclo
            found = true;
            break;
        }
        tmp = tmp->next;
    }

    if (!found)
    {
        return;
    }
    else
    {
        prev->next = tmp->next; //el sig. del previo es el sig. del elemento
        delete tmp;             //eliminamos el elemento
        this->size -= 1;        //reduciomos el tamaño
    }
}
//.............................................................................................
/*BUSCA UN ELEMENTO SI LO ENCUENTRA RETORNA SU POSICION, DE LO CONTRARIO RETORNA -1 */
template <class ty>
int linkedlist<ty>::search(ty element)
{
    Node<ty> *tmp = this->HeadrefS;
    int k = 0;
    bool found = false;

    if (element == this->HeadrefS->getdata())
    { //si el elemento es el primero de la lista
        return 0;
    }
    if (element == this->TailrefS->getdata())
    { //si el elemento es el ultimo de la lista
        return this->size - 1;
    }

    while (tmp != NULL)
    { //iteramos la lista
        if (tmp->getdata() == element)
        { //si encontramos el elemento rompemos el ciclo
            found = true;
            break;
        }
        tmp = tmp->next;
        k++;
    }

    if (found)
    { //si encontramos el elemento retornamos su posicion(k)
        return k;
    }
    else
    { //sino retornamos -1
        return -1;
    }
}
//.............................................................................................
/*INVIERTE UNA LISTA DE FORMA ITERATIVA(LA CAMBIA)*/
template <class ty>
void linkedlist<ty>::reverselist()
{ //voltea una lista de manera iterativa
    Node<ty> *tmp = NULL, *newhead = this->TailrefS, *newtail = NULL;
    Node<ty> *aux = NULL, *prev = NULL, *it = NULL;
    int k, i = 2;

    if (this->size == 1 || this->size == 0)
    { //si la lista esta vacia o solo tiene un elemento
        return;
    }
    else
    {
        newtail = this->HeadrefS; //nuevo final
        tmp = newtail;
        it = newhead;
        newhead->next = NULL;
        //it->showdata();//si quieres ver como se ejecuta el algoritmo quita los comentarios con *

        while (newtail->next != NULL)
        { //mientras el sig. del nuevo final no sea nulo iteramos
            tmp = newtail;
            k = 0;
            while (tmp->next != NULL)
            { //buscamos el penultimo y antepenultimo elemento
                if (k == this->size - i)
                {
                    //*tmp->showdata();
                    break;
                }
                if (k == this->size - i - 1)
                {
                    prev = tmp;
                    //*prev->showdata();
                }
                tmp = tmp->next;
                k++;
            }
            it->next = tmp;        //el sig. del nuevo head es el penultimo
            it->next->next = NULL; //quitamos la ref. del sig. del penultimo
            prev->next = NULL;     //quitamos la ref. del sig. del antepenultimo
            //con lo que se convierte en el nuevo penultimo y el prev. a este
            //en el nuevo antepenultimo.
            it = it->next; //itermos el nuevo head
            //*it->showdata();
            i++;
        }
        it->next = newtail;
        this->HeadrefS = newhead;
        this->TailrefS = newtail;
    }
}
//.............................................................................................
/*RETORNA LA LISTA INVERTIDA Y CONSERVA LA ORIGINAL*/
template <class ty>
linkedlist<ty> linkedlist<ty>::reverse()
{
    linkedlist<ty> reversel;
    Node<ty> *tmp = NULL, *nwhead = this->TailrefS, *nwtail = NULL;
    Node<ty> *aux = NULL, *prev = NULL;
    int k, i = 2;

    if (this->emptys)
    {
        return reversel;
    }

    nwtail = this->HeadrefS;
    tmp = nwtail;
    reversel.append(nwhead->getdata()); //añadimos el ultimo a la lista

    while (tmp != NULL)
    {
        if (i > this->size)
            break; //detenemos cuando la iteracion sea mayor que el tamaño de la lista
        tmp = nwtail;
        k = 0;

        while (tmp->next != NULL)
        { //recorremos la lista y buscamos el penultimo
            if (k == this->size - i)
                break;
            tmp = tmp->next;
            k++;
        }
        reversel.append(tmp->getdata()); //lo ponemos en la lista

        i++; //ahora en la sig. iteracion buscamos el que esta antes del penultimo y asi sucesivamente
    }

    reversel.printlist(); //eliminalo si quieres

    return reversel;
}
//.............................................................................................
/*ELIMINA TODOS LOS ELEMENTOS DE LA LISTA*/
template <class ty>
void linkedlist<ty>::clear()
{ //elimina todos los elementos de la lista
    Node<ty> *tmp = NULL, *it = NULL, *aux = NULL;

    if (this->emptys)
    { //si la lista esta vacia
        return;
    }
    tmp = this->HeadrefS;
    it = tmp->next;

    while (tmp != NULL)
    { //eliminamos el elemento en cada iteracion

        aux = tmp;       //guardamos la direccion del elemento
        tmp = tmp->next; //iteramos al sig.
        delete aux;      //eliminamos el elemento previo
    }

    this->HeadrefS = tmp;
    this->TailrefS = tmp;
    this->emptys = true;
    this->size = 0;
}
//.............................................................................................
//OPERADORES
template <class ty>
linkedlist<ty> &linkedlist<ty>::operator=(const linkedlist<ty> &lst)
{ //operador de asignacion
    Node<ty> *tmp = lst.HeadrefS;
    if (this->emptys)
    { //si la lista esta vacia
        while (tmp != NULL)
        {
            this->append(tmp->getdata());
            tmp = tmp->next;
        }
        return *this;
    }
    else
    { //si la lista no esta vacia eliminamos lo que tenga y remplazamos con la nueva lista(lst)
        this->clear();
        while (tmp != NULL)
        {
            this->append(tmp->getdata());
            tmp = tmp->next;
        }
        return *this;
    }
}
//---------------------------------------------------------------------------------------------
template <class ty>
linkedlist<ty> &linkedlist<ty>::operator+=(const linkedlist<ty> &lst)
{
    Node<ty> *nxtail = lst.HeadrefS, *nwtail = lst.TailrefS;

    if (lst.emptys)
    {
        return *this;
    }
    else
    {
        while (nxtail != NULL)
        {
            this->append(nxtail->getdata());
            this->size += 1;
            nxtail = nxtail->next;
        }
        this->TailrefS = nwtail;

        return *this;
    }
}

template <class ty>
linkedlist<ty> linkedlist<ty>::operator+(const linkedlist<ty> &lst)
{
    linkedlist<ty> listU;
    Node<ty> *tmp = this->HeadrefS, *tmp2 = lst.HeadrefS;

    while (tmp != NULL)
    {
        listU.append(tmp->getdata());
        tmp = tmp->next;
    }

    while (tmp2 != NULL)
    {
        listU.append(tmp2->getdata());
        tmp2 = tmp2->next;
    }

    return listU;
}

//---------------------------------------------------------------------------------------------
template <class ty>
bool linkedlist<ty>::operator==(const linkedlist<ty> &lst) const
{
    Node<ty> *tmp = this->HeadrefS, *cmp = lst.HeadrefS;
    int s = 0;

    if (this->size != lst.size) //si los tamaños de la lista son distintos
        return false;

    while (tmp != NULL)
    {
        if (tmp->getdata() == cmp->getdata())
            s++;
        tmp = tmp->next;
        cmp = cmp->next;
    }

    if (s == this->size) //si tiene los mismos elementos en orden
        return true;
    else
        return false;
}
//---------------------------------------------------------------------------------------------
template <class ty>
ty linkedlist<ty>::operator[](const int &index)
{
    if ((index > this->size - 1 || index < 0) && index != -1) //si el indice esta fuera de rango
        throw std::out_of_range("invalid  index \n");
    else
    {
        if (index == -1) //con el indice -1 accedemos al final de la lista
            return this->TailrefS->getdata();
        else
            return this->at(index)->getdata();
    }
}

//.............................................................................................
template <class ty>
linkedlist<ty>::~linkedlist()
{
    while (this->HeadrefS != NULL)
    {
        this->pop_front();
    }
};
//#############################################################################################
//LISTA DOBLEMENTE LIGADA
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

    void pop_front(); //elimina el primer elmento de la lista

    void pop_back(); //elimina el ultimo elemento de la lista

    void del(int index); //elimina el elemento de la posicion indicada(indices empiezan en 0)

    void clear(); //elimina todos los elementos de la lista

    void search_and_del(t element); //busca un elemento y si lo encuentra lo elimina

    int search(t element); //busca un elemento si lo encuentra regresa su posicion(si no retorna -1 )

    void reverselist(); //invierte una lista de forma iterativa

    linkedlistD<t> reverse(); //retorna la lista invertida y conserva la original

    //OPERADORES

    linkedlistD<t> &operator=(const linkedlistD<t> &list);  //operador asignacion
    linkedlistD<t> &operator+=(const linkedlistD<t> &list); //añade una lista a la lista actual
    linkedlistD<t> operator+(const linkedlistD<t> &list);   //une dos listas y retorna la lista unida
    bool operator==(const linkedlistD<t> &list) const;      //compara el tamaño y los elementos si todo es igual retorna true
    t operator[](int index);                                //oprador de acceso con corchetes

    //funciones para merge sort
    void sort();

    ~linkedlistD();
};
//.............................................................................................
template <class t>
linkedlistD<t>::linkedlistD()
{
    this->HeadrefD = NULL;
    this->TailrefD = NULL;
    this->nodes = NULL;
    this->sz = 0;
    this->emptys = true;
};
//.............................................................................................
template <class t>
void linkedlistD<t>::push(t Data)
{

    NodeD<t> *tmp = this->HeadrefD;

    this->nodes = new NodeD<t>();  //creamos el nodo
    this->nodes->changedata(Data); //insertamos el dato

    this->nodes->next = this->HeadrefD; //el sig. del nodo es head
    this->nodes->prev = NULL;
    if (this->HeadrefD != NULL)             //si el head no es nulo
        this->HeadrefD->prev = this->nodes; //el previo del head anterior es el nuevo nodo
    this->HeadrefD = this->nodes;           //hacemos head el nuevo nodo
    this->sz += 1;                          //aumentamos el tamaño
    this->emptys = false;

    if (this->sz == 1)
    { //si el tamaño de la lista es uno
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
//.............................................................................................
template <class t>
void linkedlistD<t>::append(t Data)
{
    NodeD<t> *tmp = NULL;
    if (this->HeadrefD == NULL)
    { //si la lista esta vacia hacemos push
        this->push(Data);
    }
    else
    {
        tmp = this->TailrefD; //selecionamos el final de la lista

        this->nodes = new NodeD<t>();  //creamos el nodo
        this->nodes->changedata(Data); //insertamos la data

        tmp->next = this->nodes;    //el sig. del final es el nuevo nodo
        this->nodes->prev = tmp;    //el previo del nuevo nodo es el final
        this->TailrefD = tmp->next; //hacemos que el nuevo nodo sea el final
        this->sz += 1;              //aumentamos el tamaño
        this->emptys = false;
    }
}
//.............................................................................................
template <class t>
void linkedlistD<t>::insert(int index, t Data)
{
    NodeD<t> *tmp = NULL, *prv = NULL;
    NodeD<t> *ftail = this->HeadrefD;
    int k = 0;

    if (index == 0)
        this->push(Data);
    else if (index == this->sz - 1)
        this->append(Data);
    else
    {
        tmp = this->HeadrefD;
        this->nodes = new NodeD<t>();
        this->nodes->changedata(Data);

        while (tmp != NULL && k <= index)
        {
            if (k == index)
                break;
            tmp = tmp->next;
            k++;
        }
        prv = tmp->prev;
        prv->next = this->nodes;
        this->nodes->prev = prv;
        this->nodes->next = tmp;
        tmp->prev = this->nodes;

        this->sz += 1;
        this->emptys = false;

        while (ftail->next != NULL)
        {
            ftail = ftail->next;
        }
        this->TailrefD = ftail;
    }
}
//.............................................................................................
template <class t>
NodeD<t> *linkedlistD<t>::head()
{
    return this->HeadrefD;
}
//.............................................................................................
template <class t>
NodeD<t> *linkedlistD<t>::tail()
{
    return this->TailrefD;
}
//.............................................................................................
template <class t>
NodeD<t> *linkedlistD<t>::at(int index)
{
    NodeD<t> *tmp = this->HeadrefD;
    int k = 0;

    if (index == 0)
        //para ingresar el primer elemento
        return this->HeadrefD;
    if (index == this->sz - 1 || index == -1)
        //para ingresar al ultimo elemento puedes usar el indice -1 o el tamaño total de la lista.
        return this->TailrefD;
    while (k < index && tmp != NULL)
    { //para acceder a otra posicion
        tmp = tmp->next;
        k++;
    }
    //tmp->showdata(); // eliminalo si quieres
    return tmp;
}
//.............................................................................................
template <class t>
bool linkedlistD<t>::empty()
{
    return this->emptys;
}
//.............................................................................................
template <class t>
int linkedlistD<t>::listsize()
{
    return this->sz;
}
//.............................................................................................
template <class t>
void linkedlistD<t>::sort()
{
    NodeD<t> *tmp = NULL;

    if (this->sz == 0)
        return;

    tmp = this->HeadrefD;
    tmp = mergesort(tmp);
    this->HeadrefD = tmp;
}
//.............................................................................................
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
            std::cout << " <-> " << tmp->getdata();

        tmp = tmp->next;
        k++;
    }
    std::cout << std::endl;
};
//.............................................................................................
template <class t>
void linkedlistD<t>::pop_front()
{
    NodeD<t> *tmp = NULL;

    if (this->HeadrefD == NULL)
        return;
    else if (this->sz == 1)
    {
        tmp = this->HeadrefD;
        this->HeadrefD = NULL;
        this->sz -= 1;
        this->emptys = true;
        delete tmp;
    }
    else
    {
        tmp = this->HeadrefD;
        this->HeadrefD = this->HeadrefD->next;
        this->HeadrefD->prev = NULL;
        delete tmp;
        this->sz -= 1;
    }
}
//.............................................................................................
template <class t>
void linkedlistD<t>::pop_back()
{
    NodeD<t> *tmp = this->TailrefD, *prev = NULL;
    if (this->TailrefD == NULL)
        return;
    else
    {
        prev = tmp->prev;
        prev->next = NULL;
        this->TailrefD = prev;
        delete tmp;
        this->sz -= 1;
        if (this->sz == 0)
            this->emptys = true;
    }
}
//.............................................................................................
template <class t>
void linkedlistD<t>::del(int index)
{
    NodeD<t> *tmp = NULL, *prev = NULL, *nxt = NULL;
    int k = 0;

    if (index == 0)
    {
        this->pop_front();
        return;
    }
    else if (index == this->sz - 1)
    {
        this->pop_back();
        return;
    }
    else
    {
        tmp = this->HeadrefD;
        while (tmp->next != NULL)
        {
            if (k == index)
                break;
            tmp = tmp->next;
            k++;
        }
        prev = tmp->prev;
        nxt = tmp->next;

        prev->next = nxt;
        nxt->prev = prev;

        delete tmp;
        this->sz -= 1;
    }
}
//.............................................................................................
template <class t>
void linkedlistD<t>::clear()
{
    NodeD<t> *tmp = NULL, *aux = NULL;

    if (this->emptys)
        return;

    tmp = this->HeadrefD;

    while (tmp != NULL)
    {
        aux = tmp;
        tmp = tmp->next;
        delete aux;
    }

    this->HeadrefD = tmp;
    this->TailrefD = tmp;
    this->sz = 0;
    this->emptys = true;
}
//.............................................................................................
template <class t>
void linkedlistD<t>::search_and_del(t element)
{
    NodeD<t> *tmp = NULL, *prev = NULL, *nxt = NULL;

    if (this->HeadrefD->getdata() == element)
    {
        this->pop_front();
        return;
    }
    else if (this->TailrefD->getdata() == element)
    {
        this->pop_back();
        return;
    }
    else
    {
        tmp = this->HeadrefD;

        while (tmp->next != NULL)
        {
            if (tmp->getdata() == element)
                break;
            tmp = tmp->next;
        }
        prev = tmp->prev;
        nxt = tmp->next;
        prev->next = nxt;
        nxt->prev = prev;
        delete tmp;
        this->sz -= 1;
    }
}
//.............................................................................................
template <class t>
int linkedlistD<t>::search(t element)
{
    NodeD<t> *tmp = NULL;
    int k = 0;
    bool found = false;
    if (this->HeadrefD->getdata() == element)
        return 0;
    if (this->TailrefD->getdata() == element)
        return this->sz - 1;

    tmp = this->HeadrefD;
    while (tmp->next != NULL)
    {
        if (tmp->getdata() == element)
        {
            found = true;
            break;
        }
        tmp = tmp->next;
        k++;
    }

    if (!found)
        return -1;
    else
        return k;
}
//.............................................................................................
template <class t>
void linkedlistD<t>::reverselist()
{ //en proceso XD
    NodeD<t> *tmp = NULL, *prev = NULL, *prevprev = NULL;
    NodeD<t> *nwhead = NULL, *nwtail = NULL, *it = NULL, *aux = NULL;

    int k = 0, i = 2;

    if (this->HeadrefD == NULL || this->sz == 1)
        return;

    nwhead = this->TailrefD;
    nwtail = this->HeadrefD;
    tmp = nwhead->prev;
    aux = tmp;
    it = nwhead;

    while (tmp->prev != NULL)
    {
        aux = tmp;

        it->next = tmp;
        prev = tmp->prev;
        tmp->next = NULL;

        tmp = it->prev;
    }

    //this->HeadrefD = nwhead;
    //this->TailrefD = nwtail;
}
//.............................................................................................
/*RETORNA LA LISTA INVERTIDA*/
template <class t>
linkedlistD<t> linkedlistD<t>::reverse()
{
    linkedlistD<t> listr;
    NodeD<t> *tmp = NULL;

    if (this->HeadrefD == NULL)
        return listr;
    else
    {
        tmp = this->TailrefD;

        while (tmp != NULL)
        {
            listr.append(tmp->getdata());
            tmp = tmp->prev;
        }
        listr.printlist();
        return listr;
    }
}
//.............................................................................................
//OPERADORES
template <class t>
linkedlistD<t> &linkedlistD<t>::operator=(const linkedlistD<t> &list)
{
    NodeD<t> *tmp = list.HeadrefD;

    if (this->emptys)
    {
        while (tmp != NULL)
        {
            this->append(tmp->getdata());
            tmp = tmp->next;
        }
        return *this;
    }
    else
    {
        this->clear();
        while (tmp != NULL)
        {
            this->append(tmp->getdata());
            tmp = tmp->next;
        }
        return *this;
    }
}
//.............................................................................................
template <class t>
linkedlistD<t> &linkedlistD<t>::operator+=(const linkedlistD<t> &list)
{
    NodeD<t> *tmp = list.HeadrefD;

    while (tmp != NULL)
    {
        this->append(tmp->getdata());
        tmp = tmp->next;
    }
    this->TailrefD = list.TailrefD;
    this->sz += list.sz;
    return *this;
}
//.............................................................................................
template <class t>
linkedlistD<t> linkedlistD<t>::operator+(const linkedlistD<t> &list)
{
    linkedlistD<t> listU;
    NodeD<t> *tmp = this->HeadrefD, *tmp2 = list.HeadrefD;

    while (tmp != NULL)
    {
        listU.append(tmp->getdata());
        tmp = tmp->next;
    }

    while (tmp2 != NULL)
    {
        listU.append(tmp2->getdata());
        tmp2 = tmp2->next;
    }

    return listU;
}
//.............................................................................................
template <class t>
bool linkedlistD<t>::operator==(const linkedlistD<t> &list) const
{
    NodeD<t> *tmp = this->HeadrefD, *cmp = list.HeadrefD;
    int k = 0;
    if (this->sz != list.sz)
        return false;

    while (tmp != NULL)
    {
        if (tmp->getdata() == cmp->getdata())
            k++;
        tmp = tmp->next;
        cmp = cmp->next;
    }
    if (k == this->sz)
        return true;
    else
        return false;
}
//.............................................................................................
template <class t>
t linkedlistD<t>::operator[](int index)
{
    if (index == 0)
        return this->HeadrefD->getdata();
    else if (index == this->sz - 1 || index == -1)
        return this->TailrefD->getdata();
    else if ((index < 0 && index != -1) || index > this->sz - 1)
        throw std::out_of_range("invalid index\n");
    else
    {
        return this->at(index)->getdata();
    }
}
//.............................................................................................
template <class t>
linkedlistD<t>::~linkedlistD()
{
    this->clear();
}
//.............................................................................................
template <class ti>
//divide una lista a la mitad
NodeD<ti> *split(NodeD<ti> *list);

template <class to>
//funcion para hacer merge a dos listas
NodeD<to> *merge(NodeD<to> *list1, NodeD<to> *list2);

template <class tip>
NodeD<tip> *mergesort(NodeD<tip> *list);

int main(int argc, char const *argv[])
{

    linkedlist<int> List2, list; //listas simples
    linkedlist<float> listf, L, Lcopy;
    linkedlistD<int> listadoble, l1, l2;

    /*listadoble.append(1);
    listadoble.pop_front();
    std::cout << ((listadoble.empty()) ? "true" : "false") << "\n";*/

    listadoble.push(10);
    listadoble.push(18);
    listadoble.push(17);
    listadoble.push(16);
    listadoble.append(-1);
    listadoble.push(15);
    listadoble.insert(2, 10000);
    // listadoble.sort();
    listadoble.printlist();
    l1 = listadoble;
    l2 = listadoble + l1;
    l1.printlist();
    l2.printlist();
    std::cout << l2[13] << "\n";

    listadoble.printlist();
    //listadoble.pop_front();
    //listadoble.pop_back();

    /*std::cout << listadoble.search(16) << "\n";
    listadoble.reverse();
    listadoble.printlist();*/

    /*L.push(15);
    L.empty();
    L.pop();
    L.empty();

    L.append(-1);
    L.push(150);
    L.push(100.56546);
    L.push(500);
    L.push(10000);
    L.insert(1, -99);
    L.insert_after(0, -100);
    L.listsize();
    Lcopy = L;
    listf = L;
    std::cout << ((Lcopy == listf) ? "si" : "no") << "\n";
    L = listf + Lcopy;
    std::cout << ((L == listf) ? "si" : "no") << "\n";
    std::cout << L.listsize() << "\n";
    L.printlist();
    std::cout << L[4] << "pos 5 \n";
    Lcopy.printlist();

    L.clear();
    L.empty();
    L.push(1);
    L.empty();
    L.printlist();
    //std::cout << L.search(500) << "\n";
    //L.printlist();
    //L.reverselist();
    L.reverse();
    L.printlist();
    L.search_and_del(500);
    L.printlist();
    L.del(3);
    L.printlist();
    L.append(-5);
    L.append(-2);
    L.pop_front();
    L.printlist();
    L.tail();
    L.at(L.listsize() - 1);
    L.append(-1); //tail
    L.printlist();
    L.push(120);
    L.push(888); //head
    L.pop_back();
    //Lcopy = L;
    //Lcopy.printlist();
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
    listf.printlist();*/
    return 0;
}

template <class ti>
//divide una lista a la mitad
NodeD<ti> *split(NodeD<ti> *list)
{
    NodeD<ti> *fast = list, *slow = list;
    NodeD<ti> *tmp = NULL;

    while (fast->next != NULL && fast->next->next != NULL)
    {
        fast = fast->next->next;
        slow = fast->next;
    }

    tmp = slow->next;
    slow->prev = NULL;
    return tmp;
}

template <class to>
//funcion para hacer merge a dos listas
NodeD<to> *merge(NodeD<to> *list1, NodeD<to> *list2)
{

    if (list1 == NULL) //si la primer lista esta vacia
        return list2;
    if (list2 == NULL) //si la segunda esta vacia
        return list1;

    if (list1->getdata() < list2->getdata())
    { //tomamos los elementos mas pequeños de la lista
        list1->next = merge<to>(list1->next, list2);
        list1->next->prev = list1;
        list1->prev = NULL;
        return list1;
    }
    else
    {
        list2->next = merge<to>(list1, list2->next);
        list2->next->prev = list2;
        list2->prev = NULL;
        return list2;
    }
}

template <class tip>
NodeD<tip> *mergesort(NodeD<tip> *list)
{
    NodeD<tip> *sec = NULL;

    if (list == NULL || list->next == NULL)
        return list;

    sec = split<tip>(list);

    list = mergesort<tip>(list);
    sec = mergesort<tip>(sec);

    return merge<tip>(list, sec);
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