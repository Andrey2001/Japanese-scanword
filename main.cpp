#include <iostream>

using namespace std;

int field[100][100], verch[100][20], levo[100][20], x = 0, y = 0, colvo = 0;

void strochka(int y2)
{
    int schet = 0, schet1 = 0, schet2 = 0, schet3 = 0;
    for(int j = 0; j < colvo; j++) schet = schet + levo[y2][j];
    if(schet + colvo - 1 == x)
    {
        for(int j = 0; j < colvo; j++)
        {
            for(int k = schet3 + j; k < schet3 + levo[y2][j] + j; k++) field[k][y2] = 1;
            field[schet3 + levo[y2][j] + j][y2] = 2;
            schet3 = levo[y2][j] + schet3;
        }
    }
    else
    {
        for(int j = 0; j < colvo; j++)
        {
            if(x - schet - colvo + 1 < levo[y2][j])
            {
                for(int i = 0; i < colvo; i++)
                {
                    if(i <= j) schet1 = schet1 + levo[y2][i] + 1;
                    if(i >= j) schet2 = schet2 + levo[y2][i] + 1;
                }
                if(x - schet2 < schet1) for(int i = x - schet2 + 1; i < schet1 - 1; i++) field[i][y2] = 1;
            }
            schet1 = 0;
            schet2 = 0;
        }
    }
}

void stolbic(int x2)
{
    int schet = 0, schet1 = 0, schet2 = 0, schet3 = 0;
    for(int j = 0; j < colvo; j++) schet = schet + verch[x2][j];
    if(schet + colvo - 1 == x)
    {
        for(int j = 0; j < colvo; j++)
        {
            for(int k = schet3 + j; k < schet3 + verch[x2][j] + j; k++) field[x2][k] = 1;
            field[x2][schet3 + verch[x2][j] + j] = 2;
            schet3 = verch[x2][j] + schet3;
        }
    }
    else
    {
        for(int j = 0; j < colvo; j++)
        {
            if(y - schet - colvo + 1 < verch[x2][j])
            {
                for(int i = 0; i < colvo; i++)
                {
                    if(i <= j) schet1 = schet1 + verch[x2][i] + 1;
                    if(i >= j) schet2 = schet2 + verch[x2][i] + 1;
                }
                if(y - schet2 < schet1) for(int i = x - schet2 + 1; i < schet1 - 1; i++) field[x2][i] = 1;
            }
            schet1 = 0;
            schet2 = 0;
        }
    }
}

int main()
{
    cin >> x >> y;
    for(int x1 = 0; x1 < x; x1++)
    {
        cin >> colvo;
        if(colvo > 0)
        {
            for(int j = 0; j < colvo; j++) cin >> verch[x1][j];
            stolbic(x1);
        }
    }
    for(int y1 = 0; y1 < y; y1++)
    {
        cin >> colvo;
        if(colvo > 0)
        {
            for(int j = 0; j < colvo; j++) cin >> levo[y1][j];
            strochka(y1);
        }
    }
    cout << endl;
    for(int y1 = 0; y1 < y; y1++)
    {
        for(int x1 = 0; x1 < x; x1++) cout << field[x1][y1] << " ";
        cout << endl;
    }
    return 0;
}
