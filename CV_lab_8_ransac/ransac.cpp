#include <iostream>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <fstream>


//using namespace std;

// 2D Matrix class
class Mat2D{
public:
	double a, b, c, d;

	Mat2D(){
		a = b = c = d = 0.0;
	}
	Mat2D(double m, double n, double o, double p){
		a = m;
		b = n;
		c = o;
		d = p;
	}

	void setMat(double m, double n, double o, double p){
		a = m;
		b = n;
		c = o;
		d = p;
	}
	double determinant(){
		return ((this->a*this->d)-(this->b*this->c));
	}
	void printMat(){
		std::cout << std::endl;
		std::cout << a << " " << b <<  std::endl;
		std::cout << c << " " << d <<  std::endl;
		std::cout << std::endl;
	}
	Mat2D& operator =(const Mat2D& M){
        this->a = M.a;
        this->b = M.b;
        this->c = M.c;
        this->d = M.d;

        return *this;
    }
	
};

// 2P point class

class Point2D: public Mat2D{
public:
	double x;
	double y;

	Point2D(){
		x = 0.0;
		y = 0.0;
	}
	Point2D(float a, float b){
		x = a;
		y = b;
	}
	void setxy(float a, float b){
		x = a;
		y = b;
	}
	void pointPrint(){
		std::cout << "(" << x << ", " << y << ")" << std::endl;
	}
	friend Point2D operator *(Mat2D& e, Point2D& b){
		Point2D newP;
        newP.x =(e.a * b.x) + (e.b * b.y);
        newP.y =(e.c * b.x) + (e.d * b.y);
        return newP;
    }
    friend bool operator ==(Point2D& a, Point2D& b){
        if (a.x == b.x and a.y == b.y)
            return true;
        else 
        	return false;
    }
};

class Circle : public Point2D{
public:
	Point2D Cent;
	double radius;
	bool isSingular;

	Circle(){
		Cent.x = 0.0;
		Cent.y = 0.0;
		radius = 0.0;
		isSingular = true;

	}
	Circle(Point2D A, double r){
		Cent.x = A.x;
		Cent.y = A.y;
		radius = r;
		isSingular = false;
	}
	void setCent(Point2D val){
		Cent.x = val.x;
		Cent.y = val.y;
	}
	void setRad(double val){
		radius = val;
	}
	bool checkSingular(){
		return this->isSingular;
	}
	void printC(){
		std::cout << "\nRadius:  " << radius << std::endl;
		std::cout << "center:  ";
		Cent.pointPrint(); 
	}


};

bool checkSingularity(Point2D p1, Point2D p2, Point2D p3){
	double m1=0.0, m2=0.0;
	m1 = (p2.y - p1.y)/(p2.x - p1.x);
	m2 = (p3.y - p2.y)/(p3.x - p2.x);
	if(m1 == m2)
		return true;
	return false;
}
// matrix inverse

Mat2D inverse(Mat2D& inv){
		double dt = inv.determinant();
		Mat2D newMat;
		newMat.a = inv.d/dt;
		newMat.b = -(inv.b/dt);
		newMat.c = -(inv.c/dt);
		newMat.d = inv.a/dt;

		return newMat;
	}

// Sum of x and y coordinate returned as point

Point2D sumXY(std::vector<Point2D>& val){
	double sumX = 0.0;
	double sumY = 0.0;
	for(unsigned int i=0; i<val.size(); i++){
		sumX += val[i].x;
		sumY += val[i].y;
	}
	Point2D rval;
	rval.setxy(sumX, sumY);
	return rval;
}

// Sum of squares of the points

Point2D sumSQ(std::vector<Point2D>& val){
	double sumX = 0.0;
	double sumY = 0.0;
	for(unsigned int i=0; i<val.size(); i++){
		sumX += pow(val[i].x, 2);
		sumY += pow(val[i].y, 2);
	}
	Point2D rval;
	rval.setxy(sumX, sumY);
	return rval;
}

// Sum of cubes of the x and y

Point2D sumCU(std::vector<Point2D>& val){
	double sumX = 0.0;
	double sumY = 0.0;
	for(unsigned int i=0; i<val.size(); i++){
		sumX += pow(val[i].x, 3);
		sumY += pow(val[i].y, 3);
	}
	Point2D rval;
	rval.setxy(sumX, sumY);
	return rval;
}

// Sum of x*y of the points returned as double

double sumUV(std::vector<Point2D>& val){
	double sum = 0.0;
	for(unsigned int i=0; i<val.size(); i++){
		sum += (val[i].x*val[i].y);
	}
	return sum;
}

// Sum of x*y^2 of the points returned as double

double sumUVV(std::vector<Point2D>& val){
	double sum = 0.0;
	for(unsigned int i=0; i<val.size(); i++){
		sum += (val[i].x*(pow(val[i].y, 2)));
	}
	return sum;
}

// Sum of x^2*y of the points returned as double

double sumVUU(std::vector<Point2D>& val){
	double sum = 0.0;
	for(unsigned int i=0; i<val.size(); i++){
		sum += ((pow(val[i].x, 2))*val[i].y);
	}
	return sum;
}
// Add points
Point2D addPoints(Point2D a, Point2D b){
	Point2D res;
	res.x = a.x + b.x;
	res.y = a.y + b.y;
	return res;
}
// average of the points 
Point2D average(std::vector<Point2D>& vecPoints){
	double sumX = 0.0;
	double sumY = 0.0;
	unsigned int N = vecPoints.size();
	for(unsigned int i=0; i<N; i++){
		sumX += vecPoints[i].x;
		sumY += vecPoints[i].y;
	}
	double avg_x = sumX/(double)N;
	double avg_y = sumY/(double)N;
	Point2D avgPT;
	avgPT.setxy(avg_x, avg_y);
	return avgPT;

}
// calculating u and v points
void uvCalculator(std::vector<Point2D>& vecPoints, Point2D avg, std::vector<Point2D>& uvpoints){
	for(unsigned int i = 0; i < vecPoints.size(); i++){
		Point2D temp;
		double a = vecPoints[i].x - avg.x;
		double b = vecPoints[i].y - avg.y;
		temp.setxy(a, b);
		uvpoints.push_back(temp);
	}
}

Circle fitting(std::vector<Point2D>& vecPoints){

	Point2D avgPT;
    avgPT = average(vecPoints);	
    std::vector<Point2D> uvpoints;
    uvCalculator(vecPoints, avgPT, uvpoints); // calculating u v points

    Point2D S_2uv = sumSQ(uvpoints); // consists of two points u^2 and v ^2
    Point2D S_3uv = sumCU(uvpoints); // consists of two points u^3 and v ^3
    double S_uv = sumUV(uvpoints); // consists of sum of u.v
    double S_UVV = sumUVV(uvpoints); // consists of sum of u.v^2
    double S_VUU = sumVUU(uvpoints); // consists of sum of v.u^2

    double ap = 0.5*(S_3uv.x + S_UVV);
    double bp = 0.5*(S_3uv.y + S_VUU);

    Point2D Pab;
    Pab.setxy(ap, bp);

    unsigned int N = uvpoints.size();
    N = (double)N;

    Mat2D iMat;

    Mat2D nMat(S_2uv.x, S_uv, S_uv, S_2uv.y); 	// Initial matrix
    iMat = inverse(nMat);	// inverted matrix

    Point2D val_uvC;		
    val_uvC = iMat*Pab;		// uc and vc
    
    Point2D center;
    double R;
    center = addPoints(val_uvC, avgPT); // Actual center as we add the average


    double valSN = ((S_2uv.x + S_2uv.y)/N);

    R = sqrt(pow(val_uvC.x, 2) + pow(val_uvC.y, 2) + valSN);
    Circle retCircle;
    retCircle.setCent(center);
    retCircle.setRad(R);

    return retCircle;

}

double sqr(double a){
    return (a*a);
}
double Abbs(double a){
    if (a<0.0)
        return (-1.0*a);
    else
        return a;
}
double distance(Point2D a, Point2D b){
	double ret = sqrt(sqr(a.x- b.x) + sqr(a.y- b.y));
    return ret;
}

double error(Circle C, Point2D p){
	double R = sqr(C.radius);
	double v = sqr(distance(C.Cent, p));
	double A = Abbs(R-v);
    return A;
}

double sumError(Circle C, std::vector<Point2D>& vecPoints){
	double e;
	for(unsigned int i = 0; i < vecPoints.size(); i++){
		e = error(C, vecPoints[i]);
	}
	return e;
}

std::vector<Point2D> RESET(std::vector<Point2D>& set, std::vector<Point2D>& subset){
    std::vector<Point2D> RESETset;
    for(unsigned int i = 0; i<set.size();i++){
        bool check = false;
        for (unsigned int j = 0 ; j< subset.size(); j++){
            if (set[i]==subset[j]){
                check = true;
                break;
            }
            
        }
        if (!check){
            RESETset.push_back(set[i]);
        }
    }
    return RESETset;
}

std::vector<Circle> Ransac(std::vector<Point2D>& points, int Nmin,int imax,float tau,int d){
    
    time_t seconds; 
    time(&seconds);
    srand((unsigned int) seconds); //random

    std::vector<Circle> selectedCircles;
    std::vector<Point2D> randvecpoints;

    for(int x = 0; x < 3; x++){
    	int count = 0;
    	unsigned int size = points.size();
        size = (int) size;
        Circle modelnew;
    
    	double errnew = 100000.0;
   		double e = 0.0;

    	std::vector<int> Ipts;
    	std::vector<int> Inew;

    	Circle model;

	    while(count< imax){
	        std::vector<Point2D> tempQualifiedPoints;
	        for(int j = 0 ; j< Nmin; j++){
	            Ipts.push_back(rand()%size);
	        }
	        for(int i = 0; i < Nmin; i++){
	            randvecpoints.push_back(points[Ipts[i]]);
	        }
	        //bool check = checkSingularity(points[Ipts[0]], points[Ipts[1]], points[Ipts[2]]);
	        model = fitting(randvecpoints);
	        /*if (check){
	            continue;
	        }*/
	        for(unsigned int j = 0; j<points.size(); j++){
	            if(error(model, points[j])<tau){
	                 Ipts.push_back(j);
	                 randvecpoints.push_back(points[j]);
	            }
	        }
	        if (((int) Ipts.size()) > d){
	        	model= fitting(randvecpoints);
	        	e = sumError(model, randvecpoints);
	        	if(Ipts > Inew){
	        		modelnew = model;
	        		Inew = Ipts;
	        		errnew = e;
	        	}
	        }
	        count++;
	    }
	    Ipts.clear();
	    Inew.clear();
	    points = RESET(points, randvecpoints);
	    randvecpoints.clear();
	    selectedCircles.push_back(modelnew);
	}
	return selectedCircles;
}




int main(int argc, const char * argv[]) {
    std::vector<Point2D> vecPoints;
  	std::ifstream myfile("pts_to_ransac.txt");

  	double x=0.0, y =0.0;
  	if(!myfile.is_open()){
  		std::cout << "Unable to open file"; 
  		return 0;
  	}
	while (myfile >> x >> y){
	     Point2D point;
	     point.setxy((double)x,(double)y);
         vecPoints.push_back(point);
	}
	myfile.close();
	unsigned int N = vecPoints.size();
	N = (int)N;
	std::vector<Circle> Circles = Ransac(vecPoints, 3, N, 0.05, 8);
    
    std::cout<<"Result"<<std::endl;
    for(unsigned int s = 0 ; s < Circles.size(); s++){
       Circles[s].printC();
    }
    return 0;
}