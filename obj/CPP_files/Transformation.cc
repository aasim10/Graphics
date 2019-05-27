#include "../header_files/Transformation.h"
#include <cassert>
#include <cmath>
#include "../header_files/Math.h"
using namespace std;

Vec3 RotateX(Vec3& Point,float theta){
    Mat T(4,4); //Transformation matrix
    Mat P(4,1); //Point matrix
    float angle = theta/180*pi;
    //Transformation matrix
    T(0,0) = 1;     T(0,1) = 0;         T(0,2) = 0;             T(0,3) = 0;
    T(1,0) = 0;     T(1,1) = cos(angle);T(1,2) = -sin(angle);   T(1,3) = 0;
    T(2,0) = 0;     T(2,1) = sin(angle);T(2,2) = cos(angle);    T(2,3) = 0;
    T(3,0) = 0;     T(3,1) = 0;         T(3,2) = 0;             T(3,3) = 1;
    //Point in matrix form
    P(0,0) = Point.x; P(0,1) = Point.y; P(0,2) = Point.z; P(0,3) = 1;

    P = T*P;
    Point.x = P(0,0);
    Point.y = P(0,1);
    Point.z = P(0,2);

    return Point;

}

Vec3 RotateY(Vec3& Point,float theta){
    Mat T(4,4); //Transformation matrix
    Mat P(4,1); //Point matrix
    float angle = theta/180*pi;
    //Transformation matrix
    T(0,0) = cos(angle);    T(0,1) = 0;         T(0,2) = sin(angle);    T(0,3) = 0;
    T(1,0) = 0;             T(1,1) = 1;         T(1,2) = 0;             T(1,3) = 0;
    T(2,0) = -sin(angle);   T(2,1) = 0;         T(2,2) = cos(angle);    T(2,3) = 0;
    T(3,0) = 0;             T(3,1) = 0;         T(3,2) = 0;             T(3,3) = 1;
    //Point in matrix form
    P(0,0) = Point.x; P(0,1) = Point.y; P(0,2) = Point.z; P(0,3) = 1;

    P = T*P;
    Point.x = P(0,0);
    Point.y = P(0,1);
    Point.z = P(0,2);

    return Point;

}


Vec3 RotateZ(Vec3& Point,float theta){
    Mat T(4,4); //Transformation matrix
    Mat P(4,1); //Point matrix
    float angle = theta/180*pi;
    //Transformation matrix
    T(0,0) = cos(angle);    T(0,1) = -sin(theta);       T(0,2) = 0;    T(0,3) = 0;
    T(1,0) = sin(angle);    T(1,1) = cos(theta);        T(1,2) = 0;    T(1,3) = 0;
    T(2,0) = 0;             T(2,1) = 0;                 T(2,2) = 1;    T(2,3) = 0;
    T(3,0) = 0;             T(3,1) = 0;                 T(3,2) = 0;    T(3,3) = 1;
    //Point in matrix form
    P(0,0) = Point.x; P(0,1) = Point.y; P(0,2) = Point.z; P(0,3) = 1;

    P = T*P;
    Point.x = P(0,0);
    Point.y = P(0,1);
    Point.z = P(0,2);

    return Point;


}

Vec3 translate(Vec3& Point,const Vec3& tMat){
    Mat T(4,4); //Transformation matrix
    Mat P(4,1); //Point matrix
    //Transformation matrix
    T(0,0) = 1;    T(0,1) = 0;      T(0,2) = 0;    T(0,3) = tMat.x;
    T(1,0) = 0;    T(1,1) = 1;      T(1,2) = 0;    T(1,3) = tMat.y;
    T(2,0) = 0;    T(2,1) = 0;      T(2,2) = 1;    T(2,3) = tMat.z;
    T(3,0) = 0;    T(3,1) = 0;      T(3,2) = 0;    T(3,3) = 1;
    //Point in matrix form
    P(0,0) = Point.x; P(0,1) = Point.y; P(0,2) = Point.z; P(0,3) = 1;

    P = T*P;
    Point.x = P(0,0);
    Point.y = P(0,1);
    Point.z = P(0,2);

    return Point;

}

Vec3 Reflect_Y(Vec3& Point,const Vec3& tMat){
    Mat T(4,4); //Transformation matrix
    Mat P(4,1); //Point matrix
    //Transformation matrix
    T(0,0) = 0;    T(0,1) = 1;      T(0,2) = 0;    T(0,3) = tMat.x;
    T(1,0) = 1;    T(1,1) = 0;      T(1,2) = 0;    T(1,3) = tMat.y;
    T(2,0) = 0;    T(2,1) = 0;      T(2,2) = 1;    T(2,3) = tMat.z;
    T(3,0) = 0;    T(3,1) = 0;      T(3,2) = 0;    T(3,3) = 1;
    //Point in matrix form
    P(0,0) = Point.x; P(0,1) = Point.y; P(0,2) = Point.z; P(0,3) = 1;

    P = T*P;
    Point.x = P(0,0);
    Point.y = P(0,1);
    Point.z = P(0,2);

    return Point;

}


Vec3 Scale(Vec3& Point,float scale){
    Mat T(4,4); //Transformation matrix
    Mat P(4,1); //Point matrix
    //Transformation matrix
    T(0,0) = scale;    T(0,1) = 0;      T(0,2) = 0;    T(0,3) = 0;
    T(1,0) = 0;    T(1,1) = scale;      T(1,2) = 0;    T(1,3) = 0;
    T(2,0) = 0;    T(2,1) = 0;      T(2,2) = scale;    T(2,3) = 0;
    T(3,0) = 0;    T(3,1) = 0;      T(3,2) = 0;    T(3,3) = 1;
    //Point in matrix form
    P(0,0) = Point.x; P(0,1) = Point.y; P(0,2) = Point.z; P(0,3) = 1;

    P = T*P;
    Point.x = P(0,0);
    Point.y = P(0,1);
    Point.z = P(0,2);

    return Point;

}


Vec2 project(Vec3 p, float width, float height, float angle_x)
{

    Mat S(4,1); //The source point in matrix form
    S(0) = p.x ; S(1) = p.y; S(2) = p.z ; S(3) = 1;
    float zprp = -1;
    Mat Persp(4,4);
    Mat Projected(4,1);
    Persp(0,0) = zprp ; Persp(0,1) = 0; Persp(0,2) = 0; Persp(0,3) = 0;
    Persp(1,0) = 0 ; Persp(1,1) = zprp; Persp(1,2) = 0; Persp(1,3) = 0;
    Persp(2,0) = 0 ; Persp(2,1) = 0; Persp(2,2) = zprp; Persp(2,3) = 0;
    Persp(3,0) = 0 ; Persp(3,1) = 0; Persp(3,2) = -1; Persp(3,3) = -zprp;
    Projected = Persp * S;
    p.x = Projected(0);
    p.y = Projected(1);
    p.z = Projected(2);

//    Projected = Reflect_Y(p,p);

    p = translate(p,{0,3,0});
    Projected(0) = p.x;
    Projected(1) = p.y;
    Projected(2) = p.z;


    //normalize the screen pixels
    Vec2 retVal;
    retVal.x = Projected(0)/Projected(3);
    retVal.y = Projected(1)/Projected(3);
    retVal.z = S(2);

    float  planeWidth = .5;
    float planeHeight = .3;
    retVal.x = (retVal.x + planeWidth*0.5)/planeWidth;
    retVal.y = (retVal.y + planeHeight*0.5)/planeHeight;

    //now to original screen pos in computer
    retVal.x = (int)((1-retVal.x) * width);
    retVal.y = (int)((1-retVal.y) * height);

    return retVal;
}



Vec2 world_to_pixel_wireFrame(Vec3 p, Vec3 cam, Vec3 target, float win_width, float win_height, float angle_x){

    p = world_to_pixel(p,cam,target,win_height,win_height);
        float angle_y, aspect_ratio;
    aspect_ratio = win_width / win_height;
    angle_x = deg2rad(angle_x);
    angle_y = 2*atan(tan(angle_x/2) / aspect_ratio);

    Vec2 v;
    v.x = (1 + p.x/fabs(p.z*tan(angle_x/2))) * (win_width/2);
    v.y = (1 + p.y/fabs(p.z*tan(angle_y/2))) * (win_height/2);
    v.z = p.z;
    return v;


}

Vec3 world_to_pixel(Vec3 p, Vec3 cam, Vec3 target, float win_width, float win_height, float angle_x)
{
    //first determine the World to Camera transforming matrix
    Mat WtoC(4,4);
    //for that use the concept of N, U and V unit vectors
    Vec3 N,U,V(0,1,0);

    //calculate the N unit vector
    //N is the vector from LookTo point to Camera point
//    N = (cam-target).normalize();
    target = {-target.x, -target.y, -target.z};
    N = translate(cam,target).normalize();


    //U = V X N
    U = cross(V,N).normalize();


    //readjust the V vector
    V = cross(N,U).normalize();

    //Transpose matrix from World co-ordinate to View co-ordinate
    Mat T(4,4);
    T(0,0) = 1 ; T(0,1) = 0; T(0,2) = 0; T(0,3) = -cam.x;
    T(1,0) = 0 ; T(1,1) = 1; T(1,2) = 0; T(1,3) = -cam.y;
    T(2,0) = 0 ; T(2,1) = 0; T(2,2) = 1; T(2,3) = -cam.z;
    T(3,0) = 0 ; T(3,1) = 0; T(3,2) = 0; T(3,3) = 1;

    //Rotation Matrix
    Mat R(4,4);
    R(0,0) = U[0] ; R(0,1) = U[1]; R(0,2) = U[2]; R(0,3) = 0;
    R(1,0) = V[0] ; R(1,1) = V[1]; R(1,2) = V[2]; R(1,3) = 0;
    R(2,0) = N[0] ; R(2,1) = N[1]; R(2,2) = N[2]; R(2,3) = 0;
    R(3,0) = 0 ; R(3,1) = 0; R(3,2) = 0; R(3,3) = 1;


    //Calculating the WtoC matrix W = T*R (rotate and then translate)
    WtoC = R*T;

    Mat S(4,1); //The source point in matrix form
    S(0) = p.x ; S(1) = p.y; S(2) = p.z ; S(3) = 1;

    S = WtoC * S;
    //S now represents the camera co-ordinate system's values

    p = {S(0), S(1), S(2)};

    return p;

}

