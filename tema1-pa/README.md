Tema 1 - Tehnici de programare
De Racolta Andrei-Vlad 325CD

In aceasta tema, am avut de rezolvat 4 probleme + 1 bonus folosind algoritmi invatati
in cadrul materiei Proiectarea Algoritmilor.

Acum voi prezenta fiecare problema in parte si modul in care am rezolvat-o.

Problema 1 - Servere

In aceasta problema, am avut de calculat puterea de calcul maxima a unui sistem
de servere, stiind ca clusterul dat va fi limitat la cea mai mica putere individuala.
Am rezolvat aceasta problema in felul urmator:
Am citit datele de intrare: numarul de servere, puterea de calcul a fiecarui server si
cantitatea de curent ce alimenteaza fiecare server. Apoi, cautam curentul optim pentru
toate serverele, folosind o cautare binara, un algoritm de tip Divide et Impera, care
ia stanga ca fiind curentul minim din tot setul de servere(folosind functia curent_min)
si dreapta ca fiind curentul maxim din tot setul de servere(folosind functia curent_max).
Apoi, cat timp diferenta dintre dreapta si stanga este mai mare decat 1e-3(0.001), setam
mijlocul ca fiind media dintre stanga si dreapta si verificam daca puterea minima din
mijloc - 0.001 este mai mare sau egal decat puterea minima din mijloc. Daca da, setam
dreapta ca fiind mijlocul, altfel setam stanga ca fiind mijlocul. La final, calculam
mijlocul din nou, cu valorile noi ale lui stanga si dreapta si returnam mijlocul. Puterea
minima este calculata folosind functia calcul_putere_minima. Aceasta ia initial o putere
minima standard, care are formula: prima putere din setul de servere - |curentul optim -
prima cantitate de curent ce alimenteaza primul server|. Apoi, pentru fiecare server, se
calculeaza puterea serverului folosind formula de mai sus, si folosind functia min, se
retine puterea minima dintre puterea serverului si puterea minima standard. La final,
se returneaza puterea minima. In main, odata ce am facut rost de curentul optim, am
apelat functia calcul_putere_minima, pentru a afla puterea intregului sistem de servere.
Odata ce am obtinut puterea, afisam cu setprecision(1) puterea obtinuta.
Complexitatea algoritmului este O(nlog(n)), unde n este numarul de servere si log(n) provine
de la cautarea binara.

Problema 2 - Colorare

In aceasta problema, avand un tablou dat, trebuie sa aflam numarul de moduri in care
putem colora tabloul, stiind ca putem folosi 3 culori pentru a colora fiecare dreptunghi
din tablou. De asemenea, daca avem 2 dreptunghiuri care au o latura comuna, acestea nu
pot fi colorate cu aceeasi culoare. Am rezolvat aceasta problema in felul urmator:
Am citit datele de intrare: numarul de perechi ce le va citi si perechile in sine, formate
din 2 variabile: un numar, ce reprezinta numarul de dreptunghiuri din tablou si un caracter,
care poate fi de 2 tipuri: 'V', pentru care se va pune un dreptunghi vertical si 'H', pentru
care se vor pune 2 dreptunghiuri orizontale. Declaram o valoare de tip long long, numita
result, unde apelam functia calculeazaModuriColorare, ce ia ca parametrii numarul de perechi
si perechile in sine. In functia calculeazaModuriColorare, am declarat un parametru de tip
long long, numit totalModuri, ce va retine numarul total de moduri in care putem colora
tabloul dat. Apoi, luam fiecare pereche in parte si facem in felul urmator: in cazul in care
ne aflam la prima pereche, daca caracterul este 'V', atunci totalModuri va fi inmultit cu
(3 * 2 ^ (numarul de dreptunghiuri - 1)) % MOD(care este 1000000007), altfel, daca caracterul
este 'H', totalModuri va fi inmultit cu (2 * 3 ^ (numarul de dreptunghiuri)) % MOD. Inainte de a
continua, pentru a calcula puterea, in loc sa folosesc functia pow, ce nu e cea mai eficienta
functie, am folosit functia log_pow, ce primeste 2 parametrii: baza si exponentul si returneaza
rezultatul bazei la puterea exponentului impartit la MOD. Apoi, pentru fiecare pereche in parte,
trebuie sa verificam in felul urmator: daca caracterul curent este 'H' si caracterul precedent 
este tot 'H', atunci totalModuri va fi inmultit cu 3 ^ (numarul de dreptunghiuri) % MOD, daca 
caracterul curent este 'H' si caracterul precedent este 'V', atunci totalModuri va fi inmultit cu
2 ^ (3 * (numarul de dreptunghiuri - 1)) % MOD, daca caracterul curent este 'V' si caracterul
precedent este 'V', atunci totalModuri va fi inmultit cu 2 ^ (numarul de dreptunghiuri) % MOD, iar
daca caracterul curent este 'V' si caracterul precedent este 'H', atunci totalModuri va fi inmultit
cu 2 ^ (numarul de dreptunghiuri - 1) % MOD. La final, returnam totalModuri. In main, odata ce 
am facut rost de totalModuri, afisam rezultatul obtinut.
Complexitatea algoritmului este O(n), unde n este numarul de perechi.

Problema 3 - Compresie

In aceasta problema, avem doua siruri de numere, din care trebuie sa verificam daca
putem obtine doua siruri identice, folosind 0 sau mai multe operatii de compresie
(un exemplu ar fi daca avem sirul [1, 2, 3, 4, 5] si alegem sa comprimam 2, 3 si 4, vom avea [1, 9, 5]),
si daca da, sa afisam lungimea maxima al acelui sir. Am rezolvat aceasta problema in felul urmator: 
Am citit datele de intrare: numarul de elemente din primul sir, elementele din primul sir, numarul
de elemente din al doilea sir si elementele din al doilea sir. In timpul citirii elementelor din
cele 2 siruri, am retinut suma fiecarui sir, pentru a verifica la final daca acestea sunt egale. 
Apoi, am declarat un i, j, count, ce va retine lungimea maxima a sirului, si sumele pentru comprimarea
celor 2 siruri. Dupa aceea, am verificat in felul urmator: cat timp i e mai mic sau egal decat numarul
de elemente din primul sir si j e mai mic sau egal decat numarul de elemente din al doilea sir, daca
cele 2 sume sunt egale si diferite de 0, atunci count va fi incrementat cu 1, cele 2 sume vor fi
resetate la 0 si mergem mai departe. Altfel, daca suma primului sir e mai mica decat suma celui de-al
doilea sir, atunci suma primului sir va fi incrementata cu elementul de pe pozitia i din primul sir si
mergem mai departe, altfel, daca suma celui de-al doilea sir e mai mica decat suma primului sir, atunci
suma celui de-al doilea sir va fi incrementata cu elementul de pe pozitia j din al doilea sir si mergem
mai departe. La final, daca suma primului sir e egala cu suma celui de-al doilea sir, atunci returnam
count, altfel, returnam -1.
Complexitatea algoritmului este O(n + m), unde n este numarul de elemente din primul sir si m este numarul
de elemente din al doilea sir.

Problema 4 - Criptare

In aceasta problema, avem un numar n de cuvinte, ce trebuie concatenate intr-o parola, iar fiecare parola
trebuie sa aiba o litera dominanta. Noi trebuie sa gasim cea mai lunga parola ce respecta aceasta regula.
Am rezolvat aceasta problema in felul urmator:
Am citit datele de intrare: numarul de cuvinte si cuvintele in sine. In timpul citirii fiecarui cuvant,
vom pune fiecare litera distincta intr-un set de caractere. Apoi, am declarat un unordered_map, literaStats, 
ce va retine caracterul distinct si o pereche de valori, ce ea in sine va mai contine o pereche de valori, 
ce retine numarul de aparitii ale caracterului si numarul de litere ce apar in cuvantul respectiv, si un double, 
ce va retine un raport intre numarul de aparitii al caracterului si numarul de litere ce apar in cuvantul respectiv.
Am declarat si un maxPereche, ce va retine perechea cu cea mai lunga parola. Acum pentru fiecare litera 
distincta, vom face in felul urmator: pentru fiecare cuvant, vom avea un contor, ce va retine numarul de
aparitii ale caracterului in cuvantul respectiv, un raport, ce este raportul dintre numarul de aparitii al
caracterului si numarul de litere ce apar in cuvantul respectiv, iar apoi bagam aceste 2 valori in literaStats
cu tot cu lungimea cuvantului dat. Va arata ceva de forma ((contor, lungimea cuvantului), raport). Odata ce am
terminat de calculat aceste valori pentru fiecare cuvant, le vom sorta in ordine descrescatoare, dupa raport,
folosind functia de compare. Dupa acea, declaram un i cu 0 si un j cu 1, ce vor retine pozitiile primelor 2
perechi din literaStats, si un countdown, ce este numarul total de perechi de parcurs. Dupa aceea, vom face in
felul urmator: cat timp countdown e mai mare decat 0, vom apela functia procesPerechi, ce va lua ca parametrii
literaStats, caracterul distinct curent, i si j. In functia procesPerechi, vom crea 2 perechi de valori, ce vor
lua ca valoare prima si a doua pereche din literaStats, si le vom retine ca pair1 si pair2. Acum, daca
suma dintre numarul de aparitii al caracterului distinct curent din pair1 si pair2 este mai mare decat
suma dintre numarul de litere ce apar in cuvantul respectiv din pair1 si pair2 impartit la 2
(adica ceva de forma (x1 + x2) > (y1 + y2) / 2), atunci vom crea acea pereche de valori, ce va retine
sumele descrise mai sus, eliminam primele 2 perechi din literaStats si adaugam acea pereche de valori la
inceputul lui literaStats si mergem mai departe. Daca nu, stergem perechea de pe pozitia j si mergem mai departe.
In timp ce procesam perechile, daca numarul de aparitii al literei distincte ce apar in cuvantul respectiv 
din perechea nou creata este mai mare sau egala decat cea din maxPereche si numarul de litere ce apar in cuvantul
respectiv din perechea nou creata este mai mare decat lungimea maxPereche, atunci maxPereche va fi perechea nou creata.
Vom decrementa countdown. Cand countdown va fi 0, vom afisa lungimea maxima a parolei.
Complexitatea algoritmului este O(n * m * log(m)), unde n este numarul de cuvinte, m este numarul de litere distincte
si log(m) provine de la sortarea perechilor de valori dupa raport.

Problema 5 - Oferta

In aceasta problema, avem un numar de n produse, fiecare cu un pret. Noi trebuie sa aflam pretul minim
pe care il putem obtine prin gruparea produselor de pe banda. Gruparile au 2 reguli: 1. daca grupam
2 produse, atunci primim 50% reducere la cel mai ieftin produs din grup; 2. daca grupam 3 produse, 
atunci primim cel mai ieftin produs din grup gratis. Am rezolvat aceasta problema in felul urmator:
Am citit datele de intrare: numarul de produse, un K, ce va fi setat la 1 si preturile produselor.
Vom declara un vector dp de tip double, ce primeste N + 1 elemente, unde N este numarul de produse si
vom seta primul element din dp la 0. Apoi, pentru fiecare produs (de la 1 la N inclusiv), setam dp
ca fiind pretul produsului curent (adica i - 1). Daca i e mai mare sau egal cu 2, atunci vom face
rost de produsul redus, adica minimul din cele 2 produse grupate impartit la 2, si vom seta dp[i] ca
fiind minimul dintre dp[i] si dp[i - 2] + cele doua preturi de la produsele grupate - produsul redus.
Daca i este mai mare sau egal cu 3, atunci facem rost de produsul cel mai ieftin din grupul de 3
produse, folosind min, si setam dp[i] ca fiind minimul dintre dp[i] si dp[i - 3] + cele 3 preturi
de la produsele grupate - produsul cel mai ieftin din grup. La final, daca K e 1, atunci afisam
dp[N], altfel, afisam -1.
Complexitatea algoritmului este O(n), unde n este numarul de produse.