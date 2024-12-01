#include<stdio.h>
#include<stdlib.h>
#include<string.h>


char** initializeInventory(int numSpecies){
	char** speciesSupplies = (char**)malloc(numSpecies * sizeof(char*));
    if (!speciesSupplies) {
        printf("Memory allocation failed for species array.\n");
        exit(1);
    }
    for (int i = 0; i < numSpecies; i++) {
        speciesSupplies[i] = NULL; // empty initialization 
    }
    return speciesSupplies;
}


int addSupplies(char** speciesSupplies, int speciesIndex, int numSupplies){
    if (speciesSupplies[speciesIndex] != NULL) {
        free(speciesSupplies[speciesIndex]); // Free existing supplies (if any)
    }
    speciesSupplies[speciesIndex] = (char*)malloc(numSupplies * 100 * sizeof(char));
    if (!speciesSupplies[speciesIndex]) {
        printf("Memory allocation failed for supplies.\n");
        return 1;
    }

    for (int i = 0; i < numSupplies; i++) {
        printf("Enter supply %d for species %d: ", i + 1, speciesIndex);  //user-input the supplies for each species
        scanf("%s", &speciesSupplies[speciesIndex][i * 100]);
    }
	return 0;
}

// updates the suply for the given species
void updateSupply(char** speciesSupplies, int speciesIndex, int supplyIndex, const char* newSupply) {
    if (speciesSupplies[speciesIndex]) {
        strcpy(&speciesSupplies[speciesIndex][supplyIndex * 100], newSupply);
        printf("Supply updated successfully.\n");
    } else {
        printf("No supplies found for this species.\n");
    }
}

// Function to remove a species
void removeSpecies(char*** speciesSupplies, int* numSpecies, int speciesIndex) {
    if ((*speciesSupplies)[speciesIndex]) {
        free((*speciesSupplies)[speciesIndex]); // Free the supplies
    }
    for (int i = speciesIndex; i < *numSpecies - 1; i++) {
        (*speciesSupplies)[i] = (*speciesSupplies)[i + 1];  // Shift rows up
    }
    (*speciesSupplies) = realloc((*speciesSupplies), (*numSpecies - 1) * sizeof(char*)); //reallocate the memory by reducing 1
    if (!(*speciesSupplies) && (*numSpecies - 1) > 0) {
        printf("Memory reallocation failed after removing species.\n");
        exit(1);
    }
    (*numSpecies)--;
    printf("Species removed successfully.\n");
}

void displayInventory(char **speciesSupplies, int numSpecies){
// display the inventory (all the supplies for all the species)
    printf("--- Inventory ----\n");
 	for (int i = 0; i < numSpecies; i++) {
        printf("Species %d:\n", i + 1);
        if (speciesSupplies[i]) {
            for (int j = 0; j < numSpecies; j++) {
                printf("  - %s\n", &speciesSupplies[i][j * 100]);
            }
        } else {
            printf("  No supplies available.\n");
        }
    }
}

// Function to free the inventory
void freeInventory(char** speciesSupplies, int numSpecies) {
    for (int i = 0; i < numSpecies; i++) {
        free(speciesSupplies[i]);
    }
    free(speciesSupplies);
}

int main() {
    int numSpecies;
    printf("Enter the number of species: ");
    scanf("%d", &numSpecies);
    
    // Initialize inventory
    char** speciesSupplies = initializeInventory(numSpecies);
    int choice, speciesIndex, supplyIndex;
    char newSupply[100];

    while (1) {
        printf("\nMenu:\n");
        printf("1. Add Supplies\n");
        printf("2. Update Supply\n");
        printf("3. Remove Species\n");
        printf("4. Display Inventory\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the species index (0-%d): ", numSpecies - 1);
                scanf("%d", &speciesIndex);
                if (speciesIndex >= 0 && speciesIndex < numSpecies) {
                    int numSupplies;
                    printf("Enter the number of supplies for species %d: ", speciesIndex);
                    scanf("%d", &numSupplies);
                    addSupplies(speciesSupplies, speciesIndex, numSupplies);
                } else {
                    printf("Invalid species index.\n");
                }
                break;

            case 2:
                printf("Enter the species index (0-%d): ", numSpecies - 1);
                scanf("%d", &speciesIndex);
                if (speciesIndex >= 0 && speciesIndex < numSpecies) {
                    printf("Enter the supply index(0-%d): ", supplyIndex-1);
                    scanf("%d", &supplyIndex);
                    printf("Enter the new supply name: ");
                    scanf("%s", newSupply);
                    updateSupply(speciesSupplies, speciesIndex, supplyIndex, newSupply);
                } else {
                    printf("Invalid species index.\n");
                }
                break;

            case 3:
                printf("Enter the species index (0-%d) to remove: ", numSpecies - 1);
                scanf("%d", &speciesIndex);
                if (speciesIndex >= 0 && speciesIndex < numSpecies) {
                    removeSpecies(&speciesSupplies, &numSpecies, speciesIndex);
                } else {
                    printf("Invalid species index.\n");
                }
                break;

            case 4:
                displayInventory(speciesSupplies, numSpecies);
                break;

            case 5:
                freeInventory(speciesSupplies, numSpecies);
                return 0;

            default:
                printf("Invalid choice.\n");
        }
    }
}
