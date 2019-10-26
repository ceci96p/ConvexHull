#include "convexintersection.h"
#include <iostream>

bool inside(Point p1, Point sp1, Point sp2){
return ccw(sp1, sp2, p1);
}

Point computeIntersection(Point s1, Point s2, Point i1, Point i2){
	
    // Line AB represented as a1x + b1y = c1
    double a1 = s2.y - s1.y;
    double b1 = s1.x - s2.x;
    double c1 = a1*(s1.x) + b1*(s1.y);
 
    // Line CD represented as a2x + b2y = c2
    double a2 = i2.y - i1.y;
    double b2 = i1.x - i2.x;
    double c2 = a2*(i1.x)+ b2*(i1.y);
 
    double determinant = a1*b2 - a2*b1;
    
    double x = (b2*c1 - b1*c2)/determinant;
    double y = (a1*c2 - a2*c1)/determinant;

    return Point(x, y);  
}

vector<Point> getConvexIntersection(vector<Point>& poly1, vector<Point>& poly2){
vector<Point> input;
vector<Point> output;

output = poly2;                                 //outputList = subjectPolygon;

for(unsigned i = 0 ; i < poly1.size() ; i++){  //for (Edge clipEdge in clipPolygon) do


	input = output;  							//inputList = outputList;

	output.clear();                             //outputList.clear();

	//Point s = input.back();                     //Point S = inputList.last;
	Point s = input[input.size()-1];


	for (unsigned j = 0 ; j <  input.size(); j++){ 	//for (Point E in inputList) do

		Point e = input[j];

		if (inside(e,poly1[i],poly1[(i+1) % poly1.size()])){      //if (E inside clipEdge) then

			if (!inside(s,poly1[i],poly1[(i+1) % poly1.size()])){        //if (S not inside clipEdge) then
				output.push_back(computeIntersection(s,e,poly1[i],poly1[(i+1) % poly1.size()])); //outputList.add(ComputeIntersection(S,E,clipEdge));
			}

			output.push_back(e);                 //outputList.add(E);
		}
			                                          
		else if (inside(s,poly1[i],poly1[(i+1) % poly1.size()]) == true) { //else if (S inside clipEdge) then
			output.push_back(computeIntersection(s,e,poly1[i],poly1[(i+1) % poly1.size()])); //outputList.add(ComputeIntersection(S,E,clipEdge));
		} 	

  		s = e;
		
	}
}

return output;

}
