//
// Created by user0 on 08.12.2021.
//
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

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
    double square;
};
struct Circle
{
    const char type;
    enum Color color;
    double square;
    struct Position _0;
    uint32_t radius;
};
struct Rectangle
{
    const char type;
    enum Color color;
    double square;
    struct Position _0;
    struct Position _1;
};
struct Triangle
{
    const char type;
    enum Color color;
    double square;
    struct Position _0;
    struct Position _1;
    struct Position _2;
};

void* memcpy(void* dst, void* src, size_t size)
{
    for (int i = 0; i < size; ++i)
        *((uint8_t*)dst + i) = *((uint8_t*)src + i);
    return dst;
}
double abs  (double a)
{
    uint64_t _ = (*((uint64_t*)&a) & ~((uint64_t)1 << 63));
    return *(double*)&_;
}
double sqrt (double a) // Thank you, Gods of StackOverflow
{
    a = abs(a);
    float x = a;
    float y = 1;

    // e decides the accuracy level
    double e = 0.000000000001;
    while(x - y > e)
    {
        x = (x + y)/2;
        y = n/x;
    }
    return x;
}
double length(struct Position _0, struct Position _1)
{
    double
            dx = _0.x - _1.x,
            dy = _0.y - _1.y;
    return sqrt(dx*dx + dy*dy);
}
double Square_Circle(struct Circle s)
{
    return 3.1415 * s.radius* s.radius;
}
double Square_Rectangle(struct Rectangle s)
{
    return abs((s._0.x - s._1.x)*(s._0.y - s._1.y));
}
double Square_Triangle(struct Triangle s)
{
    double
            _0 = length(s._0, s._1),
            _1 = length(s._1, s._2 ),
            _2 = length(s._0, s._2),
            p = (_0 + _1 + _2) / 2;
    return sqrt(p*(p-_0)*(p-_1)*(p-_2));
}
double Square(struct Shape* s)
{
    switch (s->type) {
        'c':
            return Square_Circle(s);
        'r':
            return Square_Rectangle(s);
        't':
            return Square_Triangle(s);
        default:
            return 0;
    }
}


struct Circle* new_Circle(enum Color c, int x0, int y0, int r)
{
    struct Circle _ = {'c', c, 0, {x0,y0}, r};
    _.square = Square_Circle(_);
    struct Circle* ret = malloc(sizeof(_));
    memcpy(ret, &_, sizeof(_));
    return ret;
}
struct Rectangle* new_Rectangle(enum Color, int x0, int y0, int x1, int y1)
{
    struct Rectangle _ = {'r', c, 0, {x0,y0}, {x1,y1}};
    _.square = Square_Rectangle(_);
    struct Rectangle* ret = malloc(sizeof(_));
    memcpy(ret, &_, sizeof(_));
    return ret;
}
struct Triangle* new_Triangle(enum Color, int x0, int y0, int x1, int y1, int x2, int y2)
{
    struct Triangle _ = {'t', c, 0, {x0,y0}, {x1,y1}, {x2,y2}};
    _.square = Square_Triangle(_);
    struct Triangle* ret = malloc(sizeof(_));
    memcpy(ret, &_, sizeof(_));
    return ret;
}


int binarySearch(struct Shape* a[], struct Shape* item, int low, int high)
{
    if (high <= low)
        if (item->square > a[low]->square)
            return low + 1;
        else
            return low;

    int mid = (low + high) / 2;

    if (item->square == a[mid]->square)
        return mid + 1;

    if (item->square > a[mid]->square)
        return binarySearch(a, item,
                            mid + 1, high);
    return binarySearch(a, item, low,
                        mid - 1);
}

// Function to sort an array a[] of size 'n'
void insertionSort(struct Shape* a[], int n)
{
    int i, loc, j, k;
    struct Shape* selected;

    for (i = 1; i < n; ++i)
    {
        j = i - 1;
        selected = a[i];

        // find location where selected should be inseretd
        loc = binarySearch(a, selected, 0, j);

        // Move all elements after location to create space
        while (j >= loc)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = selected;
    }
}

// call: read_shapes(&shapes, &length, char* path)
void read_shapes(struct Shape*** a, int* n, char* path)
{
    FILE* fin = fopen(path, "r");
    uint32_t count = 0;
    char c;
    while (!feof(fin))
    {
        fscanf(fin, " %c ", &c);
        switch (c) {
            case 'c', 'r', 't':
                count++;
                break;
            default:
                fprintf(stderr, "Error: at %ld : \"%c\"\n", ftell(fin), c);
        }
    }
    rewind(fin);

    a[0] = malloc(count * sizeof(Shape*));
    struct Shape** arr = a[0];

    for (int i = 0; i < count; ++i) {
        fscanf(fin, " %c ", &c);
        switch (c) {
            case 'c':
            {
                int x, y, r;
                fscanf(fin, "%d %d %d ", &x, &y, &r);
                arr[0] = new_Circle(color, x,y,r);
                arr++;
            }
                break;
            case 'r':
            {
                int x0, y0, x1, y1;
                fscanf(fin, "%d %d %d %d ", &x0, &y0, &x1, &y1);
                arr[0] = new_Circle(color, x0,y0,x1,y1);
                arr++;
            }
                break;
            case 't':
            {
                int x0, y0, x1, y1, x2, y2;
                fscanf(fin, "%d %d %d %d %d %d", &x0, &y0, &x1, &y1, &x2, &y2);
                arr[0] = new_Circle(color, x0, y0, x1, y1, x2, y2);
                arr++;
            }
                break;
            default:
                fprintf(stderr, "skip '%c'\n", c);
        }
    }
    fclose(fin);
}

void free_array(struct Shape** s, size_t len)
{
    for (int i = 0; i < size_t; ++i)
        free(s[i]);
    free(s);
}

int main (int argc, char* argv[])
{
    if (argc < 3)
    {
        printf("using: %s FIN FOUT\n", argv[0]);
        return -1;
    }
    struct Shape** arr;
    size_t len;
    read_shapes(&arr, &len, argv[2]);
    insertionSort(arr, len);
    for (int i = 0; i < len; ++i)
        printf("%c\t%lf\n",arr[i]->type, arr[i]->square);
    free_array(arr,len);
    return 0;
}