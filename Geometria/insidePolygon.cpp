bool collinear(Point a, Point b, Point c){
	return abs(area2(a,b,c))<EPS;
}

bool onSeg(Point a, Point b, Point c){
	return collinear(a,b,c) 
		&& (min(a.x,b.x) < c.x +EPS && c.x-EPS < max(a.x,b.x))
		&& (min(a.y,b.y) < c.y +EPS && c.y-EPS < max(a.y,b.y));
}

struct Polygon{
	vector<Point> P;
	int n=0;
	void add(Point p){
		P.pb(p);n++;
	}
	bool isInside(Point q){
		if(right(P[0],P[1],q) || left(P[0],P[n-1],q)) return 0;
		int lo = 0, hi = n;
		while(lo+1<hi){
			int mid = (lo+hi)>>1;
			if(left(P[0],P[mid],q)) lo=mid;
			else hi=mid;
		}
		return left(P[lo],P[(lo+1)%n],q) || onSeg(P[lo],P[(lo+1)%n],q);
	}
} Pol;
