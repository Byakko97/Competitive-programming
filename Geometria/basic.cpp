struct Point{
	ld x, y;
	bool operator<(const Point& other) const{
		if(abs(x-other.x)>EPS) return x<other.x-EPS;
		else return y<other.y-EPS;
	}
};

ld area2(Point a, Point b, Point c){
	return (b.x-a.x)*(c.y-a.y) - (c.x-a.x)*(b.y-a.y);
}
bool left(Point a, Point b, Point c){
	return area2(a,b,c) > EPS;
}
bool right(Point a, Point b, Point c){
	return area2(a,b,c) < -EPS;
}

bool collinear(Point a, Point b, Point c){
	return abs(area2(a,b,c))<EPS;
}

bool onSeg(Point a, Point b, Point c){
	return collinear(a,b,c) 
		&& (min(a.x,b.x) < c.x +EPS && c.x-EPS < max(a.x,b.x))
		&& (min(a.y,b.y) < c.y +EPS && c.y-EPS < max(a.y,b.y));
}

bool inter(pair<Point, Point> a, pair<Point, Point> b){
	if(colinear(a.ff,a.ss,b.ff) || colinear(a.ff,a.ss,b.ss) || colinear(b.ff,b.ss,a.ff) || colinear(b.ff,b.ss,a.ss))
		return 1;
	return izq(a.ff,a.ss,b.ff)!=izq(a.ff,a.ss,b.ss) && izq(b.ff,b.ss,a.ff)!=izq(b.ff,b.ss,a.ss);
}
