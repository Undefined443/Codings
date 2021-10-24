#include<iostream>
using namespace std;
#define max 100

//????
int locates(char* g, char ch, int number)
{
    int i;
    for (i = 0; i < number; i++)
    {
        if (g[i] == ch)
        {
            break;
        }
    }
    if (i >= number)
    {
        return -1;
    }
    return i;
}

//????
void inputc(char* c, int number)
{
    for (int i = 0; i < number; i++)
    {
        cin >> c[i];
    }
}

//??????
void inputl(int ling[max][max], int number)
{
    printf("????:\n");
    for (int i = 0; i < number; i++)
    {
        for (int j = 0; j < number; j++)
        {
            cout << ling[i][j] << "\t";
        }
        cout << endl;
    }
}


//?????????
bool judge(int ling[max][max], int number)
{
    bool zifan, duichen = true, chuandi = true;;
    //?????
    int total = 0;
    for (int i = 0; i < number; i++)
    {
        if (ling[i][i] == 1)
        {
            total++;
        }
    }
    zifan = (number == total);

    //?????
    for (int m = 0; m < number; m++)
    {
        for (int n = 0; n < number; n++)
        {
            if (ling[m][n] == 1 && ling[n][m] != 1)
            {
                duichen = false;
            }
        }
    }

    //?????
    for (int p = 0; p < number; p++)
    {
        for (int q = 0; q < number; q++)
        {
            for (int s = 0; s < number; s++)
            {
                if (ling[p][q] == 1 && ling[q][s] == 1 && ling[p][s] != 1)
                {
                    chuandi = false;
                }
            }
        }
    }
    return (zifan & duichen) & chuandi;
}

//???
void sangji(int ling[max][max], int number, char c[max])
{
    bool visited[max];
    for (int p = 0; p < number; p++)
    {
        visited[p] = false;
    }

    for (int i = 0; i < number; i++)
    {
        if (visited[i] == false)
        {
            visited[i] = true;
            cout << "{";
            cout << c[i] << ",";
            for (int j = 0; j < number; j++)
            {
                if (ling[i][j] == 1 && visited[j] == false)
                {
                    visited[j] = true;
                    cout << c[j] << ",";
                }
            }
            cout << "\b" << "}";
            cout << "  ";
        }
    }

}

int main()
{
    char c[max], a, b;
    int ling[max][max];
    int number, edge;
    cout << "?????????????:";
    cin >> number >> edge;
    cout << "?????:";
    inputc(c, number);

    for (int i = 0; i < number; i++)
    {
        for (int j = 0; j < number; j++)
        {
            ling[i][j] = 0;
        }
    }

    //??????
    cout << "???????: " << endl;
    for (int p = 0; p < edge; p++)
    {
        cin >> a >> b;
        ling[locates(c, a, number)][locates(c, b, number)] = 1;
    }

    //??????
    inputl(ling, number);
    if (judge(ling, number))
    {
        cout << "??????" << endl;
        sangji(ling, number, c);
    }
    else cout << "???????" << endl;
    return 0;
}
