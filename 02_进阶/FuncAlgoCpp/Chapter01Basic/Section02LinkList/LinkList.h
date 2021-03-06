/***********************************************************
 * @Description : 链表
 * @author      : 梁山广(Liang Shan Guang)
 * @date        : 2020/11/24 23:15
 * @email       : liangshanguang2@gmail.com
***********************************************************/

#ifndef FUNCALGOCPP_LINKLIST_H
#define FUNCALGOCPP_LINKLIST_H

#include <iostream>

using namespace std;

template<typename T>
class ListNode;

template<typename T>
class LinkList {
private:
    ListNode<T> *head;

public:
    // 无参构造函数
    LinkList() {
        head = new ListNode<T>();
    }

    // 有参数构造函数
    LinkList(ListNode<T> *node) {
        head = node;
    }

    // 析构函数
    ~LinkList() {
        delete head;
    }

    bool insert(int i, T newData); // 插入节点
    bool del(ListNode<T> *node); // 删除节点
    ListNode<T> *find(T val); // 获取指定值的节点并返回节点地址
    bool clear(); // 清空链表
    T getNodeData(ListNode<T> *node); // 获取节点数据
};

template<typename T>
bool LinkList<T>::insert(int i, T newData) {
    ListNode<T> *p = head; // 设置游标指针，初始化为头结点指针
    int j;
    for (j = 1; j <= i - 1; j++) {
        p = p->next;
        if (p == NULL) break;// 如果指针为空，则不存在该节点，或已到表尾
    }

    if (p == NULL && j < (i - 1)) { // 指针为空且没到第i个位置，则不存在该节点，说明不存在第i个节点
        cout << "插入位置无效！" << endl;
        return false;
    }
    ListNode<T> *node = new ListNode<T>(newData);
    node->next = p->next; // 将node的next指针赋值为p的后继节点地址
    p->next = node; // p的后继指针指向node
    return true;
}

template<typename T>
bool LinkList<T>::del(ListNode<T> *node) {
    if (node == NULL) { // 判断待删除节点是否存在
        cout << "待删除节点不存在！" << endl;
        return false;
    }
    ListNode<T> *nodeTmp = head; // 设置游标指针，初始化为头结点
    while (nodeTmp->next != node) { // 遍历单链表，找到q所指向节点的前驱节点
        nodeTmp = nodeTmp->next; // 不断往后走
    }
    // 找到了节点和目标节点相等的点
    nodeTmp->next = node->next; // 将node节点的后继节点地址赋值给其前驱节点的next指针
    delete node; // 回收节点node的空间
    return true;
}

template<typename T>
ListNode<T> *LinkList<T>::find(T val) {
    ListNode<T> *pCur = head; // 设置游标指针
    // 判断游标指针所指节点的值是否与val相等
    while (pCur != NULL && pCur->data != val) {
        pCur = pCur->next;
    }
    if (pCur == NULL) {
        cout << "没找到该节点！程序异常退出！" << endl;
        exit(1);
    } else {
        return pCur; // 返回所找到的节点的指针
    }
}

template<typename T>
bool LinkList<T>::clear() {
    ListNode<T> *cur = head; // 设置游标指针
    while (head->next != NULL) { // 判断head的后继节点是否为NULL
        cur = head->next;
        head->next = cur->next;
        delete cur;
    }
    return false;
}

template<typename T>
T LinkList<T>::getNodeData(ListNode<T> *node) {
    return node->data;
}

template<typename T>
class ListNode {
private:
    friend class LinkList<T>; // 将LinkList设为友元类，方便对node的成员数据和方法的访问

    T *next; // 指向下一个节点的指针
    T data; // 节点中的数据

public:
    ListNode() {
        next = NULL;
    }

    ListNode(T item, ListNode<T> *nextNode = NULL) {
        data = item;
        next = nextNode;
    }

    ~ListNode() {
        next = NULL;
    }

    // 获取节点内的数据
    T getData() {
        return data;
    }

    // 获取指针域
    ListNode *getNext() {
        return next;
    }
};

#endif //FUNCALGOCPP_LINKLIST_H
