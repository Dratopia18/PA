Tema 2 PA
De Racolta Andrei-Vlad

In aceasta tema, am avut de rezolvat 3 probleme folosind algoritmi invatati in cadrul cursului de Proiectarea Algoritmilor.
Acum voi prezenta fiecare problema in parte si modul in care am rezolvat acele probleme.

Problema 1 - Numarare
In aceasta problema, am avut la dispozitie 2 grafuri cu un numar identic de noduri si muchii si am avut de numarat cate muchii 
comune au aceste 2 grafuri.
Am rezolvat problema in felul urmator: Am citit numarul de noduri si muchii din cele 2 grafuri, am declarat apoi cele doua
grafuri sub forma de matrice de adiacenta, doi vectori dp1 si dp2 ce retin rezultate intermediare, si un vector inDegree, ce 
retine numarul de muchii ce intra intr-un nod. Am citit apoi datele primului graf, x fiind
nodul de start si y nodul de destinatie, am pus pe pozitia x a grafului 1 valoarea y, semnificand ca exista o muchie de la x la 
y, si am incrementat inDegree-ul pe pozitia y. Am facut acelasi lucru si pentru al doilea graf, doar ca am folosit find pentru
a verifica daca exista deja muchia respectiva in primul graf. Daca da, atunci o pune in al doilea graf. Si de asemenea, nu avem 
nevoie de inDegree pentru al doilea graf. Acum, apelam functia de countCommonPaths, ce primeste ca parametrii cele 2 grafuri, 
vectorii de rezultate intermediare si inDegree-ul, si face urmatorele lucruri: face sortarea topologica a grafurilor folosind BFS
(Breadth First Search). Luam o coada si pentru nodurile 1 pana la N, verificam daca inDegree-ul este 0, daca da, il punem in 
coada. Acum, cat timp coada nu este goala, scoatem un nod din fata cozii, si incepem sa facem calculele. Pentru fiecare vecin din 
nodul primului graf, adunam pe vectorul dp1[vecin] valoarea dp1[nod], totul impartit cu MOD(1000000007), apoi decrementam 
inDegree-ul vecinului si daca acesta devine 0, il punem in coada. La al doilea graf, ne uitam la vecinii nodului din al doilea 
graf si adunam pe vectorul dp2[vecin] valoarea dp2[nod], totul impartit la MOD. La final, vom avea valoriile dp1[N] si dp2[N] ce 
reprezinta numarul de muchii din cele 2 grafuri. Acum, ca sa verific care din cele doua valori este cea cu numarul de muchii 
comune, am facut urmatoarea verificare. Daca dp1[N] e mai mic decat dp2[N], atunci setez rezultatul la minimul dintre cele 2 
valori, altfel (in cazul in care sunt egale in principal) setez rezultatul la maximul dintre cele 2 valori. Afisez la final 
rezultatul.
Complexitatea codului scris este O(N), unde N este numarul de noduri din grafuri.

Problema 2 - Trenuri
In aceasta problema, avem un graf cu orase, si, avand un oras de unde plecam si oras de destinatie, sa gasim ruta de tren
cu cele mai multe orase distincte vizitate.
Am rezolvat problema in felul urmator:
Mai intai, am citit orasul de unde plecam si orasul destinatie. Apoi, am citit numarul de rute, am declarat graful ca fiind un 
map ce retine numele orasului si un vector de stringuri ce retine orasele vecine, si un dp ce retine numele orasului si numarul de
orase vizitate din acel oras. Am citit apoi rutele, si am pus in graf orasele si vecinii lor. Am apelat apoi functia solve_dfs
ce primeste ca parametrii graful si orasul de start, si face urmatoarele lucruri: initiem o stiva ce contine o pereche de string 
si int, punem in stiva orasul de start si 0, si apoi cat timp stiva nu este goala, setam orasul curent si indexul curent la 
varful stivei, scoatem un element din stiva, verificam daca indexul meu este egal cu marimea grafului pe orasul curent, adica 
daca am vizitat toate orasele vecine, daca da, vom pune in setul res (variabila declarata in afara functilor, ce retine 
rezultatul) numele orasului si continuam. Daca nu, vom pune in stiva orasul curent si indexul adunat cu 1. Acum, se verifica
daca vecinul orasului curent nu a fost vizitat, daca nu, il punem in vectorul visited(ce retine orasele vizitate) si il inseram
pe stiva cu indexul 0. Ciclul se repeta pana cand stiva devine goala. Acum, in main, inversam setul res si pentru fiecare oras
din set, ii setam dp[oras] ca fiind INT_MIN. Setam dp[oras de start] la 0 si pentru fiecare oras din set, verificam daca dp[oras]
este diferit de INT_MIN, daca da, inseamna ca orasul a fost vizitat, si pentru fiecare oras vecin, setam dp[oras vecin] la maximul
dintre dp[oras vecin] si dp[oras] + 1. La final, afisam dp[oras destinatie].
Complexitatea codului scris este O(N), unde N este numarul de orase din graf.

Problema 3 - Drumuri
In aceasta problema, avem un graf cu N noduri si M muchii, si 3 noduri x, y si z. Trebuie sa gasim drumul cu costul minim de la x
la z si drumul cu costul minim de la y la z, astfel incat ambele drumuri sa ajunga la z.
Am rezolvat problema in felul urmator:
Am setat o structura de date Edge, unde am definit nodul destinatie si costul muchiei. Acum in main, am citit numarul de noduri
si muchii, am declarat doua grafuri, unul fiind graful initial, si unul fiind graful inversat, unde am inversat muchiile, si 3 
vectori long long, distFromX, distFromY si distToZ, ce retin distantele de la nodurile x, y si z. Apoi, pentru fiecare muchie, am 
citit nodul de start, nodul destinatie si costul muchiei(ca si long long), si am pus in grafurile initial si inversat muchia 
respectiva. Am citit apoi nodurile x, y si z. Apoi am apelat de 3 ori functia dijkstra, ce primeste ca parametrii nodul de start,
vectorul de distante si graful, si face urmatoarele lucruri: setam N ca fiind numarul de noduri din graf si se initiaza vectorul 
de distante cu LLONG_MAX. Apoi, declaram o coada de prioritati, ce va stoca perechi de distante si noduri, ce sunt ordonate dupa
distanta. Setam distanta de la nodul de start la el insusi ca fiind 0, si il punem in coada. Cat timp coada nu este goala, se 
extrage nodul si distanta acestuia din fata cozii, si il scoatem din coada. Acum, pentru fiecare muchie din nodul curent, extragem
nodul destinatie si costul muchiei, si verificam daca suma distantei de la nodul curent cu costul muchiei este mai mica decat 
distanta de la nodul destinatie, daca da, setam distanta de la nodul destinatie ca fiind suma respectiva si punem in coada nodul 
destinatie si distanta de la nodul destinatie. Asa cum ziceam, am apelat de 3 ori functia dijkstra: in primul apel, am setat 
nodul de start ca fiind x, vectorul de distante ca fiind distFromX si graful ca fiind graful initial, in al doilea apel, am setat 
nodul de start ca fiind y, vectorul de distante ca fiind distFromY si graful ca fiind graful initial, si in al treilea apel, am 
setat nodul de start ca fiind z, vectorul de distante ca fiind distToZ si graful ca fiind graful inversat. Setam costul minim ca 
fiind LLONG_MAX, si pentru fiecare nod din graf, verificam daca distFromX[nod], distFromY[nod] si distToZ[nod] sunt diferite de 
LLONG_MAX, daca da, setam costul minim ca fiind minimul dintre costul minim si suma celor 3 distante. La final, afisam costul 
minim.
Complexitatea codului scris este O((N+M)*log(N)), unde N este numarul de noduri, M este numarul de muchii din graf si log(N) este
complexitatea cozii de prioritati.
