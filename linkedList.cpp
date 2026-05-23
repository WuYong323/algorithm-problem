#include <iostream>      // 引入输入输出流库，用于cout和cin
#include <stdlib.h>     // 引入标准库，用于system函数
using namespace std;     // 使用标准命名空间，避免每次写std::

// 定义链表节点结构体，用于存储数据和指向下一个节点的指针
struct Node {
    int data;           // 节点存储的数据，类型为整数
    Node* next;        // 指向下一个节点的指针
};

// 定义链表类，封装链表的所有操作
class LinkedList {
private:
    Node* head;         // 链表头指针，指向第一个节点

public:
    // 构造函数，初始化链表，头指针设为NULL
    LinkedList() {
        head = NULL;    // 初始化头指针为空，表示空链表
    }

    // 在链表头部插入新节点
    void insertAtHead(int value) {
        Node* newNode = new Node();  // 创建新节点，分配内存
        newNode->data = value;       // 设置新节点的数据值
        newNode->next = head;        // 新节点的next指向当前头节点
        head = newNode;             // 更新头指针，指向新节点
        cout << "已在头部插入: " << value << endl;  // 输出插入成功的提示
    }

    // 在链表尾部插入新节点
    void insertAtTail(int value) {
        Node* newNode = new Node();  // 创建新节点，分配内存
        newNode->data = value;       // 设置新节点的数据值
        newNode->next = NULL;         // 新节点是最后一个节点，next设为NULL

        //如果链表为空，新节点就是头节点
        if (head == NULL) {
            head = newNode;           // 头指针指向新节点
        } else {
            // 否则，遍历到链表末尾
            Node* temp = head;       // 创建临时指针从头节点开始
            while (temp->next != NULL) {  // 循环直到最后一个节点
                temp = temp->next;    // 移动到下一个节点
            }
            temp->next = newNode;    // 最后一个节点的next指向新节点
        }
        cout << "已在尾部插入: " << value << endl;  // 输出插入成功的提示
    }

    // 在指定位置插入新节点
    void insertAtPosition(int position, int value) {
        // 如果位置为0或负数，插入到头部
        if (position <= 0) {
            insertAtHead(value);     // 调用头部插入函数
            return;                  // 返回，结束函数
        }

        Node* newNode = new Node();  // 创建新节点，分配内存
        newNode->data = value;       // 设置新节点的数据值

        // 遍历到指定位置的前一个节点
        Node* temp = head;          // 创建临时指针从头节点开始
        int currentPosition = 0;      // 当前位置计数器

        // 循环遍历，直到到达指定位置或链表末尾
        while (temp->next != NULL && currentPosition < position - 1) {
            temp = temp->next;      // 移动到下一个节点
            currentPosition++;      // 位置计数器加1
        }

        // 如果到达指定位置，插入新节点
        newNode->next = temp->next;  // 新节点的next指向当前节点的下一个节点
        temp->next = newNode;        // 当前节点的next指向新节点
        cout << "已在位置 " << position << " 插入: " << value << endl;  // 输出插入成功的提示
    }

    // 删除链表头部的节点
    void deleteAtHead() {
        // 如果链表为空，无法删除
        if (head == NULL) {
            cout << "链表为空，无法删除！" << endl;  // 输出链表为空的提示
            return;                  // 返回，结束函数
        }

        Node* temp = head;          // 创建临时指针指向头节点
        head = head->next;          // 更新头指针，指向下一个节点
        delete temp;                // 释放原头节点的内存
        cout << " " << endl;        // 输出删除成功的提示
    }

    // 删除链表尾部的节点
    void deleteAtTail() {
        // 如果链表为空，无法删除
        if (head == NULL) {
            cout << "链表为空，无法删除！" << endl;  // 输出链表为空的提示
            return;                  // 返回，结束函数
        }

        // 如果只有一个节点，删除它
        if (head->next == NULL) {
            delete head;            // 释放头节点内存
            head = NULL;            // 头指针设为NULL
            cout << " " << endl;    // 输出删除成功的提示
            return;                  // 返回，结束函数
        }

        // 遍历到倒数第二个节点
        Node* temp = head;          // 创建临时指针从头节点开始
        while (temp->next->next != NULL) {  // 循环直到倒数第二个节点
            temp = temp->next;      // 移动到下一个节点
        }

        delete temp->next;          // 释放最后一个节点的内存
        temp->next = NULL;         // 倒数第二个节点的next设为NULL
        cout << " " << endl;        // 输出删除成功的提示
    }

    // 删除指定位置的节点
    void deleteAtPosition(int position) {
        // 如果位置为0或负数，删除头部节点
        if (position <= 0) {
            deleteAtHead();         // 调用删除头部函数
            return;                  // 返回，结束函数
        }

        // 如果链表为空，无法删除
        if (head == NULL) {
            cout << "链表为空，无法删除！" << endl;  // 输出链表为空的提示
            return;                  // 返回，结束函数
        }

        // 遍历到指定位置的前一个节点
        Node* temp = head;          // 创建临时指针从头节点开始
        int currentPosition = 0;      // 当前位置计数器

        // 循环遍历，直到到达指定位置的前一个节点或链表末尾
        while (temp->next != NULL && currentPosition < position - 1) {
            temp = temp->next;      // 移动到下一个节点
            currentPosition++;      // 位置计数器加1
        }

        // 如果到达指定位置，删除节点
        if (temp->next != NULL) {   // 如果还有下一个节点
            Node* toDelete = temp->next;  // 创建指针指向要删除的节点
            temp->next = toDelete->next;  // 当前节点的next跳过要删除的节点
            delete toDelete;        // 释放要删除节点的内存
            cout << " " << position << " λ" << endl;  // 输出删除成功的提示
        } else {
            cout << "λ" << position << " λ" << endl;  // 输出位置超出范围的提示
        }
    }

    // 查找指定值的节点
    bool search(int value) {
        Node* temp = head;          // 创建临时指针从头节点开始
        int position = 0;            // 位置计数器

        // 遍历链表，查找指定值
        while (temp != NULL) {      // 循环直到链表末尾
            if (temp->data == value) {  // 如果找到匹配的值
                cout << " " << value << "  " << position << " λ" << endl;  // 输出找到的提示
                return true;         // 返回true，表示找到
            }
            temp = temp->next;      // 移动到下一个节点
            position++;              // 位置计数器加1
        }

        cout << " " << value << " λ" << endl;  // 输出未找到的提示
        return false;                // 返回false，表示未找到
    }

    // 反转链表
    void reverse() {
        Node* prev = NULL;          // 指向前一个节点的指针，初始为NULL
        Node* current = head;        // 指向当前节点的指针，从头节点开始
        Node* next = NULL;          // 指向下一个节点的指针

        // 遍历链表，反转指针方向
        while (current != NULL) {   // 循环直到链表末尾
            next = current->next;    // 保存下一个节点的指针
            current->next = prev;    // 当前节点的next指向前一个节点
            prev = current;          // 前一个节点指针移动到当前节点
            current = next;          // 当前节点指针移动到下一个节点
        }

        head = prev;                 // 更新头指针，指向新的头节点
        cout << " λ" << endl;        // 输出反转成功的提示
    }

    // 遍历并显示链表
    void display() {
        // 如果链表为空
        if (head == NULL) {
            cout << " λ: []" << endl;  // 输出空链表的提示
            return;                  // 返回，结束函数
        }

        cout << " λ: ";              // 输出链表开始的提示
        Node* temp = head;          // 创建临时指针从头节点开始

        // 遍历链表，输出每个节点的数据
        while (temp != NULL) {      // 循环直到链表末尾
            cout << temp->data;      // 输出当前节点的数据
            if (temp->next != NULL) {  // 如果不是最后一个节点
                cout << " -> ";      // 输出箭头符号
            }
            temp = temp->next;      // 移动到下一个节点
        }
        cout << endl;              // 输出换行符
    }

    // 获取链表长度
    int getLength() {
        int length = 0;             // 长度计数器，初始为0
        Node* temp = head;          // 创建临时指针从头节点开始

        // 遍历链表，计算长度
        while (temp != NULL) {      // 循环直到链表末尾
            length++;               // 长度计数器加1
            temp = temp->next;      // 移动到下一个节点
        }

        return length;              // 返回链表长度
    }

    // 清空链表，释放所有节点内存
    void clear() {
        Node* current = head;       // 指向当前节点的指针，从头节点开始

        // 遍历链表，逐个释放节点
        while (current != NULL) {   // 循环直到链表末尾
            Node* next = current->next;  // 保存下一个节点的指针
            delete current;         // 释放当前节点的内存
            current = next;         // 移动到下一个节点
        }

        head = NULL;               // 头指针设为NULL，表示空链表
        cout << " λ！" << endl;    // 输出清空成功的提示
    }

    // 析构函数，对象销毁时自动清空链表
    ~LinkedList() {
        clear();                    // 调用清空函数，释放所有节点内存
    }
};

// 主函数，程序入口
int main() {
    LinkedList list;                // 创建链表对象

    cout << "====================================" << endl;  // 输出分隔线
    cout << "        λ" << endl;  // 输出标题
    cout << "====================================" << endl;  // 输出分隔线
    cout << endl;                  // 输出换行符

    // 插入操作演示
    cout << "【演示：插入操作】" << endl;  // 输出操作标题
    cout << endl;                  // 输出换行符

    list.insertAtTail(10);        // 在尾部插入10
    list.insertAtTail(20);        // 在尾部插入20
    list.insertAtTail(30);        // 在尾部插入30
    list.insertAtHead(5);         // 在头部插入5
    list.insertAtPosition(2, 15); // 在位置2插入15
    cout << endl;                  // 输出换行符

    list.display();                // 显示链表内容
    cout << " λ: " << list.getLength() << endl;  // 输出链表长度
    cout << endl;                  // 输出换行符

    // 查找操作演示
    cout << "【演示：查找操作】" << endl;  // 输出操作标题
    cout << endl;                  // 输出换行符

    list.search(20);               // 查找值20
    list.search(100);              // 查找值100（不存在）
    cout << endl;                  // 输出换行符

    // 删除操作演示
    cout << "【演示：删除操作】" << endl;  // 输出操作标题
    cout << endl;                  // 输出换行符

    list.deleteAtHead();            // 删除头部节点
    list.display();                // 显示删除后的链表
    cout << endl;                  // 输出换行符

    list.deleteAtTail();            // 删除尾部节点
    list.display();                // 显示删除后的链表
    cout << endl;                  // 输出换行符

    list.deleteAtPosition(1);       // 删除位置1的节点
    list.display();                // 显示删除后的链表
    cout << endl;                  // 输出换行符

    // 反转操作演示
    cout << "【演示：反转操作】" << endl;  // 输出操作标题
    cout << endl;                  // 输出换行符

    list.reverse();                // 反转链表
    list.display();                // 显示反转后的链表
    cout << endl;                  // 输出换行符

    // 清空操作演示
    cout << "【演示：清空操作】" << endl;  // 输出操作标题
    cout << endl;                  // 输出换行符

    list.clear();                  // 清空链表
    list.display();                // 显示清空后的链表
    cout << endl;                  // 输出换行符

    cout << "====================================" << endl;  // 输出分隔线
    cout << "       " << endl;  // 输出结束语
    cout << "====================================" << endl;  // 输出分隔线

    cout << "\nEnter..." << endl; // 输出暂停提示
    system("pause");               // 暂停程序，等待用户按键

    return 0;                      // 程序正常结束
}
