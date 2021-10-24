#include <iostream>
#include <cstdlib>

using namespace std;

typedef struct Node {
    int zhishu;
    int xishu;
    Node *next;
} Node;

Node *input(int n, int t) { //完成输入并建立链表的操作，返回链表头指针。n 是项数，t 若置为 1，则对多项式中每个系数乘以 -1
    Node *head = NULL, *p = NULL; //head 是链表头指针，p 在下面的循环中指向上次创建的结点，用于将上个结点和新结点相连
    bool flag = false; //用于确定是否给头指针赋过值
    for (int i = 0; i < n; ++i) {
        Node *newNode = (Node *) malloc(sizeof(Node));
        if (!newNode) //内存分配失败
            return NULL;
        if (!flag) { //给头指针赋值
            head = newNode;
            flag = true;
        }
        cin >> newNode->xishu >> newNode->zhishu; //输入系数，指数
        if (t) //减法
            newNode->xishu *= -1;
        if (p) //如果存在上一个结点
            p->next = newNode;
        p = newNode;
    }
    p->next = NULL;
    return head;
}

int main() {
    int n, m, t; //多项式1 的项数，多项式2 的项数，加法或减法
    cin >> n >> m >> t; //t=0 表示加法，t=1 表示减法

    //创建两个链表头并赋值
    Node *L1 = input(n, 0);
    Node *L2 = input(m, t); //如果是减法，链表2里面的系数就乘以 -1

    Node *head = L1;    //head 是结果链表的头指针
    Node *prev = NULL;  //prev 指向上一次运算操作的结点
    while (L1 && L2) {
        if (L1->zhishu == L2->zhishu) {         //次数相等就把两结点的系数相加
            L1->xishu += L2->xishu;
            prev = L1;
            L1 = L1->next;
            L2 = L2->next;
        } else if (L1->zhishu > L2->zhishu) {   //次数不等，把次数低的项插到次数高的项前面
            Node *next = L2->next;
            L2->next = L1;
            if (prev) {
                prev->next = L2;
            } else {
                head = L2;
            }
            prev = L2;
            L2 = next;
        } else if (L1->zhishu < L2->zhishu) {
            prev = L1;
            L1 = L1->next;
        }
    }
    if (L2) { //当链表2长于链表1时，链表2最后会有未处理的结点。把它们连到结果链表后面即可
        prev->next = L2;
    }

    //输出部分
    bool flag = false; //判断是否为第一项
    while (head) {
        if (head->xishu == 0) { //系数为0就跳过
            head = head->next;
            continue;
        }
        if (flag && head->xishu > 0) { //系数大于0判断是否输出'+'号
            cout << "+";
        }
        if (head->xishu != 1 && head->xishu != -1 || head->zhishu == 0) { //对于系数不为1且不等于-1或者为常数项，输出系数
            cout << head->xishu;
        }
        if (head->xishu == -1 && head->zhishu != 0) { //对于系数为-1的非常数项，只输出'-'号
            cout << "-";
        }
        if (head->zhishu != 0) { //对于非常数项，输出'x'
            cout << "x";
            if (head->zhishu != 1) { //对于指数不为1，输出"^指数"
                cout << "^" << head->zhishu;
            }
        }
        head = head->next;
        flag = true;
    }
    if (!flag) //结果为0的情况
        cout << "0";
}