#include <stdio.h>
#include <stdint.h>
#include <stddef.h>

#define OFFSET(x, str, mem) printf("#define " #x " %d\n",(int) offsetof(str, mem))
#define SIZE(x, str) printf("#define " #x " %d\n", (int) sizeof(str))
#define HEADER_START() printf("#ifndef ASM_OFFSET_H\n#define ASM_OFFSET_H\n")
#define HEADER_END() printf("#endif\n")


struct Position
{
    int32_t x;
    int32_t y;
};
enum Color
{
    Red,
    Orange,
    Yellow,
    Green,
    Sky,
    Blue,
    Purple
};
struct Shape
{
    const char type;
    enum Color color;
    double perimeter;
};
struct Circle
{
    const char type;
    enum Color color;
    double perimeter;
    struct Position _0;
    uint32_t radius;
};
struct Rectangle
{
    const char type;
    enum Color color;
    double perimeter;
    struct Position _0;
    struct Position _1;
};
struct Triangle
{
    const char type;
    enum Color color;
    double perimeter;
    struct Position _0;
    struct Position _1;
    struct Position _2;
};

int main(int argc, char *argv[]) {

    HEADER_START();

    OFFSET(Shape_type, struct Shape, type); // Substitute your struct name and member name here
    OFFSET(Shape_color, struct Shape, color); // Substitute your struct name and member name here
    OFFSET(Shape_perimeter, struct Shape, perimeter); // Substitute your struct name and member name here
    SIZE(Shape_size, struct Shape); // This macro is to get the size of a struct

    HEADER_END();

    return 0;
}