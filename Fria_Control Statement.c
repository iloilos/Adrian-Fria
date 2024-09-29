#include <stdio.h>
#include <stdlib.h>

int main()
{
    char choice;

    printf("\n\t\t MENU \n\n");
    printf("\tPRESS A. Area of Rectangle\n");
    printf("\tPRESS B. Area of Triangle\n")
    printf("\tPRESS C. Area of Parallelogram\n");
    printf("\tPRESS D. Area of Trapezoid\n");
    printf("\tPRESS E. Area of Volume of Rectangular Solid\n");
    printf("Enter your choice: ");
    scanf("%c, &choice")
    if(choice == 'A'){

    float width, length, area;

    printf("Enter width of the rectangle\n");
    scanf("%f", &width);

    printf("Enter length of the rectangle\n");
    scanf("%f", &length);

    area = width * length;

    printf("Area of Rectangle is%f\n", area);
    }
    else if (choice == 'B'){

    float base, height, area;

    printf("The base of the triangle is: ");
    scanf("%f", &base);

    printf("Enter height of the triangle: ");
    scanf("%f", &height);

    area = (.5*base)*height;

    printf("The area of the triangle is: %f", area);
    }
    else if (choice == 'C'){

    float Base, Height, area;

    printf("Enter Base of the parallelogram\n");
    scanf("%f", &Base);

    printf("Enter Height of the parallelogram\n");
    scanf("%f", &Height);

    area = Base * Height;

    printf("Area of Parallelogram is%f\n", area);
    }
    else if (choice == 'D'){

    float base1, base2, height, area;

    printf("The base1 of the trapezoid is: ");
    scanf("%f", &base1);

    printf("The base2 of the trapezoid is: ");
    scanf("%f", &base2);

    printf("Enter height of the trapezoid: ");
    scanf("%f", &height);

    area = (base1+base2)/2 * height;

    printf("The area of the trapezoid is: %f", area);
    }
    else if (choice == 'E'){

    float length, width, height, volume;

    printf("Enter length of the rectangular solid: ");
    scanf("%f", &length);

    printf("Enter width of the rectangular solid: ");
    scanf("%f", &width);

    printf("Enter height of the rectangular solid: ");
    scanf("%f", &height);

    volume = length * width * height;

    printf("The volume of the rectangular solid is: %f", volume);
}
