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

vector<Point> CH;
Point P[N];
int n;

void convexhull(){
	vector<Point> low, up;
	//Es mejor borrar los duplicados de P
	sort(P,P+n);
	For(i,0,n){
		while(sz(up)>=2 && !right(up[sz(up)-2],up.back(),P[i]))
			up.pop_back();
		up.pb(P[i]);
		while(sz(low)>=2 && !left(low[sz(low)-2],low.back(),P[i]))
			low.pop_back();
		low.pb(P[i]);
	}
	For(i,0,sz(low)-1) CH.pb(low[i]);
	roF(i,sz(up)-1,1) CH.pb(up[i]);
}
