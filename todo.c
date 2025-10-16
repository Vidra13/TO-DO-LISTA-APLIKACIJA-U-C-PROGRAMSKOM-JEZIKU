#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TASKS 100
#define MAX_LENGTH 256
#define FILE_NAME "tasks.txt"

// Struktura za zadatak
typedef struct {
    char description[MAX_LENGTH];
    int completed;
} Task;

// Globalne promenljive
Task tasks[MAX_TASKS];
int taskCount = 0;

// Deklaracije funkcija
void loadTasks();
void saveTasks();
void addTask();
void viewTasks();
void completeTask();
void deleteTask();
void clearScreen();
void showMenu();

int main() {
    int choice;
    
    loadTasks();
    
    while (1) {
        showMenu();
        printf("Izaberite opciju: ");
        scanf("%d", &choice);
        getchar(); // Čisti buffer
        
        switch (choice) {
            case 1:
                addTask();
                break;
            case 2:
                viewTasks();
                break;
            case 3:
                completeTask();
                break;
            case 4:
                deleteTask();
                break;
            case 5:
                saveTasks();
                printf("\nZadaci su sacuvani! Dovidjenja!\n");
                return 0;
            default:
                printf("\nNevalidna opcija! Pokusajte ponovo.\n");
        }
        
        printf("\nPritisnite Enter za nastavak...");
        getchar();
    }
    
    return 0;
}

// Funkcija za učitavanje zadataka iz fajla
void loadTasks() {
    FILE *file = fopen(FILE_NAME, "r");
    
    if (file == NULL) {
        printf("Fajl sa zadacima ne postoji. Kreirace se novi.\n");
        return;
    }
    
    taskCount = 0;
    while (fscanf(file, "%d\n", &tasks[taskCount].completed) == 1) {
        fgets(tasks[taskCount].description, MAX_LENGTH, file);
        tasks[taskCount].description[strcspn(tasks[taskCount].description, "\n")] = 0;
        taskCount++;
        
        if (taskCount >= MAX_TASKS) {
            break;
        }
    }
    
    fclose(file);
    printf("Ucitano %d zadataka.\n", taskCount);
}

// Funkcija za čuvanje zadataka u fajl
void saveTasks() {
    FILE *file = fopen(FILE_NAME, "w");
    
    if (file == NULL) {
        printf("Greska pri cuvanju fajla!\n");
        return;
    }
    
    for (int i = 0; i < taskCount; i++) {
        fprintf(file, "%d\n%s\n", tasks[i].completed, tasks[i].description);
    }
    
    fclose(file);
}

// Funkcija za dodavanje novog zadatka
void addTask() {
    if (taskCount >= MAX_TASKS) {
        printf("\nLista zadataka je puna!\n");
        return;
    }
    
    printf("\nUnesite opis zadatka: ");
    fgets(tasks[taskCount].description, MAX_LENGTH, stdin);
    tasks[taskCount].description[strcspn(tasks[taskCount].description, "\n")] = 0;
    
    tasks[taskCount].completed = 0;
    taskCount++;
    
    printf("\nZadatak je uspesno dodat!\n");
    saveTasks();
}

// Funkcija za prikaz svih zadataka
void viewTasks() {
    if (taskCount == 0) {
        printf("\nNema zadataka u listi!\n");
        return;
    }
    
    printf("\n========== LISTA ZADATAKA ==========\n\n");
    
    for (int i = 0; i < taskCount; i++) {
        printf("%d. [%c] %s\n", 
               i + 1, 
               tasks[i].completed ? 'X' : ' ', 
               tasks[i].description);
    }
    
    printf("\n====================================\n");
}

// Funkcija za označavanje zadatka kao završenog
void completeTask() {
    if (taskCount == 0) {
        printf("\nNema zadataka u listi!\n");
        return;
    }
    
    viewTasks();
    
    int taskNum;
    printf("\nUnesite broj zadatka koji ste zavrsili: ");
    scanf("%d", &taskNum);
    getchar();
    
    if (taskNum < 1 || taskNum > taskCount) {
        printf("\nNevalidan broj zadatka!\n");
        return;
    }
    
    tasks[taskNum - 1].completed = 1;
    printf("\nZadatak je oznacen kao zavrsen!\n");
    saveTasks();
}

// Funkcija za brisanje zadatka
void deleteTask() {
    if (taskCount == 0) {
        printf("\nNema zadataka u listi!\n");
        return;
    }
    
    viewTasks();
    
    int taskNum;
    printf("\nUnesite broj zadatka za brisanje: ");
    scanf("%d", &taskNum);
    getchar();
    
    if (taskNum < 1 || taskNum > taskCount) {
        printf("\nNevalidan broj zadatka!\n");
        return;
    }
    
    // Pomeranje zadataka
    for (int i = taskNum - 1; i < taskCount - 1; i++) {
        tasks[i] = tasks[i + 1];
    }
    
    taskCount--;
    printf("\nZadatak je uspesno obrisan!\n");
    saveTasks();
}

// Funkcija za prikazivanje menija
void showMenu() {
    printf("\n");
    printf("╔════════════════════════════════════╗\n");
    printf("║       TO-DO LISTA APLIKACIJA       ║\n");
    printf("╠════════════════════════════════════╣\n");
    printf("║  1. Dodaj novi zadatak             ║\n");
    printf("║  2. Prikazi sve zadatke            ║\n");
    printf("║  3. Oznaci zadatak kao zavrsen     ║\n");
    printf("║  4. Obrisi zadatak                 ║\n");
    printf("║  5. Sacuvaj i izadji               ║\n");
    printf("╚════════════════════════════════════╝\n");
    printf("\n");
}
