void dfs(int v){
	for(ii u: adj[v]) if(!used[u.snd]){
		used[u.snd]=1;
		dfs(u.fst);
		ANS.pb(u.snd);
	}
}

int main(){
	//Primero, revisar que a lo más dos nodos tengan grado impar (o ninguno para cycles) 
	//y lanzar el dfs desde el nodo de grado impar mayor (si no hay, cualquiera con grado mayor a 0)
	bool chi=1;
	rep(i, 0, m ) chi = chi && used[i];
	return 0;
}
