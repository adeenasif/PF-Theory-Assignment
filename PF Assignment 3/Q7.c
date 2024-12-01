#include <stdio.h>
#include <stdlib.h>

struct contentMetadata {
    char title[50];
    float rating;
    int runtime;
};

// Function to display predefined metadata
void displayMetadata() {
    printf("\n--- Content Metadata ---\n");

    // Fixed metadata for categories and content
    struct contentMetadata categories[3][3] = {
        {{"Horror1", 3.5, 150}, {"Horror2", 4.2, 100}, {"Horror3", 2.8, 90}},
        {{"Crime1", 4.7, 140}, {"Crime2", 4.0, 120}, {"Crime3", 4.9, 150}},
        {{"Comedy1", 5.0, 130}, {"Comedy2", 4.7, 135}, {"Comedy3", 3.6, 100}}
    };

    for (int i = 0; i < 3; i++) {
        printf("\nCategory %d:\n", i + 1);
        for (int j = 0; j < 3; j++) {
            printf("Title: %s | Rating: %.1f | Runtime: %d mins\n", 
                categories[i][j].title, categories[i][j].rating, categories[i][j].runtime);
        }
    }
}

// input device preferences and engagement scores
void inputUserData(int userID, int numCategories, int numDevices) {
    printf("\n--- Input Data for User %d ---\n", userID);

    // Device preferences
    int resolution[numDevices];
    float bandwidth[numDevices];
    for (int i = 0; i < numDevices; i++) {
        printf("Enter resolution for device %d (e.g., 1080): ", i + 1);
        scanf("%d", &resolution[i]);
        printf("Enter bandwidth usage for device %d (Mbps): ", i + 1);
        scanf("%f", &bandwidth[i]);
    }

    // Engagement scores
    float engagementScores[numCategories];
    printf("Enter engagement scores for user %d (0–100) for each category:\n", userID);
    for (int i = 0; i < numCategories; i++) {
        printf("Category %d: ", i + 1);
        scanf("%f", &engagementScores[i]);
    }

    // Display device preferences
    printf("\n--- Device Preferences for User %d ---\n", userID);
    for (int i = 0; i < numDevices; i++) {
        printf("Device %d | Resolution: %dp | Bandwidth Usage: %.2f Mbps\n", 
               i + 1, resolution[i], bandwidth[i]);
    }

    // Display engagement scores
    printf("\n--- Engagement Scores for User %d ---\n", userID);
    for (int i = 0; i < numCategories; i++) {
        printf("Category %d: %.2f%%\n", i + 1, engagementScores[i]);
    }
}

int main() {
    int numUsers, numCategories = 3, numDevices = 2;

    printf("Enter the number of users: ");
    scanf("%d", &numUsers);

    // Display metadata
    displayMetadata();

    // Input and display data for each user
    for (int i = 0; i < numUsers; i++) {
        inputUserData(i + 1, numCategories, numDevices);
    }

    return 0;
}
