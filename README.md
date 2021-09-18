# perpetuum_spring_2021

### Making of :

## ȘTO - personal drinking assistant

### Scurta descriere : 
Șto este un dispenser de lichide inteligent, actionat prin comanda vocala, inspirat de personajul cu acelasi nume din serialul animat "RObotzii".

<img src="https://github.com/cmarius46/Ciurea_Marius-Gabriel_perpetuum_2021/blob/main/media/implementare/23_friendly.jpeg" width="400" height="500">


### Functionalitati : 
**Comanda vocala** - de pe telefon, transmisa prin bluetooth la placuta Arduino

**Interfata media** - redare sunet (voce + muzica) de pe un card de memorie, precum si actionarea de led-uri prezente pe panoul frontal

**Dispenser lichide** - prin actionarea a doua servo-uri, ce deschid / inchid doua robinete, robotul ofera posibilitatea de a servi oricare dintre cele doua bauturi, precum si o combinatie dintre acestea

**Deplasare - incomplet**, din lipsa de element de actionare corespunzator (robotul dispune de un servo motor avand ca scop schimbarea directiei de deplasare; in cod sunt recunoscute comenzile aferente deplasarii si pe placuta de dezvoltare exista slot-uri pastrate special pentru comanda unui motor; exista o sursa de alimentare competenta; lipseste doar motorul care trebuie atasat la rotile din spate)


### Componente folosite :

Placuta de dezvoltare Arduino UNO R3
 
3x Metal gear Servo motor MG996r

Acumulator LiPo Gens Ace Bashing, 3S1P, 11.1V, 5000mAh 

Mini Breadboard

Modul Bluetooth Master Slave HC-05

Modul Slot Card Compatibil cu MicroSD

Card MicroSD

Difuzor simplu

Fire (multe), rezistente, LED-uri, tranzistor NPN (pentru amplificarea sunetului)


### Workflow :

- Utilizatorul da comanda prin intermediul aplicatiei de telefon

- In functie de cuvantul-cheie detectat, o comanda codificata este trimisa prin Bluetooth catre placuta de dezvoltare

- Robotul executa actiunile aferente comenzii primite


### Probleme intalnite :

**1. Echilibru :** Robotul original se echilibreaza pe o singura roata, lucru relativ greu de reprodus avand resurse limitate la dispozitie.

**1. Solutie :** Doua suporturi pe mai multe roti, care asigura echilibrul si permite deplasarea usoara, pastrand pe cat posibil aspectul initial.

<img src="https://github.com/cmarius46/Ciurea_Marius-Gabriel_perpetuum_2021/blob/main/media/implementare/9_main_frame_base_and_bottom.jpeg" width="160" height="200">

**2. Greutate :** Planul initial cuprindea patru robinete si surse de lichide (inspirat din functionalitatea aparatului "Armageddon" al departamentului de logistica al LSAC), dar acest lucru presupunea o greutate foarte mare, precum si diferite complicatii legate de design si cresterea dimensiunii robotului.

**2. Solutie :** Reducerea surselor de lichide la doua, in loc de patru, precum si realizarea unei structuri de rezistenta din lemn.

**3. Alimentare :** Servo-urile micro nu sunt suficiente pentru a actiona un robinet, deci am avut nevoie de servo-uri mai puternice, necesitand o sursa de alimentare superioara.

**3. Solutie :** Folosirea unei baterii LiPo de 5000mAh, pentru a asigura un curent suficient.

**4. Etanseizare :** In cadrul testelor initiale pentru trecerea apei prin sistem, am constatat picurare prin diferite locuri. Ideea robotului implica substante inflamabile (alcool), precum si circuite aflate in proximitatea acestora, ce ar putea produce scantei.

**4. Solutie :**

- soft - Etanseizarea, pe cat posibil, a sistemului de curgere a lichidelor.

- hard - Mutarea circuitului electric DEASUPRA sistemului de curgere, pentru a evita orice contact intre o posibila picatura de substanta inflamabila si circuitul electric.

- hard - Asigurarea a doua moduri usorare, independente, de decuplare a bateriei de la circuit, in caz de urgenta (un switch pentru cazuri usoare si un cleste pentru decuplarea GND, in cazuri extreme).  


<img src="https://github.com/cmarius46/Ciurea_Marius-Gabriel_perpetuum_2021/blob/main/media/implementare/25_safety_first.jpeg" width="160" height="200">


**5. Debugging :** Pentru a oferi posibilitatea de a imbunatati / modifica robotul, precum si pentru usurinta rezolvarii problemelor de hardware ce pot aparea (ex. intreruperea circuitului), componentele trebuie sa fie cat mai accesibile.

**5. Solutie :** Acest lucru a fost rezolvat de la sine prin mutarea circuitului in partea superioara a robotului.


**6. Dam foc la camin :** In timpul testarii circuitului dupa montarea pe schelet, am scurtcircuitat neintentionat bateria de 12V. Fiind un scurtcircuit direct (nu trecea prin switch-ul de intrerupere), nu am putut sa il opresc decat dupa actionarea clestelui de decuplare a GND-ului. In acest timp (2-3 secunde), firele prinse in scurtcircuit s-au topit, lipindu-se de cartonul folosit drept suport. Daca nu ar fi existat posibilitatea decuplarii directe a bateriei, ar fi trebuit sa sacrific proiectul pentru a preveni declansarea unui foc.

**6. Solutie :** Intotdeauna, inafara folosirii, bateria sta decuplata si robotul sta la distanta de orice sursa de lichid inflamabil, oricat de sete i-ar fi. 

<img src="https://github.com/cmarius46/Ciurea_Marius-Gabriel_perpetuum_2021/blob/main/media/implementare/22_scurt_la_12V.jpeg" width="240" height="300">

### Mentiuni :

- Robotul este inspirat de personajul cu acelasi nume, aparut in serialul animat "RObotzii" - link episod : https://www.youtube.com/watch?v=gpKf4iLZo7Y . Pentru o mai buna intelegere a asemanarilor, recomand vizionarea acestuia in prealabil (Atentie, limbaj licentios !).
- Evolutia in timp a proiectului se poate urmari pe fisierul README.md din directorul "media".
- Dupa finalizarea competitiei voi continua sa lucrez la Șto, atasandu-i un motor corespunzator pentru a completa functionalitatea de deplasare.
- Initial am vrut sa-mi dezvolt propria aplicatie pentru a realiza partea de speech-to-text si de a transmite datele catre placuta Arduino, prima parte a acestei aplicatii fiind prezenta in fisierul "code_v1" al acestui repo. In urma descoperirii unei aplicatii ce avea aceste functionalitati deja implementate (Arduino BlueControl by BroXcode), am ales folosirea acesteia pentru a economisi timp.
- Codul folosit in realizarea proiectului se gaseste in directorul "sto_ino/sto_final/sto_final.ino".
- Fisierele audio pe care le reda robotul sunt stocate in directorul "media/audio".
- Videoclipul de prezentare se gaseste in directorul "media/videoclip_prezentare (intrucat difuzorul de pe robot nu este foarte puternic, ar fi de preferat ca videoclipul de prezentare sa fie urmarit la volum cat mai mare, pentru a se auzi cat mai bine sunetele). 
- Diagrama Gantt se afla in directorul "media/diagrama \Gantt" al acestui repo.



<img src="https://github.com/cmarius46/Ciurea_Marius-Gabriel_perpetuum_2021/blob/main/media/implementare/26_sto.jfif" width="240" height="240">
