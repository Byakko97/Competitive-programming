const ll N=1<<21;
const ld PI = acos(-1);

struct Complejo{
	ld real, img;
	Complejo(ld _real, ld _img): real(_real), img(_img){}
	Complejo(): real(0), img(0){}
	Complejo operator +(const Complejo& other){
		Complejo res;
		res.real = this->real + other.real;
		res.img = this->img + other.img;
		return res;
	}
	Complejo operator -(const Complejo& other){
		Complejo res;
		res.real = this->real - other.real;
		res.img = this->img - other.img;
		return res;
	}
	Complejo operator *(const Complejo& other){
		Complejo res;
		res.real = this->real * other.real - this->img * other.img;
		res.img = this->real * other.img + this->img * other.real;
		return res;
	}
	Complejo operator/(int x){
		Complejo res;
		res.real = this->real/x;
		res.img = this->img/x;
		return res;
	}
	void conjugate(){
		img = -img;
	}
};

Complejo root[N];
int rev[N];

void build(int m){
	int lg = sizeof(int)*8 - __builtin_clz(m) -1;
	rev[0]=0;
	For(i,1,m) rev[i] = (rev[i>>1]>>1) + ((i&1) << (lg-1));
	root[1]=Complejo(1,0);
	Complejo z;
	For(k,1,lg){
		ld alp = 2*PI /(1<<(k+1));
		z = Complejo(cos(alp),sin(alp));
		For(i,1<<(k-1),1<<k){
			root[i<<1] = root[i];
			root[i<<1|1] = z*root[i];
		}
	}
}

Complejo aux[N];

void fft(vector<Complejo>& A){
	int m = sz(A);
	For(i,0,m) aux[i] = A[rev[i]];
	For(i,0,m) A[i] = aux[i];
	Complejo z;
	for(int k = 1; k<m; k<<=1)
		for(int i=0; i<m; i+= k<<1)
			For(j,0,k){
				z = root[j+k] * A[i+j+k];
				A[i+j+k] = A[i+j] - z;
				A[i+j] = A[i+j] + z;
			}
}

void multiply(vector<Complejo>& A, vector<Complejo>& B){
	int m = sizeof(int)*8 - __builtin_clz(max(sz(A),sz(B)));
	m = 1<<m;
	build(m);
	A.resize(m); B.resize(m);
	fft(A);
	fft(B);
	For(i,0,m)
		B[i] = A[i]*B[i]/m;
	reverse(B.begin()+1, B.end());
	fft(B);
}
inline ll conv(char c){
	return c=='a'? 1:-1;
}

