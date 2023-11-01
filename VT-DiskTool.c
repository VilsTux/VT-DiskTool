#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void createGPT(char* blockDevice) {
    // Initialisiere das Blockgerät mit gdisk und erstelle eine GPT
    printf("Initialisiere das Blockgerät mit gdisk und erstelle eine GPT...\n");
    char initGPTCommand[100];
    sprintf(initGPTCommand, "gdisk %s", blockDevice);
    system(initGPTCommand);
    printf("GPT erfolgreich erstellt.\n");
}

int main() {
    char blockDevice[50];
    int choice;

    printf("*** VT-DiskTool v0.1 | (C) 2023 - VilsTux ***\n\n");

    // Benutzer nach dem Blockgerät fragen
    printf("Geben Sie das Blockgerät ein (z.B. /dev/sda): ");
    scanf("%s", blockDevice);

    // Überprüfen, ob GPT vorhanden ist
    printf("Überpruefe GPT auf %s...\n", blockDevice);
    char checkGPTCommand[100];
    sprintf(checkGPTCommand, "gdisk -l %s | grep 'GPT present'", blockDevice);
    int gptPresent = system(checkGPTCommand);

    if (gptPresent != 0) {
        // GPT nicht gefunden, erstelle eine GPT
        createGPT(blockDevice);
    }

    // Benutzer nach der Aktion fragen
    printf("Wählen Sie eine Aktion:\n");
    printf("1. Festplatte komplett nullen\n");
    printf("2. Festplatte mit NTFS oder ext4 formatieren\n");
    scanf("%d", &choice);

    // Aktion basierend auf der Benutzerwahl ausführen
    switch (choice) {
        case 1:
            // Festplatte komplett nullen
            printf("Nullen der Festplatte %s...\n", blockDevice);
            char nullCommand[100];
            sprintf(nullCommand, "dd if=/dev/zero of=%s bs=4M", blockDevice);
            system(nullCommand);
            printf("Festplatte erfolgreich genullt.\n");
            break;
        case 2:
            // Überprüfen, ob GPT vorhanden ist
            if (gptPresent != 0) {
                // GPT nicht gefunden, erstelle eine GPT
                createGPT(blockDevice);
            }

            // Formatierung erlauben, da GPT jetzt vorhanden ist
            printf("GPT vorhanden. Suche nach Partitionen auf %s...\n", blockDevice);
            char listPartitionsCommand[100];
            sprintf(listPartitionsCommand, "gdisk -l %s | grep -E '^\\s*[0-9]'", blockDevice);
            printf("Verfügbare Partitionen:\n");
            system(listPartitionsCommand);

            int partitionChoice;
            printf("Wählen Sie die Partition aus, die formatiert werden soll: ");
            scanf("%d", &partitionChoice);

            // Formatierung basierend auf der Dateisystemwahl durchführen
            char formatCommand[100];
            int fsChoice;
            printf("Wählen Sie das Dateisystem:\n");
            printf("1. NTFS\n");
            printf("2. ext4\n");
            scanf("%d", &fsChoice);

            switch (fsChoice) {
                case 1:
                    sprintf(formatCommand, "mkfs.ntfs %s%d", blockDevice, partitionChoice);
                    break;
                case 2:
                    sprintf(formatCommand, "mkfs.ext4 %s%d", blockDevice, partitionChoice);
                    break;
                default:
                    printf("Ungueltige Auswahl.\n");
                    return 1;
            }

            // Festplatte formatieren
            printf("Formatiere die Partition %s%d...\n", blockDevice, partitionChoice);
            system(formatCommand);
            printf("Partition erfolgreich formatiert.\n");
            break;
        default:
            printf("Ungültige Auswahl.\n");
            return 1;
    }

    return 0;
}
