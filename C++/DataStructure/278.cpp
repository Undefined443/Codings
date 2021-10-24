#include <cstdio>
#include <cstdlib>

using namespace std;

typedef struct Node {
    unsigned num;
    unsigned code;
    Node *next;
} Node;

int main() {
    int num, code;
    scanf("%d%d", &num, &code);
    Node *start = NULL;
    start = (Node *) malloc(sizeof(Node)); //起始位置
    if (!start)
        exit(-1);
    start->num = 1;
    scanf("%d", &start->code);
    Node *p = start;  //用于将上一个结点与下一个结点相连
    for (int i = 0; i < num - 1; ++i) {
        Node *nextNode = (Node *) malloc(sizeof(Node));
        if (!nextNode)
            exit(-1);
        nextNode->num = i + 2;
        scanf("%d", &nextNode->code);
        p->next = nextNode;
        p = nextNode;
    }
    p->next = start; //形成闭环
    Node *curr = start, *prev = NULL;
    while (curr != prev) {
        for (int i = 0; i < code - 1; ++i) {
            prev = curr;
            curr = curr->next;
        }
        Node *temp = curr;
        curr = curr->next;
        printf("%d ", temp->num); //输出出圈人的编号
        code = temp->code;
        free(temp);
        prev->next = curr; //重新连接首尾
    }
    printf("%d ", curr->num);
    free(curr);
}