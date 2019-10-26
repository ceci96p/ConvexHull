#include "convexhull.h"
#include <iostream>

void sortByAngle(vector<Point>& v){
   double a,b,h;
   double ang_1;
   double smallest_angle;
   double smallest_index;


   double min_value_x;
   double min_value_y;
   int pos_min = 0;
   Point min_value;
   Point value;

   min_value_x = v[0].x;
   min_value_y = v[0].y;

   for (unsigned m = 1; m < v.size() -1; m++){
 
   	double first_value_y = v[m].y;
   	double first_value_x = v[m].x; 

   	if (min_value_y > first_value_y){
   		min_value_x = first_value_x;
   		min_value_y = first_value_y;

   		pos_min = m;
   	}

   	else if (min_value_y == first_value_y){
   		if(min_value_x > first_value_x){
   			min_value_x = first_value_x;
   			min_value_y = first_value_y;

   			pos_min = m;
   		}
   	}
   }

min_value.x = min_value_x;
min_value.y = min_value_y;

value.x = v[0].x ;
value.y = v[0].y ;

v[0] = min_value;
v[pos_min] = value;


     for (unsigned i = 1; i < v.size()-1 ; ++i){
		
			a = v[i].x - v[0].x;
         	b = v[i].y - v[0].y;
         	h = sqrt(a*a + b*b);

         	 smallest_angle = acos (a/h);
         	 smallest_index = i;

		for (unsigned j = i + 1; j < v.size(); ++j){
        

         	a = v[j].x - v[0].x;
         	b = v[j].y - v[0].y;
         	h = sqrt(a*a + b*b);
         	ang_1 = acos (a/h);

         	if (ang_1 < smallest_angle){
         		smallest_angle = ang_1;
         		smallest_index = j;
         	}  
        }
            Point temp1 = Point(v[i].x, v[i].y);
            Point temp2 = Point(v[smallest_index].x, v[smallest_index].y);
            v[i] = temp2;
            v[smallest_index] = temp1;    		  
    }
}


bool ccw(Point p1, Point p2, Point p3){
	if (((p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x)) > 0 ){
		return true;
	}
		return false;
}

// returns a vector of points representing the convex hull of v
// if c is the vector representing the convex hull, then c[k], c[k+1]
// is an edge in the convex hull, for all k in 0 to n-1, where n is the
// number of points in the hull. c[n-1],c[0] is also an edge in the hull.
// The returned vector should be a subset of v
// Input: v - a vector of points in arbitrary order
vector<Point> getConvexHull(vector<Point>& v){
Stack temp;
Stack temp2;
vector<Point> vec;

sortByAngle(v);

temp.push(v[0]);
temp.push(v[1]);

for (unsigned i = 0;i < v.size()-2 ;i++){
	temp.push(v[i+2]);
   
    Point third = temp.pop();//temp.pop();
    Point second = temp.pop();
    Point first = temp.pop();


if (ccw(first,second,third) == true){
	temp.push(first);
	temp.push(second);
	temp.push(third);
}

else if(ccw(first,second,third) == false){

	while (temp.size() != 0){
	if (ccw(temp.peek(), first, third)) {
		temp.push(first);
		temp.push(third);
		break;
	}

	else {
		first = temp.pop();
	}
}
}
}

int stack_size_1 = temp.size();
for(int n = 0; n < stack_size_1; n++){
    temp2.push(temp.pop());
}


int stack_size_2 = temp2.size();
for(int m = 0; m < stack_size_2; m++){
	vec.push_back(temp2.pop());
}

return vec;

}





