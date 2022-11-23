#include <stdio.h>

// Author: Megan Steinmasel
// October 2022
// Program uses structs to define a planet class and set rotation time

// Planet struct
typedef struct{
    char name[70];
    int moons;
    double diameter;
    double orbit_time, rotation_time;
}Planet;

// sets rotation time
void setRot(Planet *p, double rotation){
    p->rotation_time = rotation;
    return;
}

int main(void){
    // sets values for p1
    Planet p1 = {"Jupiter", 80, 86881.0, 105192.0, 30.0};

    // passes in a pointer to Planet p1 and its new rotation time
    setRot(&p1, 10.0);
    
    // prints new rotation time
    printf("Rotation time: %.2lf\n", p1.rotation_time);
    return(0);
}
