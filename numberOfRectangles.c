struct point
{
    int x;
    int y;
};
//in a rectangle with edges parallel to the coordinate axes
// if you invert the coordinates on one axis of the points of one diagonal
// you will get the coordinates of the other diagonal
int count_rectangles(struct point points[], int n)
{
    int count = 0;

    for (int i = 0; i < n; i++){
        for (int j = i+1; j < n; j++){

            int x1 = points[i].x;
            int y1 = points[i].y;
            int x2 = points[j].x;
            int y2 = points[j].y;

            //search for the possible diagonals
            //if one line is parallel with axes => can't be diagonal
            if (x1 == x2 || y1 == y2)
                continue;

            //supposing that those points are the vertices of a diagonal, form the other diagonal, swapping the y's
            struct point p3 = {x1, y2};
            struct point p4 = {x2, y1};
            int found_p1 = 0;
            int found_p2 = 0;

            //if we found 2 points that are equal with the vertices of the supposed diagonal that means it's really a diagonal
            for (int k = 0; k < n; k++){
                if (points[k].x == p3.x && points[k].y == p3.y)
                    found_p1 = 1;

                if (points[k].x == p4.x && points[k].y == p4.y)
                    found_p2 = 1;
            }

            if (found_p1 && found_p2){
                count++;
                //printf("(%d, %d), (%d, %d), (%d, %d), (%d, %d)\n", x1, y1, x2, y2, p3.x, p3.y, p4.x, p4.y);
            }
        }
    }
    //devide with 2 because count both diagonals and we need the number of rectangles
    return count / 2;
}

int main()
{
    //struct point points[] = {{1,1}, {1,3}, {2,1}, {3,1}, {3,3}};
    //struct point points[] = {{1,1}, {1,3}, {2,1}, {2,3}, {3,1}, {3,3}};
    struct point points[] = {{1,1}, {1,3}, {2,1}, {2,3}, {3,1}, {3,3}, {4, 1}, {4, 3}};
    int n = sizeof(points) / sizeof(points[0]);
    int count = count_rectangles(points, n);
    printf("%d\n", count);

    return 0;
}







