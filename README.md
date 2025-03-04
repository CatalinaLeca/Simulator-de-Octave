# **Simulator de Octave**
Autor: **Maria-Catalina Leca - 315CA**  
Copyright © 2023-2024  
Materia: **Programarea Calculatoarelor și Limbaje de Programare 1**  
Tema 3 - **Simulator de Octave în C**  

---

## 📖 **Descrierea Proiectului**
Acest proiect implementează un **simulator de manipulare a matricelor**, inspirat de GNU Octave, folosind limbajul C. Programul permite încărcarea, modificarea și efectuarea operațiilor matematice pe matrice, respectând restricțiile impuse de enunț.

Simulatorul este capabil să gestioneze multiple matrice simultan, utilizând alocare dinamică și tehnici eficiente de realocare. Comenzile sunt introduse prin intermediul liniei de comandă, fiecare având un format bine definit.

---

## ⚙️ **Funcționalități principale**
Programul implementează următoarele comenzi pentru gestionarea matricelor:

### 🔹 **Gestionarea matricelor**
- `L m n` → Încarcă o matrice de dimensiune `m × n` cu valori întregi.
- `D index` → Afișează dimensiunile matricei de la poziția `index`.
- `P index` → Afișează matricea de la poziția `index`.
- `F index` → Șterge matricea de la poziția `index`.

### 🔹 **Modificarea matricelor**
- `C index l <linii> c <coloane>` → Redimensionează matricea la un subset specific.
- `T index` → Transpune matricea.

### 🔹 **Operații matematice pe matrice**
- `M index1 index2` → Înmulțește matricea `index1` cu `index2` și stochează rezultatul.
- `R index putere` → Ridică matricea `index` la `putere`, utilizând exponentiere logaritmică.
- `S index1 index2` → Înmulțește două matrice folosind algoritmul lui Strassen.

### 🔹 **Sortare și gestionare memorie**
- `O` → Sortează matricile în funcție de suma elementelor.
- `Q` → Eliberează toate resursele și închide programul.

---

## 🛠️ **Descrierea implementării**
### 🔹 **Structura proiectului**
Fiecare fișier `.c` conține funcțiile principale pentru fiecare operație asupra matricelor. Programul lucrează cu:
- **O listă de matrici** → conținând datele fiecărei matrice.
- **O listă de vectori** → reținând dimensiunile fiecărei matrice.

---

### 🔹 **Detalii implementare**
#### 🏗️ **Crearea și gestionarea matricelor (`L, D, P`)**
- Funcțiile dedicate alocă dinamic memoria necesară fiecărei matrici și listei de dimensiuni.
- O funcție de realocare dublă dimensiunea listelor când spațiul se epuizează.

#### ✂️ **Redimensionare (`C`)**
- Se creează o matrice nouă cu dimensiunile dorite.
- Se copiază datele relevante, iar memoria inițială este eliberată.

#### ✖️ **Înmulțirea matricelor (`M, S`)**
- **Pentru înmulțirea clasică** → se folosește algoritmul standard de produs matricial.
- **Pentru algoritmul lui Strassen** → se împart matricile în submatrici și se calculează recursiv rezultatul.

#### 📐 **Transpunere (`T`)**
- Se creează o matrice nouă cu dimensiunile inversate.
- Valorile sunt copiate corespunzător, iar memoria veche este eliberată.

#### 🔢 **Ridicarea la putere (`R`)**
- Implementare eficientă folosind **exponentiere binară** pentru complexitate `O(log n)`.
- Se gestionează separat cazurile pentru puterea `0` (matrice identitate) și `1` (matricea originală).

#### 📊 **Sortare (`O`)**
- Se calculează suma fiecărei matrice.
- Se sortează matricele crescător, păstrând ordinea corespunzătoare în listă.

#### 🗑️ **Ștergere și eliberare memorie (`F, Q`)**
- Matricea de la un anumit index este eliminată și lista este ajustată corespunzător.
- `Q` eliberează toată memoria și închide programul.

---

## 🏁 **Exemplu de utilizare**
```bash
> L 4 4
> P 0
  1 2 3 4
  5 6 7 8
  9 10 11 12
  13 14 15 16

> T 0
> P 0
  1 5 9 13
  2 6 10 14
  3 7 11 15
  4 8 12 16

> M 0 0
> P 1
  90 100 110 120
  202 228 254 280
  314 356 398 440
  426 484 542 600

> R 1 2
> P 1
  46820 53400 59980 66560
  94100 107352 120604 133856
  141380 161304 181228 201152
  188660 215256 241852 268448

> F 1
> Q
```

---

## 🎯 **Concluzie**
Simulatorul de Octave implementează operații esențiale asupra matricelor, folosind alocare dinamică eficientă și algoritmi optimi pentru fiecare operație. Funcțiile sunt modularizate, iar programul respectă cerințele temei, oferind o gestionare robustă a memoriei și a resurselor.

🚀 **Proiect realizat cu pasiune pentru Programarea Calculatoarelor!** 🚀