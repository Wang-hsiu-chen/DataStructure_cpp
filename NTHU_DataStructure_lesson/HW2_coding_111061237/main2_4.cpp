#include "HW2_Maze.cpp"

int main(void)
{
    FILE *MAZE;
    int m, p;
    int i, j;
    MAZE = fopen("input2_4.txt", "r"); // open the file

    fscanf(MAZE, "%d", &m); // read m
    fscanf(MAZE, "%d", &p); // read p
    for (i = 0; i < m + 2; i++)
    { // edge
        for (j = 0; j < p + 2; j++)
        {
            if (i == 0 || i == m + 1)
                map[i][j] = 1; // read in the map
            else if (j == 0 || j == p + 1)
                map[i][j] = 1;
            else
                fscanf(MAZE, "%d", &map[i][j]);
        }
    }

    // first print the map
    for (i = 1; i < m + 1; i++)
    {
        for (j = 1; j < p + 1; j++)
        {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
    Path(m, p); // find a path

    return 0;
}