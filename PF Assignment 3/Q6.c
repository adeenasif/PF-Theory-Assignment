#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct equip{
    int operationalStatus;
    float fuelLevel;
    char activitySchedule[100];
};

struct sensor{
    float nutrientLevel;
    float PHlevel;
    int pestActivity;
};

struct weather{
	float temp;
	float rainfall;
	char windPatterns[50];	
};

struct crop{
	char cropType[50];
	int growthStage;
	float expectedYield;
	struct weather* forecast;
};

struct field{
	float GPSx, GPSy;
	int soilHealth;	
	int moisture;
    int numCrops, numEquipments, numSensors;
	struct crop* Crop;
    struct equip* Equip;
    struct sensor* Sensor;
};

struct AnalyticalServer{
    float expectedTotalYield;
    float irrigationEfficiency;
    float equipmentUtilization;
};

struct Hub{
    struct field* fieldInfo;
    int numFields;
    float yieldPrediction;
    char resourceDist[100];
    char emergencyPlan[100];
    struct AnalyticalServer* details;
};

int main() {
    int hubCount;
    int totalYield = 0;
    printf("Enter the number of hubs: ");
    scanf("%d", &hubCount);

    struct Hub* hubs = (struct Hub*)malloc(hubCount * sizeof(struct Hub));
    for (int k = 0; k < hubCount; k++) {
        printf("Enter the number of fields in this hub: ");
        scanf("%d", &hubs[k].numFields);
        
        // dynamically allocating memory for attributes of structure hub (that are field and analytics) 
        hubs[k].fieldInfo = (struct field*)malloc(hubs[k].numFields * sizeof(struct field));
        hubs[k].details = (struct AnalyticalServer*)malloc(sizeof(struct AnalyticalServer));
        
        // Loop thru fields
        for (int i = 0; i < hubs[k].numFields; i++){
            printf("\nENTER DATA FOR FIELD %d\n", i+1);

            printf("Enter GPS x coordinate: ");
            scanf("%f", &hubs[k].fieldInfo[i].GPSx);
            printf("Enter GPS y coordinate: ");
            scanf("%f", &hubs[k].fieldInfo[i].GPSy);
            printf("Enter soil health: ");
            scanf("%f", &hubs[k].fieldInfo[i].soilHealth);
            printf("Enter moisture: ");
            scanf("%f", &hubs[k].fieldInfo[i].moisture);
            
            printf("Enter the number of crops: ");
            scanf("%d", &hubs[k].fieldInfo[i].numCrops);
            hubs[k].fieldInfo[i].Crop = (struct crop*)malloc(hubs[k].fieldInfo[i].numCrops * sizeof(struct crop));
        
        // Loop thru crops
            for (int j = 0; j < hubs[k].fieldInfo[i].numCrops; j++){
                printf("Enter crop type: ");
                scanf("%s", hubs[k].fieldInfo[i].Crop[j].cropType);
                printf("Enter crop growth stage: ");
                scanf("%d", &hubs[k].fieldInfo[i].Crop[j].growthStage);
                printf("Enter expected yeild: ");
                scanf("%f", &hubs[k].fieldInfo[i].Crop[j].expectedYield);
                hubs[k].details->expectedTotalYield += hubs[k].fieldInfo[i].Crop[j].expectedYield;

                hubs[k].fieldInfo[i].Crop[j].forecast = (struct weather*)malloc(sizeof(struct weather));
                printf("Enter temperature forecast: ");
                scanf("%f", &hubs[k].fieldInfo[i].Crop[j].forecast->temp);
                printf("Enter rainfall forecast: ");
                scanf("%f", &hubs[k].fieldInfo[i].Crop[j].forecast->rainfall);
                printf("Enter wind patterns: ");
                scanf("%s", hubs[k].fieldInfo[i].Crop[j].forecast->windPatterns);
            }
            
            printf("Enter the number of equipments: ");
            scanf("%d", &hubs[k].fieldInfo[i].numEquipments);
            hubs[k].fieldInfo[i].Equip = (struct equip*)malloc(hubs[k].fieldInfo[i].numEquipments * sizeof(struct equip));

            // Loop thru equipments
            for(int j = 0; j < hubs[k].fieldInfo[i].numEquipments; j++){
                printf("Enter operational status (0/1): ");
                scanf("%d", &hubs[k].fieldInfo[i].Equip[j].operationalStatus);
                printf("Enter fuel level: ");
                scanf("%f", &hubs[k].fieldInfo[i].Equip[j].fuelLevel);
                printf("Enter activity schedule: ");
                scanf("%s", hubs[k].fieldInfo[i].Equip[j].activitySchedule);
            }

            printf("Enter the number of sensors: ");
            scanf("%d", &hubs[k].fieldInfo[i].numSensors);
            hubs[k].fieldInfo[i].Sensor = (struct sensor*)malloc(hubs[k].fieldInfo[i].numSensors * sizeof(struct sensor));
            
            // Loop thru sensors
            for (int j = 0; j < hubs[k].fieldInfo[i].numSensors; j++){
                printf("Enter nutrient level: ");
                scanf("%f", &hubs[k].fieldInfo[i].Sensor[j].nutrientLevel); 
                printf("Enter PH level: ");
                scanf("%f", &hubs[k].fieldInfo[i].Sensor[j].PHlevel); 
                printf("Enter pest activity: ");
                scanf("%d", &hubs[k].fieldInfo[i].Sensor[j].pestActivity); 
            }
        }

        // Placeholder for analytics
        hubs[k].details->irrigationEfficiency = 0; // Example calculation placeholder
        hubs[k].details->equipmentUtilization = 0; // Example calculation placeholder
        strcpy(hubs[k].resourceDist, "Default Resource Plan");
        strcpy(hubs[k].emergencyPlan, "Default Emergency Plan");
    }

    // Display data 
    printf("\n--- Displaying Hub Information ---\n");
    for (int h = 0; h < hubCount; h++) {
        printf("\nHub %d\n", h + 1);
        printf("  Resource Distribution: %s\n", hubs[h].resourceDist);
        printf("  Emergency Plan: %s\n", hubs[h].emergencyPlan);
        printf("  Total yield expected in this hub: %.2f\n\n", hubs[h].details->expectedTotalYield);

        // Display Field Information
        for(int j = 0; j < hubs[h].numFields; j++){
        printf("Field %d Information:\n\n", j+1);
            printf("  GPS Coordinates: (%.2f, %.2f)\n", hubs[h].fieldInfo[j].GPSx, hubs[h].fieldInfo[j].GPSy);
            printf("  Soil Health: %.2f\n", hubs[h].fieldInfo[j].soilHealth);
            printf("  Moisture Level: %.2f\n", hubs[h].fieldInfo[j].moisture);

            printf("\nCrops:\n");
            for (int i = 0; i < hubs[h].fieldInfo[j].numCrops; i++) {
                printf("  Crop %d: %s, Growth Stage: %d, Expected Yield: %.2f\n",
                i + 1, hubs[h].fieldInfo[j].Crop[i].cropType, hubs[h].fieldInfo[j].Crop[i].growthStage, hubs[h].fieldInfo[j].Crop[i].expectedYield);
            }

            printf("\nEquipment:\n");
            for (int i = 0; i < hubs[h].fieldInfo[j].numEquipments; i++) {
                printf("  Equipment %d: Operational Status: %d, Fuel Level: %.2f, Activity Schedule: %s\n",
                    i + 1, hubs[h].fieldInfo[j].Equip[i].operationalStatus, hubs[h].fieldInfo[j].Equip[i].fuelLevel,
                    hubs[h].fieldInfo[j].Equip[i].activitySchedule);
            }

            printf("\nSensors:\n");
            for (int i = 0; i < hubs[h].fieldInfo[j].numSensors; i++) {
                printf("  Sensor %d: Nutrient Level: %.2f, PH Level: %.2f, Pest Activity: %d\n",
                    i + 1, hubs[h].fieldInfo[j].Sensor[i].nutrientLevel, hubs[h].fieldInfo[j].Sensor[i].PHlevel, hubs[h].fieldInfo[j].Sensor[i].pestActivity);
            }
        }
    }
 
    // Free allocated memory
    for (int h = 0; h < hubCount; h++) {
        for (int f = 0; f < hubs[h].numFields; f++) {
            for (int c = 0; c < hubs[h].fieldInfo[f].numCrops; c++) {
                free(hubs[h].fieldInfo[f].Crop[c].forecast);
            }
            free(hubs[h].fieldInfo[f].Crop);
            free(hubs[h].fieldInfo[f].Equip);
            free(hubs[h].fieldInfo[f].Sensor);
        }
        free(hubs[h].fieldInfo);
        free(hubs[h].details);
    }
    free(hubs);

    return 0;
}