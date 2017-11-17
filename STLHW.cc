/*Name: Ashutosh Gautam 
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;

class Shape {
protected:
    double x, y, z;
public:
    Shape(double x, double y, double z):x(x), y(y), z(z){}
    virtual void draw(ofstream& out) const = 0;
    virtual ~Shape(){}

};

const double PI = 3.14159;





class Cylinder : public Shape{
private:
	double r, h;
	int facets;
public:
	Cylinder(double x, double y, double z, double r, double h, int facets)
            : Shape(x, y, z), r(r), h(h), facets(facets) {}
    void draw(ofstream& out) const {
        double x1, y1, z1;
        double x2, y2, z2;

        double x3, y3, z3;
        z1= z + h;
        z2= z;
        for (int i = 0; i < facets; i++){

            x1 = x + r * cos(2 * PI / facets * i);
            x2 = x + r * cos(2 * PI / facets * (i + 1));
            y1 = y + r * sin(2 * PI / facets * i);
            y2 = y + r * sin(2 * PI / facets * (i + 1));

            x3 = h * (y2 - y1);
            y3 = h * (x1 - x2);
            z3 = 0.0;

            out << "facet normal" << " " << x3 << " " << y3 << " " << z3 << endl;
            out << "outer loop" << endl;
            out << "vertex" << " " << x1 << " " << y1 << " " << z1 << endl;
            out << "vertex" << " " << x1 << " " << y1 << " " << z2 << endl;
            out << "vertex" << " " << x2 << " " << y2 << " " << z1 << endl;
            out << "endloop" << endl;
            out << "endfacet" << '\n' << endl;

            out << "facet normal" << " " << x3 << " " << y3 << " " << z3 << endl;
            out << "outer loop" << endl;
            out << "vertex" << " " << x1 << " " << y1 << " " << z2 << endl;
            out << "vertex" << " " << x2 << " " << y2 << " " << z1 << endl;
            out << "vertex" << " " << x2 << " " << y2 << " " << z2 << endl;
            out << "endloop" << endl;
            out << "endfacet" << '\n' << endl;

            out << "facet normal" << " " << 0 << " " << 0 << " " << 1 << endl;
            out << "outer loop" << endl;
            out << "vertex" << " " << x << " " << y << " " << z1 << endl;
            out << "vertex" << " " << x1 << " " << y1 << " " << z1 << endl;
            out << "vertex" << " " << x2 << " " << y2 << " " << z1 << endl;
            out << "endloop" << endl;
            out << "endfacet" << '\n' << endl;

            out << "facet normal" << " " << 0 << " " << 0 << " " << -1 << endl;
            out << "outer loop" << endl;
            out << "vertex" << " " << x << " " << y << " " << z2 << endl;
            out << "vertex" << " " << x1 << " " << y1 << " " << z2 << endl;
            out << "vertex" << " " << x2 << " " << y2 << " " << z2 << endl;
            out << "endloop" << endl;
            out << "endfacet" << '\n' << endl;
        }
    }
    ~Cylinder(){}
};


class Cube: public Shape {
private:
	double size;
public:
	Cube(double x, double y, double z, double size)
            : size(size), Shape(x, y, z){}
    void draw(ofstream& out) const{
        out << "facet normal" << " " << "0 0 -1" << endl;
        out << "outer loop" << endl;
        out << "vertex" << " " << x << " " << y << " " << z << endl;
        out << "vertex" << " " << x + size << " " << y << " " << z << endl;
        out << "vertex" << " " << x + size << " " << y + size << " " << z << endl;
        out << "endloop" << endl;
        out << "endfacet" << '\n' << endl;

        out << "facet normal" << " " << "0 0 -1" << endl;
        out << "outer loop" << endl;
        out << "vertex" << " " << x << " " << y << " " << z << endl;
        out << "vertex" << " " << x << " " << y + size << " " << z << endl;
        out << "vertex" << " " << x + size << " " << y + size << " " << z << endl;
        out << "endloop" << endl;
        out << "endfacet" << '\n' << endl;

        out << "facet normal" << " " << "0 -1 0" << endl;
        out << "outer loop" << endl;
        out << "vertex" << " " << x << " " << y << " " << z << endl;
        out << "vertex" << " " << x + size << " " << y << " " << z << endl;
        out << "vertex" << " " << x + size << " " << y << " " << z + size << endl;
        out << "endloop" << endl;
        out << "endfacet" << '\n' << endl;

        out << "facet normal" << " " << "0 -1 0" << endl;
        out << "outer loop" << endl;
        out << "vertex" << " " << x << " " << y << " " << z << endl;
        out << "vertex" << " " << x << " " << y << " " << z + size<< endl;
        out << "vertex" << " " << x + size << " " << y << " " << z + size << endl;
        out << "endloop" << endl;
        out << "endfacet" << '\n' << endl;

        out << "facet normal" << " " << "-1 0 0" << endl;
        out << "outer loop" << endl;
        out << "vertex" << " " << x << " " << y << " " << z << endl;
        out << "vertex" << " " << x << " " << y + size << " " << z << endl;
        out << "vertex" << " " << x << " " << y + size << " " << z + size << endl;
        out << "endloop" << endl;
        out << "endfacet" << '\n' << endl;

        out << "facet normal" << " " << "-1 0 0" << endl;
        out << "outer loop" << endl;
        out << "vertex" << " " << x << " " << y << " " << z << endl;
        out << "vertex" << " " << x << " " << y + size << " " << z + size << endl;
        out << "vertex" << " " << x << " " << y << " " << z + size << endl;
        out << "endloop" << endl;
        out << "endfacet" << '\n' << endl;

        out << "facet normal" << " " << "1 0 0" << endl;
        out << "outer loop" << endl;
        out << "vertex" << " " << x + size << " " << y << " " << z << endl;
        out << "vertex" << " " << x + size << " " << y + size << " " << z << endl;
        out << "vertex" << " " << x + size << " " << y + size << " " << z + size << endl;
        out << "endloop" << endl;
        out << "endfacet" << '\n' << endl;

        out << "facet normal" << " " << "1 0 0" << endl;
        out << "outer loop" << endl;
        out << "vertex" << " " << x + size << " " << y << " " << z << endl;
        out << "vertex" << " " << x + size << " " << y + size << " " << z + size << endl;
        out << "vertex" << " " << x + size << " " << y << " " << z + size << endl;
        out << "endloop" << endl;
        out << "endfacet" << '\n' << endl;

        out << "facet normal" << " " << "0 0 1" << endl;
        out << "outer loop" << endl;
        out << "vertex" << " " << x << " " << y << " " << z + size << endl;
        out << "vertex" << " " << x + size << " " << y << " " << z + size << endl;
        out << "vertex" << " " << x + size << " " << y + size << " " << z + size << endl;
        out << "endloop" << endl;
        out << "endfacet" << '\n' << endl;

        out << "facet normal" << " " << "0 0 1" << endl;
        out << "outer loop" << endl;
        out << "vertex" << " " << x << " " << y << " " << z + size << endl;
        out << "vertex" << " " << x << " " << y + size << " " << z + size << endl;
        out << "vertex" << " " << x + size << " " << y + size << " " << z + size << endl;
        out << "endloop" << endl;
        out << "endfacet" << '\n' << endl;

        out << "facet normal" << " " << "0 1 0" << endl;
        out << "outer loop" << endl;
        out << "vertex" << " " << x << " " << y + size << " " << z << endl;
        out << "vertex" << " " << x + size << " " << y + size << " " << z << endl;
        out << "vertex" << " " << x + size << " " << y + size << " " << z + size << endl;
        out << "endloop" << endl;
        out << "endfacet" << '\n' << endl;

        out << "facet normal" << " " << "0 1 0" << endl;
        out << "outer loop" << endl;
        out << "vertex" << " " << x << " " << y + size << " " << z << endl;
        out << "vertex" << " " << x << " " << y + size << " " << z + size<< endl;
        out << "vertex" << " " << x + size << " " << y + size << " " << z + size << endl;
        out << "endloop" << endl;
        out << "endfacet" << '\n' << endl;
    }
};
class CAD {
private:
   vector<Shape*> shapes;
public:
    CAD(){}
    ~CAD(){
        for(int i=0; i<shapes.size();i++)
            delete shapes[i];
    }
    void add(Shape* s){
        shapes.push_back( s );
    }
   
        void write(const string& path){
        ofstream out;
        out.open(path, ofstream::app);
        out << "solid shape" << endl;
        for(size_t i = 0; i < shapes.size(); i++){
            shapes[i] -> draw(out);
        }
        out << "endsolid shape" << endl;
        out.close();
	}
    };

int main() {
	CAD c;
	c.add(new Cube(0,0,0,   5));
	c.add(new Cylinder(100,0,0,    3, 10, 10));
  c.write("test.stl");
    return 0; 
}
