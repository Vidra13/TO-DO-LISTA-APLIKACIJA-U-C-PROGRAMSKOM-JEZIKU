# 📝 To-Do Lista - C Programski Jezik

## 📖 Opis projekta

Jednostavna konzolna aplikacija za upravljanje zadacima (to-do lista) napisana u **C programskom jeziku**. Aplikacija omogućava korisnicima da dodaju, pregledaju, označavaju kao završene i brišu zadatke, sa automatskim čuvanjem u fajl.

## ✨ Funkcionalnosti

- ✅ **Dodavanje novog zadatka** - Unos opisa novog zadatka
- 📋 **Prikaz svih zadataka** - Pregled cele liste sa statusom (završen/nezavršen)
- ✔️ **Označavanje zadatka kao završenog** - Praćenje napretka
- 🗑️ **Brisanje zadatka** - Uklanjanje nepotrebnih zadataka
- 💾 **Automatsko čuvanje** - Svi zadaci se čuvaju u `tasks.txt` fajl
- 🔄 **Učitavanje pri pokretanju** - Prethodni zadaci se automatski učitavaju

## 🛠️ Tehnologije

- Programski jezik: **C**
- Compiler: **GCC**
- Standard: **C11**

## 📦 Instalacija i pokretanje

### Kompajliranje programa

#### Opcija 1: Sa Makefile (Linux/Mac)
```bash
make
./todo
```

#### Opcija 2: Direktno kompajliranje
```bash
gcc todo.c -o todo
./todo
```

#### Opcija 3: Windows
```bash
gcc todo.c -o todo.exe
todo.exe
```

### Korišćenje Makefile komandi

```bash
make          # Kompajlira program
make run      # Kompajlira i pokreće program
make clean    # Briše kompajlirane fajlove
make help     # Prikazuje dostupne komande
```

## 🎮 Kako koristiti aplikaciju

1. **Pokrenite program** - `./todo`
2. **Izaberite opciju** iz menija (1-5)
3. **Pratite instrukcije** na ekranu
4. Zadaci se **automatski čuvaju** nakon svake izmene

### Primer korišćenja

```
╔════════════════════════════════════╗
║       TO-DO LISTA APLIKACIJA       ║
╠════════════════════════════════════╣
║  1. Dodaj novi zadatak             ║
║  2. Prikazi sve zadatke            ║
║  3. Oznaci zadatak kao zavrsen     ║
║  4. Obrisi zadatak                 ║
║  5. Sacuvaj i izadji               ║
╚════════════════════════════════════╝

Izaberite opciju: 1

Unesite opis zadatka: Kupiti mleko

Zadatak je uspesno dodat!
```

## 📂 Struktura projekta

```
todo-list-c/
│
├── todo.c              # Glavni izvorni kod
├── Makefile            # Automatizacija kompajliranja
├── README.md           # Dokumentacija projekta
├── .gitignore          # Git ignore fajl
└── tasks.txt           # Fajl sa zadacima (kreira se automatski)
```

## 🔧 Implementirane funkcije

### Glavne funkcije u kodu:

- `loadTasks()` - Učitava zadatke iz fajla pri pokretanju
- `saveTasks()` - Čuva zadatke u fajl
- `addTask()` - Dodaje novi zadatak u listu
- `viewTasks()` - Prikazuje sve zadatke sa statusom
- `completeTask()` - Označava zadatak kao završen
- `deleteTask()` - Briše zadatak iz liste
- `showMenu()` - Prikazuje glavni meni

### Korišćene strukture podataka:

```c
typedef struct {
    char description[MAX_LENGTH];
    int completed;
} Task;
```

## 📝 Git commit istorija

Projekat sadrži više commit-ova koji pokazuju proces razvoja:

1. **Inicijalna verzija** - Osnovne funkcionalnosti
2. **Dodato čuvanje u fajl** - Persistencija podataka
3. **Poboljšan korisnički interfejs** - Lepši meni
4. **Dodata funkcija za označavanje** - Praćenje završenih zadataka
5. **Finalna verzija** - Optimizacije i dokumentacija

## 🎓 Edukativni ciljevi

Ovaj projekat demonstrira:

- ✅ Rad sa strukturama podataka u C-u
- ✅ Upravljanje dinamičkim nizovima
- ✅ Fajl I/O operacije (čitanje/pisanje)
- ✅ Manipulacija stringovima
- ✅ Organizacija koda u funkcije
- ✅ Komentarisanje i dokumentovanje koda
- ✅ Korišćenje Git-a i GitHub-a
- ✅ Pisanje Makefile-a

## 👤 Autor

[Radivoj Vidric]
- GitHub: [@Vidra13](https://github.com/Vidra13)

## 📅 Datum kreiranja

Oktobar 2025

## 📄 Licenca

Ovaj projekat je kreiran u obrazovne svrhe.

---

**Napomena:** Projekat je rađen kao seminarski rad za predmet Sistemi za upravljanje dokumentima

