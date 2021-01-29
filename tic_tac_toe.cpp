#include <bits/stdc++.h>
using namespace std;
int x = 1, y = -1, e = 0;
vector<vector<int>> a(3, vector<int>(3, 0));
int currentp = x; //current player is 1

void putmark(vector<vector<int>> &a, int p)
{
    switch (p)

    {
    case 0:
    {
        a[0][0] = currentp;
        break;
    }
    case 1:
    {
        a[0][1] = currentp;
        break;
    }
    case 2:
    {
        a[0][2] = currentp;
        break;
    }
    case 3:
    {
        a[1][0] = currentp;
        break;
    }
    case 4:
    {
        a[1][1] = currentp;
        break;
    }
    case 5:
    {
        a[1][2] = currentp;
        break;
    }
    case 6:
    {
        a[2][0] = currentp;
        break;
    }
    case 7:
    {
        a[2][1] = currentp;
        break;
    }
    case 8:
    {
        a[2][2] = currentp;
        break;
    }

    default:
        break;
    }
    currentp = -currentp;
}

void printboard(vector<vector<int>> &a)
{
    vector<vector<char>> b(3, vector<char>(3, 0));
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (a[i][j] == 1)
                b[i][j] = 'X';
            else if (a[i][j] == -1)
                b[i][j] = '#';
            else
                b[i][j] = 'o';
        }
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << " " << b[i][j] << " ";
            if (j < 2)
                cout << "|";
        }
        cout << endl;
        if (i < 2)
            cout << "---+---+---" << endl;
    }
}

void clrboard()
{
    printboard(a);
}

bool mark(int k)
{
    int win = k * 3;
    return (a[0][0] + a[0][1] + a[0][2] == win ||
            a[1][0] + a[1][1] + a[1][2] == win ||
            a[2][0] + a[2][1] + a[2][2] == win ||
            a[0][0] + a[1][0] + a[2][0] == win ||
            a[0][1] + a[1][1] + a[2][1] == win ||
            a[0][2] + a[1][2] + a[2][2] == win ||
            a[0][0] + a[1][1] + a[2][2] == win ||
            a[0][2] + a[1][1] + a[2][0] == win);
}

int getwinner(vector<vector<int>> &a)
{
    if (mark(1))
        return 1;
    else if (mark(-1))
        return -1;
    else
        return 0;
}

bool check()
{
    int i, j;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (a[i][j] == 0)
                return 0;
        }
    }

    return 1;
}

/*void result()
{
    int winner = getwinner(a);

    if (winner == 1)
    {
        cout << " first player win(i.e. player X)" << endl;
        exit;
    }
    else if (winner == -1)
    {
        cout << " second player win(i.e. player #)" << endl;
        exit;
    }
    else if (winner == 0 && check())
    {
        cout << "match draw" << endl;
        exit;
    }
}*/

bool position(int p)
{
    switch (p)
    {
    case 0:
    {
        if (a[0][0] == 0)
            return 1;
        else
            return 0;
    }
    case 1:
    {
        if (a[0][1] == 0)
            return 1;
        else
            return 0;
    }
    case 2:
    {
        if (a[0][2] == 0)
            return 1;
        else
            return 0;
    }
    case 3:
    {
        if (a[1][0] == 0)
            return 1;
        else
            return 0;
    }
    case 4:
    {
        if (a[1][1] == 0)
            return 1;
        else
            return 0;
    }
    case 5:
    {
        if (a[1][2] == 0)
            return 1;
        else
            return 0;
    }
    case 6:
    {
        if (a[2][0] == 0)
            return 1;
        else
            return 0;
    }
    case 7:
    {
        if (a[2][1] == 0)
            return 1;
        else
            return 0;
    }
    case 8:
    {
        if (a[2][2] == 0)
            return 1;
        else
            return 0;
    }
    }
    return 0;
}

int main()
{

    cout << "WELCOME TO THE GAME" << endl
         << "HELLO PLAYER , YOU HAVE TO GIVE POSITITION OF YOUR MARK FROM 1 TO 9 " << endl
         << "THANKYOU" << endl;
    clrboard();

    for (int i = 0; i < 9; i++)
    {
    start:
        int p;
        cin >> p;
        if (p <= 0 && p >= 10)
        {
            cout << "Enter valid position ( i.e. 0<position<10)" << endl;
            goto start;
        }
        if (!position(p - 1))
        {
            cout << "THIS POSITION IS ALREADY OCCUPIED PLESAE SELECT ANOTHER POSITION" << endl;
            goto start;
        }
        putmark(a, p - 1);
        printboard(a);
        int winner = getwinner(a);

        if (winner == 1)
        {
            cout << " first player win(i.e. player X)" << endl;
            break;
        }
        else if (winner == -1)
        {
            cout << " second player win(i.e. player #)" << endl;
            break;
        }
        else if (winner == 0 && check())
        {
            cout << "match draw" << endl;
            break;
        }
    }
}