#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Desenha o numero de maneira fatiada
 *
 * @param direction -1: nada, 0: horizontal, 1: vertical
 * @param lado -1: nada, 0: esquerda, 1: direita, 2: ambos
 * @param fontSize tamanho de cada parte do corpo do numero
 * @return int
 */

int draw(int direction, int lado, int fontSize)
{

    printf(" ");
    fontSize = fontSize + 2;
    /**
     * @brief desenha a parte que é horizontal, sendo composta por "-" ou por " ";
     * 
     */
    if (direction == 0 || direction == -1)
    {
        for (int i = 0; i < fontSize; i++)
        {
            if (i == 0 || i == fontSize - 1)
                printf(" ");
            else
                printf(direction == 0 ? "-" : " ");
        }
    }

     /**
     * @brief desenha a parte que é horizontal, sendo composta por "|";
     * 
     */

    else
    {
        for (int i = 0; i < fontSize; i++)
        {
            switch (lado)
            {
            case 0:
                if (i == 0)
                    printf("|");
                else
                    printf(" ");
                break;
            case 1:
                if (i == fontSize - 1)
                    printf("|");
                else
                    printf(" ");
                break;
            case 2:
                if (i == fontSize - 1 || i == 0)
                    printf("|");
                else
                    printf(" ");
            }
        }
    }
}

void drawByLine(char *numero, int line, int fontSize)
{
    int digit1_a[5] = {0, 1, 0, 1, 0};
    int digit1[5][2] = {
        {-1, 1},
        {1, 1},
        {-1, 1},
        {1, 1},
        {-1, 1}};

    int digit2_b = {1, 1, 1, 0, 1};
    int digit2[5][2] = {
        {0, -1},
        {1, 1},
        {0, -1},
        {1, 0},
        {0, -1}};

    int digit3[5][2] = {
        {0, -1},
        {1, 1},
        {0, -1},
        {1, 1},
        {0, -1}};

    int digit4[5][2] = {
        {-1, 1},
        {1, 2},
        {0, -1},
        {1, 1},
        {-1, 1}};

    int digit5[5][2] = {
        {0, -1},
        {1, 0},
        {0, -1},
        {1, 1},
        {0, -1}};

    int digit6[5][2] = {
        {0, -1},
        {1, 0},
        {0, -1},
        {1, 2},
        {0, -1}};

    int digit7[5][2] = {
        {0, -1},
        {1, 1},
        {-1, -1},
        {1, 1},
        {-1, 1}};

    int digit8[5][2] = {
        {0, -1},
        {1, 2},
        {0, -1},
        {1, 2},
        {0, -1}};

    int digit9[5][2] = {
        {0, -1},
        {1, 2},
        {0, -1},
        {1, 1},
        {0, -1}};

    int digit0[5][2] = {
        {0, -1},
        {1, 2},
        {-1, -1},
        {1, 2},
        {0, -1}};

    for (char *s = numero; *s; s++)
    {

        switch (*s)
        {
        case '1':
            draw(digit1[line][0], digit1[line][1], fontSize);
            break;
        case '2':
            draw(digit2[line][0], digit2[line][1], fontSize);
            break;
        case '3':
            draw(digit3[line][0], digit3[line][1], fontSize);
            break;
        case '4':
            draw(digit4[line][0], digit4[line][1], fontSize);
            break;
        case '5':
            draw(digit5[line][0], digit5[line][1], fontSize);
            break;
        case '6':
            draw(digit6[line][0], digit6[line][1], fontSize);
            break;
        case '7':
            draw(digit7[line][0], digit7[line][1], fontSize);
            break;
        case '8':
            draw(digit8[line][0], digit8[line][1], fontSize);
            break;
        case '9':
            draw(digit9[line][0], digit9[line][1], fontSize);
            break;
        case '0':
            draw(digit0[line][0], digit0[line][1], fontSize);
            break;
        }
    }

    printf("\n");
}

int display(char *numero, int fontSize)
{
    /*
    -1: nada
    0: horizontal
    1: vertical

    case vertical, 0: esquerda, 1: direita, -1: nada, 2: ambos
    */

    for (int j = 0; j < 5; j++)
    {
        if (j == 1 || j == 3)
            for (int i = 0; i < fontSize; i++)
                drawByLine(numero, j, fontSize);
        else
            drawByLine(numero, j, fontSize);
    }
    printf("\n");
}

int main()
{
    char fontSize[9], number[9];
    scanf("%s %s", fontSize, number);
    while (atoi(fontSize) && atoi(number))
    {
        display(number, atoi(fontSize));
        scanf("%s %s", fontSize, number);
    }
}
