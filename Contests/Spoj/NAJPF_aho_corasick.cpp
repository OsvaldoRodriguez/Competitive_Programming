#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
const int ALPHA = 26;
int trie[N][ALPHA]; // nodos y alfabeto
int nodes;
 
// infomacion de nodo
int cnt[N]; // cantidad de palabras que terminan en ese nodo
int end_word[N]; // final de una palabra en el trie
// construccion del trie
 
int fail[N]; // aristas lilas -> fail de cada nodo
int fail_out[N]; // aristas verdes -> va directamente al nodo fail donde termina una palabra del  diccionario
void add(string &s, int idx){
    int cur = 0; // raiz del trie
    for(char c : s){
        int x = c - 'a';  // mapear el alfabeto con numeros
        if(!trie[cur][x])
            trie[cur][x] = ++nodes;
        cur = trie[cur][x];
    }
    cnt[cur]++; // termina una palabra
    end_word[cur] = idx; // idx de la palabra
}
// construccion del fail de cada nodo
// dado un nodo u, se hallara el fail de v, donde v es el hijo(s) de u
// notar que si u es padre de v, todos los fails de u ya estan calculados
// porque se esta haciendo con bfs
void build(){
    queue<int> q;
    q.push(0); // nodo raiz
    while(q.size()){
        int u = q.front(); q.pop();
        for(int i = 0; i < ALPHA; i++){
            int v = trie[u][i]; // a esto nodo se quiere calcular el fail
            if(v){ // si existe el nodo
                /*solo entra si no es la raiz*/
                if(u){ // calcular el fail  para  v y lo que se necesite
                    fail[v] = fail[u]; // voy al fail de mi padre (ya esta calculado) y luego tratar de mover con la letra i
                    // if(trie[ fail[v] ][i]){ // si existe la letra i en el trie
                    //     fail[v] = trie[ fail[v] ][i];
                    // }
                    // como no puede haber la letra i entonces tengo que ir al fail de mi fail (hasta la raiz de ser necesario)
                    // mientras no sea la raiz (bucle infinito)
                    while(fail[v] and !trie[ fail[v] ][i]){ // mientras no exista la letra i -> voy al fail de mi fail
                        fail[v] = fail[ fail[v] ];
                    }
 
                    fail[v] = trie[ fail[v] ][i]; // apuntar a la letra i 
                    cnt[v] += cnt[ fail[v] ]; // para contar las palabras del diccionario
                    fail_out[v] = end_word[ fail[v] ] ? fail[v] : fail_out[ fail[v] ]; // calcular arista verde
                } 
 
 
                q.push(v); 
            }
        }
    }
}
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    for(int w = 0; w < t; w++){
        string s, p;
        vector<string> words;
        cin >> s >> p;
        words.push_back(p);
        add(p, 1);
        build(); // aho korasick
        int cur = 0; // raiz del trie
        int sum = 0; // cantidad de palabras que matchean con s
        vector<int> ans;
        for(int i = 0; i < s.size(); i++){
            char c = s[i];
            int x = c - 'a';
            while(cur > 0 and !trie[cur][x])
                cur = fail[cur];
            cur = trie[cur][x];  // apuntar a la letra x (sino apunta a la raiz) 
            // cout << i << " " << end_word[cur] << endl;
            if(end_word[cur] == 1)
                ans.push_back(i + 1 - p.size() + 1);
            sum += cnt[cur];
            int tmp = cur;
            while(tmp){         // O(sqrt(suma de los caracteres del diccionario))
                if(end_word[tmp]){
                    // cout << i << ' ';
                    // ans.push_back(i); 
                    // cout << words[end_word[tmp] - 1] << '\n';
                }
 
                tmp = fail_out[tmp];
            }
        }
        if(w)
            cout << '\n';
        if(ans.size()){
            cout << ans.size() << '\n';
            cout << ans[0];
            for(int i = 1; i < ans.size(); i++)
                cout << ' ' << ans[i];
 
        }else
            cout << "Not Found";
        cout << '\n';
        // cout << "Nro Match: " << sum << '\n';
    }
    return 0;
}
