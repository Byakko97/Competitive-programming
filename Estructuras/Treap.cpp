//Treap implicito con insercion, remocion y cambio de valor en posicion
//funcion objetivo muy especifica del problema (los trechos donde aparece estan comentados)
//Resuelve Can you answer these queries VIII (https://www.spoj.com/problems/GSS8/)
//u_int es especifico del problema

typedef struct item *pitem;
struct item{
	u_int cnt, pr;
	u_int val;
	u_int ans[11];
	pitem l, r;
	item(u_int _val) : pr(rand()*RAND_MAX+rand()),val(_val),cnt(1),l(nullptr),r(nullptr){} 
};

u_int cnt(pitem t){
	return t!=nullptr? t->cnt : 0;
}

/*u_int getans(pitem t, int i){
	return t!=nullptr? t->ans[i]:0;
}*/

void upd(pitem t){
	if(t!=nullptr){
		u_int tam_l = cnt(t->l), tam_r = cnt(t->r);
		t->cnt = tam_l + 1 + tam_r;
		/*For(k,0,11){ Funcion objetivo
			u_int base = 1; 
			t->ans[k] = getans(t->l,k);
			For(j,0,k+1){
				t->ans[k] += comb[k][j]*base*getans(t->r,k-j);
				if(j<k) base *= tam_l+1; //base = (tam_l+1)^(j+1)
			}
			t->ans[k]+=base*t->val;
		}*/
	}
}

void merge(pitem &t, pitem l, pitem r){
	if(l==nullptr || r==nullptr)
		t = l!=nullptr ? l:r;
	else if(l->pr > r->pr)
		merge(l->r, l->r, r), t=l;
	else 
		merge(r->l, l, r->l), t=r;
	upd(t);
}

void split(pitem t, pitem &l, pitem &r, u_int key, u_int add=0){
	if(t==nullptr){
		l=r=nullptr; return;
	}
	u_int cur_key = add + cnt(t->l);
	if(key <= cur_key)
		split(t->l, l, t->l, key, add), r=t;
	else
		split(t->r, t->r, r, key, add+1+cnt(t->l)), l=t;
	upd(t);
}

void insert(pitem& t, u_int pos, u_int val){
	pitem it = new item(val);
	pitem t1, t2;
	split(t,t1,t2,pos);
	merge(t1,t1,it);
	merge(t,t1,t2);
}

void erase(pitem&t, u_int key, u_int add=0){
	u_int cur_key = add+cnt(t->l);
	if(key==cur_key)
		merge(t,t->l,t->r);
	else{
		if(key<cur_key)
			erase(t->l, key, add);
		else
			erase(t->r, key, add+1+cnt(t->l));
		upd(t);
	}
}
	
void replace(pitem& t, u_int key, u_int val, u_int add=0){
	u_int cur_key = add+cnt(t->l);
	if(key==cur_key)
		t->val=val;
	else if(key<cur_key)
		replace(t->l,key,val,add);
	else
		replace(t->r,key,val,add+1+cnt(t->l));
	upd(t);
}

/*u_int que(pitem& t, u_int l, u_int r, int k){
	pitem t1, t2, t3;
	split(t,t1,t2,l);
	split(t2,t2,t3,r-l+1);
	u_int ans = t2->ans[k];
	merge(t,t1,t2);
	merge(t,t,t3);
	return ans;
}*/
