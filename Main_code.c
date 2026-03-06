#include "raylib.h"
#include <string.h>

#define INGREDIENT_COUNT 5
#define MAX_SELECTED 2

// Structure for ingredients
typedef struct
{
    char name[20];
    int calories;
    int type;
} Ingredient;

// Array of structures
Ingredient ingredients[INGREDIENT_COUNT] =
{
    {"Tomato", 20, 1},
    {"Cheese", 120, 2},
    {"Chicken", 150, 3},
    {"Bread", 80, 4},
    {"Lettuce", 10, 1}
};

// Function to check recipe
void checkRecipe(int a, int b, char result[])
{
    if ((a == 0 && b == 4) || (a == 4 && b == 0))
    {
        strcpy(result, "Salad Created!");
    }
    else if ((a == 2 && b == 3) || (a == 3 && b == 2))
    {
        strcpy(result, "Chicken Sandwich!");
    }
    else if ((a == 1 && b == 3) || (a == 3 && b == 1))
    {
        strcpy(result, "Cheese Sandwich!");
    }
    else
    {
        strcpy(result, "Invalid Recipe");
    }
}

int main()
{
    InitWindow(900, 600, "Interactive Recipe Game");

    int selected[MAX_SELECTED] = {-1, -1};
    int selectedCount = 0;

    char result[50] = "Select two ingredients";

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        // Mouse click detection
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            Vector2 mouse = GetMousePosition();

            for (int i = 0; i < INGREDIENT_COUNT; i++)
            {
                Rectangle box = {80 + i * 150, 420, 120, 80};

                if (CheckCollisionPointRec(mouse, box))
                {
                    if (selectedCount < MAX_SELECTED)
                    {
                        selected[selectedCount] = i;
                        selectedCount++;
                    }
                }
            }
        }

        // When 2 ingredients selected
        if (selectedCount == 2)
        {
            checkRecipe(selected[0], selected[1], result);

            selectedCount = 0;
            selected[0] = -1;
            selected[1] = -1;
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawText("Interactive Recipe Logic Game", 250, 40, 30, DARKBLUE);

        DrawText("Click two ingredients to create a recipe", 240, 90, 20, GRAY);

        // Draw ingredients
        for (int i = 0; i < INGREDIENT_COUNT; i++)
        {
            Rectangle box = {80 + i * 150, 420, 120, 80};

            DrawRectangleRec(box, LIGHTGRAY);
            DrawRectangleLinesEx(box, 2, BLACK);

            DrawText(ingredients[i].name, box.x + 20, box.y + 30, 18, BLACK);
        }

        DrawText("Result:", 380, 250, 25, BLACK);
        DrawText(result, 350, 290, 25, RED);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
