#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

// structure for 2D vector to represent a position
struct vec2{

    vector<vector<double>> pos;
};
// structure for a sphere
struct sphere{
    double Size_Radius;
    vec2 direction;
    vec2 position;
    vec2 motion;
};
// display sphere object
void display_sphere_object(sphere &mySphere){
    cout << "Position     : <"
         << mySphere.position.pos[0][0]
         << ","
         << mySphere.position.pos[0][1]
         << ">"
         << endl;
    cout << "Size_radius  : "
         << mySphere.Size_Radius
         << endl;
    cout << "Motion_vector: <"
         << mySphere.motion.pos[0][0]
         << ","
         << mySphere.motion.pos[0][1]
         << ">"
         << endl;
    cout << endl;
};
//angle to direction vector
vector<vector<double>> angle_to_direction_vector(double degree){
    // TODO: Finish the function
    double PI = 2*asin(1.0); // finding value of PI using sin function
    double radians = (degree * PI)/180; // converting degrees to radians
    double x,y;
    x = sin(radians);
    y = cos(radians);
    vector<vector<double>> direction = {{x,y}};
    return direction;
};
//point to point distance
double point_to_point_distance(vec2 p1,vec2 p2){
    double x,y;
    x = p1.pos[0][0] - p2.pos[0][0];
    y = p1.pos[0][1] - p2.pos[0][1];
    double distance = pow(x, 2) + pow(y, 2); //calculating Euclidean distance
	distance = sqrt(distance);
    return distance;
};
//dot production
double dot_product(double vector1[], double vector2[]){
    double product = 0;
    for (int i = 0; i < 2; i++)
    {
        product = product + vector1[i] * vector2[i];
    }
    return product;
};
//normalize vector
vec2 normalize_vector(vec2 vec){

    double distance = vec.pos[0][0]/sqrt(pow(vec.pos[0][0],2)+ pow(vec.pos[0][1],2));
    //double distance = point_to_point_distance(vecN[0],vecN[1]);
    if(distance > 0){
        // ensuring we do not divide by 0
    }
    return vec;
};
//reflect
vector<double> reflect(vector<double> incident, vector<double> normal){
    // TODO: Finish the function
    vector<double> reflection;
    return reflection;
};
//check intersection
bool check_intersection(sphere rolling_ball, sphere obstacle){
    return point_to_point_distance(rolling_ball.position, obstacle.position) < (rolling_ball.Size_Radius + obstacle.Size_Radius);
};
//display sphere
void display_sphere(sphere &s){
    // TODO: Finish the function
};
int main()
{
    int max_steps = 100;
    sphere s;
    s.Size_Radius = 1.0;
    s.position.pos = {{-1.0,-2.5}};
    s.direction.pos = angle_to_direction_vector(90.0);
    s.motion.pos = {{-1.0,-2.5}};

    sphere obstacle;
    obstacle.position.pos = {{0.3,1.0}};
    obstacle.Size_Radius = 1.0;

    int user_steps = 0;
    cout << "Enter number of steps: \n";
    cin >> user_steps;
    if(user_steps > 100 || user_steps < 0){
        cout << "Please enter valid steps! \n";
        return 0;
    }
    for(int i=0;i<user_steps;i++){
        display_sphere_object(s);
    }

    return 0;
}
