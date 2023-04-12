//
// Created by allen on 4/28/2021.
//

#include "LinkedList.h"

void LinkedList::insertBefore(const Card& x,Node *node)
{
    if (node->next == head)
    {
        Node *n=new Node{x,head};
        head=n;
        _size++;
    }
    else if (node->next != head)
    {
        Node *n= new Node {x,node->next};
        node->next=n;
        _size++;
    }
}

void LinkedList::insertAfter(const Card& x, Node *node)
{
    if(node==tail)
    {
        Node *n=new Node{x,nullptr};
        tail->next=n;
        tail=n;
        _size++;
    }
    else if(node!=tail)
    {
        Node *n=new Node{x,node->next};
        node->next=n;
        _size++;
    }
}
Node *LinkedList::search(const Card& x)
{
    Node *walker=head;
    if(empty())
    {
        return nullptr;
    }
    while(!(walker->data==x))
    {
        if(walker->next==nullptr&&!(x==walker->data))
            return nullptr;
        walker=walker->next;

    }
    return walker;
}

void LinkedList::insertBefore(const Card& item, const Card& before)
{
    Node *walker=head;
    if (search(before)==nullptr) std::cout<<"input correct data."<<std::endl;
    else if (search(before)!=nullptr)
    {
        if(head->data==before)
        {
            Node* newWalk;
            newWalk->next=head;
            insertBefore(item, newWalk);
        }
        else if(!(head->data==before))
        {
            while(walker->next!=search(before))
                walker=walker->next;
            insertBefore(item,walker);
        }

    }
}

void LinkedList::insertAfter(const Card& item, const Card& after)
{
    if (search(after)==nullptr) std::cout<<"input correct data not found"<<std::endl;
    else if (search(after)!=nullptr)
    {
        Node *node = search(after);
        insertAfter(item, node);
    }
}

void LinkedList::remove(const Card& item)
{
    Node *walker=head;
    Node *temp;
    if (search(item)==nullptr) std::cout<<"input correct data not found"<<std::endl;
    else if (search(item)!=nullptr)
    {
        if (head->data == item)
        {
            if (head == tail)
            {
                tail = nullptr;
                head = nullptr;
                delete walker;
                _size--;
            }
            else if (head != tail)
            {
                head = head->next;
                delete walker;
                _size--;
            }
        } else if (!(head->data == item))
        {
            while (walker->next != search(item)) walker = walker->next;
            temp=search(item);
            if (temp!=tail)
            {
                walker->next = temp->next;
                delete temp;
                _size--;
            }
            else if(temp==tail)
            {
                tail=walker;
                tail->next=nullptr;
                delete temp;
                _size--;
            }
        }
    }
}

void LinkedList::push_back(const Card& item)
{
    if (!empty())
    {
        Node *n = new Node{item, nullptr};
        tail->next = n;
        tail = n;
        _size++;
    }
    else if(empty())
    {
        Node *n = new Node{item,nullptr};
        head=n;
        tail=n;
        _size++;
    }
}

void LinkedList::push_front(const Card& item)
{
    if (!empty())
    {
        Node *n = new Node{item, head};
        head=n;
        _size++;
    }
    else if(empty())
    {
        Node *n = new Node{item,nullptr};
        head=n;
        tail=n;
        _size++;
    }
}

int LinkedList::size() const
{
    return _size;
}

bool LinkedList::empty() const// returns true if no nodes in linked list
{
    return(head==nullptr && tail == nullptr && _size==0);
}

std::ostream &operator<<(std::ostream &out, LinkedList x)
{
    Node*n=x.head;
    for(int i=0;i<x.size();i++)
    {
        out << n->data.col() <<" "<<n->data.num()<<std::endl;
        n=n->next;
    }
    return out;
}

Card LinkedList::back()
{
    return tail->data;
}

Node * LinkedList::index(int x) const {
    Node *temp=head;
    for(int i=0;i<x;i++)
    {
        temp=temp->next;
    }
    return temp;
}

Card LinkedList::front()
{
    return head->data;
}

